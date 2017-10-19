/**
	@file
	rhythmogram.c
 
	@name 
	bach.rhythmogram
 
	@realname 
	bach.rhythmogram
 
	@type
	object
 
	@module
	bach
 
	@author
	bachproject
	
	@status
	experimental
 
	@digest 
	Fourier rhythmic analysis
 
	@description 
	Performs Fourier rhythmic analysis from symbolic data, and also 
	interactively detects metric information.
 
	@discussion
 
	@category
	bach, bach objects, bach notation
 
 	@keywords
	rhythm, Fourier, analysis, spectrogram, partial tracking, quantize, measureinfo, estimation

	@seealso
	bach.roll, bach.score, bach.quantize
 
	@owner
	Daniele Ghisi
 */

#include "notation_spectral.h"
#include "bach_math_utilities.h"
#include "ext.h"
#include "ext_obex.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_globalsymbol.h"
#include "ext_systhread.h"
#include "ext_common.h"
#include "ext_critical.h"
#include <stdio.h>
#include <locale.h>


#define CONST_MAX_SAMPLING_POINTS 1000
#define CONST_MIN_SINGLEWEIGHT_TO_ACCOUNT 0.00001

typedef enum _rhythmogram_modes 
{
	k_MODE_ONSET_WAVE = 0,
	k_MODE_RHYTHMOSCOPE = 1,
	k_MODE_AUTOCORRELATION = 2,
	k_MODE_RHYTHMOGRAM = 3,
	k_MODE_AUTOCORRELOGRAM = 4,
	k_MODE_PARTIAL_TRACKING = 5,
	k_MODE_TS_DETECTOR = 6,
} e_rhythmogram_modes;


typedef struct _rhythmogram 
{
	t_llllobj_jbox	j_box; 

	char			mode;
	char			realtime;
	char			phase;
	
	double			winsize;
	long			oversampling;
	
	long			height;			///< Height of the object in pixels
	long			width;			///< Width of the object in pixels

	e_win_types		win_type;
	e_shape_types	shape_of_contributions;		///< Shape of the contributions
	double			bpm_peak_decay;
	char			normalize;		///< Normalize amplitudes with respect to the number of notes

	// modeling parameter
	double			voice_coupling;
	double			velocity_slope;
	
	char			use_masking_detection;
	double			extend_masking_ms;
	char			extend_masking_components_over_masked_ones;
	double			non_sequential_events_multiplier; 
	double			cluster_size_ms;
	double			waveshaping_exp;
	
	double			gain_multiplier_for_maxima;
	double			gain_multiplier_for_minima;
	double			debug_bpm[2];
	
	// harmonic analysis
	char			use_harmonic_detection;
	double			harmonic_changes_contribution;
	char			snap_harmonic_detected_onsets_to_nearest_note;
	double			harmonic_detection_median_filtering_window_ms;
	double			hc_winsize; 
	double			hc_hopsize;
	double			delete_softer_harmonic_changes_inside_win_ms;
	
	t_jrgba			j_color;
	t_jrgba			j_bgcolor;
	t_jrgba			j_bordercolor;
	t_jrgba			j_hintcolor;
	t_jrgba			j_hintbgcolor;
	
	char			show_hint; 
	double			curr_hint_bpm;
	double			curr_hint_hz;
	long			curr_hint_frame;
	double			curr_hint_ms;
	t_tsd_config	*curr_mouseover_tsd_segment;
	t_pt			curr_mouse_pt;
	
	char			j_mouse_is_over;
	int				mousecursor;
	
	double			min_sampled_bpm;
	double			max_sampled_bpm;

	double			min_displayed_bpm;
	double			max_displayed_bpm;
	char			auto_display_amplitude;	// automatically normalize colors
	double			max_amplitude;			// maximum amplitude actually happening in the data
	double			max_displayed_amplitude;
	double			min_displayed_amplitude;
	double			max_displayed_amplitude_rhythmoscope;
	double			max_displayed_amplitude_onset_wave;
	
	// partial tracking
	long			numpeaks;
	double			minpeakamp;
	double			minpeakrelamp;
	char			ptrack_filter_secondary_peaks;
	long			ptrack_voices;
	double			ptrack_amp; 
	double			ptrack_amplow; 
	char			ptrack_amprel; // amplitudes are relative to the greater bin amplitude across all frames
	double			ptrack_freqratio; 
	double			ptrack_phasedelta; 
	double			ptrack_attack;
	double			ptrack_release;
	double			ptrack_locut; // lowcut frequency (in bpm)
	
	char			use_combined_dft_fmacf_function;
	
	double			max_ptrack_amplitude; // maximum amplitude across all ptrack peaks
	
	// time signature detection
	double			min_tempo;
	double			max_tempo;
	char			max_divisions;
	char			only_standard_subdivisions;
	double			prefer_longer_segments;
	double			ignore_segments_under_ms;
	double			ignore_covered_segments_with_relative_weight_under;
	
	long			denominator_for_binary_ts;
	long			denominator_for_ternary_ts;
	long			denominator_for_nonstandard_ts;
	
	char			autocorrect;
	char			autoclear_roll_markers;
	
	t_tsd_config	*first_segment_config;
	t_tsd_config	*last_segment_config;
	long			num_segment_tsd_configs;
	double			max_tsd_segment_weight;
	char			detected_onsets_affect_tsd_weights;

	double			mc_outer_threshold;
	double			mc_inner_threshold;
	
	double			*sampling_vals;
	double			*sampling_phase;
	long			num_sampling_vals;
	long			num_sampling_vals_between_minbpm_and_maxbpm;
	long			num_windows_in_history;	// actually the number of FRAMES
	long			fixed_num_windows_in_history;
	
	t_tsd_config	*selected_config;
	long			mousedown_config_pos; // -1: mousedown the beginning, 1: mousedown the end, 0 middle or nothing
	char			segment_config_has_been_dragged;
	
	long			scroll_count; // private
	
	double			end_ms;
	double			*tags;
	long			tags_size;
	
	// used by ONSET_WAVE modeling
	char			algorithm;
	double			forced_length; 
	double			decay_time;
	double			sampling_frequency;
	double			zero_padding_factor;
	
	t_llll			*wave_data;
	t_llll			*dft_data;
	t_llll			*dft_peaks_data;
	t_llll			*acf_data;
	t_llll			*acf_peaks_data;
	t_llll			*ptrack_data;
	t_llll			*tsd_data;
	
	/// frame selection
	long			selected_frame_number; // 1-based
	
	
	t_jsurface		*surface;
	
	t_systhread_mutex		c_mutex;

	char			recalled_attributes;
	char			first_surface_draw;
} t_rhythmogram;


// global class pointer variable
t_class	*s_rhythmogram_class = NULL;

// functions
void rhythmogram_inletinfo(t_rhythmogram *x, void *b, long a, char *t);
void rhythmogram_assist(t_rhythmogram *x, void *b, long m, long a, char *s);
void rhythmogram_bang(t_rhythmogram *x);

void rhythmogram_free(t_rhythmogram *x);

void rhythmogram_focusgained(t_rhythmogram *x, t_object *patcherview);
void rhythmogram_focuslost(t_rhythmogram *x, t_object *patcherview);
void rhythmogram_mousedown(t_rhythmogram *x, t_object *patcherview, t_pt pt, long modifiers);
void rhythmogram_mousemove(t_rhythmogram *x, t_object *patcherview, t_pt pt, long modifiers);
void rhythmogram_mousedoubleclick(t_rhythmogram *x, t_object *patcherview, t_pt pt, long modifiers);
void rhythmogram_mouseup(t_rhythmogram *x, t_object *patcherview, t_pt pt, long modifiers);
void rhythmogram_mousedrag(t_rhythmogram *x, t_object *patcherview, t_pt pt, long modifiers);
long rhythmogram_oksize(t_rhythmogram *x, t_rect *newrect);
void rhythmogram_mouseenter(t_rhythmogram *x, t_object *patcherview, t_pt pt, long modifiers);
void rhythmogram_mouseleave(t_rhythmogram *x, t_object *patcherview, t_pt pt, long modifiers);
long rhythmogram_key(t_rhythmogram *x, t_object *patcherview, long keycode, long modifiers, long textcharacter);

t_rhythmogram* rhythmogram_new(t_symbol *s, long argc, t_atom *argv);

void rhythmogram_paint(t_rhythmogram *x, t_object *view);

void rhythmogram_anything(t_rhythmogram *x, t_symbol *s, long argc, t_atom *argv);
void rhythmogram_dump(t_rhythmogram *x, t_symbol *s, long argc, t_atom *argv);
void rhythmogram_peaks(t_rhythmogram *x, t_symbol *s, long argc, t_atom *argv);
void rhythmogram_acpeaks(t_rhythmogram *x, t_symbol *s, long argc, t_atom *argv);

t_max_err rhythmogram_setattr_numpoints(t_rhythmogram *x, t_object *attr, long ac, t_atom *av);
t_max_err rhythmogram_setattr_numhistorywins(t_rhythmogram *x, t_object *attr, long ac, t_atom *av);
t_max_err rhythmogram_setattr_mode(t_rhythmogram *x, t_object *attr, long ac, t_atom *av);

void initialize_surface(t_rhythmogram *x, long height);


/** Algorithms to handle frequency contents
	@ingroup	spectral
 */
typedef enum _rhythmogram_algorithms
{
	k_RHYTHMOGRAM_ALGORITHM_ONSET_DIFFERENCES = 0,	///< Obtain frequencial information just by using onset differences inside the score
	k_RHYTHMOGRAM_ALGORITHM_ONSET_WAVE = 1,			///< Obtain frequencial information by modeling an "onset wave", a wave having dampened sinusoidal components for chords couples.
} e_rhythmogram_algorithms;
	
int T_EXPORT main(void){
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();

	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}

	c = class_new("bach.rhythmogram", 
						(method)rhythmogram_new,
						(method)rhythmogram_free,
						sizeof(t_rhythmogram),
						(method)NULL,
						A_GIMME,
						0L);
	
	c->c_flags |= CLASS_FLAG_NEWDICTIONARY;

//	jbox_initclass(c, JBOX_COLOR | JBOX_FIXWIDTH | JBOX_FONTATTR);
	jbox_initclass(c, 0);
	
	class_addmethod(c, (method) rhythmogram_paint,			"paint", A_CANT, 0);

	class_addmethod(c, (method) rhythmogram_anything,		"anything", A_GIMME, 0);
	class_addmethod(c, (method) rhythmogram_anything,		"list", A_GIMME, 0);
	class_addmethod(c, (method) rhythmogram_dump,			"dump", A_GIMME, 0);
	class_addmethod(c, (method) rhythmogram_peaks,			"peaks", A_GIMME, 0);
	class_addmethod(c, (method) rhythmogram_acpeaks,		"acpeaks", A_GIMME, 0);

	class_addmethod(c, (method) rhythmogram_mousedown,			"mousedown", A_CANT, 0);
    class_addmethod(c, (method) rhythmogram_mousedoubleclick,	"mousedoubleclick", A_CANT, 0);
	class_addmethod(c, (method) rhythmogram_mousedrag,			"mousedrag", A_CANT, 0);
	class_addmethod(c, (method) rhythmogram_mouseup,			"mouseup", A_CANT, 0);
	class_addmethod(c, (method) rhythmogram_mousemove,			"mousemove", A_CANT, 0);
	class_addmethod(c, (method) rhythmogram_oksize,				"oksize", A_CANT, 0);
	class_addmethod(c, (method) rhythmogram_mouseenter,			"mouseenter", A_CANT, 0);
	class_addmethod(c, (method) rhythmogram_mouseleave,			"mouseleave", A_CANT, 0);
  	class_addmethod(c, (method) rhythmogram_key,				"key", A_CANT, 0);

	class_addmethod(c, (method) rhythmogram_inletinfo,		"inletinfo", A_CANT, 0);
	class_addmethod(c, (method) rhythmogram_assist,			"assist", A_CANT, 0);
	class_addmethod(c, (method) rhythmogram_bang,			"bang", 0);

	llllobj_class_add_out_attr(c, LLLL_OBJ_UI);


	CLASS_ATTR_DEFAULT(c, "patching_rect", 0, "0 0 240 120"); // new dimensions
	// @exclude bach.rhythmogram

	CLASS_STICKY_ATTR(c,"category",0,"Color");

		CLASS_ATTR_RGBA(c, "color", 0, t_rhythmogram, j_color);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "color", 0, "0.3 0. 0. 1.");
		CLASS_ATTR_STYLE_LABEL(c, "color", 0, "rgba", "Graph Color");

		CLASS_ATTR_RGBA(c, "bgcolor", 0, t_rhythmogram, j_bgcolor);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bgcolor", 0, "1. 1. 1. 1.");
		CLASS_ATTR_STYLE_LABEL(c, "bgcolor", 0, "rgba", "Background Color");
		CLASS_ATTR_BASIC(c,"bgcolor",0);

		CLASS_ATTR_RGBA(c, "bordercolor", 0, t_rhythmogram, j_bordercolor);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bordercolor", 0, "0.2 0.2 0.2 1.");
		CLASS_ATTR_STYLE_LABEL(c, "bordercolor", 0, "rgba", "Border Color");

		CLASS_ATTR_RGBA(c, "hintcolor", 0, t_rhythmogram, j_hintcolor);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "hintcolor", 0, "0.2 0.2 0.2 1.");
		CLASS_ATTR_STYLE_LABEL(c, "hintcolor", 0, "rgba", "Hint Color");

		CLASS_ATTR_RGBA(c, "hintbgcolor", 0, t_rhythmogram, j_hintbgcolor);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "hintbgcolor", 0, "0.84 0.84 0.74 1.");
		CLASS_ATTR_STYLE_LABEL(c, "hintbgcolor", 0, "rgba", "Hint Background Color");

	CLASS_STICKY_ATTR_CLEAR(c, "category");
	

	CLASS_STICKY_ATTR(c,"category",0,"Settings");


		CLASS_ATTR_CHAR(c,"mode",0, t_rhythmogram, mode);
		CLASS_ATTR_STYLE_LABEL(c,"mode",0,"enumindex","Mode");
		CLASS_ATTR_ENUMINDEX(c,"mode", 0, "Onset Wave Rhythmoscope Autocorrelation Rhythmogram Autocorrelogram Peak Tracking Measureinfo Estimation"); 
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"mode",0,"3");
		CLASS_ATTR_ACCESSORS(c, "mode", (method)NULL, (method)rhythmogram_setattr_mode);
		CLASS_ATTR_BASIC(c,"mode",0);

		CLASS_ATTR_CHAR(c,"algorithm",0, t_rhythmogram, algorithm);
		CLASS_ATTR_STYLE_LABEL(c,"algorithm",0,"enumindex","Algorithm");
		CLASS_ATTR_ENUMINDEX(c,"algorithm", 0, "Onset Differences (OD) Onset Wave & DFT (OW)"); 
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"algorithm",0,"1");
		CLASS_ATTR_FILTER_CLIP(c, "algorithm", 0, 1);
		CLASS_ATTR_INVISIBLE(c, "algorithm", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE); // just for now

		CLASS_ATTR_CHAR(c,"realtime",0, t_rhythmogram, realtime);
		CLASS_ATTR_STYLE_LABEL(c,"realtime",0,"onoff","Realtime Mode");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"realtime",0,"0");
		CLASS_ATTR_FILTER_CLIP(c, "realtime", 0, 1);
		CLASS_ATTR_INVISIBLE(c, "realtime", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE); // just for now

		CLASS_ATTR_CHAR(c,"autoclearrollmarkers",0, t_rhythmogram, autoclear_roll_markers);
		CLASS_ATTR_STYLE_LABEL(c,"autoclearrollmarkers",0,"onoff","Automatically Clear Markers Of Connected bach.roll");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"autoclearrollmarkers",0,"0");
		CLASS_ATTR_FILTER_CLIP(c, "autoclearrollmarkers", 0, 1);
	
		CLASS_ATTR_CHAR(c,"phase",0, t_rhythmogram, phase);
		CLASS_ATTR_STYLE_LABEL(c,"phase",0,"enumindex","Display");
		CLASS_ATTR_ENUMINDEX(c,"phase", 0, "Amplitude Phase Both"); 
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"phase",0,"0");
		CLASS_ATTR_FILTER_CLIP(c, "phase", 0, 2);

	CLASS_STICKY_ATTR_CLEAR(c, "category");


	CLASS_STICKY_ATTR(c,"category",0,"Model");

/*		CLASS_ATTR_CHAR(c, "peakshape", 0, t_rhythmogram, shape_of_contributions); 
		CLASS_ATTR_STYLE_LABEL(c,"peakshape",0,"enumindex","OD: Shape Of Each Peak Contribution");
		CLASS_ATTR_ENUMINDEX(c,"peakshape", 0, "Triangular Cosine Gaussian Hanning Punctual"); 
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"peakshape",0,"0");

		CLASS_ATTR_DOUBLE(c, "velocityslope", 0, t_rhythmogram, velocity_slope); 
		CLASS_ATTR_STYLE_LABEL(c,"velocityslope",0,"text","OD: Velocity Handling Slope");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"velocityslope",0,"0");
		CLASS_ATTR_FILTER_CLIP(c, "velocityslope", -1, 1);
*/
		CLASS_ATTR_DOUBLE(c, "voicecoupling", 0, t_rhythmogram, voice_coupling); 
		CLASS_ATTR_STYLE_LABEL(c,"voicecoupling",0,"text","Voice Coupling");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"voicecoupling",0,"0.2");
		CLASS_ATTR_FILTER_CLIP(c, "voicecoupling", 0, 1);

		CLASS_ATTR_DOUBLE(c, "waveshapingexp", 0, t_rhythmogram, waveshaping_exp); 
		CLASS_ATTR_STYLE_LABEL(c,"waveshapingexp",0,"text","Waveshaping Exponent");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"waveshapingexp",0,"1.");
		CLASS_ATTR_FILTER_CLIP(c, "waveshapingexp", 0, 1);

		CLASS_ATTR_CHAR(c, "normalize", 0, t_rhythmogram, normalize); 
		CLASS_ATTR_STYLE_LABEL(c,"normalize",0,"onoff","Normalize Wave");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"normalize",0,"1");
		CLASS_ATTR_FILTER_CLIP(c, "normalize", 0, 1);

		CLASS_ATTR_DOUBLE(c, "pitchthreshold1", 0, t_rhythmogram, mc_inner_threshold); 
		CLASS_ATTR_STYLE_LABEL(c,"pitchthreshold1",0,"text","Pitch Threshold For Complete Account (mc)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"pitchthreshold1",0,"500");
		CLASS_ATTR_INVISIBLE(c, "pitchthreshold1", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE);

		CLASS_ATTR_DOUBLE(c, "pitchthreshold2", 0, t_rhythmogram, mc_outer_threshold); 
		CLASS_ATTR_STYLE_LABEL(c,"pitchthreshold2",0,"text","Pitch Threshold For No Account (mc)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"pitchthreshold2",0,"20");
		CLASS_ATTR_INVISIBLE(c, "pitchthreshold2", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE);

		CLASS_ATTR_DOUBLE(c, "decaytime", 0, t_rhythmogram, decay_time); 
		CLASS_ATTR_STYLE_LABEL(c,"decaytime",0,"text","Decay Time");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"decaytime",0,"5000");
		CLASS_ATTR_FILTER_MIN(c, "decaytime", 0);

		CLASS_ATTR_DOUBLE(c, "samplingrate", 0, t_rhythmogram, sampling_frequency); 
		CLASS_ATTR_STYLE_LABEL(c,"samplingrate",0,"text","Sampling Rate");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"samplingrate",0,"40");
		CLASS_ATTR_FILTER_MIN(c, "samplingrate", 1);

		CLASS_ATTR_DOUBLE(c, "nonseq", 0, t_rhythmogram, non_sequential_events_multiplier); 
		CLASS_ATTR_STYLE_LABEL(c,"nonseq",0,"text","Amplitude Dampening For Non-Sequential Onsets");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"nonseq",0,"0.5");

		CLASS_ATTR_DOUBLE(c,"clustersize",0, t_rhythmogram, cluster_size_ms);
		CLASS_ATTR_STYLE_LABEL(c,"clustersize",0,"text","Denoise Clustering Window Size (ms)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"clustersize",0,"70");
		CLASS_ATTR_FILTER_MIN(c, "clustersize", 0);

		CLASS_ATTR_CHAR(c, "useharmony", 0, t_rhythmogram, use_harmonic_detection); 
		CLASS_ATTR_STYLE_LABEL(c,"useharmony",0,"onoff","Account For Harmonic Changes");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"useharmony",0,"0");
		CLASS_ATTR_FILTER_CLIP(c, "useharmony", 0, 1);
		CLASS_ATTR_BASIC(c,"useharmony",0);
		
		CLASS_ATTR_DOUBLE(c,"gainmax",0, t_rhythmogram, gain_multiplier_for_maxima);
		CLASS_ATTR_STYLE_LABEL(c,"gainmax",0,"text","Gain Multiplier For Pitch Maxima");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"gainmax",0,"1.");
		CLASS_ATTR_FILTER_MIN(c, "gainmax", 0);
		
		CLASS_ATTR_DOUBLE(c,"gainmin",0, t_rhythmogram, gain_multiplier_for_minima);
		CLASS_ATTR_STYLE_LABEL(c,"gainmin",0,"text","Gain Multiplier For Pitch Minima");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"gainmin",0,"1.2");
		CLASS_ATTR_FILTER_MIN(c, "gainmin", 0);

		CLASS_ATTR_DOUBLE_ARRAY(c,"debugbpm",0, t_rhythmogram, debug_bpm, 2);
		CLASS_ATTR_STYLE_LABEL(c,"debugbpm",0,"text","Debug BPM");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"debugbpm",0,"-5 -5");
		CLASS_ATTR_INVISIBLE(c, "debugbpm", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE);

		CLASS_ATTR_CHAR(c, "masking", 0, t_rhythmogram, use_masking_detection); 
		CLASS_ATTR_STYLE_LABEL(c,"masking",0,"onoff","Use Masking Detection");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"masking",0,"1");
		CLASS_ATTR_BASIC(c,"masking",0);

		CLASS_ATTR_CHAR(c, "maskingextover", 0, t_rhythmogram, extend_masking_components_over_masked_ones); 
		CLASS_ATTR_STYLE_LABEL(c,"maskingextover",0,"onoff","Extend Masking Components Over Masked Ones");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maskingextover",0,"1");

		CLASS_ATTR_DOUBLE(c, "maskingext", 0, t_rhythmogram, extend_masking_ms); 
		CLASS_ATTR_STYLE_LABEL(c,"maskingext",0,"text","Extend Masking Over Boundaries (Ms)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maskingext",0,"0");

	CLASS_STICKY_ATTR_CLEAR(c, "category");


	CLASS_STICKY_ATTR(c,"category",0,"Analysis");

		CLASS_ATTR_DOUBLE(c, "zeropadding", 0, t_rhythmogram, zero_padding_factor); 
		CLASS_ATTR_STYLE_LABEL(c,"zeropadding",0,"text","Zero Padding FFT Factor");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"zeropadding",0,"5");
		CLASS_ATTR_FILTER_MIN(c, "zeropadding", 1);

		CLASS_ATTR_DOUBLE(c,"winsize",0, t_rhythmogram, winsize);
		CLASS_ATTR_STYLE_LABEL(c,"winsize",0,"text","Window Size (ms)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"winsize",0,"12000");
		CLASS_ATTR_FILTER_MIN(c, "winsize", 0);

		CLASS_ATTR_CHAR(c, "wintype", 0, t_rhythmogram, win_type); 
		CLASS_ATTR_STYLE_LABEL(c,"wintype",0,"enumindex","Window Type");
		CLASS_ATTR_ENUMINDEX(c,"wintype", 0, "Rectangular Triangular Hamming Hanning Cosine"); 
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"wintype",0,"0");
	
		CLASS_ATTR_LONG(c,"oversampling",0, t_rhythmogram, oversampling);
		CLASS_ATTR_STYLE_LABEL(c,"oversampling",0,"text","Oversampling");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"oversampling",0,"8");
		CLASS_ATTR_FILTER_MIN(c, "oversampling", 1);
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");


	CLASS_STICKY_ATTR(c,"category",0,"Harmonic Detection")
	
		CLASS_ATTR_DOUBLE(c, "hcwinsize", 0, t_rhythmogram, hc_winsize); 
		CLASS_ATTR_STYLE_LABEL(c,"hcwinsize",0,"text","Harmonic Changes Detection Window Size");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"hcwinsize",0,"2000");

		CLASS_ATTR_DOUBLE(c, "hchopsize", 0, t_rhythmogram, hc_hopsize); 
		CLASS_ATTR_STYLE_LABEL(c,"hchopsize",0,"text","Harmonic Changes Detection Hop Size");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"hchopsize",0,"50");
		
		CLASS_ATTR_DOUBLE(c, "hcclustersize", 0, t_rhythmogram, delete_softer_harmonic_changes_inside_win_ms); 
		CLASS_ATTR_STYLE_LABEL(c,"hcclustersize",0,"text","Detected Harmonic Changes Clustering Window Size (ms)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"hcclustersize",0,"600");

		CLASS_ATTR_DOUBLE(c, "harmchange", 0, t_rhythmogram, harmonic_changes_contribution); 
		CLASS_ATTR_STYLE_LABEL(c,"harmchange",0,"text","Detected Harmonic Changes Contribution");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"harmchange",0,"8.");
		CLASS_ATTR_FILTER_MIN(c, "harmchange", 0);

		CLASS_ATTR_CHAR(c, "snapharmchange", 0, t_rhythmogram, snap_harmonic_detected_onsets_to_nearest_note); 
		CLASS_ATTR_STYLE_LABEL(c,"snapharmchange",0,"onoff","Snap Detected Harmonic Changes To Nearest Note");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"snapharmchange",0,"1");

		CLASS_ATTR_DOUBLE(c, "harmchangefilterwinsize", 0, t_rhythmogram, harmonic_detection_median_filtering_window_ms); 
		CLASS_ATTR_STYLE_LABEL(c,"harmchangefilterwinsize",0,"text","Harmonic Changes Median Filtering Window Size (ms)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"harmchangefilterwinsize",0,"150");

	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c,"category",0,"Peak Tracking");
	
		CLASS_ATTR_LONG(c, "numpeaks", 0, t_rhythmogram, numpeaks); 
		CLASS_ATTR_STYLE_LABEL(c,"numpeaks",0,"text","Maximum Number Of Peaks Per Frame");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"numpeaks",0,"6");

		CLASS_ATTR_DOUBLE(c, "minpeakamp", 0, t_rhythmogram, minpeakamp); 
		CLASS_ATTR_STYLE_LABEL(c,"minpeakamp",0,"text","Minimum Peak Amplitude");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"minpeakamp",0,"0");
		CLASS_ATTR_FILTER_MIN(c, "minpeakamp", 0);

		CLASS_ATTR_DOUBLE(c, "minpeakrelamp", 0, t_rhythmogram, minpeakrelamp); 
		CLASS_ATTR_STYLE_LABEL(c,"minpeakrelamp",0,"text","Minimum Relative Peak Amplitude");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"minpeakrelamp",0,"0");
		CLASS_ATTR_FILTER_MIN(c, "minpeakrelamp", 0);

		CLASS_ATTR_LONG(c, "ptvoices", 0, t_rhythmogram, ptrack_voices); 
		CLASS_ATTR_STYLE_LABEL(c,"ptvoices",0,"text","Maximum Number Of Voices Per Frame");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"ptvoices",0,"10");
		CLASS_ATTR_FILTER_MIN(c, "ptvoices", 1);

		CLASS_ATTR_DOUBLE(c, "ptamp", 0, t_rhythmogram, ptrack_amp); 
		CLASS_ATTR_STYLE_LABEL(c,"ptamp",0,"text","Minimum Amplitude For A Voice To Start");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"ptamp",0,"0.");
		CLASS_ATTR_FILTER_MIN(c, "ptamp", 0);

		CLASS_ATTR_DOUBLE(c, "ptamplow", 0, t_rhythmogram, ptrack_amplow); 
		CLASS_ATTR_STYLE_LABEL(c,"ptamplow",0,"text","Minimum Amplitude For A Voice To Continue");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"ptamplow",0,"0.");
		CLASS_ATTR_FILTER_MIN(c, "ptamplow", 0);

		CLASS_ATTR_CHAR(c, "useacf", 0, t_rhythmogram, use_combined_dft_fmacf_function); 
		CLASS_ATTR_STYLE_LABEL(c,"useacf",0,"onoff","Combine Spectral Data With Autocorrelation Function");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"useacf",0,"1");
		CLASS_ATTR_BASIC(c,"useacf",0);

		CLASS_ATTR_CHAR(c, "ptamprel", 0, t_rhythmogram, ptrack_amprel); 
		CLASS_ATTR_STYLE_LABEL(c,"ptamprel",0,"onoff","Minimum Amplitudes Are Relative");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"ptamprel",0,"1");

		CLASS_ATTR_DOUBLE(c, "ptfreqratio", 0, t_rhythmogram, ptrack_freqratio); 
		CLASS_ATTR_STYLE_LABEL(c,"ptfreqratio",0,"text","Maximum Frequency Ratio For A Voice To Continue");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"ptfreqratio",0,"1.1");
		
		CLASS_ATTR_DOUBLE(c, "ptphasedelta", 0, t_rhythmogram, ptrack_phasedelta); 
		CLASS_ATTR_STYLE_LABEL(c,"ptphasedelta",0,"text","Maximum Allowed Phase Error (In Degrees) For A Voice To Continue");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"ptphasedelta",0,"360");

		CLASS_ATTR_DOUBLE(c, "ptattack", 0, t_rhythmogram, ptrack_attack); 
		CLASS_ATTR_STYLE_LABEL(c,"ptattack",0,"text","Attack Time (In Milliseconds)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"ptattack",0,"50");
		CLASS_ATTR_FILTER_MIN(c, "ptattack", 0);

		CLASS_ATTR_DOUBLE(c, "ptrelease", 0, t_rhythmogram, ptrack_release); 
		CLASS_ATTR_STYLE_LABEL(c,"ptrelease",0,"text","Release Time (In Milliseconds)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"ptrelease",0,"20000");  
		CLASS_ATTR_FILTER_MIN(c, "ptrelease", 0);

		CLASS_ATTR_DOUBLE(c, "ptlowcut", 0, t_rhythmogram, ptrack_locut); 
		CLASS_ATTR_STYLE_LABEL(c,"ptlowcut",0,"text","Low Cut Tempo (In BPM)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"ptlowcut",0,"15");  
		CLASS_ATTR_FILTER_MIN(c, "ptlowcut", 0);
		
		CLASS_ATTR_CHAR(c, "ptfiltersecpeaks", 0, t_rhythmogram, ptrack_filter_secondary_peaks); 
		CLASS_ATTR_STYLE_LABEL(c,"ptfiltersecpeaks",0,"onoff","Filter Secondary Peaks");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"ptfiltersecpeaks",0,"1");
		
		
	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c,"category",0,"Measureinfo Estimation");
	
		CLASS_ATTR_DOUBLE(c, "mintempo", 0, t_rhythmogram, min_tempo); 
		CLASS_ATTR_STYLE_LABEL(c,"mintempo",0,"text","Minimum Tempo (In BPM)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"mintempo",0,"50");
		CLASS_ATTR_BASIC(c,"mintempo",0);

		CLASS_ATTR_DOUBLE(c, "maxtempo", 0, t_rhythmogram, max_tempo); 
		CLASS_ATTR_STYLE_LABEL(c,"maxtempo",0,"text","Maximum Tempo (In BPM)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxtempo",0,"150");
		CLASS_ATTR_BASIC(c,"maxtempo",0);

		CLASS_ATTR_CHAR(c, "maxdiv", 0, t_rhythmogram, max_divisions); 
		CLASS_ATTR_STYLE_LABEL(c,"maxdiv",0,"text","Maximum Number Of Divisions");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxdiv",0,"4");
		CLASS_ATTR_FILTER_MIN(c, "maxdiv", 2);

		CLASS_ATTR_CHAR(c, "standardsubdiv", 0, t_rhythmogram, only_standard_subdivisions); 
		CLASS_ATTR_STYLE_LABEL(c,"standardsubdiv",0,"onoff","Only Standard Subdivisions");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"standardsubdiv",0,"1");

		CLASS_ATTR_CHAR(c, "autocorrect", 0, t_rhythmogram, autocorrect); 
		CLASS_ATTR_STYLE_LABEL(c,"autocorrect",0,"enumindex","Autocorrect Division Onsets");
		CLASS_ATTR_ENUMINDEX(c,"autocorrect", 0, "None Slight Heavy"); 
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"autocorrect",0,"1");
		CLASS_ATTR_BASIC(c,"autocorrect",0);

		CLASS_ATTR_CHAR(c, "evennessaffectsweight", 0, t_rhythmogram, detected_onsets_affect_tsd_weights); 
		CLASS_ATTR_STYLE_LABEL(c,"evennessaffectsweight",0,"onoff","Division Evenness Affects Segment Weight");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"evennessaffectsweight",0,"1");

		CLASS_ATTR_LONG(c, "den2", 0, t_rhythmogram, denominator_for_binary_ts); 
		CLASS_ATTR_STYLE_LABEL(c,"den2",0,"text","Denominator For Binary Time Signatures");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"den2",0,"4");

		CLASS_ATTR_LONG(c, "den3", 0, t_rhythmogram, denominator_for_ternary_ts); 
		CLASS_ATTR_STYLE_LABEL(c,"den3",0,"text","Denominator For Ternary Time Signatures");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"den3",0,"8");

		CLASS_ATTR_LONG(c, "denns", 0, t_rhythmogram, denominator_for_nonstandard_ts); 
		CLASS_ATTR_STYLE_LABEL(c,"denns",0,"text","Denominator For Non-Standard Time Signatures");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"denns",0,"8");
		
		CLASS_ATTR_DOUBLE(c, "longsegments", 0, t_rhythmogram, prefer_longer_segments); 
		CLASS_ATTR_STYLE_LABEL(c,"longsegments",0,"text","Prefer Long Segments");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"longsegments",0,"0.8");
		CLASS_ATTR_FILTER_CLIP(c, "longsegments", 0., 1.);

		CLASS_ATTR_DOUBLE(c, "discardsegmentsunder", 0, t_rhythmogram, ignore_segments_under_ms); 
		CLASS_ATTR_STYLE_LABEL(c,"discardsegmentsunder",0,"text","Discard Segments Under (In Ms)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"discardsegmentsunder",0,"5000");
		CLASS_ATTR_FILTER_MIN(c, "discardsegmentsunder", 0.);

		CLASS_ATTR_DOUBLE(c, "discardsegmentsunderrelweight", 0, t_rhythmogram, ignore_covered_segments_with_relative_weight_under); 
		CLASS_ATTR_STYLE_LABEL(c,"discardsegmentsunderrelweight",0,"text","Discard Covered Segments Threshold %");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"discardsegmentsunderrelweight",0,"10");
		CLASS_ATTR_FILTER_MIN(c, "discardsegmentsunderrelweight", 0.);

	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c,"category",0,"Display");

		CLASS_ATTR_CHAR(c, "hint", 0, t_rhythmogram, show_hint); 
		CLASS_ATTR_STYLE_LABEL(c,"hint",0,"onoff","Show Mouseover Hint");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"hint",0,"1");
	
		CLASS_ATTR_DOUBLE(c,"minbpm",0, t_rhythmogram, min_displayed_bpm);
		CLASS_ATTR_STYLE_LABEL(c,"minbpm",0,"text","Minimum Displayed BPM");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"minbpm",0,"0");
		CLASS_ATTR_FILTER_MIN(c, "minbpm", 0);
	
		CLASS_ATTR_DOUBLE(c,"maxbpm",0, t_rhythmogram, max_displayed_bpm);
		CLASS_ATTR_STYLE_LABEL(c,"maxbpm",0,"text","Maximum Displayed BPM");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxbpm",0,"400");
		CLASS_ATTR_FILTER_MIN(c, "maxbpm", 0);

		CLASS_ATTR_CHAR(c,"autocolor",0, t_rhythmogram, auto_display_amplitude);
		CLASS_ATTR_STYLE_LABEL(c,"autocolor",0,"onoff","Automatically Normalize Colors");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"autocolor",0,"1");
		CLASS_ATTR_FILTER_MIN(c, "autocolor", 0);
		
		CLASS_ATTR_DOUBLE(c,"coloredampli",0, t_rhythmogram, max_displayed_amplitude);
		CLASS_ATTR_STYLE_LABEL(c,"coloredampli",0,"text","Amplitude Is Full Coloured Over");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"coloredampli",0,"0.5");
		CLASS_ATTR_FILTER_MIN(c, "coloredampli", 0);
		
		CLASS_ATTR_DOUBLE(c,"maxwaveampli",0, t_rhythmogram, max_displayed_amplitude_onset_wave);
		CLASS_ATTR_STYLE_LABEL(c,"maxwaveampli",0,"text","Maximum Displayed Amplitude For Onset Wave");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxwaveampli",0,"1.");
		CLASS_ATTR_FILTER_MIN(c, "maxwaveampli", 0);

		CLASS_ATTR_DOUBLE(c,"minampli",0, t_rhythmogram, min_displayed_amplitude);
		CLASS_ATTR_STYLE_LABEL(c,"minampli",0,"text","Amplitude Is White Under");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"minampli",0,"0.001");
		CLASS_ATTR_FILTER_MIN(c, "minampli", 0);

		CLASS_ATTR_DOUBLE(c,"maxamplirhythmoscope",0, t_rhythmogram, max_displayed_amplitude_rhythmoscope);
		CLASS_ATTR_STYLE_LABEL(c,"maxamplirhythmoscope",0,"text","Rhythmoscope Maximum Amplitude");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxamplirhythmoscope",0,"0.1");
		CLASS_ATTR_FILTER_MIN(c, "maxamplirhythmoscope", 0);
	
//		CLASS_ATTR_DOUBLE(c, "bpmpeakdecay", 0, t_rhythmogram, bpm_peak_decay); 
//		CLASS_ATTR_STYLE_LABEL(c,"bpmpeakdecay",0,"text","Peak Decay (bpm)");
//		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"bpmpeakdecay",0,"3");
//		CLASS_ATTR_FILTER_MIN(c, "bpmpeakdecay", 0);
/*	
		CLASS_ATTR_LONG(c,"numpoints",0, t_rhythmogram, num_sampling_vals);
		CLASS_ATTR_STYLE_LABEL(c,"numpoints",0,"text","Number Of Sampling Points");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"numpoints",0,"100");
		CLASS_ATTR_FILTER_CLIP(c, "numpoints", 2, CONST_MAX_SAMPLING_POINTS);
		CLASS_ATTR_ACCESSORS(c, "numpoints", (method)NULL, (method)rhythmogram_setattr_numpoints);
*/
		CLASS_ATTR_LONG(c,"numhistorywins",0, t_rhythmogram, fixed_num_windows_in_history);
		CLASS_ATTR_STYLE_LABEL(c,"numhistorywins",0,"text","Number Of Windows In History");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"numhistorywins",0,"100");
		CLASS_ATTR_FILTER_MIN(c, "numhistorywins", 0);
		CLASS_ATTR_ACCESSORS(c, "numhistorywins", (method)NULL, (method)rhythmogram_setattr_numhistorywins);
	
	
	CLASS_STICKY_ATTR_CLEAR(c, "category"); 

	s_rhythmogram_class = c;
	class_register(CLASS_BOX, s_rhythmogram_class);
	
	dev_post("bach.rhythmogram compiled %s %s", __DATE__, __TIME__);
	return 0;
}


void rhythmogram_set_numpoints(t_rhythmogram *x, long num_pts)
{
	x->num_sampling_vals = MAX(num_pts, 1);
	x->num_sampling_vals_between_minbpm_and_maxbpm = x->num_sampling_vals * (x->max_displayed_bpm/60. - x->min_displayed_bpm/60.)/x->sampling_frequency; 
	
	if (x->sampling_vals)
		bach_freeptr(x->sampling_vals);
	if (x->sampling_phase)
		bach_freeptr(x->sampling_phase);
	x->sampling_vals = (double *)bach_newptrclear(x->num_sampling_vals * sizeof(double));
	x->sampling_phase = (double *)bach_newptrclear(x->num_sampling_vals * sizeof(double));
}


t_max_err rhythmogram_setattr_numpoints(t_rhythmogram *x, t_object *attr, long ac, t_atom *av){
	if (ac) {
		rhythmogram_set_numpoints(x, atom_getlong(av));
		initialize_surface(x, x->num_sampling_vals_between_minbpm_and_maxbpm);
		jbox_redraw((t_jbox *) x);
	}
	return MAX_ERR_NONE;
}


t_max_err rhythmogram_setattr_numhistorywins(t_rhythmogram *x, t_object *attr, long ac, t_atom *av){
	if (ac) {
		x->fixed_num_windows_in_history = MAX(0, atom_getlong(av));
		if (x->realtime)
			x->num_windows_in_history = (x->fixed_num_windows_in_history == 0 ? MAX(x->width, 1) : x->fixed_num_windows_in_history);
		initialize_surface(x, x->num_sampling_vals_between_minbpm_and_maxbpm);
		jbox_redraw((t_jbox *) x);
	}
	return MAX_ERR_NONE;
}


t_max_err rhythmogram_setattr_mode(t_rhythmogram *x, t_object *attr, long ac, t_atom *av){
	if (ac) {
		x->mode = MAX(0, atom_getlong(av));
		if (x->recalled_attributes)
			rhythmogram_bang(x);
	}
	return MAX_ERR_NONE;
}

void rhythmogram_bang(t_rhythmogram *x)
{
	rhythmogram_anything(x, _sym_bang, 0, NULL);
}


void rhythmogram_assist(t_rhythmogram *x, void *b, long m, long a, char *s){
    if (m == ASSIST_INLET) {
		sprintf(s, "llll: Input");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_UI, a, &type);
		switch (a) {
			case 0:	sprintf(s, "llll (%s): Modelized Onset Wave", type);	break;
			case 1:	sprintf(s, "llll (%s): Spectral Data", type);	break;
			case 2:	sprintf(s, "llll (%s): Spectral Peaks", type);	break;
			case 3:	sprintf(s, "llll (%s): Autocorrelation Function", type);	break;
			case 4:	sprintf(s, "llll (%s): Autocorrelation Peaks", type);	break;
			case 5:	sprintf(s, "llll (%s): Peak Tracking", type);	break;
			case 6:	sprintf(s, "llll (%s): Detected Measureinfo", type);	break;
			case 7:	sprintf(s, "llll (%s): Doubleclicked Estimated Measureinfo Segment", type);	break;
			case 8:	sprintf(s, "llll (%s): Marker Messages for bach.roll", type);	break;
		}
	}
}

void rhythmogram_inletinfo(t_rhythmogram *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void rhythmogram_dump(t_rhythmogram *x, t_symbol *s, long argc, t_atom *argv){
	t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_RETAIN);
	if (!arguments || arguments->l_size == 0 || is_symbol_in_llll_first_level(arguments, gensym("tsdetection"))){
		llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 6, x->tsd_data);
	} 
	if (!arguments || arguments->l_size == 0 || is_symbol_in_llll_first_level(arguments, gensym("partialtracking"))){
		llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 5, x->ptrack_data);
	} 
	if (!arguments || arguments->l_size == 0 || is_symbol_in_llll_first_level(arguments, gensym("acpeaks"))){
		llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 4, x->acf_peaks_data);
	} 
	if (!arguments || arguments->l_size == 0 || is_symbol_in_llll_first_level(arguments, gensym("autocorrelation"))){
		llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 3, x->acf_data);
	} 
	if (!arguments || arguments->l_size == 0 || is_symbol_in_llll_first_level(arguments, gensym("peaks"))){
		llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 2, x->dft_peaks_data);
	} 
	if (!arguments || arguments->l_size == 0 || is_symbol_in_llll_first_level(arguments, gensym("spectraldata"))){
		llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 1, x->dft_data);
	} 
	if (!arguments || arguments->l_size == 0 || is_symbol_in_llll_first_level(arguments, gensym("onsetwave"))){
		llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 0, x->wave_data);
	}
}


void append_frame_dft_data(t_rhythmogram *x){
	systhread_mutex_lock(x->c_mutex);
//	if (x->mode == k_MODE_RHYTHMOSCOPE){
		long i;
		t_llll *this_data = llll_get();
		for (i = 0; i < x->num_sampling_vals; i++) {
			// building output llll: (bin bpm ampli phase)
			t_llll *thisv = llll_get();
			llll_appendlong(thisv, i, 0, WHITENULL_llll);
			llll_appenddouble(thisv, 60. * i * x->sampling_frequency/x->num_sampling_vals, 0, WHITENULL_llll); // bpm
			llll_appenddouble(thisv, x->sampling_vals[i], 0, WHITENULL_llll);
			llll_appenddouble(thisv, rad2deg(x->sampling_phase[i]), 0, WHITENULL_llll);
			llll_appendllll(this_data, thisv, 0, WHITENULL_llll);
		}
		llll_appendllll(x->dft_data, this_data, 0, WHITENULL_llll);
//	}
	systhread_mutex_unlock(x->c_mutex);
}


void append_frame_acf_data(t_rhythmogram *x){
	systhread_mutex_lock(x->c_mutex);
	long i;
	t_llll *this_data = llll_get();
	for (i = 0; i < x->num_sampling_vals; i++) {
		// building output llll: (bin bpm ampli phase)
		t_llll *thisv = llll_get();
		llll_appendlong(thisv, i, 0, WHITENULL_llll);
		llll_appenddouble(thisv, 60. * i * x->sampling_frequency/x->num_sampling_vals, 0, WHITENULL_llll); // bpm
		llll_appenddouble(thisv, x->sampling_vals[i], 0, WHITENULL_llll);
		llll_appendllll(this_data, thisv, 0, WHITENULL_llll);
	}
	llll_appendllll(x->acf_data, this_data, 0, WHITENULL_llll);
	systhread_mutex_unlock(x->c_mutex);
}

void update_max_amplitude(t_rhythmogram *x){
	long i;
	double maxampli = 0;
	for (i = 0; i < x->num_sampling_vals; i++)
		if (x->sampling_vals[i] > maxampli)
			maxampli = x->sampling_vals[i];
	x->max_amplitude = maxampli;
}

void update_frame(t_rhythmogram *x){
	long i;

	jgraphics_image_surface_scroll(x->surface, 1, 0, x->num_windows_in_history - 1, x->num_sampling_vals, -1, 0, NULL);
	x->scroll_count++;

	if (x->algorithm == 0) {
		for (i = 0; i < x->num_sampling_vals; i++) {
			if (x->phase == 0) //ampli
				jgraphics_image_surface_set_pixel(x->surface, x->num_windows_in_history - 1, x->num_sampling_vals - i, 
												  change_alpha(x->j_color, CLAMP(x->sampling_vals[i]/(x->auto_display_amplitude ? x->max_amplitude : x->max_displayed_amplitude), 0., 1.)));
			else if (x->phase == 1) //phase
				jgraphics_image_surface_set_pixel(x->surface, x->num_windows_in_history - 1, x->num_sampling_vals - i, 
												  change_alpha(x->j_color, CLAMP(x->sampling_phase[i]/TWOPI, 0., 1.)));
			else // both (coloured)
				jgraphics_image_surface_set_pixel(x->surface, x->num_windows_in_history - 1, x->num_sampling_vals - i, 
												  change_alpha(double_to_color(x->sampling_phase[i], 0., TWOPI, false), CLAMP(x->sampling_vals[i]/(x->auto_display_amplitude ? x->max_amplitude : x->max_displayed_amplitude), 0., 1.)));
		}
	} else {
		long start = floor(x->num_sampling_vals * (x->min_displayed_bpm/60.)/x->sampling_frequency);
		for (i = 0; i < x->num_sampling_vals_between_minbpm_and_maxbpm; i++){
			long c = start + i;
			if (x->phase == 0) //ampli
				jgraphics_image_surface_set_pixel(x->surface, x->num_windows_in_history - 1, x->num_sampling_vals_between_minbpm_and_maxbpm - i, 
												  change_alpha(x->j_color, CLAMP(x->sampling_vals[c]/(x->auto_display_amplitude ? x->max_amplitude : x->max_displayed_amplitude), 0., 1.)));
			else if (x->phase == 1) //phase
				jgraphics_image_surface_set_pixel(x->surface, x->num_windows_in_history - 1, x->num_sampling_vals_between_minbpm_and_maxbpm - i, 
												  change_alpha(x->j_color, CLAMP(x->sampling_phase[c]/TWOPI, 0., 1.)));
			else // both (coloured)
				jgraphics_image_surface_set_pixel(x->surface, x->num_windows_in_history - 1, x->num_sampling_vals_between_minbpm_and_maxbpm - i, 
												  change_alpha(double_to_color(x->sampling_phase[c], 0., TWOPI, false), CLAMP(x->sampling_vals[c]/(x->auto_display_amplitude ? x->max_amplitude : x->max_displayed_amplitude), 0., 1.)));
		}
	}
	
//	for (i = 1; i < 20; i++)
//		jgraphics_image_surface_set_pixel(x->surface, x->num_windows_in_history - 1, i, long_to_color(x->scroll_count));
}


void build_surface_do(t_rhythmogram *x, t_symbol *s, long argc, t_atom *argv){
	long i;	
	double denominator = x->max_displayed_amplitude;
	t_llllelem *frame, *bin;
	t_llll *ll = (x->mode == k_MODE_AUTOCORRELATION || x->mode == k_MODE_AUTOCORRELOGRAM) ? x->acf_data : x->dft_data;

	if (x->auto_display_amplitude) {
		// find max amplitude
		double maxamp = 0.;
		for (frame = ll->l_head; frame; frame = frame->l_next) {
			t_llll *fr = hatom_getllll(&frame->l_hatom);
			if (fr) {
				for (bin = fr->l_head; bin; bin = bin->l_next) {
					t_llll *binll = hatom_getllll(&bin->l_hatom);
					if (binll && binll->l_head && binll->l_head->l_next && binll->l_head->l_next->l_next) {
						double this_amp = hatom_getdouble(&binll->l_head->l_next->l_next->l_hatom);
						if (this_amp > maxamp)
							maxamp = this_amp;
					}
				}
			}
		}
		denominator = maxamp > 0 ? maxamp : 1.;
	}
	
	for (frame = ll->l_head; frame; frame = frame->l_next) {
		t_llll *fr = hatom_getllll(&frame->l_hatom);
		double num_bins = fr->l_size;
	
		jgraphics_image_surface_scroll(x->surface, 1, 0, x->num_windows_in_history - 1, x->num_sampling_vals, -1, 0, NULL);
		
		double mult = (x->mode == k_MODE_RHYTHMOGRAM || x->mode == k_MODE_AUTOCORRELOGRAM) ? 1 : 0.4;
		long start = floor(num_bins * (x->min_displayed_bpm/60.)/x->sampling_frequency);
		bin = llll_getindex(fr, start + 1, I_STANDARD);
		for (i = 0; bin && i < x->num_sampling_vals_between_minbpm_and_maxbpm; bin = bin->l_next, i++) {
			t_llll *binll = hatom_getllll(&bin->l_hatom);
			//				long c = start + i;
			//				double i = hatom_getlong(&binll->l_head->l_hatom);
			double ampli = hatom_getdouble(&binll->l_head->l_next->l_next->l_hatom);
			double phase = x->mode == k_MODE_AUTOCORRELOGRAM ? 0 : hatom_getdouble(&binll->l_head->l_next->l_next->l_next->l_hatom);
			
			if (x->phase == 0) //ampli
				jgraphics_image_surface_set_pixel(x->surface, x->num_windows_in_history - 1, x->num_sampling_vals_between_minbpm_and_maxbpm - i, 
												  change_alpha(x->j_color, mult * CLAMP(ampli/denominator, 0., 1.)));
			else if (x->phase == 1) //phase
				jgraphics_image_surface_set_pixel(x->surface, x->num_windows_in_history - 1, x->num_sampling_vals_between_minbpm_and_maxbpm - i, 
												  change_alpha(x->j_color, mult * CLAMP(phase/TWOPI, 0., 1.)));
			else // both (coloured)
				jgraphics_image_surface_set_pixel(x->surface, x->num_windows_in_history - 1, x->num_sampling_vals_between_minbpm_and_maxbpm - i, 
												  change_alpha(double_to_color(phase, 0., TWOPI, false), mult * CLAMP(ampli/denominator, 0., 1.)));
		}
	}
	jbox_redraw((t_jbox *)x);
}

void build_surface(t_rhythmogram *x){
	build_surface_do(x, NULL, 0, NULL);
	if (x->first_surface_draw) { // I really don't know why we have to put this, but the first time the surface is NEVER drawn.
								 // NB: the problem might/should even be ELSEWHERE, before the call to build_surface(), yet I really don't see where
		x->first_surface_draw = false;
		rhythmogram_bang(x);
	}
}




void rhythmogram_acpeaks(t_rhythmogram *x, t_symbol *s, long argc, t_atom *argv){
	x->acf_peaks_data = get_peaks(x->acf_data, true, true, x->numpeaks, x->minpeakamp, x->minpeakrelamp, x->sampling_frequency, x->num_sampling_vals);
	t_atom av;
	atom_setsym(&av, gensym("acpeaks"));
	rhythmogram_dump(x, NULL, 1, &av);
}

void rhythmogram_peaks(t_rhythmogram *x, t_symbol *s, long argc, t_atom *argv){
	x->dft_peaks_data = get_peaks(x->dft_data, false, true, x->numpeaks, x->minpeakamp, x->minpeakrelamp, x->sampling_frequency, x->num_sampling_vals);
	t_atom av;
	atom_setsym(&av, gensym("peaks"));
	rhythmogram_dump(x, NULL, 1, &av);
}


void build_wave_data(t_rhythmogram *x, long num_vals, double *vals){
	long i;
	llll_clear(x->wave_data);
	for (i = 0; i < num_vals; i++) 
		llll_appenddouble(x->wave_data, vals[i], 0, WHITENULL_llll);
}

void ratios_to_ts(t_rhythmogram *x, t_tsd_config *cfg)
{
	if (cfg->ratios.subdiv < 0)
		cfg->ratios.subdiv = 2;
		
	if (cfg->ratios.subdiv == 2) {
		cfg->ts.num_numerator_elements = 1;
		cfg->ts.denominator = x->denominator_for_binary_ts;
		cfg->ts.numerator = cfg->ts.numerator_elements[0] = (cfg->ratios.div < 0 ? 4 : cfg->ratios.div) ;
		cfg->tempo_figure = genrat(1, x->denominator_for_binary_ts);
	} else if (cfg->ratios.subdiv == 3) {
		cfg->ts.num_numerator_elements = 1;
		cfg->ts.denominator = x->denominator_for_ternary_ts;
		cfg->ts.numerator = cfg->ts.numerator_elements[0] = (cfg->ratios.div < 0 ? 4 : cfg->ratios.div) * 3;
		cfg->tempo_figure = genrat(3, x->denominator_for_ternary_ts);
	} else {
		long i;
		cfg->ts.num_numerator_elements = (cfg->ratios.div < 0 ? 1 : cfg->ratios.div);
		cfg->ts.numerator = 0;
		for (i = 0; i < cfg->ts.num_numerator_elements; i++) {
			cfg->ts.numerator_elements[i] = cfg->ratios.subdiv;
			cfg->ts.numerator += cfg->ts.numerator_elements[i];
		}
		cfg->ts.denominator = x->denominator_for_nonstandard_ts;
		cfg->tempo_figure = genrat(cfg->ratios.subdiv, x->denominator_for_nonstandard_ts);
	}
}

// use -1 as jolly for division or subdivision ratio
// also fills  ist_div_phases and ist_subdiv_phases if given
t_tsd_config *params_to_tsd_config(t_rhythmogram *x, double weight, long num_divs, long num_subdivs, double measure_phase, 
											double tempo_div, long voice1, long voice2, long voice3, 
											double *ist_meas_phases, double *ist_div_phases, double *ist_subdiv_phases, long num_ist_phases, t_tsd_adaptation *adapt){

	long i;
	t_tsd_config *tsc = (t_tsd_config *)bach_newptr(sizeof(t_tsd_config));
	tsc->weight = weight;
	tsc->voice_nums[0] = voice1;
	tsc->voice_nums[1] = voice2;
	tsc->voice_nums[2] = voice3;
	tsc->tempo_div = tempo_div;
	
	tsc->force_barline_rot = tsc->force_div_rot = tsc->force_add_div = 0;
	
	tsc->ratios.div = num_divs;
	tsc->ratios.subdiv = num_subdivs;

	tsc->phase.phase_measure = measure_phase;
	tsc->phase.phase_div = fmod(measure_phase, 1./num_divs);
	tsc->phase.phase_subdiv = fmod(measure_phase, 1./(num_divs * num_subdivs));
	
	tsc->ist_meas_phases = tsc->ist_div_phases = tsc->ist_subdiv_phases = NULL;
	tsc->onsets_ms = tsc->detected_onsets_ms = NULL;
	tsc->detected_onsets_std_dev_ms = tsc->detected_onsets_std_dev_rel = 0;
	
	if (ist_meas_phases && ist_div_phases && ist_subdiv_phases) {
		for (i = 0; i < num_ist_phases; i++) {
			ist_div_phases[i] = fmod(ist_meas_phases[i], 1./num_divs);
			ist_subdiv_phases[i] = fmod(ist_meas_phases[i], 1./(num_divs * num_subdivs));
		}
	}
	
	adapt->type = k_TSD_ADAPT_TYPE_NONE;
	adapt->old_new_div_ratio = adapt->old_new_subdiv_ratio = long2rat(1);

	// checking goodness with respect to tempo range
	if (tsc->tempo_div < x->min_tempo && tsc->tempo_div * num_subdivs <= x->max_tempo) {
		// tempo is too slow. Subdivisions become divisions
		tsc->tempo_div *= num_subdivs;
		tsc->ratios.div = num_subdivs;
		tsc->ratios.subdiv = -1; // any
		
		adapt->type = (e_tsd_adapt_type) (adapt->type | k_TSD_ADAPT_TYPE_SUBDIV_TO_DIV);
		
		tsc->phase.phase_measure = tsc->phase.phase_div;
		tsc->phase.phase_div = tsc->phase.phase_subdiv;
		tsc->phase.phase_subdiv = -1;
		if (ist_meas_phases && ist_div_phases && ist_subdiv_phases) {
			for (i = 0; i < num_ist_phases; i++) {
				ist_meas_phases[i] = ist_div_phases[i];
				ist_div_phases[i] = ist_subdiv_phases[i];
				ist_subdiv_phases[i] = -1;
			}
		}
	}
	
	if (tsc->tempo_div > x->max_tempo && tsc->tempo_div / num_divs >= x->min_tempo) {
		// tempo is too fast. Divisions become subdivisions
		tsc->tempo_div /= num_divs;
		tsc->ratios.subdiv = tsc->ratios.div;
		tsc->ratios.div = -1;
		
		adapt->type = (e_tsd_adapt_type) (adapt->type | k_TSD_ADAPT_TYPE_DIV_TO_SUBDIV);
		
		tsc->phase.phase_subdiv = tsc->phase.phase_div;
		tsc->phase.phase_div = tsc->phase.phase_measure;
		tsc->phase.phase_measure = -1;
		if (ist_meas_phases && ist_div_phases && ist_subdiv_phases) {
			for (i = 0; i < num_ist_phases; i++) {
				ist_subdiv_phases[i] = ist_div_phases[i];
				ist_div_phases[i] = ist_meas_phases[i];
				ist_meas_phases[i] = -1;
			}
		}
	}
	
/*	if (tsc->tempo_div < x->min_tempo || tsc->tempo_div > x->max_tempo) {
		bach_freeptr(tsc);
		return NULL; // unacceptable solution
	}*/ //WE DO THIS LATER!
	
	// checking standardness
	if (x->only_standard_subdivisions) {
		if (tsc->ratios.subdiv != 2 && tsc->ratios.subdiv != 3) {
			if (tsc->ratios.subdiv % 3 == 0) {
				adapt->old_new_subdiv_ratio = genrat(tsc->ratios.subdiv, 3);
				tsc->ratios.subdiv = 3;
				tsc->phase.phase_subdiv = fmod(measure_phase, 1./(tsc->ratios.div * tsc->ratios.subdiv));
				if (ist_meas_phases && ist_div_phases && ist_subdiv_phases) 
					for (i = 0; i < num_ist_phases; i++) 
						ist_subdiv_phases[i] = fmod(ist_meas_phases[i], 1./(tsc->ratios.div * tsc->ratios.subdiv));
			} else { 
				adapt->old_new_subdiv_ratio = genrat(tsc->ratios.subdiv, 2);
				tsc->ratios.subdiv = 2;
				tsc->phase.phase_subdiv = fmod(measure_phase, 1./(tsc->ratios.div * tsc->ratios.subdiv));
				if (ist_meas_phases && ist_div_phases && ist_subdiv_phases) 
					for (i = 0; i < num_ist_phases; i++) 
						ist_subdiv_phases[i] = fmod(ist_meas_phases[i], 1./(tsc->ratios.div * tsc->ratios.subdiv));
			}
		}
	}
	
	if (tsc->ratios.div > x->max_divisions) {
		long old_div = tsc->ratios.div;
		if (x->max_divisions >= 4 && tsc->ratios.div % 4 == 0 && (tsc->tempo_div <= x->max_tempo || (tsc->tempo_div / 4. <= x->max_tempo && tsc->tempo_div / 4. >= x->min_tempo))) {
			// notice that the tempo checking is due to the fact that if is the tempo is high (suppose 160) and the current number of divisions is, say, 8,
			// IF the tempo divided by 4 will be in the tempo range, then we decide to use 4-division measures (e.g. 4/4), so that later we will turn those measures into division
			// and we'll reduce the tempo by a factor of 1/4. Otherwise, we better 
			// use now 2-division, which we handle in the third case of this "if" clause, 
			// (so that 2/4 measures might eventually become divisions, with a tempo inside the allowed tempo range).
			adapt->old_new_div_ratio = genrat(tsc->ratios.div, 4);
			tsc->ratios.div = 4;
			tsc->phase.phase_measure = fmod(tsc->phase.phase_measure, 4./old_div);
			tsc->phase.phase_div = fmod(measure_phase, 1./tsc->ratios.div);
			tsc->phase.phase_subdiv = fmod(measure_phase, 1./(tsc->ratios.div * tsc->ratios.subdiv));
			if (ist_meas_phases && ist_div_phases && ist_subdiv_phases) {
				for (i = 0; i < num_ist_phases; i++) {
					ist_meas_phases[i] = fmod(ist_meas_phases[i], 4./old_div);
					ist_div_phases[i] = fmod(ist_meas_phases[i], 1./tsc->ratios.div);
					ist_subdiv_phases[i] = fmod(ist_meas_phases[i], 1./(tsc->ratios.div * tsc->ratios.subdiv));
				}
			}
		} else if (x->max_divisions >= 3 && tsc->ratios.div % 3 == 0) {
			adapt->old_new_div_ratio = genrat(tsc->ratios.div, 3);
			tsc->ratios.div = 3;
			tsc->phase.phase_measure = fmod(tsc->phase.phase_measure, 3./old_div);
			tsc->phase.phase_div = fmod(measure_phase, 1./tsc->ratios.div);
			tsc->phase.phase_subdiv = fmod(measure_phase, 1./(tsc->ratios.div * tsc->ratios.subdiv));
			if (ist_meas_phases && ist_div_phases && ist_subdiv_phases) {
				for (i = 0; i < num_ist_phases; i++) {
					ist_meas_phases[i] = fmod(ist_meas_phases[i], 3./old_div);
					ist_div_phases[i] = fmod(ist_meas_phases[i], 1./tsc->ratios.div);
					ist_subdiv_phases[i] = fmod(ist_meas_phases[i], 1./(tsc->ratios.div * tsc->ratios.subdiv));
				}
			}
		} else if (tsc->ratios.div % 2 == 0 || x->max_divisions < 4) {
			adapt->old_new_div_ratio = genrat(tsc->ratios.div, 2);
			tsc->ratios.div = 2;
			tsc->phase.phase_measure = fmod(tsc->phase.phase_measure, 2./old_div);
			tsc->phase.phase_div = fmod(measure_phase, 1./tsc->ratios.div);
			tsc->phase.phase_subdiv = fmod(measure_phase, 1./(tsc->ratios.div * tsc->ratios.subdiv));
			if (ist_meas_phases && ist_div_phases && ist_subdiv_phases) {
				for (i = 0; i < num_ist_phases; i++) {
					ist_meas_phases[i] = fmod(ist_meas_phases[i], 2./old_div);
					ist_div_phases[i] = fmod(ist_meas_phases[i], 1./tsc->ratios.div);
					ist_subdiv_phases[i] = fmod(ist_meas_phases[i], 1./(tsc->ratios.div * tsc->ratios.subdiv));
				}
			}
		} else {
			adapt->old_new_div_ratio = genrat(tsc->ratios.div, 4);
			tsc->ratios.div = 4;
			tsc->phase.phase_measure = fmod(tsc->phase.phase_measure, 4./old_div);
			tsc->phase.phase_div = fmod(measure_phase, 1./tsc->ratios.div);
			tsc->phase.phase_subdiv = fmod(measure_phase, 1./(tsc->ratios.div * tsc->ratios.subdiv));
			if (ist_meas_phases && ist_div_phases && ist_subdiv_phases) {
				for (i = 0; i < num_ist_phases; i++) {
					ist_meas_phases[i] = fmod(ist_meas_phases[i], 4./old_div);
					ist_div_phases[i] = fmod(ist_meas_phases[i], 1./tsc->ratios.div);
					ist_subdiv_phases[i] = fmod(ist_meas_phases[i], 1./(tsc->ratios.div * tsc->ratios.subdiv));
				}
			}
		}
	}
	
	
	
	// checking goodness AGAIN
	if (tsc->tempo_div < x->min_tempo || tsc->tempo_div > x->max_tempo) {
		num_divs = tsc->ratios.div;
		num_subdivs = tsc->ratios.subdiv;
		
		if (tsc->tempo_div < x->min_tempo && tsc->tempo_div * num_subdivs <= x->max_tempo) {
			// tempo is too slow. Subdivisions become divisions
			tsc->tempo_div *= num_subdivs;
			tsc->ratios.div = num_subdivs;
			tsc->ratios.subdiv = -1; // any
			
			adapt->type = (e_tsd_adapt_type) (adapt->type | k_TSD_ADAPT_TYPE_SUBDIV_TO_DIV);
			
			tsc->phase.phase_measure = tsc->phase.phase_div;
			tsc->phase.phase_div = tsc->phase.phase_subdiv;
			tsc->phase.phase_subdiv = -1;
			if (ist_meas_phases && ist_div_phases && ist_subdiv_phases) {
				for (i = 0; i < num_ist_phases; i++) {
					ist_meas_phases[i] = ist_div_phases[i];
					ist_div_phases[i] = ist_subdiv_phases[i];
					ist_subdiv_phases[i] = -1;
				}
			}
		}
		
		if (tsc->tempo_div > x->max_tempo && tsc->tempo_div / num_divs >= x->min_tempo) {
			// tempo is too fast. Divisions become subdivisions
			tsc->tempo_div /= num_divs;
			tsc->ratios.subdiv = tsc->ratios.div;
			tsc->ratios.div = -1;
			
			adapt->type = (e_tsd_adapt_type) (adapt->type | k_TSD_ADAPT_TYPE_DIV_TO_SUBDIV);
			
			tsc->phase.phase_subdiv = tsc->phase.phase_div;
			tsc->phase.phase_div = tsc->phase.phase_measure;
			tsc->phase.phase_measure = -1;
			if (ist_meas_phases && ist_div_phases && ist_subdiv_phases) {
				for (i = 0; i < num_ist_phases; i++) {
					ist_subdiv_phases[i] = ist_div_phases[i];
					ist_div_phases[i] = ist_meas_phases[i];
					ist_meas_phases[i] = -1;
				}
			}
		}

		// checking standardness again
		if (x->only_standard_subdivisions) {
			if (tsc->ratios.subdiv != 2 && tsc->ratios.subdiv != 3) {
				if (tsc->ratios.subdiv % 3 == 0) {
					adapt->old_new_subdiv_ratio = genrat(tsc->ratios.subdiv, 3);
					tsc->ratios.subdiv = 3;
					tsc->phase.phase_subdiv = fmod(measure_phase, 1./(tsc->ratios.div * tsc->ratios.subdiv));
					if (ist_meas_phases && ist_div_phases && ist_subdiv_phases) 
						for (i = 0; i < num_ist_phases; i++) 
							ist_subdiv_phases[i] = fmod(ist_meas_phases[i], 1./(tsc->ratios.div * tsc->ratios.subdiv));
				} else { 
					adapt->old_new_subdiv_ratio = genrat(tsc->ratios.subdiv, 2);
					tsc->ratios.subdiv = 2;
					tsc->phase.phase_subdiv = fmod(measure_phase, 1./(tsc->ratios.div * tsc->ratios.subdiv));
					if (ist_meas_phases && ist_div_phases && ist_subdiv_phases) 
						for (i = 0; i < num_ist_phases; i++) 
							ist_subdiv_phases[i] = fmod(ist_meas_phases[i], 1./(tsc->ratios.div * tsc->ratios.subdiv));
				}
			}
		}		

		if (tsc->tempo_div < x->min_tempo || tsc->tempo_div > x->max_tempo) {
			bach_freeptr(tsc);
			return NULL; // unacceptable solution, we did what we can to modify it.
		}
	}
	
	
	tsc->detected_ratios.div = tsc->ratios.div;
	tsc->detected_ratios.subdiv = tsc->ratios.subdiv;

	tsc->adapt = *adapt;
	
	ratios_to_ts(x, tsc);

	return tsc;
}


// private function, only for a very special case
void rewrap_to_next_llll(t_llll *ll, t_llllelem *elem)
{
	if (elem && elem->l_parent && elem->l_parent->l_owner) {
		long d = llllelem_get_depth(elem);
//		char *buf = NULL, *buf2 = NULL, *buf3 = NULL;
//		llll_to_text_buf(ll, &buf, 0, 1, 0, NULL); // buf + 250   buf2 + 250  buf3 + 250
		t_llllelem *next_llll = elem->l_parent->l_owner->l_next;
		t_llllelem *ab = llllelem_create_abyss(elem->l_prev, d - 2);
//		llll_to_text_buf(ll, &buf2, 0, 1, 0, NULL);
		if (ab && next_llll && next_llll->l_prev) {
			llll_wrap_element_range(next_llll->l_prev, next_llll);
			llll_flat(ll, 2, 0, 0, LLLL_FREETHING_DONT);
//			llll_to_text_buf(ll, &buf3, 0, 1, 0, NULL);
//			d++; // dummy, just for debug
		}
	}
}


// private function, only for a very special case
void rewrap_to_prev_llll(t_llll *ll, t_llllelem *elem)
{
	if (elem && elem->l_parent && elem->l_parent->l_owner) {
		long d = llllelem_get_depth(elem);
//		char *buf = NULL, *buf2 = NULL, *buf3 = NULL;
//		llll_to_text_buf(ll, &buf, 0, 1, 0, NULL); // buf + 250   buf2 + 250  buf3 + 250
		t_llllelem *prev_llll = elem->l_parent->l_owner->l_prev;
		t_llllelem *ab = llllelem_create_abyss(elem, d - 2);
//		llll_to_text_buf(ll, &buf2, 0, 1, 0, NULL);
		if (ab && prev_llll && prev_llll->l_prev) {
			llll_wrap_element_range(prev_llll, prev_llll->l_next);
			llll_flat(ll, 2, 0, 0, LLLL_FREETHING_DONT);
//			llll_to_text_buf(ll, &buf3, 0, 1, 0, NULL);
//			d++; // dummy, just for debug
		}
	}
}



void free_tsd_config(t_rhythmogram *x, t_tsd_config *config) 
{
	if (config == x->selected_config)
		x->selected_config = NULL;

	if (config == x->curr_mouseover_tsd_segment)
		x->curr_mouseover_tsd_segment = NULL;
		
	if (config->onsets_ms)
		llll_free(config->onsets_ms);
	if (config->detected_onsets_ms)
		llll_free(config->detected_onsets_ms);
	if (config->ist_meas_phases)
		bach_freeptr(config->ist_meas_phases);
	if (config->ist_div_phases)
		bach_freeptr(config->ist_div_phases);
	if (config->ist_subdiv_phases)
		bach_freeptr(config->ist_subdiv_phases);
	bach_freeptr(config);
}

void free_segment_configs(t_rhythmogram *x) 
{
	t_tsd_config *next, *temp = x->first_segment_config;
	while (temp) {
		next = temp->next;
		free_tsd_config(x, temp);
		temp = next;
	}
	x->first_segment_config = x->last_segment_config = NULL;
	x->num_segment_tsd_configs = 0;
}


//returns: 0 = NO, 1 = PARTIALLY, 2 = COMPLETELY
char are_configs_compatible(t_rhythmogram *x, t_tsd_config *config1, t_tsd_config *config2) 
{
	if (config1->ratios.subdiv != config2->ratios.subdiv)
		return 0;

	return 0;
	// TO DO
}



void renumber_configs(t_rhythmogram *x, long base_idx){
	t_tsd_config *cfg;
	long i;
	for (i = base_idx, cfg = x->first_segment_config; cfg; cfg = cfg->next, i++)
		cfg->ID = i;
}

char sort_segment_configs_by_weight(t_rhythmogram *x){
	char changed = false;
	t_tsd_config *curr_nt = x->first_segment_config;
	while(curr_nt && (curr_nt->next)) {
		if (curr_nt->next->weight > curr_nt->weight){ // we have to swap them
			if (curr_nt->prev){
				if (curr_nt->next->next) { // swap between two inner configs
					t_tsd_config *temp1, *temp2, *temp3, *temp4;
					temp1 = curr_nt->prev; temp2=curr_nt; temp3=curr_nt->next; temp4=curr_nt->next->next;
					curr_nt->next->next->prev = temp2;
					curr_nt->prev->next = temp3;
					curr_nt->next->next = temp2;
					curr_nt->next->prev = temp1;
					curr_nt->next = temp4;
					curr_nt->prev = temp3;
					
					
					changed = true;
				} else { // swap between the last two notes
					t_tsd_config *temp1, *temp2, *temp3, *temp4;
					temp1 = curr_nt->prev; temp2=curr_nt; temp3=curr_nt->next; temp4=NULL;
					curr_nt->prev->next = temp3;
					curr_nt->next->next = temp2;
					curr_nt->next->prev = temp1;
					curr_nt->next = NULL;
					curr_nt->prev = temp3;
					x->last_segment_config = temp2;
					changed = true;
				}
			} else { // swap between 1st and 2nd config
				t_tsd_config *temp1, *temp2, *temp3, *temp4;
				temp1 = NULL; temp2=curr_nt; temp3=curr_nt->next; temp4=curr_nt->next->next;
				if (!temp4) // we have just 2 configs:
					x->last_segment_config = temp2;
				else
					curr_nt->next->next->prev = temp2;
				curr_nt->next->next = temp2;
				curr_nt->next->prev = NULL;
				curr_nt->next = temp4;
				curr_nt->prev = temp3;
				x->first_segment_config = temp3;
				changed = true;
			}
			//... and to restart to check from the beginning
			curr_nt = x->first_segment_config;
		} else 
			curr_nt = curr_nt->next;
	}
	
	return changed;
}



void retrieve_measure_and_division_onsets_for_segment(t_rhythmogram *x, t_tsd_config *config)
{
	t_llll *onsets = llll_get();
	t_llll *t_errors = llll_get();
	long i;
	for (i = config->detected_start_fr; i <= config->detected_end_fr; i++) {
		double frame_onset = (i - 1) * x->winsize/x->oversampling;
		double frame_dur_ms = x->winsize/x->oversampling;
		const double thresh = 0.05;
		long j = i - config->detected_start_fr;
		
		
		if (config->ist_div_phases[j] >= 0.) {
			double div_period_ms = (60./config->tempo_div) * config->ratios.div * 1000./config->ratios.div;
			t_llll *prevs = llll_get();
			t_llll *t_error_prevs = llll_get();
			double prev_onset = frame_onset - config->ist_div_phases[j] * div_period_ms;
			
			while (prev_onset >= frame_onset - frame_dur_ms*(0.5 + thresh)){
				llll_appenddouble(prevs, prev_onset, 0, WHITENULL_llll);
				llll_appenddouble(t_error_prevs, fabs(prev_onset - frame_onset), 0, WHITENULL_llll);
				prev_onset -= div_period_ms;
			}
			llll_rev(prevs, 0, 0);
			llll_rev(t_error_prevs, 0, 0);
			
			// checking superpositions
			if (prevs->l_head && onsets->l_tail && t_error_prevs->l_head && t_errors->l_tail) {
				double first_prevs = hatom_getdouble(&prevs->l_head->l_hatom);
				double last_onsets = hatom_getdouble(&onsets->l_tail->l_hatom);
				double first_prevs_t_error = hatom_getdouble(&t_error_prevs->l_head->l_hatom);
				double last_onsets_t_error = hatom_getdouble(&t_errors->l_tail->l_hatom);
				if (fabs(first_prevs - last_onsets) < 2 * thresh * frame_dur_ms) {
//					double new_onset = (first_prevs + last_onsets)/2.;
					llll_behead(prevs);
					llll_behead(t_error_prevs);
					hatom_setdouble(&onsets->l_tail->l_hatom, (first_prevs * last_onsets_t_error + 
						last_onsets * first_prevs_t_error)/(last_onsets_t_error + first_prevs_t_error));
					hatom_setdouble(&t_errors->l_tail->l_hatom, (first_prevs_t_error * last_onsets_t_error + 
						last_onsets_t_error * first_prevs_t_error)/(last_onsets_t_error + first_prevs_t_error));
				}
			}
			llll_chain(onsets, prevs);
			llll_chain(t_errors, t_error_prevs);
			
			double next_onset = frame_onset + (1 - config->ist_div_phases[j]) * div_period_ms;
			while (next_onset <= frame_onset + frame_dur_ms * (0.5 + thresh)){
				llll_appenddouble(onsets, next_onset, 0, WHITENULL_llll);
				llll_appenddouble(t_errors, fabs(next_onset - frame_onset), 0, WHITENULL_llll);
				next_onset += div_period_ms;
			}
		}
	}

	if (config->detected_onsets_ms)
		llll_free(config->detected_onsets_ms);
	config->detected_onsets_ms = onsets;
	llll_free(t_errors);
}


void correct_deltas_for_measure_and_division_onsets_for_segment(t_rhythmogram *x, t_tsd_config *config, double threshold_for_periods, long min_num_measures_for_segments_to_be_kept)
{
	double div_period_ms = (60./config->tempo_div) * config->ratios.div * 1000./config->ratios.div;
	t_llllelem *elem;
	double start_ms = config->detected_onsets_ms && config->detected_onsets_ms->l_head ? hatom_getdouble(&config->detected_onsets_ms->l_head->l_hatom) : 0;
	t_llll *diffs = llll_x2dx_of_plain_double_llll(config->detected_onsets_ms);
	
	// retrieve "good" segments
	t_llllelem *start = NULL, *end = NULL;
	
	dev_llll_print(diffs, NULL, 0, 0, NULL);
	
	for (elem = diffs->l_head; elem; elem = elem->l_next) {
		double this_diff = hatom_getdouble(&elem->l_hatom);
		if (this_diff < div_period_ms * threshold_for_periods && this_diff > div_period_ms / threshold_for_periods) {
			if (!start)
				start = elem;
		} else {
			if (start && elem->l_prev) 
				llll_wrap_element_range(start, elem->l_prev);
			start = NULL;
		}
	}
	if (start && diffs->l_tail)
		llll_wrap_element_range(start, diffs->l_tail);
	
	dev_llll_print(diffs, NULL, 0, 0, NULL);
	
	// discard little segments
	elem = diffs->l_head;
	while (elem) {
		t_llllelem *nextelem = elem->l_next;
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *ll = hatom_getllll(&elem->l_hatom);
			//				double size = llll_sum_of_doubles_llll(ll);
			if (ll->l_size < config->ratios.div * min_num_measures_for_segments_to_be_kept) 
				llll_splatter(elem, LLLL_FREETHING_DONT);
		}
		elem = nextelem;
	}
	
	dev_llll_print(diffs, NULL, 0, 0, NULL);
	
	// correcting outliners
	elem = diffs->l_head;
	while (elem) {
		t_llllelem *nextelem = elem->l_next;
		if (hatom_gettype(&elem->l_hatom) != H_LLLL) {
			double tot = hatom_getdouble(&elem->l_hatom);
			long round_times;
			start = elem;
			while (elem && elem->l_next && hatom_gettype(&elem->l_next->l_hatom) != H_LLLL) {
				tot += hatom_getdouble(&elem->l_next->l_hatom);	
				elem = elem->l_next;
			}
			end = elem;
			nextelem = end->l_next;
			round_times = round(tot/div_period_ms);
			if (round_times == 0) 
				hatom_setdouble(&start->l_prev->l_hatom.h_w.w_llll->l_tail->l_hatom, hatom_getdouble(&start->l_prev->l_hatom.h_w.w_llll->l_tail->l_hatom) + tot);
			else {
				t_llll *to_delete;
				long i;
				for (i = 0; i < round_times; i++)
					llll_insertdouble_before(tot/round_times, start, 0, WHITENULL_llll);
				to_delete = llll_wrap_element_range(start, end);
				llll_destroyelem(to_delete->l_owner);
				dev_llll_print(diffs, NULL, 0, 0, NULL);
			}
		}
		elem = nextelem;
	}
	
	llll_flatten(diffs, 0, 0);
	
	dev_llll_print(diffs, NULL, 0, 0, NULL);
	
	llll_free(config->detected_onsets_ms);
	config->detected_onsets_ms = llll_dx2x_of_plain_double_llll(diffs, start_ms);
	llll_free(diffs);
}



void correct_deltas_for_measure_and_division_onsets_for_segment_old(t_rhythmogram *x, t_tsd_config *config, double threshold_for_max_relative_length, double threshold_for_correct_rephasing)
{
	long num_frames = config->end_fr - config->start_fr + 1;
	double div_period_ms = (60./config->tempo_div) * config->ratios.div * 1000./config->ratios.div;
	t_llllelem *elem, *elem2;
	double start = config->detected_onsets_ms && config->detected_onsets_ms->l_head ? hatom_getdouble(&config->detected_onsets_ms->l_head->l_hatom) : 0;
	t_llll *diffs = llll_x2dx_of_plain_double_llll(config->detected_onsets_ms);
	
	for (elem = diffs->l_head; elem; elem = elem->l_next) {
		double this_diff = hatom_getdouble(&elem->l_hatom);
		if (this_diff < div_period_ms * 0.75 || this_diff > div_period_ms * 1.25) {
			double partial_sum = this_diff;
			long n = 1;
			for (elem2 = elem->l_next; elem2; elem2 = elem2->l_next, n++){
				partial_sum += hatom_getdouble(&elem2->l_hatom);
				if (n > num_frames * threshold_for_max_relative_length) {
					elem = elem2;
					break; // we break, it's been a too long difficult section
				}
				if (fabs(partial_sum/div_period_ms - round(partial_sum/div_period_ms)) < threshold_for_correct_rephasing) {
					long this_num_divs = round(partial_sum/div_period_ms);
					long j = 0;
					double equal_subdiv = partial_sum/this_num_divs;
					t_llllelem *temp1 = elem, *temp2;
					
					elem = elem2->l_next;
					while (temp1) {
						char to_break = (temp1 == elem2 ? 1 : 0);
						temp2 = temp1->l_next;
						llll_destroyelem(temp1);
						temp1 = temp2;
						if (to_break)
							break;
					}
					
					for (j = 0; j < this_num_divs; j++)
						llll_insertdouble_before(equal_subdiv, elem, 0, WHITENULL_llll);
					
					elem = elem ? elem->l_prev : diffs->l_tail; // since we'll perform the ->l_next in the for cycle
					break;
				}
			}
			if (!elem)
				break;
		}
	}
	
	llll_free(config->detected_onsets_ms);
	config->detected_onsets_ms = llll_dx2x_of_plain_double_llll(diffs, start);
	llll_free(diffs);
}


void box_measure_and_division_onsets_for_segment(t_rhythmogram *x, t_tsd_config *config)
{
//	char *buf = NULL;
	long i;

	llll_wrap_once(&config->detected_onsets_ms);
//	llll_to_text_buf(config->detected_onsets_ms, &buf, 0, 2, 0, NULL);

	for (i = config->start_fr; i <= config->end_fr; i++) {
		double frame_onset = (i - 1) * x->winsize/x->oversampling;
		double frame_dur_ms = x->winsize/x->oversampling;
		const double thresh = 0.05;
		long j = i - config->start_fr;
		
		if (config->ist_meas_phases[j] >= 0.) {
			
			if (config->ist_div_phases[j] >= 0.) {
				double m = config->ist_meas_phases[j] * config->ratios.div - config->ist_div_phases[j];
				if (fabs(m - round(m)) > 0.05)
					continue;
			}
			
			
			double measure_period_ms = (60./config->tempo_div) * config->ratios.div * 1000.;
			double next_onset = frame_onset + (1 - config->ist_meas_phases[j]) * measure_period_ms;
			double prev_onset = frame_onset - config->ist_meas_phases[j] * measure_period_ms;
			while (next_onset <= frame_onset + frame_dur_ms*(0.5 + thresh)){
				t_llllelem *nearest = get_nearest_llllelem_to_double(config->detected_onsets_ms, next_onset);
				if (nearest && nearest->l_prev)
					llllelem_create_abyss(nearest->l_prev, 0);
				next_onset += measure_period_ms;
			}
			while (prev_onset >= frame_onset - frame_dur_ms*(0.5 + thresh)){
				t_llllelem *nearest = get_nearest_llllelem_to_double(config->detected_onsets_ms, prev_onset);
				if (nearest && nearest->l_prev)
					llllelem_create_abyss(nearest->l_prev, 0);
				prev_onset -= measure_period_ms;
			}
		}
	}
	
	
	// refine measure boxing
	if (x->autocorrect) {
		t_llllelem *elem;
		long num_div = config->ratios.div;
		for (elem = config->detected_onsets_ms->l_head; elem; elem = elem->l_next){
			if (hatom_gettype(&elem->l_hatom) == H_LLLL){
				t_llll *ll = hatom_getllll(&elem->l_hatom);
				t_llll *prev_ll = elem->l_prev && hatom_gettype(&elem->l_prev->l_hatom) == H_LLLL ? hatom_getllll(&elem->l_prev->l_hatom) : NULL;
				t_llll *next_ll = elem->l_next && hatom_gettype(&elem->l_next->l_hatom) == H_LLLL ? hatom_getllll(&elem->l_next->l_hatom) : NULL;
				if (ll->l_size < num_div) {
					if (prev_ll && prev_ll->l_size > num_div && prev_ll->l_size % num_div != 0) {
						t_llllelem *left = prev_ll->l_tail;
						long i;
						for (i = ll->l_size + 1; i < num_div && left; i++)
							left = left->l_prev;
						rewrap_to_next_llll(config->detected_onsets_ms, left);
					} else if (next_ll && next_ll->l_size > num_div && next_ll->l_size % num_div != 0) {
						t_llllelem *right = next_ll->l_head;
						long i;
						for (i = ll->l_size + 1; i < num_div && right; i++)
							right = right->l_next;
						rewrap_to_prev_llll(config->detected_onsets_ms, right);
					}
				}
			}
		}
		
		for (elem = config->detected_onsets_ms->l_head; elem; elem = elem->l_next){
			if (hatom_gettype(&elem->l_hatom) == H_LLLL){
				t_llll *ll = hatom_getllll(&elem->l_hatom);
				if (ll->l_size > num_div + 1) {
					llll_groupllll(ll, num_div, 0);
					if (ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_LLLL)
						llll_upgrade_depth(ll->l_head->l_hatom.h_w.w_llll);
				}
			}
		}
		llll_flat(config->detected_onsets_ms, -2, -2, 0, LLLL_FREETHING_DONT);
		
		
		
		if (x->autocorrect >= 2) { // heavy autocorrect!
			
			// finding best sequence of correct-lengthed measures
			t_llllelem *thisstart, *thisend, *beststart = NULL, *bestend = NULL;
			long bestlen = 0;
			for (elem = config->detected_onsets_ms->l_head; elem; elem = elem->l_next){
				if (hatom_gettype(&elem->l_hatom) == H_LLLL){
					t_llll *ll = hatom_getllll(&elem->l_hatom);
					if (ll->l_size == num_div) {
						long this_len = 1;
						t_llllelem *elem2;
						thisstart = thisend = elem;
						for (elem2 = elem->l_next; elem2; elem2 = elem2->l_next) {
							if (hatom_gettype(&elem2->l_hatom) == H_LLLL){
								t_llll *ll2 = hatom_getllll(&elem2->l_hatom);
								if (ll2->l_size == num_div) {
									thisend = elem2;
									this_len++;
								} else
									break;
							}
						}
						if (this_len > bestlen){
							beststart = thisstart;
							bestend = thisend;
							bestlen = this_len;
						}
					}
				}
			}
			
			if (beststart && bestend && config->detected_onsets_ms->l_head){
				if (beststart->l_prev) {
					t_llll *ll = llll_wrap_element_range(config->detected_onsets_ms->l_head, beststart->l_prev);
					if (ll) {
						llll_flatten(ll, 0, 0);
						llll_rev(ll, 0, 0);
						llll_groupllll(ll, num_div, 0);
						llll_rev(ll, 0, 0);
						llll_splatter(ll->l_owner, LLLL_FREETHING_DONT);
					}
				}
				if (bestend->l_next) {
					t_llll *ll = llll_wrap_element_range(bestend->l_next, config->detected_onsets_ms->l_tail);
					if (ll) {
						llll_flatten(ll, 0, 0);
						llll_groupllll(ll, num_div, 0);
						llll_splatter(ll->l_owner, LLLL_FREETHING_DONT);
					}
				}
			}
			
			if (config->detected_onsets_ms->l_head && config->detected_onsets_ms->l_head->l_hatom.h_w.w_llll->l_size < num_div)
				llll_destroyelem(config->detected_onsets_ms->l_head);
			
			if (config->detected_onsets_ms->l_tail && config->detected_onsets_ms->l_tail->l_hatom.h_w.w_llll->l_size < num_div)
				llll_destroyelem(config->detected_onsets_ms->l_tail);
		}
	}
}
	
void retrieve_measure_and_division_onsets(t_rhythmogram *x, char also_affect_weights){ //argv+1
	
	// retrieve measure and division onsets
	t_tsd_config *config;
	for (config = x->first_segment_config; config; config = config->next) 
		retrieve_measure_and_division_onsets_for_segment(x, config);
	
	// compute standard deviation for each segment (which might also affect weights?)
	long max_length = 0;
	for (config = x->first_segment_config; config; config = config->next) {
		long length = config->detected_end_fr - config->detected_start_fr + 1;
		if (length > max_length)
			max_length = length;
	}
	for (config = x->first_segment_config; config; config = config->next) {
		t_llll *flattened;
		t_llll *diff;
		double avg = 0;
		
		flattened = llll_clone(config->detected_onsets_ms);
		llll_flatten(flattened, 0, 0);
		diff = llll_x2dx_of_plain_double_llll(flattened);
		config->detected_onsets_std_dev_ms = get_stdev_of_plain_double_llll(diff, &avg);
		config->detected_onsets_std_dev_rel = config->detected_onsets_std_dev_ms / avg;
		
		if (also_affect_weights)
			config->weight *= 1/(1 + config->detected_onsets_std_dev_rel * 10.);
		llll_free(flattened);
		llll_free(diff);
	}
	
	// intercepting and adapting errors
	if (x->autocorrect) 
		for (config = x->first_segment_config; config; config = config->next) {
			if (x->autocorrect >= 2) { 
				correct_deltas_for_measure_and_division_onsets_for_segment(x, config, 1.12, 6);
			} else {
				correct_deltas_for_measure_and_division_onsets_for_segment(x, config, 1.2, 3);
			}
		}
	
	
	// boxing according to measures
	for (config = x->first_segment_config; config; config = config->next) 
		box_measure_and_division_onsets_for_segment(x, config);
		
	// clone detected onset to full onsets
	for (config = x->first_segment_config; config; config = config->next) {
		config->onsets_ms = llll_clone(config->detected_onsets_ms);
	}

}

void append_segment_config_tsd_data(t_rhythmogram *x)
{
	t_llll *ptrackvoices_configs = llll_get();
	t_tsd_config *config;

	for (config = x->first_segment_config; config; config = config->next) {
		t_llll *conf = llll_get();
		t_llll *phases = llll_get();
		t_llll *ratios = llll_get();
		t_llll *voicenums = llll_get(); 
		t_llll *range = llll_get(); 
		t_llll *tempo = llll_get(); 
		llll_appendlong(range, config->start_fr, 0, WHITENULL_llll);
		llll_appendlong(range, config->end_fr, 0, WHITENULL_llll);
		llll_appendllll(conf, range, 0, WHITENULL_llll);
		llll_appendllll(conf, get_timesignature_as_llll(&config->ts), 0, WHITENULL_llll);
		llll_appendlong(ratios, config->ratios.div, 0, WHITENULL_llll);
		llll_appendlong(ratios, config->ratios.subdiv, 0, WHITENULL_llll);
		llll_appendllll(conf, ratios, 0, WHITENULL_llll);
		t_llll *phases1 = double_array_to_llll(config->ist_meas_phases, config->end_fr - config->start_fr);
		t_llll *phases2 = double_array_to_llll(config->ist_div_phases, config->end_fr - config->start_fr);
		t_llll *phases3 = double_array_to_llll(config->ist_subdiv_phases, config->end_fr - config->start_fr);
		llll_appendllll(phases, phases1, 0, WHITENULL_llll);
		llll_appendllll(phases, phases2, 0, WHITENULL_llll);
		llll_appendllll(phases, phases3, 0, WHITENULL_llll);
		llll_appendllll(conf, phases, 0, WHITENULL_llll);
		llll_appenddouble(voicenums, config->voice_nums[0], 0, WHITENULL_llll);
		llll_appenddouble(voicenums, config->voice_nums[1], 0, WHITENULL_llll);
		llll_appenddouble(voicenums, config->voice_nums[2], 0, WHITENULL_llll);
		llll_appendllll(conf, voicenums, 0, WHITENULL_llll);
//		llll_appenddouble(conf, config->tempo_div, 0, WHITENULL_llll);
		llll_appendrat(tempo, config->tempo_figure, 0, WHITENULL_llll);
		llll_appenddouble(tempo, config->tempo_div, 0, WHITENULL_llll);
		llll_appendllll(conf, tempo, 0, WHITENULL_llll);
		llll_appenddouble(conf, config->weight, 0, WHITENULL_llll);
		
		// onsets
		t_llll *onsets_ms = llll_clone(config->onsets_ms);
		llll_appendllll(conf, onsets_ms, 0, WHITENULL_llll);
		
		llll_appendllll(ptrackvoices_configs, conf, 0, WHITENULL_llll);
	}
	llll_appendllll(x->tsd_data, ptrackvoices_configs, 0, WHITENULL_llll);
}

void choose_painting_lines_for_segments(t_rhythmogram *x)
{
	// choose painting positioning for segment configs
	long *line_max = (long *) bach_newptr(x->num_segment_tsd_configs * sizeof(long));
	long *line_min = (long *) bach_newptr(x->num_segment_tsd_configs * sizeof(long));
	long i;
	t_tsd_config *config;
	for (i = 0; i < x->num_segment_tsd_configs; i++)
		line_max[i] = line_min[i] = -1;
	
	
	for (config = x->first_segment_config; config; config = config->next) 
		config->painting_line = -1;
	
	for (config = x->first_segment_config; config; config = config->next) {
		long first_empty_line = -1, min_dist_i = -1;
		for (i = 0; i < x->num_segment_tsd_configs; i++) {
			if (line_max[i] < 0) {
				first_empty_line = i + 1;
				break;
			}
			if (config->start_fr > line_max[i]) {
				min_dist_i = i+1;
				break;
				/*										dist = config->start_fr - line_max[i];
				 if (min_dist < 0 || dist < min_dist) {
				 min_dist = dist;
				 min_dist_i = i + 1;
				 } */
			} else if (config->end_fr < line_min[i]) {
				min_dist_i = i+1;
				break;
				/*										dist = line_min[i] - config->end_fr;
				 if (min_dist < 0 || dist < min_dist) {
				 min_dist = dist;
				 min_dist_i = i + 1;
				 }*/
			}
		}
		config->painting_line = min_dist_i < 0 ? first_empty_line : min_dist_i;
		line_min[config->painting_line - 1] = line_min[config->painting_line - 1] < 0 ? config->start_fr : MIN(line_min[config->painting_line - 1], config->start_fr);
		line_max[config->painting_line - 1] = line_max[config->painting_line - 1] < 0 ? config->end_fr : MAX(line_max[config->painting_line - 1], config->end_fr);
	}
	bach_freeptr(line_min);
	bach_freeptr(line_max);
}


void rhythmogram_anything(t_rhythmogram *x, t_symbol *s, long argc, t_atom *argv){ //argv+1
	
//	t_llll *inlist = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, s, argc, argv, LLLL_PARSE_CLONE);
	if (s == _sym_clear) {
		llll_clear(x->dft_data);
		llll_clear(x->dft_peaks_data);
		llll_clear(x->acf_data);
		llll_clear(x->acf_peaks_data);
		llll_clear(x->wave_data);
		llll_clear(x->ptrack_data);
		llll_clear(x->tsd_data);
	}
	
	if (s != _sym_bang)
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_UI, s, argc, argv, 0);

	t_llll *inlist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_UI, 0, true);

	if (inlist){
		
		if (inlist->l_head && hatom_gettype(&inlist->l_head->l_hatom) == H_SYM && hatom_getsym(&inlist->l_head->l_hatom) == _llllobj_sym_roll)
			llll_behead(inlist);
		
		llll_clear(x->dft_data);
		llll_clear(x->acf_data);
		llll_clear(x->dft_peaks_data);
		llll_clear(x->acf_peaks_data);
		llll_clear(x->wave_data);
		llll_clear(x->ptrack_data);
		llll_clear(x->tsd_data);
		
		if (inlist && inlist->l_head)
			cluster_averaging(&inlist, x->cluster_size_ms);
		
		// proper spectral calculations
		if (x->mode == k_MODE_ONSET_WAVE) {
			
			if (s == gensym("forcelength") && argc)
				x->forced_length = is_atom_number(argv) ? atom_getfloat(argv) : -1;
			else {
				double len = x->forced_length > 0 ? x->forced_length : get_max_rhythm_length(inlist) + x->decay_time;
				long i;
				
				// setting num_sampling_points
				rhythmogram_set_numpoints(x, ceil((len/1000.) * x->sampling_frequency));
				gathered_syntax_to_onset_wave(inlist, x->sampling_vals, x->num_sampling_vals, x->sampling_frequency, x->decay_time, x->voice_coupling, 0,
												5000, 1000, 0, x->mc_outer_threshold, x->mc_inner_threshold, x->normalize, CONST_USE_COSINE_IN_WAVE_MODEL, 
												x->use_masking_detection, x->non_sequential_events_multiplier, NULL, 0, x->waveshaping_exp, x->use_harmonic_detection * x->harmonic_changes_contribution, 
												NULL, x->hc_winsize, x->hc_hopsize, x->snap_harmonic_detected_onsets_to_nearest_note, 
												x->harmonic_detection_median_filtering_window_ms, x->delete_softer_harmonic_changes_inside_win_ms,
												x->gain_multiplier_for_maxima, x->gain_multiplier_for_minima, x->extend_masking_ms, x->extend_masking_components_over_masked_ones, x->debug_bpm[0], x->debug_bpm[1]);

				for (i = 0; i < x->num_sampling_vals; i++)
					if (i < x->tags_size)
						x->tags[i] = 1000 * i / x->sampling_frequency;
				
				x->num_windows_in_history = x->num_sampling_vals;
				x->end_ms = len;
				build_wave_data(x, x->num_sampling_vals, x->sampling_vals);
			}
			 
		} else if (!x->realtime && (inlist->l_head && hatom_gettype(&inlist->l_head->l_hatom) == H_SYM && hatom_getsym(&inlist->l_head->l_hatom) == _llllobj_sym_frame)
					|| x->mode == k_MODE_RHYTHMOSCOPE || x->mode == k_MODE_AUTOCORRELATION) {

			// single frame entered
			if (inlist->l_head && hatom_gettype(&inlist->l_head->l_hatom) == H_SYM)
				llll_behead(inlist);
			
			if (x->algorithm == 0) {
				// direct frequency retrieving from difference sets
//				rhythmogram_set_numpoints(x, ceil((len/1000.) * x->sampling_frequency));
				get_spectral_rhythm_config_in_window(0, 0, inlist, true, true, x->win_type, x->velocity_slope, x->voice_coupling, x->mc_outer_threshold, x->mc_inner_threshold, x->normalize, x->phase,
												 NULL, x->sampling_vals, x->sampling_phase, x->num_sampling_vals, x->min_displayed_bpm, x->max_displayed_bpm, x->bpm_peak_decay,
												 CONST_MIN_SINGLEWEIGHT_TO_ACCOUNT, 0., x->shape_of_contributions, false);
				x->min_sampled_bpm = x->min_displayed_bpm;
				x->max_sampled_bpm = x->max_displayed_bpm;

			} else {
				long i;
				const long zero_padding_factor = x->zero_padding_factor;	
				long num_sampling_vals = zero_padding_factor * ceil(x->sampling_frequency * (get_max_rhythm_length(inlist) + x->decay_time) / 1000.);
				double *wave = (double *) bach_newptr(num_sampling_vals * sizeof(double)); 
				// onset waveform modeling, and then fft on it
				
				// clearing onset waveform (needed since when we retrieve it, it'll be just the first part
				for (i = 0; i < num_sampling_vals; i++)
					wave[i] = 0;
				
				// retrieve onset waveform
				gathered_syntax_to_onset_wave(inlist, wave, num_sampling_vals / zero_padding_factor, x->sampling_frequency, x->decay_time, x->voice_coupling, 0,
												5000, 1000, 0,
												x->mc_outer_threshold, x->mc_inner_threshold, x->normalize, CONST_USE_COSINE_IN_WAVE_MODEL, 
												x->use_masking_detection, x->non_sequential_events_multiplier, NULL, 0, x->waveshaping_exp, 
												x->use_harmonic_detection * x->harmonic_changes_contribution, NULL, x->hc_winsize, x->hc_hopsize,
												x->snap_harmonic_detected_onsets_to_nearest_note, x->harmonic_detection_median_filtering_window_ms,
												x->delete_softer_harmonic_changes_inside_win_ms,
												x->gain_multiplier_for_maxima, x->gain_multiplier_for_minima, x->extend_masking_ms, x->extend_masking_components_over_masked_ones, x->debug_bpm[0], x->debug_bpm[1]);
												
				build_wave_data(x, num_sampling_vals / zero_padding_factor, wave);

				// retrieve fft
				kiss_fft_cpx *onsetf_cpx = (kiss_fft_cpx *) bach_newptr(num_sampling_vals * sizeof(kiss_fft_cpx));
				for (i = 0; i < num_sampling_vals / zero_padding_factor; i++){
					onsetf_cpx[i].r = wave[i];
					onsetf_cpx[i].i = 0;
				}
				
				for (i = num_sampling_vals / zero_padding_factor; i < num_sampling_vals; i++)	// zero padding
					onsetf_cpx[i].r = onsetf_cpx[i].i = 0;
				
				rhythmogram_set_numpoints(x, num_sampling_vals);

				if (x->mode == k_MODE_AUTOCORRELATION) {
					bach_fm_acf(num_sampling_vals, onsetf_cpx, x->sampling_frequency, x->sampling_vals, true, true);
					for (i = 0; i < num_sampling_vals; i++)
						x->sampling_phase[0] = 0;
				} else {
					bach_fft(num_sampling_vals, false, onsetf_cpx, x->sampling_vals, x->sampling_phase);
				}
				
				// rescale amplitudes to be independent from the length of the input 
				for (i = 0; i < num_sampling_vals; i++)
					x->sampling_vals[i] /= num_sampling_vals;
				
				x->min_sampled_bpm = 0;
				x->max_sampled_bpm = x->sampling_frequency * 60;
				bach_freeptr(wave);
				bach_freeptr(onsetf_cpx);
			}
			
			if (x->mode == k_MODE_RHYTHMOGRAM || x->mode == k_MODE_AUTOCORRELOGRAM) {
				update_max_amplitude(x);
				update_frame(x);
			}
				
			if (x->mode == k_MODE_AUTOCORRELATION)
				append_frame_acf_data(x);
			else
				append_frame_dft_data(x);
			
		} else if (!x->realtime && (x->mode == k_MODE_RHYTHMOGRAM || x->mode == k_MODE_AUTOCORRELOGRAM || x->mode == k_MODE_PARTIAL_TRACKING || x->mode == k_MODE_TS_DETECTOR)){
			// perform STFT
			
			double len = get_max_rhythm_length(inlist);
			double win_size = x->winsize;
			long i, j;
			double cursor;
			x->num_windows_in_history = ceil(len/(win_size/x->oversampling));
			
			if (win_size > 0) {
				if (false) { // NO LONGER USED
					initialize_surface(x, x->num_sampling_vals);
					
					for (j = 0, cursor = 0; cursor < len; cursor += win_size/x->oversampling, j++){
						t_llll *thiswin = cut_window_from_rhythm(inlist, cursor, cursor+win_size);
						
						if (x->algorithm == 0) {
							// direct frequency retrieving from difference sets
							rhythmogram_set_numpoints(x, ceil((len/1000.) * x->sampling_frequency));
							get_spectral_rhythm_config_in_window(0, 0, thiswin, true, true, x->win_type, x->velocity_slope, x->voice_coupling, x->mc_outer_threshold, x->mc_inner_threshold, x->normalize, x->phase,
																 NULL, x->sampling_vals, x->sampling_phase, x->num_sampling_vals, x->min_displayed_bpm, x->max_displayed_bpm, x->bpm_peak_decay,
																 CONST_MIN_SINGLEWEIGHT_TO_ACCOUNT, x->min_displayed_amplitude, x->shape_of_contributions, false);
						}
						if (j < x->tags_size)
							x->tags[j] = cursor;
						llll_free(thiswin);
						update_max_amplitude(x);
						update_frame(x);
						append_frame_dft_data(x);
					}
				} else {
					const double zero_padding_factor = x->zero_padding_factor;	
					long num_sampling_vals = ceil(x->sampling_frequency * (get_max_rhythm_length(inlist) + x->decay_time) / 1000.);
					double *wave = (double *) bach_newptr(num_sampling_vals * sizeof(double)); 
					long single_window_size_in_samps = ceil(win_size * x->sampling_frequency / 1000.);
					long window_size_size_with_zero_padding_in_samps = ceil(single_window_size_in_samps * zero_padding_factor);

					// clearing onset waveform (needed since when we retrieve it, it'll be just the first part
					for (i = 0; i < num_sampling_vals; i++)
						wave[i] = 0;
					
					t_multiphase_spectrogram mph;
					
					// retrieve onset waveform
					t_llll *debug = NULL;
					gathered_syntax_to_onset_wave(inlist, wave, num_sampling_vals, x->sampling_frequency, x->decay_time, x->voice_coupling, 0, // or 1?
													5000, 1000, 0,
													x->mc_outer_threshold, x->mc_inner_threshold, x->normalize, CONST_USE_COSINE_IN_WAVE_MODEL, 
													x->use_masking_detection, x->non_sequential_events_multiplier, x->algorithm == 0 ? &mph : NULL, 
													single_window_size_in_samps, x->waveshaping_exp, x->use_harmonic_detection * x->harmonic_changes_contribution, &debug,
													x->hc_winsize, x->hc_hopsize, x->snap_harmonic_detected_onsets_to_nearest_note, 
													x->harmonic_detection_median_filtering_window_ms, x->delete_softer_harmonic_changes_inside_win_ms,
													x->gain_multiplier_for_maxima, x->gain_multiplier_for_minima, x->extend_masking_ms, x->extend_masking_components_over_masked_ones, x->debug_bpm[0], x->debug_bpm[1]);
					if (debug) {
						llll_prependsym(debug, gensym("debug"), 0, WHITENULL_llll);
						if (llll_check(debug)){
							char foo = 8;
							foo++;
						}
						llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 0, debug);
						llll_free(debug);
					}
					
					if (x->algorithm == 0) {
						// from multiphase spectrogram to spectrogram, via choosing phase and downsampling (NO LONGER USED, OLD ALGORITHM)
						rhythmogram_set_numpoints(x, single_window_size_in_samps);
						initialize_surface(x, x->num_sampling_vals_between_minbpm_and_maxbpm);

						for (j = 0, cursor = 0; cursor < len; cursor += win_size/x->oversampling, j += round(single_window_size_in_samps/x->oversampling)) {
							for (i = 0; i < single_window_size_in_samps; i++){
								// find highest amplitude among the mph.bins[j][i] multibin
								double max_ampli = 0; 
								double ampli_sum = 0;
								long max_id = -1;
								long k;
								for (k = 0; k < CONST_MULTIPHASE_NUM_PHASE_BINS; k++){
									double this_am = mph.bins[j][i].ampli[k];
									ampli_sum += this_am;
									if (this_am > max_ampli) {
										max_ampli = this_am;
										max_id = k;
									}
								}
								if (max_id >= 0) {
									x->sampling_phase[i] = mph.bins[j][i].phase[max_id];
									x->sampling_vals[i] = ampli_sum;
								} else {
									x->sampling_phase[i] = x->sampling_vals[i] = 0;
								}
							}								   
							if (j < x->tags_size)
								x->tags[j] = cursor;
							append_frame_dft_data(x);
						}
						free_multiphase_spectrogram(&mph);
						build_surface(x);					
									   
					} else if (x->algorithm == 1) {
					
					
						build_wave_data(x, num_sampling_vals, wave);
						
						//					t_llll *ll1 = double_array_to_llll(wave, num_sampling_vals);
						//					llll_writetxt((t_object *) x, NULL, ll1);
						
						initialize_surface(x, x->num_sampling_vals_between_minbpm_and_maxbpm);
						
						kiss_fft_cpx *onsetf_cpx = (kiss_fft_cpx *) bach_newptr(window_size_size_with_zero_padding_in_samps * sizeof(kiss_fft_cpx));
						kiss_fft_cpx *onsetf_win_cpx = (kiss_fft_cpx *) bach_newptr(window_size_size_with_zero_padding_in_samps * sizeof(kiss_fft_cpx));
		
						for (j = 0, cursor = 0; cursor < len; cursor += win_size/x->oversampling, j++) {
//							double double_cursor_sample = cursor * x->sampling_frequency / 1000.;
							long cursor_sample = round(cursor * x->sampling_frequency / 1000.);
							
							// retrieve fft
							
							for (i = 0; i < single_window_size_in_samps; i++) {
								onsetf_win_cpx[i].r = onsetf_cpx[i].r = i + cursor_sample < num_sampling_vals ? wave[i + cursor_sample] : 0;
								onsetf_win_cpx[i].i = onsetf_cpx[i].i = 0;
							}
							
							windowize(single_window_size_in_samps, x->win_type, onsetf_cpx, onsetf_win_cpx);
							
							for (i = single_window_size_in_samps; i < window_size_size_with_zero_padding_in_samps; i++)	// zero padding
								onsetf_win_cpx[i].r = onsetf_win_cpx[i].i = 0;
							
							rhythmogram_set_numpoints(x, window_size_size_with_zero_padding_in_samps);
							
							bach_fft(window_size_size_with_zero_padding_in_samps, false, onsetf_win_cpx, x->sampling_vals, x->sampling_phase);
							
							// rescale amplitudes to be independent from the length of the input 
							for (i = 0; i < window_size_size_with_zero_padding_in_samps; i++)
								x->sampling_vals[i] /= single_window_size_in_samps * zero_padding_factor;
							
							if (j < x->tags_size)
								x->tags[j] = cursor;

							append_frame_dft_data(x);
							
							if (x->mode == k_MODE_AUTOCORRELOGRAM || (x->mode != k_MODE_RHYTHMOGRAM && x->use_combined_dft_fmacf_function)) {
								bach_fm_acf(window_size_size_with_zero_padding_in_samps, onsetf_win_cpx, x->sampling_frequency, x->sampling_vals, true, true);
								append_frame_acf_data(x);
							}
							
							//							update_max_amplitude(x);
							//							update_frame(x);
						}
						
						bach_freeptr(onsetf_cpx);
						bach_freeptr(onsetf_win_cpx);

						build_surface(x);					
						
					}
					bach_freeptr(wave);
				}

				if (x->mode == k_MODE_PARTIAL_TRACKING || x->mode == k_MODE_TS_DETECTOR) {
					// also do partial tracking
					long num_frames = x->dft_data->l_size;
					t_llllelem *frame, *peak;
					long *num_peaks = (long *) bach_newptr(num_frames * sizeof(long));
					long i, j, max_num_peaks = 0;
					double max_peak_amplitude = 0;
					
					// finding peaks
					t_llll *dft_data_to_use = llll_clone(x->dft_data);
					if (x->use_combined_dft_fmacf_function) {
						t_llllelem *dft_elem, *acf_elem, *dft_elem2, *acf_elem2;
						double max_acf_ampli = 0;

						// we find the maximum acf bin
						for (acf_elem = x->acf_data->l_head; acf_elem; acf_elem = acf_elem->l_next) {
							t_llll *acf_frame = acf_elem->l_hatom.h_w.w_llll;
							for (acf_elem2 = acf_frame->l_head; acf_elem2; acf_elem2 = acf_elem2->l_next) {
								double this_acf_ampli = hatom_getdouble(&acf_elem2->l_hatom.h_w.w_llll->l_head->l_next->l_next->l_hatom);
								if (this_acf_ampli > max_acf_ampli)
									max_acf_ampli = this_acf_ampli;
							}
						}
						
						if (max_acf_ampli == 0)
							max_acf_ampli = 1;
						
						// we multiply by the fm-acf
						for (dft_elem = dft_data_to_use->l_head, acf_elem = x->acf_data->l_head; dft_elem && acf_elem; dft_elem = dft_elem->l_next, acf_elem = acf_elem->l_next) {
							t_llll *dft_frame = dft_elem->l_hatom.h_w.w_llll;
							t_llll *acf_frame = acf_elem->l_hatom.h_w.w_llll;
							for (dft_elem2 = dft_frame->l_head, acf_elem2 = acf_frame->l_head; dft_elem2 && acf_elem2; dft_elem2 = dft_elem2->l_next, acf_elem2 = acf_elem2->l_next) {
								double this_dft_ampli = hatom_getdouble(&dft_elem2->l_hatom.h_w.w_llll->l_head->l_next->l_next->l_hatom);
								double this_acf_ampli = hatom_getdouble(&acf_elem2->l_hatom.h_w.w_llll->l_head->l_next->l_next->l_hatom);
								hatom_setdouble(&dft_elem2->l_hatom.h_w.w_llll->l_head->l_next->l_next->l_hatom, this_dft_ampli * (this_acf_ampli/max_acf_ampli));
							}
						}
					}
					if (x->dft_peaks_data)
						llll_free(x->dft_peaks_data);
					x->dft_peaks_data = get_peaks(dft_data_to_use, false, true, x->numpeaks, x->minpeakamp, 
													x->minpeakrelamp, x->sampling_frequency, x->num_sampling_vals); // build peaks
					llll_free(dft_data_to_use);
//
//					llll_post(x->dft_data, 0, 1, 4, NULL, NULL);
//					llll_post(x->dft_peaks_data, 0, 1, 4, NULL, NULL);
//					return;
					
					// partial tracking
					if (x->dft_peaks_data) {
						
						// filtering small peaks just next to big peaks (we use the fact that peaks are given ordered by amplitude
						if (x->ptrack_filter_secondary_peaks) {
							for (frame = x->dft_peaks_data->l_head; frame; frame = frame->l_next) {
								for (peak = frame ? frame->l_hatom.h_w.w_llll->l_head : NULL; peak; peak = peak->l_next) {
									t_llllelem *peak2;
									t_llll *peakll = hatom_getllll(&peak->l_hatom);
									double ampli1 = hatom_getdouble(&peakll->l_head->l_next->l_next->l_hatom);
									double freq1 = hatom_getdouble(&peakll->l_head->l_hatom)/60.;
									peak2 = peak->l_next;
									while (peak2) {
										t_llllelem *next = peak2->l_next;
										t_llll *peakll2 = hatom_getllll(&peak2->l_hatom);
										double ampli2 = hatom_getdouble(&peakll2->l_head->l_next->l_next->l_hatom);
										double freq2 = hatom_getdouble(&peakll2->l_head->l_hatom)/60.;
										if (ampli2 < ampli1 && // should be always true, cause the peaks are ordere
											freq_ratio(freq1, freq2) < x->ptrack_freqratio)
											llll_destroyelem(peak2);
										peak2 = next;
									}
								}
							}
						}
						
						for (i = 0, frame = x->dft_peaks_data->l_head; i < num_frames; i++, frame = frame->l_next) {
							num_peaks[i] = frame ? frame->l_hatom.h_w.w_llll->l_size : 0;
							if (num_peaks[i] > max_num_peaks)
								max_num_peaks = num_peaks[i];
						}
						
						t_spectral_peak ***peaks = (t_spectral_peak ***)bach_newptr(num_frames * sizeof(t_spectral_peak **));
						
						for (i = 0; i < num_frames; i++) {
							peaks[i] = (t_spectral_peak **)bach_newptr(max_num_peaks * sizeof(t_spectral_peak *));
							for (j = 0; j < max_num_peaks; j++)
								peaks[i][j] = NULL;
						}

						
						// build peaks
						double max_peak_ampli = 0;
						for (i = 0, frame = x->dft_peaks_data->l_head; i < num_frames && frame; i++, frame = frame->l_next) {
							for (j = 0, peak = frame ? frame->l_hatom.h_w.w_llll->l_head : NULL; j < max_num_peaks && peak; j++, peak = peak->l_next) {
								t_llll *peakll = hatom_getllll(&peak->l_hatom);
								peaks[i][j] = (t_spectral_peak *) bach_newptr(sizeof(t_spectral_peak));
								peaks[i][j]->freq = hatom_getdouble(&peakll->l_head->l_hatom)/60.;
								peaks[i][j]->phase = hatom_getdouble(&peakll->l_head->l_next->l_hatom) * PI/180.;
								peaks[i][j]->amplitude = hatom_getdouble(&peakll->l_head->l_next->l_next->l_hatom);
								if (peaks[i][j]->amplitude > max_peak_amplitude)
									max_peak_amplitude = peaks[i][j]->amplitude;
								peaks[i][j]->width = hatom_getlong(&peakll->l_head->l_next->l_next->l_next->l_hatom);
								peaks[i][j]->ptrack_next = peaks[i][j]->ptrack_prev = NULL;
								peaks[i][j]->tsdetect_next = peaks[i][j]->tsdetect_prev = NULL;
								peaks[i][j]->ptrack_status = peaks[i][j]->done = k_PARTIAL_TRACKING_VOICE_NO; /// WATCH OUT!!!
								peaks[i][j]->frame_number = i;
								peaks[i][j]->frame_ms = i * x->winsize / x->oversampling;
								if (peaks[i][j]->amplitude > max_peak_ampli)
									max_peak_ampli = peaks[i][j]->amplitude;
							}
						}
						x->max_ptrack_amplitude = max_peak_ampli;
						
						// partial tracking
						long num_ptrack_voices = 0; // will be filled
						t_ptrack_voice *ptvoice, *first_ptrack_voice = NULL, *last_ptrack_voice = NULL; // will be filled
						partial_tracking(num_frames, num_peaks, peaks, x->winsize/x->oversampling, x->ptrack_voices, 
										 x->ptrack_amp, x->ptrack_amplow, x->ptrack_amprel, x->ptrack_freqratio, deg2rad(x->ptrack_phasedelta), 
										 x->ptrack_attack, x->ptrack_release, x->ptrack_locut / 60., &num_ptrack_voices, &first_ptrack_voice, &last_ptrack_voice);
						
						// set data in llll form (we'll draw starting from this llll)
						llll_clear(x->ptrack_data);
						for (ptvoice = first_ptrack_voice; ptvoice; ptvoice = ptvoice->next){
							t_llll *voice = llll_get();
							t_spectral_peak *ptpeak;
							for (ptpeak = ptvoice->first_peak; ptpeak; ptpeak = ptpeak->ptrack_next) {
								t_llll *peak = llll_get();
								llll_appendlong(peak, ptpeak->frame_number + 1, 0, WHITENULL_llll);
								llll_appendlong(peak, ptpeak->frame_ms, 0, WHITENULL_llll);
								llll_appenddouble(peak, ptpeak->freq, 0, WHITENULL_llll);	
								llll_appenddouble(peak, ptpeak->amplitude, 0, WHITENULL_llll);	
								llll_appenddouble(peak, ptpeak->phase, 0, WHITENULL_llll);	
								llll_appendllll(voice, peak, 0, WHITENULL_llll);
							}
							llll_appendllll(x->ptrack_data, voice, 0, WHITENULL_llll);
						}
						
						
						if (x->mode == k_MODE_TS_DETECTOR) {
							t_tsd_frame **tsd_frame = (t_tsd_frame **) bach_newptr(num_frames * sizeof(t_tsd_frame *));
							t_ptrack_voice *ptvoice;
							t_spectral_peak *ptpeak;
							
							
							// A. FRAMEWISE CONFIGURATIONS
							for (i = 0; i < num_frames; i++) {
								tsd_frame[i] = (t_tsd_frame *)bach_newptr(sizeof(t_tsd_frame));
								tsd_frame[i]->frame_num = i;
								tsd_frame[i]->first_peak = tsd_frame[i]->last_peak = NULL;
								tsd_frame[i]->first_tsd_config = tsd_frame[i]->last_tsd_config = NULL;
								tsd_frame[i]->num_peaks = tsd_frame[i]->num_tsd_configs = 0;
								tsd_frame[i]->prev = i > 0 ? tsd_frame[i-1] : NULL;
								tsd_frame[i]->next = i < num_frames - 1 ? tsd_frame[i+1] : NULL;
							}

							for (ptvoice = first_ptrack_voice; ptvoice; ptvoice = ptvoice->next)
								for (ptpeak = ptvoice->first_peak; ptpeak; ptpeak = ptpeak->ptrack_next) 
									append_peak_to_tsd_frame(tsd_frame[ptpeak->frame_number], ptpeak); 
							
							for (i = 0; i < num_frames; i++) {
								t_tsd_frame *this_frame = tsd_frame[i];
								t_spectral_peak *p1, *p2, *p3;

								// 1. FINDING CONFIGURATIONS
								if (this_frame->num_peaks >= 3) {
									// find 3-combinations
									for (p1 = this_frame->first_peak; p1; p1 = p1->tsdetect_next)
										for (p2 = p1->tsdetect_next; p2; p2 = p2->tsdetect_next)
											for (p3 = p2->tsdetect_next; p3; p3 = p3->tsdetect_next) {
												double f1 = p1->freq, f2 = p2->freq, f3 = p3->freq;
												double ph1 = p1->phase, ph2 = p2->phase, ph3 = p3->phase;
												
												reorder_triplet_of_doubles_and_other_doubles_accordingly(&f1, &f2, &f3, &ph1, &ph2, &ph3);

												// now f1 < f2 < f3
												// analyzing ratios
												
												double division = f2/f1;
												double subdivision = f3/f2;
												long round_division = round(division);
												long round_subdivision = round(subdivision);
												
												if (round_division > 1 && round_subdivision > 1) { // otherwise we step back in the 2-combination case, which we'll handle later on												
													// are phases ok?
													double k = (ph2 * f3)/(TWOPI * f2) - ph3/TWOPI;
													double h = (ph1 * f3)/(TWOPI * f1) - ph3/TWOPI;
													double t = (h-k)*f2/f3;

													double weight_phases = 1/(1 + fabs(k - round(k)) + fabs(h - round(h)) + fabs(t - round(t)));
													double weight_approx = 1/(1 + fabs(division - round_division) + fabs(subdivision - round_subdivision));

//													double measure_phase = positive_fmod((ph3/TWOPI + round(m)) / (division * subdivision), 1.);
													double measure_phase = positive_fmod(ph1/TWOPI, 1.);
//													double measure_phase = positive_fmod((ph2/TWOPI + round(n)) / subdivision, 1.);
													
// WAS: WRONG FORMULA:
//													double measure_phase = positive_fmod(ph3/TWOPI + round(m)/f3, 1.); //fmod((ph1/TWOPI + (ph2/TWOPI + round(q)/f2) + (ph3/TWOPI + round(m)/f3))/3., 1.); // average of the three sinusoidal phases; this value is in [0., 1.]

													t_tsd_adaptation dummy;
													t_tsd_config *tsc = params_to_tsd_config(x, weight_approx * weight_phases, round_division, round_subdivision, measure_phase, f2 * 60, 
																								p1->ptrack_parent->ID, p2->ptrack_parent->ID, p3->ptrack_parent->ID, NULL, NULL, NULL, 0, &dummy);
													if (tsc) 
														append_tsd_config_to_tsd_frame(tsc, this_frame);
												}
											}
								}
							

								if (this_frame->num_peaks >= 2) {
									// find 2-combinations
/*									for (p1 = this_frame->first_peak; p1; p1 = p1->tsdetect_next)
										for (p2 = p1->tsdetect_next; p2; p2 = p2->tsdetect_next) {
												double f1 = p1->freq, f2 = p2->freq;
												double ph1 = p1->phase, ph2 = p2->phase;
										
												if (f1 > f2)
													swap_doubles(&f1, &f2);
										
												// now f1 < f2 < f3
												// analyzing ratios
												double ratio = f2/f1;
												double round_ratio = round(ratio);
												if (round_ratio > 1) {
													// are phases ok?
													double n = (ph1 * f2)/(TWOPI * f1) - ph2/TWOPI;
													double weight_phases = 1/(1 + 3 * fabs(n - round(n)));	// for symmetry with the 3-case
													double weight_approx = 1/(1 + 2 * fabs(ratio - round_ratio)); // for symmetry with the 3-case
												}
										}*/
								}
								
								
								// 2. REGROUPING CONFIGURATIONS DEPENDING ON TS
								
							}


							llll_clear(x->tsd_data);
							t_tsd_config *config;
							t_llll *single_frame_configs = llll_get();
							for (i = 0; i < num_frames; i++) {
								t_llll *frame = llll_get();
								t_tsd_frame *this_frame = tsd_frame[i];
								
								for (config = this_frame->first_tsd_config; config; config = config->next) {
									t_llll *conf = llll_get();
									t_llll *phases = llll_get();
									t_llll *ratios = llll_get();
									t_llll *voicenums = llll_get(); 
									llll_appendlong(ratios, config->ratios.div, 0, WHITENULL_llll);
									llll_appendlong(ratios, config->ratios.subdiv, 0, WHITENULL_llll);
									llll_appendllll(conf, ratios, 0, WHITENULL_llll);
									llll_appenddouble(phases, config->phase.phase_measure, 0, WHITENULL_llll);
									llll_appenddouble(phases, config->phase.phase_div, 0, WHITENULL_llll);
									llll_appenddouble(phases, config->phase.phase_subdiv, 0, WHITENULL_llll);
									llll_appendllll(conf, phases, 0, WHITENULL_llll);
									llll_appenddouble(voicenums, config->voice_nums[0], 0, WHITENULL_llll);
									llll_appenddouble(voicenums, config->voice_nums[1], 0, WHITENULL_llll);
									llll_appenddouble(voicenums, config->voice_nums[2], 0, WHITENULL_llll);
									llll_appendllll(conf, voicenums, 0, WHITENULL_llll);
									llll_appenddouble(conf, config->tempo_div, 0, WHITENULL_llll);
									llll_appenddouble(conf, config->weight, 0, WHITENULL_llll);
									
									llll_appendllll(frame, conf, 0, WHITENULL_llll);
								}
								
								llll_inplacesort(frame, (sort_fn)llll_sort_by_last);
								llll_rev(frame, 0, 1);
								llll_appendllll(single_frame_configs, frame, 0, WHITENULL_llll);
							}
							llll_appendllll(x->tsd_data, single_frame_configs, 0, WHITENULL_llll);
							
							
							// B. PARTIAL-WISE SEGMENTS (most important part)
							t_ptrack_voice *p1, *p2, *p3;
							free_segment_configs(x);
							x->num_segment_tsd_configs = 0;
							for (p1 = first_ptrack_voice; p1; p1 = p1->next)
								for (p2 = p1->next; p2; p2 = p2->next)
									for (p3 = p2->next; p3; p3 = p3->next) {
										long start_fr, end_fr;
										get_ptrack_voices_superposition_range(p1, p2, p3, &start_fr, &end_fr);
										
										if (start_fr >= 0) {
											long num_fr = end_fr - start_fr + 1;
 											double f1, a1, f2, a2, f3, a3; // average frequencies and amplitudes

											double *ph1 = (double *)bach_newptr(num_fr * sizeof(double)); // "istantaneous" phases
											double *ph2 = (double *)bach_newptr(num_fr * sizeof(double));
											double *ph3 = (double *)bach_newptr(num_fr * sizeof(double));
											double *if1 = (double *)bach_newptr(num_fr * sizeof(double)); // "istantaneous" frequencies
											double *if2 = (double *)bach_newptr(num_fr * sizeof(double));
											double *if3 = (double *)bach_newptr(num_fr * sizeof(double));

											get_ptrack_voice_average_frequence_and_ampli_in_frame_range(p1, &f1, &a1, start_fr, end_fr);
											get_ptrack_voice_average_frequence_and_ampli_in_frame_range(p2, &f2, &a2, start_fr, end_fr);
											get_ptrack_voice_average_frequence_and_ampli_in_frame_range(p3, &f3, &a3, start_fr, end_fr);
											
											// getting phases for each voice
											for (i = start_fr; i <= end_fr; i++) {
												ph1[i-start_fr] = get_averaged_phase_at_frame(p1, i, x->winsize/x->oversampling);
												ph2[i-start_fr] = get_averaged_phase_at_frame(p2, i, x->winsize/x->oversampling);
												ph3[i-start_fr] = get_averaged_phase_at_frame(p3, i, x->winsize/x->oversampling);
												if1[i-start_fr] = get_averaged_freq_at_frame(p1, i, x->winsize/x->oversampling);
												if2[i-start_fr] = get_averaged_freq_at_frame(p2, i, x->winsize/x->oversampling);
												if3[i-start_fr] = get_averaged_freq_at_frame(p3, i, x->winsize/x->oversampling);
											}
											
											reorder_triplet_of_doubles_and_other_doubles_and_double_arrays_accordingly(&f1, &f2, &f3, &a1, &a2, &a3, &ph1, &ph2, &ph3, &if1, &if2, &if3);
											
											// now f1 < f2 < f3
											// analyzing ratios
											double division = f2/f1;
											double subdivision = f3/f2;
											long round_division = round(division);
											long round_subdivision = round(subdivision);
											t_tsd_adaptation adapt;
											
											if (round_division > 1 && round_subdivision > 1) {		
																				
												char subdiv_phase_defined = true, div_phase_defined = true; // measure_phase_defined = true;
												
												double *measure_phase = (double *)bach_newptr(num_fr * sizeof(double));	 // istantaneous phases related to measure/div/subdiv
												double *div_phase = (double *)bach_newptr(num_fr * sizeof(double));
												double *subdiv_phase = (double *)bach_newptr(num_fr * sizeof(double));
												
												// how OK are phases?
												double weight_phases = 0, weight_approx = 1;
												t_tsd_config *tsc;
												
												double *mphase_possib = (double *) bach_newptr((round_division * round_subdivision + round_division) * sizeof(double));
												double *mphase_diffs = (double *) bach_newptr((round_division * round_subdivision + round_division) * sizeof(double));
												for (i = start_fr; i <= end_fr; i++) {
													long j = i-start_fr;
													double k = (ph2[j] * f3)/(TWOPI * f2) - ph3[j]/TWOPI;
													double h = (ph1[j] * f3)/(TWOPI * f1) - ph3[j]/TWOPI;
													double t = (h-k)*f2/f3;
													weight_phases += 1/(1 + fabs(k - round(k)) + fabs(h - round(h)) + fabs(t - round(t)));
													
//													measure_phase[j] = positive_fmod(ph3[j]/TWOPI + round(m)/if3[j], 1.); //fmod((ph1[j]/TWOPI + (ph2[j]/TWOPI + round(q)/if2[j]) + (ph3[j]/TWOPI + round(m)/if3[j]))/3., 1.);

													// list of possibilities for the measure phase
													long s, best_idx = -1;
													double best_err = 1.; 
													for (s = 0; s < round_division * round_subdivision; s++)
														mphase_possib[s] = ((ph3[j]/TWOPI) + s)/(round_division * round_subdivision);
													for (s = 0; s < round_division; s++)
														mphase_possib[round_division * round_subdivision + s] = ((ph2[j]/TWOPI) + s)/round_division;
													for (s = 0; s < round_division * round_subdivision + round_division; s++) {
														mphase_diffs[s] = phase_dist(mphase_possib[s], ph1[j]/TWOPI, 1.);
														if (mphase_diffs[s] < best_err) {
															best_idx = s;
															best_err = mphase_diffs[s];
														}
													}
													measure_phase[j] = best_idx > -1 ? mphase_possib[best_idx] : mphase_possib[0];
												}
												bach_freeptr(mphase_possib);
												bach_freeptr(mphase_diffs);
												weight_phases /= num_fr;
												
												weight_approx = 1/(1 + fabs(division - round_division) + fabs(subdivision - round_subdivision));
												
//												t_llll *measure_phase_llll = double_array_to_llll(measure_phase, num_fr);
//												char *ph = NULL;
//												llll_to_text_buf(measure_phase_llll, &ph, 0, 2, 0, NULL);
//												bach_freeptr(ph);
												
												// correcting outliners in measure phases
/*												double phase_err_with_first_phase[num_fr];
												for (i = 0; i < num_fr; i++)	// calculating phase error with respect to the first phase (of course if all phase errors will be big, probably the first phase will be wrong: we'll check it later by finding the mode)
													phase_err_with_first_phase[i] = phase_error(measure_phase[0], measure_phase[i], f2, f2, i * x->winsize/x->oversampling, 1.);
												const double approx_tolerance = 1/20.;
												double approximated_mode = find_mode_of_double_array_with_modulo(phase_err_with_first_phase, num_fr, approx_tolerance, 1.);
												for (i = 0; i < num_fr; i++) {
													if (fabs(phase_err_with_first_phase[i] - approximated_mode) > approx_tolerance) {	// modifying measure_phase
														measure_phase[i] = positive_fmod(measure_phase[0] + f2 * i * x->winsize/x->oversampling / 1000. + approximated_mode, 1.);
														phase_err_with_first_phase[i] = phase_error(measure_phase[0], measure_phase[i], f2, f2, i * x->winsize/x->oversampling, 1.);
													}
												}
												
												t_llll *phase_err_llll = double_array_to_llll(phase_err_with_first_phase, num_fr);
												char *ph2 = NULL;
												llll_to_text_buf(phase_err_llll, &ph2, 0, 2, 0, NULL); */

												
												tsc = params_to_tsd_config(x, weight_approx * weight_phases * (1 * (1 - x->prefer_longer_segments) + x->prefer_longer_segments * num_fr * (x->winsize/(x->oversampling * 1000))), 
																				round_division, round_subdivision, 0, f2 * 60, p1->ID, p2->ID, p3->ID,
																				measure_phase, div_phase, subdiv_phase, num_fr, &adapt);
												
												if (tsc) {
													tsc->cycles_bpm[0] = 60*f1;
													tsc->cycles_bpm[1] = 60*f2;
													tsc->cycles_bpm[2] = 60*f3;	
												}
//
//												llll_to_text_buf(measure_phase_llll, &ph, 0, 2, 0, NULL);
//												llll_free(measure_phase_llll);
//												llll_free(phase_err_llll);

												// subdiv phase
												if (adapt.type & k_TSD_ADAPT_TYPE_SUBDIV_TO_DIV) {
													subdiv_phase_defined = false;
												} else if (adapt.type & k_TSD_ADAPT_TYPE_DIV_TO_SUBDIV) {
													if (adapt.old_new_subdiv_ratio.r_den != 1)
														subdiv_phase_defined = false;
													else {
														for (i = 0; i < num_fr; i++)
															subdiv_phase[i] = positive_fmod(ph2[i] / TWOPI, 1.);
													}
												} else {
													if (adapt.old_new_subdiv_ratio.r_den != 1)
														subdiv_phase_defined = false;
													else {
														for (i = 0; i < num_fr; i++)
															subdiv_phase[i] = positive_fmod(ph3[i] / TWOPI, 1.);
													}
												}

												// div phase
												if (adapt.old_new_div_ratio.r_den != 1)
													div_phase_defined = false;
												else {
													if (adapt.type & k_TSD_ADAPT_TYPE_DIV_TO_SUBDIV) {
														// if we want to risk we do this:
//														for (i = 0; i < num_fr; i++)
//															div_phase[i] = positive_fmod(ph1[i]/ TWOPI, 1.);

														// but ph1[i] is usually very imprecise, so we take the ph2[i] nearest to ph1;
														// the phase must be one of the ph2[i]+ 2pi * k/n, with n = num_subdiv and k < n. 
														
														
														if (true) {
															// WE RISK RISK:
															for (i = 0; i < num_fr; i++)
																div_phase[i] = positive_fmod(ph1[i]/ TWOPI, 1.);
														} else {
															// WE DON't RISK
															double best_j = 0;
															double best_err = num_fr * TWOPI;
															for (j = 0; j < round_subdivision; j++) {
																double this_err = 0;
																for (i = 0; i < num_fr; i++) {
																	double this_phase = (ph2[i]+ TWOPI * ((double)j)/round_subdivision);
																	this_err += phase_dist(this_phase, ph1[i], TWOPI);
																}
																if (this_err < best_err) {
																	best_err = this_err;
																	best_j = j; 
																}
															}
															for (i = 0; i < num_fr; i++)
																div_phase[i] = positive_fmod((ph2[i] + TWOPI * ((double)best_j)/round_subdivision) / TWOPI, 1.);
														}
														
													} else {
														for (i = 0; i < num_fr; i++)
															div_phase[i] = positive_fmod((adapt.type & k_TSD_ADAPT_TYPE_SUBDIV_TO_DIV ? ph3[i] : ph2[i]) / TWOPI, 1.);
													}	
												}
												
												if (tsc) {
													tsc->detected_start_fr = tsc->start_fr = start_fr + 1;
													tsc->detected_end_fr = tsc->end_fr = end_fr + 1;
													tsc->ist_meas_phases = measure_phase;
													tsc->ist_div_phases = div_phase;
													tsc->ist_subdiv_phases = subdiv_phase;
													if (x->last_segment_config) {
														tsc->next = NULL;
														tsc->prev = x->last_segment_config;
														x->last_segment_config->next = tsc;
														x->last_segment_config = tsc;
													} else {
														tsc->prev = tsc->next = NULL;
 														x->first_segment_config = x->last_segment_config = tsc;
													}
													x->num_segment_tsd_configs++;
												} else {
													bach_freeptr(measure_phase);
													bach_freeptr(div_phase);
													bach_freeptr(subdiv_phase);
												}
											}
											
											bach_freeptr(ph1);
											bach_freeptr(ph2);
											bach_freeptr(ph3);
											bach_freeptr(if1);
											bach_freeptr(if2);
											bach_freeptr(if3);
										}
									}
							
							// drop short segments, or segments completely covered by other segments and whose weight is < theshold * other segment's weight
							double thresh_num_frames = x->ignore_segments_under_ms/(x->winsize/x->oversampling);
							config = x->first_segment_config;
							while (config) {
								t_tsd_config *next = config->next;
								char need_to_drop = false;
								
								if (config->end_fr - config->start_fr < thresh_num_frames)
									need_to_drop = true;
								else {
									t_tsd_config *temp;
									for (temp = x->first_segment_config; temp; temp = temp->next) {
										if (temp == config)
											continue;
										else if (temp->start_fr <= config->start_fr && temp->end_fr >= config->end_fr &&
												config->weight < x->ignore_covered_segments_with_relative_weight_under * temp->weight / 100.) {
											need_to_drop = true;
											break;
										}
									}
								}
								
								if (need_to_drop) {
									if (config->prev)
										config->prev->next = config->next;
									else
										x->first_segment_config = config->next;
									if (config->next)
										config->next->prev = config->prev;
									else
										x->last_segment_config = config->prev;
									free_tsd_config(x, config);
								}
								config = next;
							}

							
							// convert wild chars
							for (config = x->first_segment_config; config; config = config->next) {
								if (config->ratios.subdiv < 0) {
									config->ratios.subdiv = 2;
//									for (i = config->start_fr; i <= config->end_fr; i++) {
//										long j = i - config->start_fr;
//									}
								}
								if (config->ratios.div < 0)
									config->ratios.div = (config->ratios.subdiv == 3 ? 2 : 4); // JUST FOR NOW!!! then we'll have TO DO it better (todo)
							}

							retrieve_measure_and_division_onsets(x, x->detected_onsets_affect_tsd_weights);

							// sort by weight
							sort_segment_configs_by_weight(x);
							
							// set index for configs
							renumber_configs(x, 1);
							
							// finding max weight
							x->max_tsd_segment_weight = 0;
							for (config = x->first_segment_config; config; config = config->next)
								if (config->weight > x->max_tsd_segment_weight)
									x->max_tsd_segment_weight = config->weight;

//							WAS:
//							retrieve_measure_and_division_onsets(x, false);
									
							append_segment_config_tsd_data(x);
							
							choose_painting_lines_for_segments(x);
							

							// free stuff
							for (i = 0; i < num_frames; i++) {
								t_tsd_config *next, *config = tsd_frame[i]->first_tsd_config; 
								while (config) {
									next = config->next;
									bach_freeptr(config);
									config = next;
								}
							}

							for (i = 0; i < num_frames; i++)
								bach_freeptr(tsd_frame[i]);
								
								
							// TO DO: FREE...
							bach_freeptr(tsd_frame);
						}


						// free stuff
						ptvoice = first_ptrack_voice;
						while (ptvoice){
							t_ptrack_voice *next = ptvoice->next;
							bach_freeptr(ptvoice);
							ptvoice = next;
						}

						for (i = 0; i < num_frames; i++)
							for (j = 0; j < max_num_peaks; j++)
								if (peaks[i][j])
									bach_freeptr(peaks[i][j]);
						
						for (i = 0; i < num_frames; i++)
							bach_freeptr(peaks[i]);
						
						bach_freeptr(peaks);

					}
				}

			}
		}
		llll_free(inlist);
		jbox_redraw((t_jbox *) x);
	}
}


t_rhythmogram* rhythmogram_new(t_symbol *s, long argc, t_atom *argv){
	t_rhythmogram* x = NULL;
	t_max_err err = MAX_ERR_GENERIC;
	t_dictionary *d;
	long flags;

	if (!(d=object_dictionaryarg(argc,argv)))
		return NULL;

	x = (t_rhythmogram*) object_alloc_debug(s_rhythmogram_class);
	flags = 0 
			| JBOX_DRAWFIRSTIN 
			| JBOX_NODRAWBOX
			| JBOX_DRAWINLAST
	//		| JBOX_TRANSPARENT	
	//		| JBOX_NOGROW
	//		| JBOX_GROWY
			| JBOX_GROWBOTH
			| JBOX_HILITE
			| JBOX_BACKGROUND
	//		| JBOX_TEXTFIELD
	//		| JBOX_DRAWBACKGROUND
	//		| JBOX_DEFAULTNAMES
	//		| JBOX_MOUSEDRAGDELTA
			;
	
	x->curr_mouseover_tsd_segment = NULL;
	x->selected_config = NULL;
	x->first_segment_config = x->last_segment_config = NULL;
	x->num_segment_tsd_configs = 0;
	x->max_tsd_segment_weight = 1;
	x->max_ptrack_amplitude = 1;
	x->selected_frame_number = -1;
	x->end_ms = 0;
	x->recalled_attributes = 0;
	x->dft_data = llll_get();
	x->acf_data = llll_get();
	x->ptrack_data = llll_get();
	x->wave_data = llll_get();
	x->dft_peaks_data = llll_get();
	x->acf_peaks_data = llll_get();
	x->tsd_data = llll_get();
	x->surface = NULL;
	x->tags = NULL;
	x->tags_size = 0;
	x->fixed_num_windows_in_history = 0;
	x->sampling_vals = x->sampling_phase = NULL;
	x->algorithm = 1; // static
	x->cluster_size_ms = 150;
	x->bpm_peak_decay = 3; // no more used
	x->first_surface_draw = true;
	
	err = jbox_new(&x->j_box.l_box, flags, argc, argv); 
	x->j_box.l_box.b_firstin = (t_object*) x;

	x->curr_mouse_pt.x = 0; 
	x->curr_mouse_pt.y = 0;
	x->curr_hint_hz = 0;
	x->curr_hint_bpm = 0;
	x->j_mouse_is_over = false;
	x->forced_length = -1;
	
	
	// retrieve saved attribute values
	attr_dictionary_process(x, d);
	
	llllobj_jbox_setup((t_llllobj_jbox *) x, 1, "444444444");

	// mutex
	systhread_mutex_new_debug(&x->c_mutex, 0);

	jbox_ready(&x->j_box.l_box);

	x->recalled_attributes = 1;

	if (x)
		return x;

	object_free_debug(x);
	return NULL;
}

void rhythmogram_free(t_rhythmogram *x){
	if (x->surface)
		jgraphics_surface_destroy(x->surface);
	if (x->tags)
		bach_freeptr(x->tags);
	if (x->sampling_vals)
		bach_freeptr(x->sampling_vals);
	if (x->sampling_phase)
		bach_freeptr(x->sampling_phase);
	free_segment_configs(x);
	llll_free(x->dft_data);
	llll_free(x->dft_peaks_data);
	llll_free(x->acf_data);
	llll_free(x->acf_peaks_data);
	llll_free(x->wave_data);
	llll_free(x->ptrack_data);
	llll_free(x->tsd_data);
	jbox_free(&x->j_box.l_box);
	systhread_mutex_free_debug(x->c_mutex);
	llllobj_jbox_free((t_llllobj_jbox *) x);
}


void rhythmogram_paint(t_rhythmogram *x, t_object *view){
	t_jgraphics *g;
	long i = 0;
	t_rect rect;
	t_jfont *jf_legend;
	t_modifiers modifiers = jkeyboard_getcurrentmodifiers();

	if (x->max_displayed_bpm <= x->min_displayed_bpm)
		return;
		
	if (!x->sampling_vals)
		return;
	
	jf_legend = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, 10);

	// getting rectangle dimensions
	g = (t_jgraphics*) patcherview_get_jgraphics(view); 
	jbox_get_rect_for_view(&x->j_box.l_box.b_ob, view, &rect);
	
	paint_background((t_object *)x, g, &rect, &x->j_bgcolor, 4.);

	// only used by the rhythmoscope
	long min_i = round(rescale(x->min_displayed_bpm, x->min_sampled_bpm, x->max_sampled_bpm, 0, x->num_sampling_vals - 1));
	long max_i = round(rescale(x->max_displayed_bpm, x->min_sampled_bpm, x->max_sampled_bpm, 0, x->num_sampling_vals - 1));
	double min_pix = 0;
	double max_pix = rect.width;
	double samples_graphical_delta_x = (max_pix - min_pix) / (max_i - min_i);
	t_llll *ptrack_pt_mouseover = NULL;
	
	if (x->mode == k_MODE_ONSET_WAVE) {
		paint_line(g, get_grey(0.6), 0, rect.height/2., rect.width, rect.height/2, 0.5);
		if (x->num_sampling_vals > 0) {
			double prev_xx = 0, prev_yy = rescale(x->sampling_vals[0], -1., 1., rect.height, 0);
			for (i = 1; i < x->num_sampling_vals; i++){
				double xx = rescale(i, 0, x->num_sampling_vals - 1, 0, rect.width);
				double yy = rescale(x->sampling_vals[i], -x->max_displayed_amplitude_onset_wave, x->max_displayed_amplitude_onset_wave, rect.height, 0);
				paint_line(g, x->j_color, prev_xx, prev_yy, xx, yy, 1);
				prev_xx = xx;
				prev_yy = yy;
			}
		}
	} else if (x->mode == k_MODE_RHYTHMOGRAM || x->mode == k_MODE_AUTOCORRELOGRAM){
		t_rect src, dst;
		src.x = 0;
		src.y = 0;
		src.width = x->num_windows_in_history;
		src.height = x->num_sampling_vals_between_minbpm_and_maxbpm;
		dst.x = 0; 
		dst.y = 0;
		dst.width = rect.width;
		dst.height = rect.height;
		jgraphics_image_surface_draw(g, x->surface, src, dst);
	} else if (x->mode == k_MODE_RHYTHMOSCOPE || x->mode == k_MODE_AUTOCORRELATION){
		double prev_xx = 0, prev_yy = rect.height;
		
		for (i = min_i; i < x->num_sampling_vals && i <= max_i; i++){
			double xx = rescale(i, 0, (max_i - min_i + 1) - 1, min_pix, max_pix);
			double yy = rescale(x->sampling_vals[i], 0, x->max_displayed_amplitude_rhythmoscope, rect.height, 0);
			paint_line(g, x->j_color, prev_xx, prev_yy, xx, yy, 1);
			prev_xx = xx;
			prev_yy = yy;
		}
	} else if ((x->mode == k_MODE_PARTIAL_TRACKING || x->mode == k_MODE_TS_DETECTOR) && x->ptrack_data){
		t_rect src, dst;
		src.x = 0;
		src.y = 0;
		src.width = x->num_windows_in_history;
		src.height = x->num_sampling_vals_between_minbpm_and_maxbpm;
		dst.x = 0; 
		dst.y = 0;
		dst.width = rect.width;
		dst.height = rect.height;
		jgraphics_image_surface_draw(g, x->surface, src, dst);

		t_llllelem *ptvoice, *ptpt;
		double prev_xx = -1, prev_yy = -1, prev_radius = -1;
		
		// for ts detector
		long curr_mouseover_frame_num = rescale(x->curr_mouse_pt.x, 0, rect.width, 0, x->num_windows_in_history); // 0-based
		double left, frameleft = rescale(curr_mouseover_frame_num, 0, x->num_windows_in_history, 0, rect.width);
		double framewidth = rect.width/x->num_windows_in_history;
		const double width = 270; // width for ts detector window
		if (frameleft + width + 20 <= rect.width)
			left = frameleft + 20;
		else
			left = frameleft - 20 - (width - framewidth);
		
		for (i = 1, ptvoice = x->ptrack_data->l_head; ptvoice; i++, ptvoice = ptvoice->l_next){
			t_jrgba color = long_to_color(i);

			// first we paint all lines
			for (ptpt = ptvoice->l_hatom.h_w.w_llll->l_head; ptpt; ptpt = ptpt->l_next) {
				t_llll *ptptll = hatom_getllll(&ptpt->l_hatom);
				long frame_num = hatom_getlong(&ptptll->l_head->l_hatom);
				double freq = hatom_getdouble(&ptptll->l_head->l_next->l_next->l_hatom);
				double ampli = hatom_getdouble(&ptptll->l_head->l_next->l_next->l_next->l_hatom);
				
				double xx = rescale(frame_num, 1, x->num_windows_in_history+1, 0, rect.width);
				double yy = rescale(freq * 60., x->min_displayed_bpm, x->max_displayed_bpm, rect.height, 0);
				double radius = CLAMP(rescale(ampli, x->ptrack_amplow * (x->ptrack_amprel ? x->max_ptrack_amplitude : 1), x->max_ptrack_amplitude, CONST_PTRACK_MIN_POINT_RADIUS, CONST_PTRACK_MAX_POINT_RADIUS), CONST_PTRACK_MIN_POINT_RADIUS, CONST_PTRACK_MAX_POINT_RADIUS);
				
				if (ptpt->l_prev)
					paint_doublewidth_line(g, color, prev_xx, prev_yy, xx, yy, prev_radius/2., radius/2.);

				if (!ptpt->l_next) { // && x->mode == k_MODE_TS_DETECTOR) {
					paint_line(g, color, xx, yy, xx + framewidth, yy, radius/2.);
					paint_line(g, color, xx + framewidth, yy - 2, xx + framewidth, yy + 2, radius/2.);
				}
					
				prev_xx = xx;
				prev_yy = yy;
				prev_radius = radius;
			}
						
			// then we paint all circles
			for (ptpt = ptvoice->l_hatom.h_w.w_llll->l_head; ptpt; ptpt = ptpt->l_next) {
				t_llll *ptptll = hatom_getllll(&ptpt->l_hatom);
				long frame_num = hatom_getlong(&ptptll->l_head->l_hatom);
				double freq = hatom_getdouble(&ptptll->l_head->l_next->l_next->l_hatom);
				double ampli = hatom_getdouble(&ptptll->l_head->l_next->l_next->l_next->l_hatom);
				
				double xx = rescale(frame_num, 1, x->num_windows_in_history+1, 0, rect.width);
				double yy = rescale(freq * 60., x->min_displayed_bpm, x->max_displayed_bpm, rect.height, 0);
				double radius = CLAMP(rescale(ampli, x->ptrack_amplow * (x->ptrack_amprel ? x->max_ptrack_amplitude : 1), x->max_ptrack_amplitude, CONST_PTRACK_MIN_POINT_RADIUS, CONST_PTRACK_MAX_POINT_RADIUS), CONST_PTRACK_MIN_POINT_RADIUS, CONST_PTRACK_MAX_POINT_RADIUS);
				
				if (x->mode == k_MODE_PARTIAL_TRACKING && !ptrack_pt_mouseover && 
					(x->curr_mouse_pt.x - xx)*(x->curr_mouse_pt.x - xx) + (x->curr_mouse_pt.y - yy)*(x->curr_mouse_pt.y - yy) < 25) {
					ptrack_pt_mouseover = ptptll;
					paint_circle_filled(g, get_grey(0.9), xx, yy, radius);
					paint_circle_stroken(g, color, xx, yy, radius, 1);
				} else
					paint_circle_filled(g, color, xx, yy, radius);

				if (x->mode == k_MODE_TS_DETECTOR && frame_num == curr_mouseover_frame_num + 1 && (modifiers & eControlKey)) {
					char text[10];
					double text_width, text_height;
					snprintf_zero(text, 10, "%ld", i);
					jfont_text_measure(jf_legend, text, &text_width, &text_height);
					double text_x = curr_mouseover_frame_num > 0 && left < frameleft ? xx + radius : xx - radius - text_width;
					double text_y = yy + radius + text_height < rect.height ? yy + radius : yy - radius - text_height;
					write_text_simple(g, jf_legend, color, text, text_x, text_y, rect.width - text_x, rect.height - text_y);
				}
				
				prev_xx = xx;
				prev_yy = yy;
				prev_radius = radius;
			}
		}
		
		if (x->mode == k_MODE_TS_DETECTOR && x->tsd_data->l_head) {
			if (modifiers & eControlKey) {
				// paint ISTANTANEOUS FRAME POSSIBILITIES
				t_llllelem *sols_elem = llll_getindex(x->tsd_data->l_head->l_hatom.h_w.w_llll, curr_mouseover_frame_num + 1, I_STANDARD);
				if (sols_elem) {
					t_llll *sols = hatom_getllll(&sols_elem->l_hatom);
					
					paint_filledrectangle(g, build_jrgba(0.9, 0.85, 0.85, 0.3), frameleft, 0, framewidth, rect.height);
					
					if (true) { 
						const double vstep = 10;
						double curr_y = 10;
						t_llllelem *config;
						
						// paint possibilities
						paint_rectangle_rounded(g, get_grey(0.4), change_alpha(x->j_hintbgcolor, 0.9), left, 0, width, rect.height, 1, 5, 5);
						
						write_text_simple(g, jf_legend, x->j_hintcolor, "  Admissible istantaneous configurations:", left, curr_y, width, rect.height - curr_y);
						curr_y += vstep;
						for (config = sols->l_head; config; config = config->l_next) {
							char text[500];
							t_llll *configll = hatom_getllll(&config->l_hatom);
							long div = hatom_getlong(&configll->l_head->l_hatom.h_w.w_llll->l_head->l_hatom);
							long subdiv = hatom_getlong(&configll->l_head->l_hatom.h_w.w_llll->l_head->l_next->l_hatom);
							double measure_phase = hatom_getdouble(&configll->l_head->l_next->l_hatom.h_w.w_llll->l_head->l_hatom);
							long v1 = hatom_getlong(&configll->l_head->l_next->l_next->l_hatom.h_w.w_llll->l_head->l_hatom);
							long v2 = hatom_getlong(&configll->l_head->l_next->l_next->l_hatom.h_w.w_llll->l_head->l_next->l_hatom);
							long v3 = hatom_getlong(&configll->l_head->l_next->l_next->l_hatom.h_w.w_llll->l_head->l_next->l_next->l_hatom);
							double tempo_div = hatom_getdouble(&configll->l_head->l_next->l_next->l_next->l_hatom);
							double weight = hatom_getdouble(&configll->l_head->l_next->l_next->l_next->l_next->l_hatom);
							snprintf_zero(text, 500, "  • w %.2f: (%ld:%ld), τ %.1f, meas φ %.2f, voices {%ld, %ld, %ld}", weight, div, subdiv, tempo_div, measure_phase, v1, v2, v3);
							write_text_simple(g, jf_legend, x->j_hintcolor, text, left, curr_y, width, rect.height - curr_y);
							curr_y += vstep;
						}
					}
				}
			} else {
				t_tsd_config *config;
				double v_cursor = 4;
				const double v_height = 17;
				for (config = x->first_segment_config; config; config = config->next) {
					char text[3500];
					long start_fr = config->start_fr;
					long end_fr = config->end_fr;
					long num = config->ts.numerator;
					long den = config->ts.denominator;
					double tempo_div = config->tempo_div;
					double weight = config->weight;
					
					v_cursor = 4 + (config->painting_line - 1) * v_height;
					
//					snprintf_zero(text, 3500, "   w %.2f • (%ld:%ld), τ %.1f, %s φ %s, voices {%ld, %ld, %ld}", weight, div, subdiv, tempo_div, ph_referred_to == 0 ? "meas" : (ph_referred_to == 1 ? "div" : "subdiv"), phases, v1, v2, v3);
//					snprintf_zero(text, 3500, "   %ld/%ld, τ %ld/%ld=%.1f", num, den, config->tempo_figure.r_num, config->tempo_figure.r_den, tempo_div);
					snprintf_zero(text, 3500, "   %ld/%ld, τ %.0f", num, den, tempo_div);
					double xs = rescale(start_fr, 1, x->num_windows_in_history+1, 0, rect.width);
					double xe = rescale(end_fr + 1, 1, x->num_windows_in_history+1, 0, rect.width);

					config->painting_rect = build_rect(xs, v_cursor, xe - xs - 2, v_height - 2);
					
					paint_rectangle(g, x->j_hintcolor, x->selected_config == config ? change_luminosity(x->j_hintbgcolor, 1.2) : x->j_hintbgcolor, xs, v_cursor, xe - xs - 2, v_height-2, 1);
					write_text_simple(g, jf_legend, x->j_hintcolor, text, xs, v_cursor + 2.5, xe - xs - 2, rect.height - v_cursor);

					paint_filledrectangle(g, long_to_color(config->voice_nums[0]), xs, v_cursor, 5, 5);
					paint_filledrectangle(g, long_to_color(config->voice_nums[1]), xs, v_cursor + 5, 5, 5);
					paint_filledrectangle(g, long_to_color(config->voice_nums[2]), xs, v_cursor + 10, 5, 5);
					
					t_llllelem *meas, *onset;
					for (meas = config->onsets_ms->l_head; meas; meas = meas->l_next){
						if (hatom_gettype(&meas->l_hatom) == H_LLLL) {
							for (onset = meas->l_hatom.h_w.w_llll->l_head; onset; onset = onset->l_next){
								double ms = hatom_getdouble(&onset->l_hatom);
								double tick_x = rescale(ms, 0, x->num_windows_in_history * x->winsize/x->oversampling, 0, rect.width);
								if (tick_x < xe && tick_x > xs)
									paint_line(g, onset == meas->l_hatom.h_w.w_llll->l_head ? get_grey(0.1) : get_grey(0.3), tick_x, v_cursor, tick_x, v_cursor + (onset == meas->l_hatom.h_w.w_llll->l_head ? 4.25 : 3), onset == meas->l_hatom.h_w.w_llll->l_head ? 1 : 0.5);
							}
						}
					}
					
					paint_rectangle(g, get_grey(0.2), get_grey(1), xe - 5 - 2, v_cursor, 5, v_height - 2, 0.5);
					paint_rectangle(g, get_grey(0.2), get_grey(0.2), xe - 5 - 2, v_cursor, 5, (v_height - 2) * weight/x->max_tsd_segment_weight, 0.5);

					v_cursor += v_height;
				}

				if (x->curr_mouseover_tsd_segment && x->j_mouse_is_over) {
					char legenda1[1000], legenda2[1000], legenda3[1000], legenda4[1000], legenda5[1000], legenda6[1000];
					double x1 = x->curr_mouse_pt.x, y1 = x->curr_mouse_pt.y;
					double txtwidth1, txtwidth2, txtwidth3, txtwidth4, txtwidth5, txtwidth6, txtheight1, txtheight2, txtheight3, txtheight4, txtheight5, txtheight6, maxwidth;
					snprintf_zero(legenda1, 1000, "Time Signature: %ld/%ld", x->curr_mouseover_tsd_segment->ts.numerator, x->curr_mouseover_tsd_segment->ts.denominator);
					snprintf_zero(legenda2, 1000, "Tempo: %ld/%ld = %.1f", x->curr_mouseover_tsd_segment->tempo_figure.r_num, x->curr_mouseover_tsd_segment->tempo_figure.r_den, x->curr_mouseover_tsd_segment->tempo_div);
					snprintf_zero(legenda3, 1000, "Detected Onsets Standard Deviation: %.1fms (%.0f%%)", x->curr_mouseover_tsd_segment->detected_onsets_std_dev_ms, x->curr_mouseover_tsd_segment->detected_onsets_std_dev_rel * 100.);
					snprintf_zero(legenda4, 1000, "Confidence Index: %.3f", x->curr_mouseover_tsd_segment->weight);
					snprintf_zero(legenda5, 1000, "BPM: (%.1f, %.1f, %.1f) – Ratio %ld:%ld – Peak Tracking Voices: {%d %d %d}", x->curr_mouseover_tsd_segment->cycles_bpm[0], x->curr_mouseover_tsd_segment->cycles_bpm[1], x->curr_mouseover_tsd_segment->cycles_bpm[2],
																											x->curr_mouseover_tsd_segment->ratios.div, x->curr_mouseover_tsd_segment->ratios.subdiv,
																											x->curr_mouseover_tsd_segment->voice_nums[0], x->curr_mouseover_tsd_segment->voice_nums[1], x->curr_mouseover_tsd_segment->voice_nums[2]);
					snprintf_zero(legenda6, 1000, "Manual Adjust: Measures: rot %+ld, Divisions: %+ld, rot %+ld", x->curr_mouseover_tsd_segment->force_barline_rot, x->curr_mouseover_tsd_segment->force_div_rot, x->curr_mouseover_tsd_segment->force_add_div);

					jfont_text_measure(jf_legend, legenda1, &txtwidth1, &txtheight1);
					jfont_text_measure(jf_legend, legenda2, &txtwidth2, &txtheight2);
					jfont_text_measure(jf_legend, legenda3, &txtwidth3, &txtheight3);
					jfont_text_measure(jf_legend, legenda4, &txtwidth4, &txtheight4);
					jfont_text_measure(jf_legend, legenda5, &txtwidth5, &txtheight5);
					jfont_text_measure(jf_legend, legenda6, &txtwidth6, &txtheight6);
					maxwidth = MAX(MAX(MAX(MAX(txtwidth1, MAX(txtwidth2, txtwidth3)), txtwidth4), txtwidth5), txtwidth6);
					if (x->curr_mouse_pt.x + maxwidth + 10 > rect.width)
						x1 = x->curr_mouse_pt.x - maxwidth;
					if (x->curr_mouse_pt.y - (txtheight1 + txtheight2 + txtheight3 + txtheight4 + txtheight5) - 10 < 0) {
						y1 = x->curr_mouse_pt.y;
						if (x1 > x->curr_mouse_pt.x - maxwidth)
							x1 += 10;
					}
					paint_rectangle(g, get_grey(0.4), get_grey(0.8), x1, y1, maxwidth, txtheight1 + txtheight2 + txtheight3 + txtheight4 + txtheight5 + txtheight6, 0.5);
					write_text_simple(g, jf_legend, x->j_hintcolor, legenda1, x1, y1, maxwidth + 20, txtheight1 + 20);
					write_text_simple(g, jf_legend, x->j_hintcolor, legenda2, x1, y1 + txtheight1, maxwidth + 20, txtheight2 + 20);
					write_text_simple(g, jf_legend, x->j_hintcolor, legenda3, x1, y1 + txtheight1 + txtheight2, maxwidth + 20, txtheight3 + 20);
					write_text_simple(g, jf_legend, x->j_hintcolor, legenda4, x1, y1 + txtheight1 + txtheight2 + txtheight3, maxwidth + 20, txtheight4 + 20);
					write_text_simple(g, jf_legend, x->j_hintcolor, legenda5, x1, y1 + txtheight1 + txtheight2 + txtheight3 + txtheight4, maxwidth + 20, txtheight5 + 20);
					write_text_simple(g, jf_legend, x->j_hintcolor, legenda6, x1, y1 + txtheight1 + txtheight2 + txtheight3 + txtheight4 + txtheight5, maxwidth + 20, txtheight6 + 20);
				}
				
			}
		}
	}
	
	if (x->show_hint && x->j_mouse_is_over && x->mode != k_MODE_TS_DETECTOR){
		double x1, y1;
		double txtwidth, txtheight, txtwidth2, txtheight2;
		char legend1[1000], legend2[1000];
		long this_idx_for_rhythmoscope_circle = 0;
		legend2[0] = 0;
		
		if (!x->realtime && (x->mode == k_MODE_RHYTHMOGRAM || x->mode == k_MODE_AUTOCORRELOGRAM)){
			snprintf_zero(legend1, 1000, "%.f s (frame %ld)", x->curr_hint_ms / 1000., x->curr_hint_frame + 1);
			snprintf_zero(legend2, 1000, "%.2f bpm (%.2f Hz)", x->curr_hint_bpm, x->curr_hint_hz);
		} else if (!x->realtime && x->mode == k_MODE_RHYTHMOSCOPE) {
			this_idx_for_rhythmoscope_circle = CLAMP(floor(rescale(x->curr_mouse_pt.x, 0, x->width, min_i, max_i)), 0, x->num_sampling_vals);
			snprintf_zero(legend1, 1000, "%.2f bpm (%.2f Hz)", x->curr_hint_bpm, x->curr_hint_hz);
			snprintf_zero(legend2, 1000, "ampli %.4f, phase %.0f°", x->sampling_vals[this_idx_for_rhythmoscope_circle], rad2deg(x->sampling_phase[this_idx_for_rhythmoscope_circle]));
		} else if (!x->realtime && x->mode == k_MODE_AUTOCORRELATION) {
			this_idx_for_rhythmoscope_circle = CLAMP(floor(rescale(x->curr_mouse_pt.x, 0, x->width, min_i, max_i)), 0, x->num_sampling_vals);
			snprintf_zero(legend1, 1000, "%.2f bpm (%.2f Hz)", x->curr_hint_bpm, x->curr_hint_hz);
			snprintf_zero(legend2, 1000, "ampli %.4f", x->sampling_vals[this_idx_for_rhythmoscope_circle]);
		} else if (x->mode == k_MODE_ONSET_WAVE) {
			double ms = rescale(x->curr_mouse_pt.x, 0, x->width, 0, x->end_ms);
			this_idx_for_rhythmoscope_circle = round(rescale(x->curr_mouse_pt.x, 0, x->width, 0, x->num_sampling_vals));
			snprintf_zero(legend1, 1000, "%.3f s", ms / 1000.);
			snprintf_zero(legend2, 1000, "ampli %.2f",x->sampling_vals[this_idx_for_rhythmoscope_circle]);
		} else if (x->mode == k_MODE_PARTIAL_TRACKING) {
			if (ptrack_pt_mouseover) {
				long voice_num = llllelem_getpos(ptrack_pt_mouseover->l_owner->l_parent->l_owner);
				long frame_num = hatom_getlong(&ptrack_pt_mouseover->l_head->l_hatom);
				double freq = hatom_getdouble(&ptrack_pt_mouseover->l_head->l_next->l_next->l_hatom);
				double ampli = hatom_getdouble(&ptrack_pt_mouseover->l_head->l_next->l_next->l_next->l_hatom);
				double phase = hatom_getdouble(&ptrack_pt_mouseover->l_head->l_next->l_next->l_next->l_next->l_hatom);
				snprintf_zero(legend1, 1000, "voice %ld, frame %ld (%.3f s)", voice_num, frame_num, (frame_num - 1) * (x->winsize/x->oversampling) / 1000.);
				snprintf_zero(legend2, 1000, "%.2f bpm (%.2f Hz), phase %.0f°, ampli %.4f", freq * 60., freq, rad2deg(phase), ampli);
			} else {
				snprintf_zero(legend1, 1000, "%.3f s (frame %ld)", x->curr_hint_frame * (x->winsize/x->oversampling) / 1000., x->curr_hint_frame + 1);
				snprintf_zero(legend2, 1000, "%.2f bpm (%.2f Hz)", x->curr_hint_bpm, x->curr_hint_hz);
			}
		} else 
			snprintf_zero(legend1, 1000, "%.2f bpm (%.2f Hz)", x->curr_hint_bpm, x->curr_hint_hz);
		
		jfont_text_measure(jf_legend, legend1, &txtwidth, &txtheight);
		if (legend2[0]) {
			jfont_text_measure(jf_legend, legend2, &txtwidth2, &txtheight2);
			if (txtwidth2 > txtwidth)
				txtwidth = txtwidth2;
			txtheight += txtheight2;
		}
		if (x->mode == k_MODE_PARTIAL_TRACKING && ptrack_pt_mouseover) {
			x1 = x->curr_mouse_pt.x + CONST_PTRACK_MAX_POINT_RADIUS;
			y1 = x->curr_mouse_pt.y - txtheight - CONST_PTRACK_MAX_POINT_RADIUS;
		} else {
			x1 = x->curr_mouse_pt.x;
			y1 = x->curr_mouse_pt.y - txtheight;
		}
		if (x->curr_mouse_pt.x + txtwidth + 10 > rect.width)
			x1 = x->curr_mouse_pt.x - txtwidth;
		if (x->curr_mouse_pt.y - txtheight - 10 < 0) {
			y1 = x->curr_mouse_pt.y;
			if (x1 > x->curr_mouse_pt.x - txtwidth)
				x1 += 10;
		}

		if (x->mode == k_MODE_ONSET_WAVE)
			paint_line(g, build_jrgba(0.5, 0.5, 0.5, 1.), x->curr_mouse_pt.x, 0, x->curr_mouse_pt.x, rect.height, 0.5);
		else if (x->mode == k_MODE_RHYTHMOGRAM || x->mode == k_MODE_AUTOCORRELOGRAM)
			paint_line(g, build_jrgba(0.5, 0.5, 0.5, 1.), 0, x->curr_mouse_pt.y, rect.width, x->curr_mouse_pt.y, 0.5);
		else if (x->mode == k_MODE_RHYTHMOSCOPE || x->mode == k_MODE_AUTOCORRELATION) {
			double yy = rescale_with_slope(x->sampling_vals[this_idx_for_rhythmoscope_circle], 0, x->max_displayed_amplitude_rhythmoscope, rect.height, 0, 0);
			paint_line(g, build_jrgba(0.5, 0.5, 0.5, 1.), x->curr_mouse_pt.x, 0, x->curr_mouse_pt.x, rect.height, 0.5);
			paint_circle_filled(g, x->j_color, x->curr_mouse_pt.x, yy, 2.3);
			if (samples_graphical_delta_x >= 3) {
				double start_x = floor((x->curr_mouse_pt.x - min_pix)/samples_graphical_delta_x) * samples_graphical_delta_x + min_pix;
				paint_line(g, x->j_color, start_x, yy, start_x + samples_graphical_delta_x, yy, 1.7);
			}
		}	
		paint_filledrectangle(g, x->j_hintbgcolor, x1, y1, txtwidth, txtheight);
		write_text_simple(g, jf_legend, x->j_hintcolor, legend1, x1, y1, txtwidth + 20, txtheight + 20);
		if (legend2[0])
			write_text_simple(g, jf_legend, x->j_hintcolor, legend2, x1, y1 + txtheight - txtheight2, txtwidth + 20, txtheight + 20);
	}
	
	paint_border((t_object *)x, g, &rect, &x->j_bordercolor, 1., 4.);

	jfont_destroy_debug(jf_legend);
}

t_tsd_config *find_clicked_config(t_rhythmogram *x, t_pt pt, long *whatclicked)
{
	t_tsd_config *cfg = x->first_segment_config;
	for (cfg = x->first_segment_config; cfg; cfg = cfg->next) {
		if (is_pt_in_rectangle(pt, cfg->painting_rect)) {
			if (whatclicked) {
				if (fabs(pt.x - cfg->painting_rect.x) < 10 && fabs(pt.x - cfg->painting_rect.x) < cfg->painting_rect.width / 2.)
					*whatclicked = -1; // start
				else if (fabs(pt.x - (cfg->painting_rect.x + cfg->painting_rect.width)) < 10 && fabs(pt.x - (cfg->painting_rect.x + cfg->painting_rect.width)) < cfg->painting_rect.width / 2.)
					*whatclicked = 1; // end
				else
					*whatclicked = 0;
			}
			return cfg;
		}
	}
	return NULL;
}

void rhythmogram_mousemove(t_rhythmogram *x, t_object *patcherview, t_pt pt, long modifiers) {
	x->curr_mouse_pt = pt;
	
	if (x->mode == k_MODE_TS_DETECTOR && !(modifiers & eControlKey)) {
		long whatclicked = 0;
		t_tsd_config *cfg = find_clicked_config(x, pt, &whatclicked);
		if (cfg && whatclicked) {
			bach_set_cursor((t_object *)x, &x->mousecursor, patcherview, BACH_CURSOR_RESIZE_LEFTRIGHT);
		} else {
			bach_set_cursor((t_object *)x, &x->mousecursor, patcherview, BACH_CURSOR_DEFAULT);
		}
	} else {
		bach_set_cursor((t_object *)x, &x->mousecursor, patcherview, BACH_CURSOR_RESIZE_LEFTRIGHT);
	}
		
	if (x->show_hint){
		if (x->mode == k_MODE_RHYTHMOGRAM || x->mode == k_MODE_AUTOCORRELOGRAM || x->mode == k_MODE_PARTIAL_TRACKING || x->mode == k_MODE_TS_DETECTOR) {
			x->curr_hint_bpm = rescale_with_slope(pt.y, 0, x->height, x->max_displayed_bpm, 0, 0);
		} else if (x->mode == k_MODE_RHYTHMOSCOPE || x->mode == k_MODE_AUTOCORRELATION){
			x->curr_hint_bpm = rescale_with_slope(pt.x, 0, x->width, x->min_displayed_bpm, x->max_displayed_bpm, 0);
		}
		x->curr_hint_hz = x->curr_hint_bpm / 60;
		
		if (x->mode == k_MODE_RHYTHMOSCOPE || x->mode == k_MODE_AUTOCORRELATION){
			x->curr_hint_frame = 1;
			x->curr_hint_ms = 0;
		} else if (x->mode == k_MODE_RHYTHMOGRAM || x->mode == k_MODE_AUTOCORRELOGRAM){
			x->curr_hint_frame = x->tags_size <= 0 ? 0 : CLAMP(floor(rescale(pt.x, 0, x->width, 0, x->num_windows_in_history)), 0, x->tags_size - 1);
			x->curr_hint_ms = x->tags && x->tags_size > 0 ? x->tags[x->curr_hint_frame] : 0;
		} else if (x->mode == k_MODE_ONSET_WAVE){
			x->curr_hint_frame = 1;
			x->curr_hint_ms = 0;
//		} else if (x->mode == k_MODE_PARTIAL_TRACKING || x->mode == k_MODE_TS_DETECTOR){
		} else if (x->mode == k_MODE_PARTIAL_TRACKING){
			x->curr_hint_frame = x->tags_size <= 0 ? 0 : CLAMP(floor(rescale(pt.x, 0, x->width, 0, x->num_windows_in_history)), 0, x->tags_size - 1);
			x->curr_hint_ms = x->curr_hint_frame * x->winsize/x->oversampling;
		} else if (x->mode == k_MODE_TS_DETECTOR){
			long what = 0;
			x->curr_mouseover_tsd_segment = find_clicked_config(x, pt, &what);
			if (what != 0)
				x->curr_mouseover_tsd_segment = NULL;
		}
		jbox_redraw((t_jbox *) x);
	}
}

void rhythmogram_mouseenter(t_rhythmogram *x, t_object *patcherview, t_pt pt, long modifiers) {
	x->j_mouse_is_over = true;
	jbox_redraw((t_jbox *)x);
}

void rhythmogram_mouseleave(t_rhythmogram *x, t_object *patcherview, t_pt pt, long modifiers) {
	x->j_mouse_is_over = false;
	jbox_redraw((t_jbox *)x);
}


void trim_onsets_beginning(t_rhythmogram *x, t_llll *onsets, double new_start_ms)
{
	t_llllelem *elem;
	
	elem = onsets->l_head;
	while (elem) {
		t_llllelem *nextelem = elem->l_next;
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *ll = hatom_getllll(&elem->l_hatom);
			if (ll->l_tail && hatom_getdouble(&ll->l_tail->l_hatom) < new_start_ms)
				llll_destroyelem(elem);
			else if (ll->l_tail)
				break;
		} else {
			if (hatom_getdouble(&elem->l_hatom) < new_start_ms)
				llll_destroyelem(elem);
			else
				break;
		}
		elem = nextelem;
	}
}

void pad_onsets_beginning(t_rhythmogram *x, t_tsd_config *config, double new_start_ms)
{
	long num_divs = MAX(1, config->ratios.div);
	t_llll *onsets = config->onsets_ms;
	double div_period_ms = (60./config->tempo_div) * config->ratios.div * 1000./config->ratios.div;

	if (onsets && onsets->l_head) {
		double first_onset = 0;
		
		while (onsets->l_head && hatom_gettype(&onsets->l_head->l_hatom) != H_LLLL)
			llll_behead(onsets);
			
		if (onsets->l_head) {
			t_llll *ll = hatom_getllll(&onsets->l_head->l_hatom);
			double cur;

			first_onset = ll->l_head ? hatom_getdouble(&ll->l_head->l_hatom) : 0;
			cur = first_onset;

			while (cur > new_start_ms) {
				t_llll *newll = llll_get();
				long i;
				for (i = 0; i < num_divs; i++)
					llll_prependdouble(newll, cur -= div_period_ms, 0, WHITENULL_llll);
				llll_prependllll(onsets, newll, 0, WHITENULL_llll);
			}
		}
	}
}

void trim_onsets_end(t_rhythmogram *x, t_llll *onsets, double new_end_ms)
{
	t_llllelem *elem;
	
	elem = onsets->l_tail;
	while (elem) {
		t_llllelem *prevelem = elem->l_prev;
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *ll = hatom_getllll(&elem->l_hatom);
			if (ll->l_head && hatom_getdouble(&ll->l_head->l_hatom) > new_end_ms)
				llll_destroyelem(elem);
			else if (ll->l_head)
				break;
		} else {
			if (hatom_getdouble(&elem->l_hatom) > new_end_ms)
				llll_destroyelem(elem);
		}
		elem = prevelem;
	}
}

void pad_onsets_end(t_rhythmogram *x, t_tsd_config *config, double new_end_ms)
{
	long num_divs = MAX(1, config->ratios.div);
	t_llll *onsets = config->onsets_ms;
	double div_period_ms = (60./config->tempo_div) * config->ratios.div * 1000./config->ratios.div;

	if (onsets && onsets->l_tail) {
		double last_onset = 0;
		
		while (onsets->l_tail && hatom_gettype(&onsets->l_tail->l_hatom) != H_LLLL)
			llll_betail(onsets);
			
		if (onsets->l_tail) {
			t_llll *ll = hatom_getllll(&onsets->l_tail->l_hatom);
			double cur;

			last_onset = ll->l_tail ? hatom_getdouble(&ll->l_tail->l_hatom) : 0;
			cur = last_onset;

			while (cur < new_end_ms) {
				t_llll *newll = llll_get();
				long i;
				for (i = 0; i < num_divs; i++)
					llll_appenddouble(newll, cur += div_period_ms, 0, WHITENULL_llll);
				llll_appendllll(onsets, newll, 0, WHITENULL_llll);
			}
		}
	}
}



void rotate_onsets_and_force_add_div(t_rhythmogram *x, t_tsd_config *cfg, long meas_shift, long div_shift, long force_add_div, char and_complete_measures) 
{
	meas_shift = positive_mod(meas_shift, cfg->ratios.div);
	div_shift = positive_mod(div_shift, cfg->ratios.subdiv);

	if (force_add_div) {
		cfg->ratios.div = cfg->detected_ratios.div + force_add_div;
		ratios_to_ts(x, cfg);
		llll_flatten(cfg->onsets_ms, 0, 0);
		llll_groupllll(cfg->onsets_ms, cfg->ratios.div, 0);
	}

	if (meas_shift > 0) {
		long num_divs = cfg->ratios.div;
		double div_period_ms = (60./cfg->tempo_div) * 1000.;
		t_llll *fl;
		long i, num_start_single_els = 0, num_end_single_els = 0;
		t_llllelem *elem;

		// onsets are: (a b c) (d e f g h) (i j k l)
		// suppose shift = 2
		
		fl = llll_clone(cfg->onsets_ms);
		llll_flatten(fl, 0, 0); // fl is: a b c d e f g h i j k l
		llll_rot(fl, 0, 1, meas_shift); // fl is: c d e f g h i j k l a b 
		llll_reshape(fl, cfg->onsets_ms, NULL); // fl is: (c d e) (f g h i j) (k l a b) 
		
		// handling last llll
		if (fl->l_tail && hatom_gettype(&fl->l_tail->l_hatom) == H_LLLL)
			llll_splatter(fl->l_tail, LLLL_FREETHING_DONT);    // fl is: (c d e) (f g h i j) k l a b
		llll_rot(fl, 0, 1, -meas_shift);   // fl is: a b (c d e) (f g h i j) k l
		
		// completing start and end 
		elem = fl->l_head;
		while (elem && hatom_gettype(&elem->l_hatom) != H_LLLL) {
			num_start_single_els++;
			elem = elem->l_next;
		}
		elem = fl->l_tail;
		while (elem && hatom_gettype(&elem->l_hatom) != H_LLLL) {
			num_end_single_els++;
			elem = elem->l_prev;
		}
			
		if (and_complete_measures) {
		    if (num_start_single_els > 0) {
				double cursor = hatom_getdouble(&fl->l_head->l_hatom);
				for (i = num_start_single_els; i < num_divs; i++) 
					llll_prependdouble(fl, cursor -= div_period_ms, 0, WHITENULL_llll);
				num_start_single_els = num_divs;
			}
		    if (num_end_single_els > 0) {
				double cursor = hatom_getdouble(&fl->l_tail->l_hatom);
				for (i = num_end_single_els; i < num_divs; i++) 
					llll_appenddouble(fl, cursor += div_period_ms, 0, WHITENULL_llll);
				num_end_single_els = num_divs;
			}
		}
		
		if (num_start_single_els > 0) {
			t_llllelem *last_to_wrap = llll_getindex(fl, num_start_single_els, I_STANDARD);
			if (last_to_wrap) 
				llll_wrap_element_range(fl->l_head, last_to_wrap);
		}
		if (num_end_single_els > 0) {
			t_llllelem *first_to_wrap = llll_getindex(fl, -num_end_single_els, I_STANDARD);
			if (first_to_wrap) 
				llll_wrap_element_range(first_to_wrap, fl->l_tail);
		}
		
		llll_free(cfg->onsets_ms);
		cfg->onsets_ms = fl;
	}
	
	if (div_shift) {
		double subdiv_period_ms = (60./cfg->tempo_div) * 1000./cfg->ratios.subdiv;
		t_llllelem *elem, *subelem;
		for (elem = cfg->onsets_ms->l_head; elem; elem = elem->l_next) {
			if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
				t_llll *ll = hatom_getllll(&elem->l_hatom);
				for (subelem = ll->l_head; subelem; subelem = subelem->l_next) 
					hatom_setdouble(&subelem->l_hatom, hatom_getdouble(&subelem->l_hatom) + subdiv_period_ms * div_shift);
			} else
				hatom_setdouble(&elem->l_hatom, hatom_getdouble(&elem->l_hatom) + subdiv_period_ms * div_shift);
		}
	}
}

// extends the configuration from (detected_start_fr detected_end_fr) to (start_fr end_fr) 
// and take into account possible rotations
void rhythmogram_adjust_segment(t_rhythmogram *x, t_tsd_config *cfg) 
{
	double new_start_frame_onset, new_end_frame_onset;
	
	if (cfg->ratios.subdiv < 0)
		return;
	
	if (cfg->start_fr >= cfg->end_fr)
		cfg->start_fr = cfg->end_fr;
		
	if (!cfg->detected_onsets_ms || cfg->detected_onsets_ms->l_depth != 2)
		return;

	llll_clear(cfg->onsets_ms);
	llll_clone_upon(cfg->detected_onsets_ms, cfg->onsets_ms);

	if (cfg->force_barline_rot || cfg->force_div_rot || cfg->force_add_div)
		rotate_onsets_and_force_add_div(x, cfg, cfg->force_barline_rot, cfg->force_div_rot, cfg->force_add_div, true);

	new_start_frame_onset = (cfg->start_fr - 1) * x->winsize/x->oversampling;
	new_end_frame_onset = (cfg->end_fr - 1) * x->winsize/x->oversampling;

	// padding first, then trimming
	if (cfg->start_fr < cfg->detected_start_fr) 
		pad_onsets_beginning(x, cfg, new_start_frame_onset);
	if (cfg->end_fr > cfg->detected_end_fr) 
		pad_onsets_end(x, cfg, new_end_frame_onset);
	if (cfg->start_fr >= cfg->detected_start_fr) 
		trim_onsets_beginning(x, cfg->onsets_ms, new_start_frame_onset);
	if (cfg->end_fr <= cfg->detected_end_fr) 
		trim_onsets_end(x, cfg->onsets_ms, new_end_frame_onset);

	if (x->tsd_data) {
		llll_betail(x->tsd_data);
		append_segment_config_tsd_data(x);
	}
}

// revert the configuration to the detected frames (detected_start_fr detected_end_fr) to (start_fr end_fr) 
void rhythmogram_revert_cfg_extension(t_rhythmogram *x, t_tsd_config *cfg) 
{
	llll_clear(cfg->onsets_ms);
	llll_clone_upon(cfg->detected_onsets_ms, cfg->onsets_ms);
	cfg->start_fr = cfg->detected_start_fr;
	cfg->end_fr = cfg->detected_end_fr;
	cfg->ratios = cfg->detected_ratios;
	cfg->force_barline_rot = cfg->force_div_rot = cfg->force_add_div = 0;
	ratios_to_ts(x, cfg);
	
	if (x->tsd_data) {
		llll_betail(x->tsd_data);
		append_segment_config_tsd_data(x);
	}
}


void rhythmogram_mousedoubleclick(t_rhythmogram *x, t_object *patcherview, t_pt pt, long modifiers) 
{
	t_rect rect; 
	jbox_get_rect_for_view(&x->j_box.l_box.b_ob, patcherview, &rect);
	if (x->mode == k_MODE_TS_DETECTOR && x->tsd_data->l_head) {
		if (!(modifiers & eControlKey)) {
			t_tsd_config *clicked = find_clicked_config(x, pt, NULL);
			if (clicked && x->tsd_data && x->tsd_data->l_tail) {
				t_llllelem *llelem = llll_getindex(hatom_getllll(&x->tsd_data->l_tail->l_hatom), clicked->ID, I_STANDARD);
				t_llll *ll = hatom_getllll(&llelem->l_hatom);
				t_llll *cloned = llll_clone(ll);
				llll_prependsym(cloned, gensym("tsdconfig"), 0, WHITENULL_llll);
				llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 7, cloned);
				llll_free(cloned);
				
				// sending messages to roll
				if (true) { // ALWAYS
					if (x->autoclear_roll_markers) {
						t_llll *clear = llll_get();
						llll_appendsym(clear, gensym("clearmarkers"), 0, WHITENULL_llll);
						llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 8, clear);
						llll_free(clear);
					}
					
					t_llll *tempo = llll_getindex(ll, 6, I_STANDARD)->l_hatom.h_w.w_llll;
					t_llll *timesig = llll_getindex(ll, 2, I_STANDARD)->l_hatom.h_w.w_llll;
					t_llll *ratios = llll_getindex(ll, 3, I_STANDARD)->l_hatom.h_w.w_llll;
					t_llll *onsets = llll_getindex(ll, 8, I_STANDARD)->l_hatom.h_w.w_llll;
					double first_onset = onsets && onsets->l_head ? (hatom_gettype(&onsets->l_head->l_hatom) == H_LLLL ? 
																	 (hatom_getllll(&onsets->l_head->l_hatom)->l_size > 0 ? 
																	  hatom_getdouble(&onsets->l_head->l_hatom.h_w.w_llll->l_head->l_hatom) : 0) : 
																	 hatom_getdouble(&onsets->l_head->l_hatom)) : 0;
					long num_divs = hatom_getlong(&ratios->l_head->l_hatom);
					long num_subdivs = hatom_getlong(&ratios->l_tail->l_hatom);

					// 1. sending the tempo
					t_llll *tempoll = llll_get();
					llll_appendllll_clone(tempoll, tempo, 0, WHITENULL_llll, NULL);
					llll_prependsym(tempoll, _llllobj_sym_tempo, 0, WHITENULL_llll);
					llll_prependsym(tempoll, _llllobj_sym_tempo, 0, WHITENULL_llll); // marker name is still "tempo"
					llll_prependdouble(tempoll, first_onset, 0, WHITENULL_llll);
					llll_prependsym(tempoll, gensym("addmarker"), 0, WHITENULL_llll);
					llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 8, tempoll);
					llll_free(tempoll);
					
					// 2. sending the markers
					char need_to_use_timesig = false;
					for (llelem = onsets->l_head; llelem; llelem = llelem->l_next) {
						if (hatom_gettype(&llelem->l_hatom) == H_LLLL) {
							t_llll *measll = hatom_getllll(&llelem->l_hatom);
							t_llllelem *subelem;
							for (subelem = measll->l_head; subelem; subelem = subelem->l_next) {
								t_llll *thisll = llll_get();
								double this_onset = hatom_getdouble(&subelem->l_hatom);
								if (subelem == measll->l_head) {
									need_to_use_timesig |= (llelem == onsets->l_head || measll->l_size != num_divs);
									if (need_to_use_timesig) {
										if (measll->l_size == num_divs) { // correct measure
											llll_appendllll_clone(thisll, timesig, 0, WHITENULL_llll, NULL);
											need_to_use_timesig = false;
										} else {
											t_tsd_config *cfg = (t_tsd_config *)bach_newptr(sizeof(t_tsd_config));
											cfg->ratios.div = measll->l_size;
											cfg->ratios.subdiv = num_subdivs;
											ratios_to_ts(x, cfg);
											llll_appendllll(thisll, get_timesignature_as_llll(&cfg->ts), 0, WHITENULL_llll);
											need_to_use_timesig = true; // we need to reuse time signature for next barline as well
											bach_freeptr(cfg);
										}
										llll_prependsym(thisll, _llllobj_sym_timesig, 0, WHITENULL_llll);
										llll_prependsym(thisll, _llllobj_sym_barline, 0, WHITENULL_llll); // marker name is "barline"
										llll_prependdouble(thisll, this_onset, 0, WHITENULL_llll);
										llll_prependsym(thisll, gensym("addmarker"), 0, WHITENULL_llll);
										llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 8, thisll);
										llll_free(thisll);
									} else {
										llll_prependsym(thisll, _llllobj_sym_barline, 0, WHITENULL_llll);
										llll_prependsym(thisll, _llllobj_sym_barline, 0, WHITENULL_llll); // marker name is "barline"
										llll_prependdouble(thisll, this_onset, 0, WHITENULL_llll);
										llll_prependsym(thisll, gensym("addmarker"), 0, WHITENULL_llll);
										llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 8, thisll);
										llll_free(thisll);
									}
								} else {
									llll_prependsym(thisll, _llllobj_sym_division, 0, WHITENULL_llll);
									llll_prependsym(thisll, _llllobj_sym_division, 0, WHITENULL_llll); // marker name is "division"
									llll_prependdouble(thisll, this_onset, 0, WHITENULL_llll);
									llll_prependsym(thisll, gensym("addmarker"), 0, WHITENULL_llll);
									llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 8, thisll);
									llll_free(thisll);
								}
							}
						}
					}
				}
				
			}
		}
	}
}


void rhythmogram_mousedown(t_rhythmogram *x, t_object *patcherview, t_pt pt, long modifiers){
	t_rect rect; 
	jbox_get_rect_for_view(&x->j_box.l_box.b_ob, patcherview, &rect);

	evnum_incr();

	x->segment_config_has_been_dragged = 0;
	x->selected_config = NULL;

	if (x->mode == k_MODE_TS_DETECTOR && x->tsd_data->l_head) {
		if (!(modifiers & eControlKey)) 
			x->selected_config = find_clicked_config(x, pt, &x->mousedown_config_pos);
	}
	jbox_redraw((t_jbox *)x);
}

void rhythmogram_mouseup(t_rhythmogram *x, t_object *patcherview, t_pt pt, long modifiers){
	if (x->segment_config_has_been_dragged) {
		choose_painting_lines_for_segments(x);
		jbox_redraw((t_jbox *)x);
	}
	x->mousedown_config_pos = 0;
}

// 0-based
long rel_xpos_to_frame_number(t_rhythmogram *x, double rel_xpos){
	long val = CLAMP(round(rel_xpos * x->num_windows_in_history), 0, x->num_windows_in_history);
	return val;
}

void rhythmogram_mousedrag(t_rhythmogram *x, t_object *patcherview, t_pt pt, long modifiers){
	if (x->mode == k_MODE_TS_DETECTOR && x->tsd_data->l_head) {
		t_rect rect; 
		double rel_xpos;
		
		jbox_get_rect_for_view(&x->j_box.l_box.b_ob, patcherview, &rect);
		rel_xpos = pt.x / ((double) rect.width);
		if (x->selected_config && x->mousedown_config_pos == -1) {
			// drag left head
			long new_left_frame = CLAMP(rel_xpos_to_frame_number(x, rel_xpos) + 1, 1, x->selected_config->end_fr);
			x->selected_config->start_fr = new_left_frame;
		} else if (x->selected_config && x->mousedown_config_pos == 1) {
			// drag right head
			long new_right_frame = CLAMP(rel_xpos_to_frame_number(x, rel_xpos), x->selected_config->start_fr, x->num_windows_in_history);
			x->selected_config->end_fr = new_right_frame;
		}
		if (x->selected_config) {
			rhythmogram_adjust_segment(x, x->selected_config);
			x->segment_config_has_been_dragged = 1;
			jbox_redraw((t_jbox *) x);
		}
	}
}

long rhythmogram_key(t_rhythmogram *x, t_object *patcherview, long keycode, long modifiers, long textcharacter){
	if (x->mode == k_MODE_TS_DETECTOR && x->tsd_data->l_head && x->selected_config) {
		if (keycode == JKEY_ESC) {
			rhythmogram_revert_cfg_extension(x, x->selected_config);
			x->segment_config_has_been_dragged = true;
			jbox_redraw((t_jbox *)x);
			return 1;
		} else if (textcharacter == 'r') {
			if (modifiers & eShiftKey)
				x->selected_config->force_barline_rot -= 1;
			else
				x->selected_config->force_barline_rot += 1;
			x->selected_config->force_barline_rot = positive_mod(x->selected_config->force_barline_rot, x->selected_config->ratios.div);
			rhythmogram_adjust_segment(x, x->selected_config);
			jbox_redraw((t_jbox *)x);
			return 1;
		} else if (textcharacter == 'd') {
			if (modifiers & eShiftKey)
				x->selected_config->force_div_rot -= 1;
			else
				x->selected_config->force_div_rot += 1;
			x->selected_config->force_div_rot = positive_mod(x->selected_config->force_div_rot, x->selected_config->ratios.subdiv);
			rhythmogram_adjust_segment(x, x->selected_config);
			jbox_redraw((t_jbox *)x);
			return 1;
		} else if (textcharacter == '+' || textcharacter == '-') {
			x->selected_config->force_add_div += (textcharacter == '+' ? 1 : -1);
			rhythmogram_adjust_segment(x, x->selected_config);
			ratios_to_ts(x, x->selected_config);
			jbox_redraw((t_jbox *)x);
			return 1;
		}
	}
	return 0;
}

void initialize_surface(t_rhythmogram *x, long height){
	if (x->surface)
		jgraphics_surface_destroy(x->surface);
	
	x->scroll_count = 0;
	x->surface = jgraphics_image_surface_create(JGRAPHICS_FORMAT_ARGB32, x->num_windows_in_history, height);
	
	if (x->tags)
		bach_freeptr(x->tags);
	
	x->tags_size = x->num_windows_in_history;
	x->tags = (double *) bach_newptr(x->num_windows_in_history * sizeof(double));
}

long rhythmogram_oksize(t_rhythmogram *x, t_rect *newrect)
{
	x->width = newrect->width;
	x->height = newrect->height;
	
	if (x->fixed_num_windows_in_history == 0){
		x->num_windows_in_history = x->width;
		initialize_surface(x, x->num_sampling_vals);	
	}
	
	return 0;
}

