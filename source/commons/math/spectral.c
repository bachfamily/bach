/*
 *  spectral.c
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License
 * as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, see <https://www.gnu.org/licenses/>.
 *
 */

/**
	notation_spectral.c - spectral functions for notation objects
*/

#include "foundation/bach.h"
#include "math/spectral.h" // notation.h is inside here



/// ******************************
/// KISS FFT EXTENSION
/// ******************************

kiss_fft_scalar cpx_euclidean_dist(long num_entries, kiss_fft_cpx *vec1, kiss_fft_cpx *vec2)
{
	kiss_fft_scalar res = 0;
	long i;
	for (i = 0; i < num_entries; i++)
		res += sqrt((vec1[i].r - vec2[i].r) * (vec1[i].r - vec2[i].r) + (vec1[i].i - vec2[i].i) * (vec1[i].i - vec2[i].i));
	return res;
} 

kiss_fft_cpx cpx_product(kiss_fft_cpx num1, kiss_fft_cpx num2)
{
	kiss_fft_cpx res;
	res.r = num1.r * num2.r - num1.i * num2.i;
	res.i = num1.r * num2.i + num1.i * num2.i;
	return res;
}

kiss_fft_cpx cpx_conjugate(kiss_fft_cpx num)
{
	kiss_fft_cpx res;
	res.r = num.r;
	res.i = -num.i;
	return res;
}

kiss_fft_cpx polar_to_cpx(double radius, double angle)
{
	kiss_fft_cpx res;
	res.r = radius * cos(angle);
	res.i = radius * sin(angle);
	return res;
}

kiss_fft_scalar get_cpx_ampli(kiss_fft_cpx num)
{
	return sqrt(num.r * num.r + num.i * num.i);
}

kiss_fft_scalar get_cpx_phase(kiss_fft_cpx num)
{
	kiss_fft_scalar phase;
	
    if (num.r == 0)
        phase = 0;
	else if (num.r > 0)
		phase = atan(num.i/num.r);
	else
		phase = atan(num.i/num.r) + PI;
	
	if (phase < 0)
		phase += TWOPI;
		
	return phase;
}



void windowize(long nfft, e_win_types window_type, const kiss_fft_cpx *fin, kiss_fft_cpx *fout)
{
	long i;
	long nfft_minus_one = nfft - 1;
	double weight_windowing = 1.;
	for (i = 0; i < nfft; i++) {
		if (window_type == k_WIN_HANNING) {
			weight_windowing = 0.5 * (1 - cos(TWOPI * i/nfft_minus_one));
		} else if (window_type == k_WIN_HAMMING) {
			weight_windowing = 0.54 - 0.46 * cos(TWOPI * i/nfft_minus_one);
		} else if (window_type == k_WIN_COSINE) { 
			weight_windowing = cos((((double)i)/nfft_minus_one - 0.5) * PI);
		} else if (window_type == k_WIN_TRIANGULAR) {
			weight_windowing = 2/nfft_minus_one * (nfft_minus_one/2. - fabs(i - nfft_minus_one/2.));
		} else {
			weight_windowing = 1.;
		}
		fout[i].r = fin[i].r * weight_windowing;
		fout[i].i = fin[i].i * weight_windowing;
	}
}


// inplace on *wave
void normalize(long num_samples, double *wave, double max_amplitude_to_set)
{
	long i;
	double maximum = 0;
	for (i = 0; i < num_samples; i++) {
		double abs_wave_i = fabs(wave[i]);
		if (abs_wave_i > maximum)
			maximum = abs_wave_i;
	}

	if (maximum > 0) {
		double multiplier = max_amplitude_to_set / maximum;
		for (i = 0; i < num_samples; i++)	
			wave[i] *= multiplier;
	}
}


void bach_fft_cartesian_complex(int nfft, char is_inverse_fft, const kiss_fft_cpx *fin, kiss_fft_cpx *fout, bool unitary)
{
	int i;
	kiss_fft_cfg cfg = kiss_fft_alloc(nfft, is_inverse_fft, NULL, NULL);
	
    kiss_fft(cfg, fin, fout);
	
    if (unitary) {
        double s = sqrt(nfft);
        for (long i = 0; i < nfft; i++) {
            fout[i].r /= s;
            fout[i].i /= s;
        }
    } else if (is_inverse_fft){	// apparently there's a bug in the library...
		for (i = 0; i < nfft; i++) {
			fout[i].r /= nfft;
			fout[i].i /= nfft;
		}
	}
	free(cfg);
}

// ampli and phase must be already initialized
// this makes sense if you do it just once, otherwise use the _kiss versions
void bach_fft(int nfft, char is_inverse_fft, const kiss_fft_cpx *fin, double *ampli, double *phase, bool unitary)
{
	int i;
	kiss_fft_cpx *fout = (kiss_fft_cpx *) bach_newptr(nfft * sizeof (kiss_fft_cpx));
	bach_fft_cartesian_complex(nfft, is_inverse_fft, fin, fout, unitary);

	// splitting freq and phase
	for (i = 0; i < nfft; i++) {
		ampli[i] = get_cpx_ampli(fout[i]);
		phase[i] = get_cpx_phase(fout[i]);
	}
	bach_freeptr(fout);
}


void bach_rfft(int nfft, const double *input, double *ampli, double *phase, bool unitary)
{
    int i;
    kiss_fft_cpx *fin = (kiss_fft_cpx *) bach_newptr(nfft * sizeof (kiss_fft_cpx));
    kiss_fft_cpx *fout = (kiss_fft_cpx *) bach_newptr(nfft * sizeof (kiss_fft_cpx));
    
    for (i = 0; i < nfft; i++) {
        fin[i].r = input[i];
        fin[i].i = 0.;
    }
    
    bach_fft_cartesian_complex(nfft, false, fin, fout, unitary);
    
    // splitting freq and phase
    for (i = 0; i < nfft; i++) {
        ampli[i] = get_cpx_ampli(fout[i]);
        phase[i] = get_cpx_phase(fout[i]);
    }
    bach_freeptr(fin);
    bach_freeptr(fout);
}

void bach_irfft(int nfft, const double *input_ampli, const double *input_phase, double *output, bool unitary)
{
    int i;
    kiss_fft_cpx *fin = (kiss_fft_cpx *) bach_newptr(nfft * sizeof (kiss_fft_cpx));
    kiss_fft_cpx *fout = (kiss_fft_cpx *) bach_newptr(nfft * sizeof (kiss_fft_cpx));
    
    for (i = 0; i < nfft; i++) {
        fin[i].r = input_ampli[i]*cos(input_phase[i]);
        fin[i].i = input_ampli[i]*sin(input_phase[i]);
    }
    
    bach_fft_cartesian_complex(nfft, true, fin, fout, unitary);
    
    // splitting freq and phase
    for (i = 0; i < nfft; i++) {
        output[i] = fout[i].r;
    }
    bach_freeptr(fin);
    bach_freeptr(fout);
}

// use this one if you want to make fft repeatedly: this does not allocate memory (you do, outside)
void bach_fft_kiss(kiss_fft_cfg cfg, int nfft, char is_inverse_fft, const kiss_fft_cpx *fin, kiss_fft_cpx *fout, bool unitary)
{
    kiss_fft(cfg, fin, fout);
    
    if (unitary) {
        double s = sqrt(nfft);
        for (long i = 0; i < nfft; i++) {
            fout[i].r /= s;
            fout[i].i /= s;
        }
    } else if (is_inverse_fft){
        // apparently kissfft won't normalize by the number of samples...
        for (long i = 0; i < nfft; i++) {
            fout[i].r /= nfft;
            fout[i].i /= nfft;
        }
    }
}




// freq_mapped_acf must be already inizialized and sized at least nfft
void bach_fm_acf(int nfft, const kiss_fft_cpx *fin, double sample_rate, double *freq_mapped_acf, char rectify, char filter_last_peak, bool unitary)
{
	// following TIME VARIABLE TEMPO DETECTION AND BEAT MARKING (Geoffroy Peeters)
	
	kiss_fft_cpx *fout = (kiss_fft_cpx *) bach_newptr (nfft * sizeof(kiss_fft_cpx));
	kiss_fft_cpx *prod = (kiss_fft_cpx *) bach_newptr (nfft * sizeof(kiss_fft_cpx));
	bach_fft_cartesian_complex(nfft, false, fin, fout, unitary);
	double *ac_ampli = (double *) bach_newptr(nfft * sizeof(double));
	double *ac_phase = (double *) bach_newptr(nfft * sizeof(double));
	long i;
	
	double *f = (double *) bach_newptr(nfft * sizeof(double)); // frequences corresponding to fft bins
	double *lags = (double *) bach_newptr(nfft * sizeof(double)); // time lags corresponding to samples
	double *idx_for_interp = (double *) bach_newptr(nfft * sizeof(double)); // indices of the bins in which we will have to interpolate the time-lagged acf

	for (i = 0; i < nfft; i++) {
		f[i] = i * sample_rate/(nfft - 1);
		lags[i] = i/sample_rate;
		idx_for_interp[i] = sample_rate/f[i];
	}

	for (i = 0; i < nfft; i++) 
		prod[i] = cpx_product(fout[i], cpx_conjugate(fout[i]));

	bach_fft(nfft, true, prod, ac_ampli, ac_phase, unitary);
	
	// since prod[i] is mirrored, the outcome will be real!
	// so we put it real, and change sign if needed
	for (i = 0; i < nfft; i++){
		if (ac_phase[i] > PIOVERTWO && ac_phase[i] < 3 * PIOVERTWO) 
			ac_ampli[i] = -fabs(ac_ampli[i]);
		ac_phase[i] = 0;
	}

	
	// now we must interpolate ac_ampli to obtain the frequency mapped acf
	for (i = 0; i < nfft; i++){
		// linear interpolation, for now:
		double idx = CLAMP(idx_for_interp[i], 0, nfft - 1);
		long round_idx = round(idx);
		if (idx == 0 || idx == nfft - 1 || round_idx == idx)
			freq_mapped_acf[i] = ac_ampli[round_idx];
		else {
			long lower = floor(idx), upper = lower + 1;
			freq_mapped_acf[i] =  (upper - idx) * ac_ampli[lower] + (idx - lower) * ac_ampli[upper]; 
		}
	}
	
	if (rectify) {
		for (i = 0; i < nfft; i++)
			if (freq_mapped_acf[i] < 0)
				freq_mapped_acf[i] = 0;
	}
	
	if (filter_last_peak) {	// filtering first acf peak = last freq_mapped_acf peak (corresponding to very high frequencies, and very small time lags
		for (i = nfft - 1; i >= 0; i--) {
			if (freq_mapped_acf[i] > 0)
				freq_mapped_acf[i] = 0;
			else
				break;
		}
	}
	bach_freeptr(fout);
	bach_freeptr(prod);
	bach_freeptr(ac_ampli);
	bach_freeptr(ac_phase);
	bach_freeptr(f);
	bach_freeptr(lags);
	bach_freeptr(idx_for_interp);
}




void unwrap_phase(int num_samples, double *phases, double **new_phases)
{
	if (num_samples > 0) {
		long i;
		double toadd = 0;

		*new_phases = (double *)bach_newptr(num_samples * sizeof(double));
		(*new_phases)[0] = phases[0];

		for (i = 1; i < num_samples; i++){
			double diff = (phases[i] + toadd) - (*new_phases)[i-1];
			while (diff > PI){
				toadd -= TWOPI;
				diff -= TWOPI;
			}
			while (diff < -PI){
				toadd += TWOPI;
				diff += TWOPI;
			} 
			(*new_phases)[i] = phases[i] + toadd;
		}
	}
}


// leave NULL fft_phases if you don't need phase estimation.
// max_num_peaks is the maximum number of peaks to be returned; if max_num_peaks <= 0 --> there's no max
// min_peaks_ampli is the minimum amplitude of the peaks to be found, if max_peaks_ampli <= 0 --> there's no minimum
// min_relative_peaks_ampli is the minimum relative amplitude (with respect to the higher peak) of the peaks to be found, if min_relative_peaks_ampli <= 0 --> there's no minimum
void find_peaks_for_frame(int num_bins, double *fft_amplis, double *fft_phases, long max_num_peaks, double min_peaks_ampli, double min_relative_peaks_ampli,
					long *num_found_peaks, double **peak_bins, double **peak_amplis, double **peak_phases, long **peak_bin_widths, 
					char reduce_to_half_spectrum)
{
	long i;
	long nfft = num_bins;
	long nfft_to_use = reduce_to_half_spectrum ? ceil(nfft / 2.) : nfft;
	double *ampli_wk = (double *) bach_newptr(nfft_to_use * sizeof(double)); 	// working-copy of the amplitudes
	double *max_bin = (double *) bach_newptr(nfft_to_use * sizeof(double));
	double *max_ampli = (double *) bach_newptr(nfft_to_use * sizeof(double));
	double *max_phase = (double *) bach_newptr(nfft_to_use * sizeof(double));
	double *max_bin_widths = (double *) bach_newptr(nfft_to_use * sizeof(double)); // will contain the found maximum (which cannot be more than nfft, of course)
	double *done = (double *) bach_newptr(nfft_to_use * sizeof(double)); // will contain data on each sample: do we have already found a peak containing the sample?

	double *phases_wk = NULL;	// working-copy of the phases (we'll unwrap them)
	long num_found = 0; // current number of found maxima
	
	// copying amplitudes to the working array
	for (i = 0; i < nfft_to_use; i++) {
		ampli_wk[i] = fft_amplis[i];
		done[i] = false;
	}


	// unwrapping phase 
	// https://ccrma.stanford.edu/~jos/sasp/Matlab_Unwrapping_Spectral_Phase.html#sec:unwrapml
	if (fft_phases)
		unwrap_phase(nfft_to_use, fft_phases, &phases_wk);


	if (max_num_peaks <= 0)
		max_num_peaks = nfft_to_use;
		
	while (num_found < max_num_peaks) {
		// find the best maximum
		double this_ampli_max = 0;
		long this_max_idx = -1;
		long j;
		for (i = 1; i < nfft_to_use - 1; i++) {	// we ignore first and last element: we would not be able to interpolate with the parabole 
			if (!done[i] && ampli_wk[i] >= this_ampli_max) {
				this_ampli_max = ampli_wk[i];
				this_max_idx = i;
			}
		}
		
		if (this_max_idx < 0)
			break;
		
		long right_width = 0, left_width = 0;
		for (j = this_max_idx + 1; j < nfft_to_use; j++) {
// 			if (ampli_wk[j] <= ampli_wk[j-1] && ampli_wk[j] >= 0) // ampli_wk[j] < 0 is for an already deleted peak
 			if (ampli_wk[j] <= ampli_wk[j-1] && !done[j]) 
				right_width++;
			else
				break;
		}
		for (j = this_max_idx - 1; j >= 0; j--) {
//			if (ampli_wk[j] <= ampli_wk[j+1] && ampli_wk[j] >= 0)
			if (ampli_wk[j] <= ampli_wk[j+1] && !done[j])
				left_width++;
			else
				break;
		}

		max_bin_widths[num_found] = MIN(left_width, right_width);
		
		// estimating maximum with parabolic interpolation of bins (this_max_idx-1, this_max_idx, this_max_idx+1)
		// see https://ccrma.stanford.edu/~jos/parshl/Peak_Detection_Steps_3.html for notation
		double alpha = ampli_wk[this_max_idx-1];
		double beta = ampli_wk[this_max_idx];
		double gamma = ampli_wk[this_max_idx+1];
		
		if (alpha <= beta && beta >= gamma && beta > 0) {
			double p = 0.5 * ((alpha - gamma)/(alpha - 2*beta + gamma));
			
			double bin = this_max_idx + p;
			double ampli = beta - 0.25 * (alpha - gamma) * p;
			
			if (min_peaks_ampli > 0 && ampli < min_peaks_ampli)
				break;
			
			if (num_found > 0 && min_relative_peaks_ampli > 0 && ampli < max_ampli[0] * min_relative_peaks_ampli)
				break;
			
			max_bin[num_found] = bin;
			max_ampli[num_found] = ampli;
			
			// estimating phase
			if (fft_phases) {
				max_phase[num_found] = phases_wk[this_max_idx] * fabs(1 - fabs(p)) + (p > 0 ? phases_wk[this_max_idx+1] : phases_wk[this_max_idx-1]) * fabs(p);
				while (max_phase[num_found] < 0)
					max_phase[num_found] += TWOPI;
				while (max_phase[num_found] > TWOPI)
					max_phase[num_found] -= TWOPI;
			}
		}
	
		// deleting current peak
		for (j = this_max_idx - left_width; j <= this_max_idx + right_width; j++)
			done[j] = true; // was: ampli_wk[j] = -1;

		num_found++;
	}
	
	*num_found_peaks = num_found;
	if (num_found) {
		*peak_bins = (double *)bach_newptr(num_found * sizeof(double));
		*peak_amplis = (double *)bach_newptr(num_found * sizeof(double));
		if (fft_phases)
			*peak_phases = (double *)bach_newptr(num_found * sizeof(double));
		*peak_bin_widths = (long *)bach_newptr(num_found * sizeof(long));
		for (i = 0; i < num_found; i++){
			(*peak_bins)[i] = max_bin[i];
			(*peak_amplis)[i] = max_ampli[i];
			if (fft_phases)
				(*peak_phases)[i] = max_phase[i];
			(*peak_bin_widths)[i] = max_bin_widths[i];
		}
	}
	
	if (phases_wk)
		bach_freeptr(phases_wk);
	bach_freeptr(ampli_wk);
	bach_freeptr(max_bin);
	bach_freeptr(max_ampli);
	bach_freeptr(max_phase);
	bach_freeptr(max_bin_widths);
	bach_freeptr(done);
}


/*
void test_kiss_fft()
{
	kiss_fft_cfg cfg = kiss_fft_alloc(16, false, NULL, NULL);
	kiss_fft_cfg icfg = kiss_fft_alloc(16, true, NULL, NULL);
	kiss_fft_cpx cx_in[16];
	kiss_fft_cpx cx_out[16];
	kiss_fft_cpx cx_in2[16];
	long i;
	
	srand(time(NULL));
	for (i = 0; i < 16; i++) {
		cx_in[i].r = (rand() % 100)/100.;
		cx_in[i].i = (rand() % 100)/100.;
	}
	
	kiss_fft(cfg, cx_in, cx_out);
	kiss_fft(icfg, cx_out, cx_in2);
	
	for (i = 0; i < 16; i++){
		cx_in2[i].r /= 16.;
		cx_in2[i].i /= 16.;
	}
	
	kiss_fft_scalar dist = cpx_euclidean_dist(16, cx_in, cx_in2);
	post("dist: %.2f", dist);
	
	free(cfg);
}
*/

