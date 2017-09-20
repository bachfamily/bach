/**
	@file	bach_doc_commons_dg.h
	@brief	Common documentation about some basic concepts and syntaxes of bach.
	
	by Daniele Ghisi
*/

	
#define BACH_DOC_REGULARITYBOXES
	//	Regularity boxes are a concept that helps bach.quantize quantizing properly by preserving untouched important beat positions. 
	//  Indeed, bach.quantize's algorithm is a box-based algorithm: bach.quantize first cuts a measure into different boxes (for instance having widths of 1/4 each, but the default boxes depend
	//  on the time signature in general), and then performs the quantization in each box. This allows things falling almost exactly on box boundaries to be kept exactly on the box boundaries,
	//  so that they may not float due to quantization errors. You can assign custom boxes by explicitely saying which boxes you want. 
	//  You have to give a llll for each voice (in our case, just one), containing for each measure: either a rational number, which represents the 
	//  width of each box (e.g. <b>1/8</b>) and which will be repeated; or a list, containing explicitely the box width for each box, e.g. <b>(1/4 3/4)</b>.
	//  This has to be done for each voice, so that for instance a list like <b>(1/8 2/4) () ((1/4 3/4) 1/8)</b> sets to 1/8 the boxes for firt measure of first voice, 
	//  to 2/4 the boxes for second measure of first voice (and all the possibly following ones); leaves by default the boxes of second voice; sets explicitely to <b>(1/4 3/4)</b> the boxes for
	//  the first measure of the third voice and then to 1/8 for all the following ones.
	//  <br /> <br />
	
#define BACH_DOC_SETTHEORY_MODULO
	// 	In the standard framework, the modulo is the number of subdivision of the octave (represented as a circle). The modulo is thus the number of
	//	points in this circle. The default and most common modulo is 12 (corresponding to semitonal grid). Modulo 24 is the quartertone grid, and so on.
	//  <br /> <br />

#define BACH_DOC_SETTHEORY_PC_AND_PCSET
	//  A pitch-class set is a plain collection of pitch-classes. A pitch class is nothing but the representative of a set of pitches.
	//  Traditionally, it corresponds to the concept of "note", once we abstract it from its octave. 
	//  For instance, the semitonal framework (when the modulo is 12), all the C belong to the same pitch-class
	//  which will be named 0 = {..., C-1, C0, C1, C2, C3, C4, C5, ...}. The pitch-class 1 will be the one containing all C#'s (or Db's); pitch-class
	//  2 will contain all D's, and so on. One will use to name pitch class numbers from 0 to the modulo - 1: indeed, with modulo = 12, pitch-class 12 will coincide
	//  with pitch-class 0 (it'll be the C one octave higher). One can thus think at pitch-classes as equally spaced points on a clock, and transposing
	//  means rotating them on the clock. A pitch class set is thus represented just by a plain list of pitch classes, such <b>0 4 7</b>, representing the
	//  C major chord. Notice that this coincides with any other representation such as <b>12 4 19</b> or <b>0 -8 -5</b>, but the canonical form, where numbers
	//  are from 0 to the modulo-1 is always preferred. Also for pitch-class sets the order of elements is immaterial, and thus
	//  <b>0 4 7</b> or <b>4 0 7</b> or <b>7 4 0</b> will all represent the same set.
	//  On the other hand a pitch-class (as an abstract concept) can be used to represent things other than pitches, 
	//  as for instance temporal position in a rhythmic pattern (loop) having a certain number (the modulo) of equally spaced elements.
	//  <br /> <br />

#define BACH_DOC_SETTHEORY_GROUPS
	// 	In Set Theory, two pitch-class sets are often considered to be "the same" when they are linked by the action of some simple transformation.
	//  For instance, the sets <b>0 1 4</b> and <b>2 3 6</b> are linked by a transposition of 2 (corresponding, on the clock diagram, to a rotation of 2 steps).
	//	Such "simple transformations" usually form a group. One thus usually needs to choose a group to determine a framework; this group will entail
	//  the concept of "copy" of a pitch-class set: which is any other pitch-class set obtained by the action of a transformation of the group.
	//	For instance, if our group is the group of transposition, <b>2 3 6</b> is a copy of <b>0 1 4</b>, and viceversa. <br />
	//  The most common groups of such form in increasing nesting are: <br />
	//	- the group of transposition: formed by all the transposition by a certain amount, and there are only 12 transposition if our modulo is 12, or
	//  in general n transposition if our modulo is n (the mathemathicians would say that such group is isomorphic to the cyclic group Z_n).
	//	For instance, a C major chord is the same as a D major chord, with respect to this group, but it is NOT the same as a C minor chord. <br />
	//	- the group of transposition and inversions: formed by all the transposition of the previous group, plus all the combination of such transposition with
	//  inversions, i.e. reflection with respect to any axis on the clock diagram. If our modulo is n, this group has 2n elements (the mathemathicians 
	//	would say that such group is isomorphic to the dihedral group D_n).
	//  For instance, a C major chord is the same as a D major chord, with respect to this group, and also the same as a C minor chord. <br />
	//	- the affine group of transposition, inversions, and multiplications: this group (here things get a little bit more complicated...) is formed
	//	by all the elements of the previous group plus we add the transformation multiplying each pitch class by a certain number k (prime with the modulo).
	//  Classical multiplications, with modulo = 12, are M_5 (multiplication by 5) and M_7 (multiplication by 7).
	//  For instance, our <b>0 4 7</b> C major chord is the same as <b>0 8 11</b>, since 5 * (0 4 7) = (0 20 35) = (0 8 11). <br />
	//  Up to the group of transposition and inversion, the interval vector of a pitch-class set is preserved. The affine group does not preserve the interval vector.
	//  <br /> <br />

#define BACH_DOC_SETTHEORY_PRIMEFORMORDERINGCRITERION
	//	The prime form is always defined to be the "smallest" copy of a given set. This definition depends on the ordering one chooses.
	//  Two ordering are supported by bach: <br />
	//  <m>Lexicographic</m>: the prime form is the "smallest" copy of the set lexicographically (numbers are compared left to right).
	//	For instance <b>0 1 5 11</b> is preferred to <b>0 6 7 8</b>. <br />
	//  <m>Compactness First</m>: the lexicographic clause is secondary: primarily the prime form is chosen among the "most compact" prime forms,
	//  For instance <b>0 6 7 8</b> is preferred to its transposed <b>0 1 5 11</b>, although it is not preferred to its other transposed <b>0 1 2 6</b>.
	//  <br /> <br />

#define BACH_DOC_MATRIXCALCULUS_MATRIX
	// 	In the bach environment, a matrix is just a llll having depth two, whose first-level sublllls are the rows of the matrix.
	//  For instance the matrix <b>(1 0 0) (0 1 0) (0 0 1)</b> is the 3 by 3 identity matrix. A "good" matrix is supposed to be well formed,
	//  i.e. all its rows must have the same length. A matrix is square if the length of the rows (which is the number of columns) is the same 
	//  as the number of rows.
	//  <br /> <br />

#define BACH_DOC_TONEDIVISION
	// 	In the bach environment, the tone division defines the microtonal accuracy of the symbolic representation,
	//  by representing the number of steps in which each tone is divided.
	//  For the standard semitonal representation (where just sharps and flats suffice), one can stick with 
	//  <m>tonedivision</m> being 2, meaning: the tone is divided into two semitones.
	//  By increasing this value, the microtonal grid gets more dense: for instance, 4 is the quartertonal grid
	//  (where each tone is divided in 4 quartertones); 8 is the eight-tonal grid, and so on.
	//  <br /> <br />

#define BACH_DOC_ACCIDENTALSPREFERENCES
	// 	Sets how non-natural notes should be represented: <br />
	//  - Auto: let bach choose a default representation. <br /> 
	//  - Sharps: always choose sharp accidentals (more precisely, in general: always 
	//  choose a representation such that the displayed diatonic pitch is below the actual note). <br /> 
	//  - Flats: always choose flat accidentals (more precisely, in general: always 
	//  choose a representation such that the displayed diatonic pitch is above the actual note). <br /> 
	//  - Custom: use a custom enharmonic table, defined via the <m>enharmonictable</m> attribute.
	//  <br /> <br />		
	
#define BACH_DOC_ACCIDENTALSGRAPHIC
	// 	Sets the way of displaying accidentals: <br />
	//  - None: no accidental is displayed. <br />
	//  - Classical: accidentals are displayed with the classical symbols (sharps, flats...). 
	//  This option is only available if <m>tonedivision</m> is 2, 4 or 8. <br />
	//  - Fraction: accidentals are displayed as fractions of tone (e.g. "-1/4" for quartertone flat or "+1/2" for
	//  an ordinary sharp). <br />
	//  - Unreduced Fraction: as the previous one, but fractions are never reduced. For instance, if <m>tonedivision</m> is
	//  48 one would have "+2/8" and not "+1/4". Denominator of each fraction is the <m>tonedivision</m>
	//  (thus a tonedivision 2 has denominators 2, as expected for standard sharps and flats). <br />
	//  - Cents: accidentals are displayed as cents differences with respect to the diatonic note. 
	//  Remark that, unless <m>tonedivision</m> is 100, the displayed cents difference will not in general correspond to the 
	//  real cents difference: the first one will be indeed a cents difference snapped to the chosen microtonal grid.
	//  For instance, if <m>tonedivision</m> is 8, a note having midicents 6027 will be displayed as a middle C with a "+25cents" accidental.
	//  <br /> <br />		

#define BACH_DOC_ENHARMONICTABLE
	//  An enharmonic table is a string of elements defining the accidentals to be used for each step of the chromatic scale.
	//  A symbol for each voice (containing such string of characters) is expected. If less symbols than the number of voices
	//  are defined, the last one is padded.
	//  The number of elements in the string depends on the <m>tonedivision</m>; more precisely it is the <m>tonedivision</m> multiplied by 6. 
	//  Standard case is <m>tonedivision</m> = 2, and thus the full 12 steps must be defined.
	//  Elements are sequencies of characters associated to accidentals.
	//  For instance "bb" is associated to a double flat, while "#+" is associated to a three quarter tones sharp.
	//  Such elements are to be separated by white spaces. For instance, if <m>tonedivision</m> is 12, a string like
	//  <b>enharmonictable "n # n b n n b n b n b x"</b> says that the C must be represented as natural, the note above will
	//  be a C# (and not a Db), the one above a D natural, the one above a Eb (and not a D#), and so on. Last note says that
	//  the B will actually be a Ax (A double diesis). <br />
	//  @copy BACH_DOC_ACCIDENTALS_ASCII_CONVENTION
	//  <br /> <br />		

#define BACH_DOC_NOTENAMESSTYLE
	// 	In the bach environment you can choose to represent note names in two different ways: either with the latin
	//	symbols (Do, Re, Mi, Fa, Sol, La, Si) or with the anglo-saxon letters (C, D, E, F, G, A, B). 
	//  <br /> <br />	
		
#define BACH_DOC_MIDDLECOCTAVE
	// 	The octave number corresponding to the octave where the middle C is. It is usually either 4 or 3, depending
	//  on the musical culture. By default, in bach, this is 4, i.e. C4 is the middle C. 
	//  <br /> <br />	
	
#define BACH_DOC_ACCIDENTALS_ASCII_CONVENTION
	// 	In the bach environment, accidentals can be written or output as ascii using the following symbols: <br />
	//  # for stanard 1/2 tone sharp <br />
	//  b for stanard 1/2 tone flat <br />
	//  x for stanard tone sharp <br />
	//  bb for stanard tone flat <br />
	//	+ for 1/4 tone sharp; <br />
	//	d or - for 1/4 tone flat; <br />
	//	#+ for 3/4 tone sharp; <br />
	//	db for 3/4 tone flat; <br />
	//	^ for 1/8 tone up; <br />
	//	v for 1/8 tone down. <br />
	//	Of course, these symbols can be combined, like in #+^ or dv.
	//	The 1/8 symbols are used also for smaller intervals (at output time).
	//  <br /> <br />	
	
#define BACH_DOC_EMBED
	// 	Toggles the ability to save the content with the patch when this latter is saved. 
	//  The default behaviour is 1 (save the data with the patch).
	//  <br /> <br />	

#define BACH_DOC_MARKERROLES
	// 	In <o>bach.roll</o>, one can assign a role for each marker, so that they can represent elements such as
	//  time signatures, tempi, barline, measure divisions. Time signature markers and tempi markers 
	//	also require a "content", i.e. an llll specifying the time signature or the tempo. 
	//  When adding a marker via the <m>addmarker</m> message, the role can be specified as third parameter, 
	//  and the content as fourth parameter. Alternatively, roles and content can be set via the marker inspector.
	//	Roles can be: <br />
	//  <m>Time Signature</m>: set by the symbol "timesig", it represents a time signature, and expects the time signature llll as content.
	//  For instance, a message to add such a marker could be <b>addmarker 0 foo timesig (4 4)</b>.<br />
	//  <m>Tempo</m>: set by the symbol "tempo", it represents a time signature, and expects the tempo llll as content (tempo figure and tempo
	//  value). For instance, a message to add such a marker could be <b>addmarker 0 foo tempo (1/8 50)</b>, meaning
	//  that the tempo is 1/8 = 50.<br />
	//  <m>Measure Barlines</m>: set by the symbol "barline", it represents a barline, and expects no content.
	//  For instance, a message to add such a marker could be <b>addmarker 0 foo barline</b>. <br />
	//  <m>Measure Division</m>: set by the symbol "division", it represents a measure division, and expects no content.
	//  For instance, a message to add such a marker could be <b>addmarker 0 foo division</b>. <br />
    //  <m>Measure Subdivision</m>: set by the symbol "subdivision", it represents a measure subdivision, and expects no content.
    //  For instance, a message to add such a marker could be <b>addmarker 0 foo subdivision</b>. <br />
	//	All these marker can be parsed by bach.quantize in order to automatically retrieve the measureinfo of the
	//  entire bach.roll.
	//  <br /> <br />	

#define BACH_DOC_LAMBDA
	//  A certain number of bach objects are equipped with "lambda" inlets and outlets. These inlets and outlets - 
	//  always the rightmost ones - serve the purpose of letting you define a function the object will base its behavior upon.
	//  Such function is indeed a patching loop: parameters are taken from the lambda outlet(s), processed, and the "result" is
	//  plugged in the lambda inlet(s). The type of function, and the corresponding expected result, depend on the object behavior;
	//  for instance, cycles modifying elements will expect as "result" the modified element; cycles testing for custom equalities will
	//  expect a 0/1 answer (0 meaning: not equal; 1 meaning: equal), as well as cycles testing custom inequalities and sorting (1 meaning: the two 
	//  elements are in the correct order; 0 meaning: the order is wrong). Refer to each specific object to know more about it.
	//  With many objects, it is not mandatory to provide an evaluation cycle: if you don't, a default function will be used. <br />
	//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	//  <br /> <br />

#define BACH_DOC_LAMBDA_INLET_GENERAL_HEADER
	// 	A lambda inlet is an inlet receiving the answer from a test or modification performed on elements sent out the lambda outlets. <br />

#define BACH_DOC_LAMBDA_OUTLET_GENERAL_HEADER
	// 	A lambda outlet is an outlet outputting an element on which some test or modification must be performed. 
	//  The result of the test or modification is then expected in a lambda inlet. <br />

#define BACH_DOC_LAMBDA_GENERAL_WARNING
	//  It is important to know that the evaluation chain inside the lambda loop must be direct: you can't use objects such as <o>delay</o>, 
	//  <o>pipe</o>, <o>defer</o>; nor store the value anywhere waiting for some other event to trigger it. Also see #lambda in the bach Help Center.

#define BACH_DOC_LAMBDA_INLET_ACCEPT
	// 	@copy BACH_DOC_LAMBDA_INLET_GENERAL_HEADER
	//  In this case, the answer is in a 0/1 form: if the element output from the lambda outlet is accepted 
	//  (according to your needs, defined in the lambda loop),
	//  this inlet should receive a 1; otherwise it should receive a 0. <br />
	//  The lambda inlet also accepts the 0/1 result in a native llll form, so you can sometimes avoid the explicit @out t. <br />
	//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	//	<br /> <br />

#define BACH_DOC_LAMBDA_OUTLET_ACCEPT
	// 	@copy BACH_DOC_LAMBDA_OUTLET_GENERAL_HEADER
	//  In this case, the elements output from the lambda outlet have to be tested in order to know if they are accepted:
	//  in the first case, you should return a 1 into the lambda inlet, in the second case you should return a 0. <br /> 
	//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	//	<br /> <br />
	
#define BACH_DOC_LAMBDA_INLET_MATCH
	// 	@copy BACH_DOC_LAMBDA_INLET_GENERAL_HEADER
	//  In this case, the answer is in a 0/1 form: if the element output from the lambda outlet is a match 
	//  (according to your custom matching function, defined in the lambda loop),
	//  this inlet should receive a 1; otherwise it should receive a 0. <br />
	//  The lambda inlet also accepts the 0/1 result in a native llll form, so you can sometimes avoid the explicit @out t. <br />
	//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	//	<br /> <br />
	
#define BACH_DOC_LAMBDA_OUTLET_MATCH
	// 	@copy BACH_DOC_LAMBDA_OUTLET_GENERAL_HEADER
	//  In this case, the elements output from the lambda outlet have to be tested in order to know if they are a match:
	//  in the first case, you should return a 1 into the lambda inlet, in the second case you should return a 0. <br /> 
	//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	//	<br /> <br />
	
#define BACH_DOC_LAMBDA_INLET_EQUALITY
	// 	@copy BACH_DOC_LAMBDA_INLET_GENERAL_HEADER
	//  In this case, the answer is in a 0/1 form: if the two elements
	//  output via the lambda outlet are equal (according to your custom meaning of the word "equality"),
	//  this inlet should receive a 1; otherwise it should receive a 0. <br />
	//  The lambda inlet also accepts the 0/1 result in a native llll form, so you can sometimes avoid the explicit @out t. <br />
	//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	//	<br /> <br />

#define BACH_DOC_LAMBDA_OUTLET_EQUALITY
	// 	@copy BACH_DOC_LAMBDA_OUTLET_GENERAL_HEADER
	//  In this case, the elements output from each one of the two lambda outlets have to be tested for "equality":
	//  you should tell whether they are "equal" (according to your custom meaning of the word "equality") or not.
	//  In the first case, you should return a 1 into the lambda inlet, in the second case you should return a 0. <br /> 
	//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	//	<br /> <br />

#define BACH_DOC_LAMBDA_INLET_ORDER
	// 	@copy BACH_DOC_LAMBDA_INLET_GENERAL_HEADER
	//  In this case, the answer is in a 0/1 form: if the two elements
	//  output via the lambda outlet are in correct order (according to your custom ordering),
	//  this inlet should receive a 1; otherwise it should receive a 0. <br />
	//  The lambda inlet also accepts the 0/1 result in a native llll form, so you can sometimes avoid the explicit @out t. <br />
	//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	//	<br /> <br />

#define BACH_DOC_LAMBDA_OUTLET_ORDER
	// 	@copy BACH_DOC_LAMBDA_OUTLET_GENERAL_HEADER
	//  In this case, the elements output from each one of the two lambda outlets have to be tested for "order":
	//  you should tell whether they are in the correct order (according to your custom ordering) or not.
	//  In the first case, you should return a 1 into the lambda inlet, in the second case you should return a 0. <br /> 
	//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	//	<br /> <br />

#define BACH_DOC_LAMBDA_INLET_MODIFICATION
	// 	@copy BACH_DOC_LAMBDA_INLET_GENERAL_HEADER
	//  In this case, the answer is expected to be a modification of the elements which had been sent out: 
	//  the element output via the lambda outlet can be customly modified and then plugged in into this lambda inlet:
	//  such modification will be accounted for by the algorithm. <br />
	//  The lambda inlet also accepts the result in llll form, so you can sometimes avoid the explicit @out t. <br />
	//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	//	<br /> <br />

#define BACH_DOC_LAMBDA_OUTLET_MODIFICATION
	// 	@copy BACH_DOC_LAMBDA_OUTLET_GENERAL_HEADER
	//  In this case, the elements output from the lambda outlet may be customly modified, so that such modification will be taken into
	//  account by the algorithm. To modify each element, just use patching and then plug into the lambda inlet the 
	//  modified version of the element. <br />
	//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	//	<br /> <br />

#define BACH_DOC_LAMBDA_INLET_CALCULATION
	// 	@copy BACH_DOC_LAMBDA_INLET_GENERAL_HEADER
	//  In this case, the answer is some calculation triggered on the elements which had been sent out. <br />
	//  The lambda inlet also accepts the result in llll form, so you can sometimes avoid the explicit @out t. <br />
	//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	//	<br /> <br />

#define BACH_DOC_LAMBDA_OUTLET_CALCULATION
	// 	@copy BACH_DOC_LAMBDA_OUTLET_GENERAL_HEADER
	//  In this case, on the elements output from the lambda outlet may be performed some calculation, taken than into 
	//  account by the algorithm (just use patching and then plug into the lambda inlet the 
	//  result of the calculation). <br />
	//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	//	<br /> <br />

#define BACH_DOC_LAMBDA_INLET_COLLECTION
    // 	@copy BACH_DOC_LAMBDA_INLET_GENERAL_HEADER
    //  In this case, the answer is some content which should be appropriately collected by the mechanism. <br />
    //  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
    //	<br /> <br />

#define BACH_DOC_PLAYOUT_SYNTAX_ROLL
	// 	For <o>bach.roll</o>, the playout syntax is used whenever the information about a note or chord is sent through the playout (either at playtime
	//  or at offline play, or selection dump).
	//  The playout syntax is a slight variation of the standard chord gathered syntax. Two different cases apply, according to the <m>playmode</m>
	//  attribute value. If the <m>playmode</m> is set to Chordwise, the information about each chord is output in the form <br />
	//  <b>chord <m>voice_number</m> <m>MIDI_channel</m> (<m>onset</m> <m>NOTE1</m> <m>NOTE2</m> <m>NOTE3</m> <m>chord_flag</m>) </b> <br />
	//  where each <b><m>NOTE</m></b> is the gathered syntax of the note (see below).
	//  If the <m>playmode</m> is set to Notewise, information about each note is output as if the note were the only note in the chord, i.e. in the form <br />
	//  <b>note <m>voice_number</m> <m>MIDI_channel</m> (<m>onset</m> <m>NOTE</m> <m>chord_flag</m>) </b> <br />
	//  where <b><m>NOTE</m></b> is the note gathered syntax.
	//  The <m>MIDI_channels</m> is the one associated with the voice to which the note or chord belongs. The <m>onset</m> is in milliseconds,
	//  The <m>chord_flag</m> is a bitfield summing values of 1 (if chord is locked), 2 (if chord is muted), 4 (if chord is solo). <br />
	//  The playout syntax also concerns markers: they are output in the form: <b>marker <m>NAME_OR_NAMES</m> <m>onset_ms</m> <m>role</m> <m>optional:content</m></b>
	//  where the <m>NAME_OR_NAMES</m> is either a single atom (if the marker has a single name) or a wrapped plain llll containing the names, and the <m>optional:content</m>
	//  is only output if the marker role requires it.
	//  <br /> <br />
	//  @copy BACH_DOC_MARKERROLES
	//  @copy BACH_DOC_NOTE_GATHERED_SYNTAX_ROLL
	
	
#define BACH_DOC_TIMEPOINT_SYNTAX_SCORE
	//  A timepoint represents a given instant inside <o>bach.score</o>, as a measure-attached position.
	//  It identifies such point according to a measure, a position inside such measure,
	//  and possibly a voice (in case tempi and time signatures are not synchronous for all voices).
	//  Differently from absolute millisecond positions,
	//  timepoints are represented by lllls, in one of the following syntaxes: <br />
	//  - <b>(<m>measure_number</m>)</b>: represents the point is at the beginning of the measure identified by the introduced measure number, in the first voice. 
	//  For instance, <b>(4)</b> represents the point at the very beginning of measure 4, voice 1. <br />
	//  - <b>(<m>measure_number</m> <m>sym_onset_in_measure</m>)</b>: represents the point inside the measure identified by the introduced measure number (in the first voice),
	//  but not necessarily at the beginning, rather at the generic position in measure identified by the symbolic onset <m>sym_onset_in_measure</m>.
	//  For instance, <b>(4 1/4)</b> represents the point at measure 4, voice 1, after 1/4 from the beginning of the measure. <br />
	//  - <b>(<m>voice_number</m> <m>measure_number</m> <m>sym_onset_in_measure</m>)</b>: represents the point inside the measure identified by the introduced measure number, 
	//  in the voice identified, by the introduced voice number, at the generic position in measure identified by the symbolic onset <m>sym_onset_in_measure</m>.
	//  For instance, <b>(2 4 1/4)</b> represents the point at measure 4, voice 2, after 1/4 from the beginning of the measure. Specifying voice numbers explicitly is especially
	//  important if voices don't have the same tempi or time signatures. 
	//  <br />
	//  A timepoint can also  be specified via a <b>(<m>float_measure_number</m>)</b>, representing the point in a floating
	//  point position between two measures (referred to the first voice). For instance, <b>(4.2)</b> represents the point at the 20% of measure 4, voice 1. 
	//  Furthermore, the <m>sym_onset_in_measure</m> can be replaced by a float between 0 and 1 to represent a point between the beginning (0) and the end 
	//  of the measure (1); for instance <b>(1 4 0.2)</b> represents the point after 20% of measure 4, voice 1.
    //  <br />
    //  If the measure number is replaced by the <b>any</b> symbol, then the following rational is interpreted as a global symbolic onset inside the score.
    //  For instance, <b>(any 27/4)</b> represents the point at 27/4 after the beginning of the score, referred to the measureinfo of voice 1;
    //  <b>(3 any 27/4)</b> does the same for voice 3.
    //  <br /> <br />
	

#define BACH_DOC_PLAYOUT_SYNTAX_SCORE
	// 	For <o>bach.score</o>, the playout syntax is used whenever the information about a note or chord is sent through the playout (either at playtime
	//  or at offline play, or selection dump).
	//  The playout syntax is a slight variation of the standard chord gathered syntax. Two different cases apply, according to the <m>playmode</m>
	//  attribute value. If the <m>playmode</m> is set to Chordwise, the information about each chord is output in the form <br />
	//  <b>chord <m>voice_number</m> <m>MIDI_channel</m> (<m>symbolic_duration</m> <m>duration_ms</m> <m>symbolic_onset_in_measure</m>
	//  <m>onset_from_score_beginning_in_ms</m> <m>NOTE1</m> <m>NOTE2</m> <m>NOTE3</m> <m>chord_flag</m>) </b> <br />
	//  where each <b><m>NOTE</m></b> is the gathered syntax of the note. 
	//  If <m>playrest</m> is set to 1, and the chord is a rest, the router symbol is <b>rest</b> instead of chord. <br />
	//  If the <m>playmode</m> is set to Notewise, information about each note is output as if the note were the only note in the chord, i.e. in the form <br />
	//  <b>note <m>voice_number</m> <m>MIDI_channel</m> (<m>symbolic_duration</m> <m>duration_ms</m> <m>symbolic_onset_in_measure</m>
	//  <m>onset_from_score_beginning_in_ms</m> <m>NOTE</m> <m>note_flag</m>) </b> <br />
	//  where <m>NOTE</m> is the note gathered syntax. <br />
	//  If <m>playrest</m> is set to 1, and the chord is a rest, the router symbol is <b>rest</b> instead of chord, and there is no <m>NOTE</m> llll. <br />
	//  In case the played note or chord is just a grace chord, the <m>symbolic_duration</m> becomes an llll in the form <b>(g <m>grace_symbolic_duration</m>)</b>.
	//  The <m>MIDI_channels</m> is the one associated with the voice to which the note or chord belongs. The <m>onset</m> is in milliseconds,
	//  The <m>chord_flag</m> is a bitfield summing values of 1 (if chord is locked), 2 (if chord is muted), 4 (if chord is solo). <br />
	//  The playout syntax also concerns markers: they are output in the form: <b>marker <m>NAME_OR_NAMES</m> <m>ONSET</m> none</b>
	//  where the <m>NAME_OR_NAMES</m> is either a single atom (if the marker has a single name) or a wrapped llll containing the names.
	//  The last <b>none</b> symbol is the marker role, currently unsupported in <o>bach.score</o>. The <m>ONSET</m> can either be a single
	//  floating point value, representing the onset in milliseconds (if the marker is attached to the milliseconds position), or an llll representing
	//  the onset timepoint (if the marker is attached to the position inside the measure). <br />
    //  The playout syntax also concerns tempi: they are output in the form <b>tempo <m>voice_number</m> <m>tempo</m> <m>TEMPO_LLLL</m></b>,
    //  where <m>tempo</m> is the floating point tempo referred to the quarter note, and
    //  <m>TEMPO_LLLL</m> is in the form <b>(<m>tempo_figure</m> <m>tempo_value</m> <m>tempo_sym_onset</m> <m>interpolation_to_next?</m>)</b>.
    //  If the tempo starts an accelerando/rallentando (i.e. interpolation is set to 1), then the <m>tempo</m> element is substituted by the llll
    //  <b>(<m>tempo</m> <m>next_tempo</m> <m>interp_duration_ms</m>)</b>.  <br />
    //  The playout syntax also concerns measures: if <m>playmeasures</m> is 1, at the beginning of each measure (for each voice), an llll is output
    //  in the form <b>measure <m>voice_number</m> <m>measure_number</m> <m>MEASUREINFO_LLLL</m></b>.
    //  If a tempo and/or a chord lie at the beginning of a measure, the order of output for the elements is: measure, tempo, chord (or notes). <br /> 
    //  For all the previously exposed cases, if the <m>playoutfullpath</m> attribute is set to 1, the <m>voice_number</m> is substituted by
    //  an llll determining the address of the element (see the <m>playoutfullpath</m> attribute for more information. <br /> <br />
	//  @copy BACH_DOC_TIMEPOINT_SYNTAX_SCORE
	//  @copy BACH_DOC_NOTE_GATHERED_SYNTAX_SCORE
    //  @copy BACH_DOC_MEASUREINFO_SYNTAX


#define BACH_DOC_GENERIC_GATHERED_SYNTAX
	// 	The gathered syntax of any notation object is in the form <b><m>notation_object_name</m> <m>HEADER</m> <m>BODY</m></b>, where
	//  where the first symbol is optional as input (but always given as output) and identifies the notation object
	//  (e.g.: <b>roll</b> or <b>score</b>). The <m>HEADER</m> is an llll containing all the 
	//  meta-information about the object (such as key signatures, clefs, markers...), while <m>BODY</m> is the llll
	//  containing the actual content of the notation object (i.e. the content of each voice, or measure, or chord,
	//  or note: the form varies depending on the notation object). <br /> <br />
	//  @copy BACH_DOC_HEADER_SYNTAX


#define BACH_DOC_ROLL_GATHERED_SYNTAX
	// 	The gathered syntax of a whole <o>bach.roll</o> is in the form <b>roll <m>HEADER</m> <m>BODY</m></b>, where
	//  the first symbol is optional as input (but always given as output). <m>HEADER</m> is an llll containing all the 
	//  <o>bach.roll</o> meta-information (such as key signatures, clefs, markers...), 
	//  while <m>BODY</m> has the form of a sequence of voices: <b>(<m>VOICE1</m> <m>VOICE2</m>...)</b>
	//  where each voice is an llll in gathered syntax (see below for more information about this). <br /> <br />
	//  @copy BACH_DOC_HEADER_SYNTAX
	//  @copy BACH_DOC_VOICE_GATHERED_SYNTAX_ROLL


#define BACH_DOC_SCORE_GATHERED_SYNTAX
	// 	The gathered syntax of a whole <o>bach.score</o> is in the form <b>score <m>HEADER</m> <m>BODY</m></b>, where
	//  the first symbol is optional as input (but always given as output). <m>HEADER</m> is an llll containing all the 
	//  <o>bach.score</o> meta-information (such as key signatures, clefs, markers...),
	//  while <m>BODY</m> has the form of a sequence of voices: <b>(<m>VOICE1</m> <m>VOICE2</m>...)</b>
	//  where each voice is an llll in gathered syntax (see below for more information about this). <br /> <br />
	//  @copy BACH_DOC_HEADER_SYNTAX
	//  @copy BACH_DOC_VOICE_GATHERED_SYNTAX_SCORE


#define BACH_DOC_VOICE_GATHERED_SYNTAX_ROLL
	// 	For <o>bach.roll</o>, the gathered syntax for any voice, in its simplest form <b>(<m>CHORD1</m> <m>CHORD1</m>... <m>voice_flag</m>)</b>
	//  where each <m>CHORD</m> is an llll representing a chord in gathered syntax, and the <m>voice_flag</m> is an optional bitfield summing values of 
	//  1 (if voice is locked), 2 (if voice is muted), 4 (if voice is solo). <br />
	//  @copy BACH_DOC_CHORD_GATHERED_SYNTAX_ROLL
	

#define BACH_DOC_VOICE_GATHERED_SYNTAX_SCORE
	// 	For <o>bach.score</o>, the gathered syntax for any voice, in its simplest form <b>(<m>MEASURE1</m> <m>MEASURE2</m>... <m>voice_flag</m>)</b>
	//  where each <m>MEASURE</m> is an llll representing a measure in gathered syntax, and the <m>voice_flag</m> is an optional bitfield summing values of 
	//  1 (if voice is locked), 2 (if voice is muted), 4 (if voice is solo). <br /> <br />
	//  @copy BACH_DOC_MEASURE_GATHERED_SYNTAX_SCORE


#define BACH_DOC_MEASURE_GATHERED_SYNTAX_SCORE
	// 	For <o>bach.score</o>, the gathered syntax for any measure is, in its simplest form <b>(<m>MEASUREINFO</m> <m>CHORD1</m> <m>CHORD2</m>... <m>measure_flag</m>)</b>
	//  where <m>MEASUREINFO</m> is the information concerning time signatures and tempi, as well as possibly other information regarding barlines, widths and more (see below), 
	//  each <m>CHORD</m> is an llll representing a chord and must be in the chord gathered syntax, and the <m>measure_flag</m> is an optional bitfield summing values of 
	//  1 (if measure is locked), 2 (if measure is muted), 4 (if measure is solo), 8 (if measure rhythmic tree is locked). <br /> 
	//  In the most general form, chord information is not represented linearly as a sequence of <m>CHORD</m> lllls, rather as a rhythmic tree, so
	//  chord lllls are in general wrapped into further levels of parentheses. This is not necessary as input, although you can define such levels
	//  also as input, in order to suggest to <o>bach.score</o> the rhythmic tree you want to have,
	//  for instance: <b>(<m>MEASUREINFO</m> ((<m>CHORD1</m> <m>CHORD2</m>) <m>CHORD3</m>)... <m>measure_flag</m>)</b>.
	//  These additional levels act as suggestions on the bach algorithms, which might create further levels (e.g. by refining levels) or modify the existing ones
	//  according to the <m>treehandling</m> and <m>maketreecompatiblewithts</m> attributes.
	//  Each level llll by default has as first element, while output, an llll in the form <b>(leveltype <m>type</m>)</b>, where <m>type</m> is a number
	//  which accounts for the "lifecycle" of the level (was it created by the user? was it refined by bach itself?...) and which should be 
	//  opaque to the user: such level type should never be set by hand, only kept to guarantee a good storage or rebuilding of <o>bach.score</o>.
	//  The interpretation of rhythmic tree levels as input will depend on all the rhythmic tree attributes, the most important of which are
	//  <m>treehandling</m> and <m>maketreecompatiblewithts</m>. At output, the gathered syntax might or might not contain the rhythmic tree
	//  levels of parentheses, depending on the <m>outputtrees</m> attribute. Also it might or might not contain level type specifications, 
	//  depending on the <m>saveleveltypes</m> attribute. <br /> 
	//  Grace chords are characterized by being elements inside grace levels. Grace levels are identified by a "g" symbol at the very beginning
	//  of the level. A grace level may contain sub-levels as any other ordinary level. Indeed, grace chords may have any symbolic duration,
	//  they may also be rests, or organized in tuplets. The general form of the grace level is thus <b>(g <m>CHORD_OR_CHORDS</m>)</b>,
	//  where <m>CHORD_OR_CHORDS</m> may be a complex llll containing the gathered syntax of chords. For instance: <b>(g (1/8 (6000 127 1)) ((-1/12) (1/24 (6000 127 1))))</b>.
	//  <br /> <br />
	//  @copy BACH_DOC_MEASUREINFO_SYNTAX
	//  @copy BACH_DOC_CHORD_GATHERED_SYNTAX_SCORE


#define BACH_DOC_CHORD_GATHERED_SYNTAX_ROLL
	// 	For <o>bach.roll</o>, the gathered syntax for any chord, in its simplest form <b>(<m>onset_ms</m> <m>NOTE1</m> <m>NOTE2</m>... <m>chord_flag</m>)</b>
	//  where <m>onset_ms</m> is the onset of the chord (starting temporal point) in milliseconds each <m>NOTE</m>
	//  is an llll representing a note in gathered syntax, and the <m>chord_flag</m> is an optional bitfield summing values of 
	//  1 (if chord is locked), 2 (if chord is muted), 4 (if chord is solo). <br />
	//  In its most general form, each chord can have a specification defining its name(s). This specification must be in the form
	//  <b>(name <m>NAME_OR_LLLL_OF_NAMES</m>)</b>, and must be put after the last note llll,
	//  before the <m>chord_flag</m>. For instance, a chord definition might 
	//  have the form <b>(500 (7000. 500 127) (7200. 1200 100) (name paul) 0)</b>
	//  <br /> <br />
	//  @copy BACH_DOC_NOTE_GATHERED_SYNTAX_ROLL


#define BACH_DOC_CHORD_GATHERED_SYNTAX_SCORE
	// 	For <o>bach.score</o>, the gathered syntax for any chord, in its simplest form <b>(<m>sym_duration</m> <m>NOTE1</m> <m>NOTE2</m>... <m>chord_flag</m>)</b>
	//  where <m>sym_duration</m> is the symbolic rational duration of the chord, as a fraction of the whole note (e.g. <b>1/4</b>), each <m>NOTE</m>
	//  is an llll representing a note in gathered syntax, and the <m>chord_flag</m> is an optional bitfield summing values of 
	//  1 (if chord is locked), 2 (if chord is muted), 4 (if chord is solo). <br />
	//  In its most general form, each chord can have specifications defining its name(s) or its slots.
	//  Each of these specifications is done in the form <b>(<m>specification_name</m> <m>SPECIFICATION CONTENT</m>)</b>, and must be put after the last note llll,
	//  and before the <m>chord_flag</m>. The order in which the specifications are listed is, on the other hand, irrelevant. For instance, a chord definition might 
	//  have the form <b>(1/4 (7000. 127 1) (7200. 100 0) (name john) (slots (10 fermata)) 0)</b>.
	//  <br /> <br />
	//  @copy BACH_DOC_NOTE_GATHERED_SYNTAX_SCORE


#define BACH_DOC_NOTE_GATHERED_SYNTAX_ROLL
	// 	For <o>bach.roll</o>, the gathered syntax for any note is, in its simplest form <b>(<m>pitch_cents</m> <m>duration</m> <m>velocity</m> <m>note_flag</m>)</b>
	//  where <m>pitch_cents</m> is the pitch of the note in MIDI cents, the <m>duration</m> is measured in milliseconds, the <m>velocity</m>
	//  is a value from 1 to 127 corresponding to the note dynamic, and
	//  the <m>note_flag</m> is an optional bitfield summing values of 1 (if note is locked), 2 (if note is muted), 4 (if note is solo). <br />
	//  In its most general form, each note can have different specifications and attributes, defining 
	//  graphics, pitch breakpoints, slots, names.
	//  Each of these specifications is done in the form <b>(<m>specification_name</m> <m>SPECIFICATION CONTENT</m>)</b>, and must be put after the <m>velocity</m>
	//  and before the <m>note_flag</m>. The order in which the specifications are listed is, on the other hand, irrelevant. For instance, a note definition might have the form
	//  <b>(7300. 136. 127 (graphic 7400 -1/2) (slots (1 (0. 0. 0.) (0.294118 81.138889 0.) (0.294118 38.805556 0.) (1. 0. 0.))) (name pippo) 0 )</b>
	//  <br /> <br />
	//  @copy BACH_DOC_PITCHES_ALSO_AS_NOTENAMES
	//  @copy BACH_DOC_NOTE_GRAPHIC_SYNTAX
	//  @copy BACH_DOC_NOTE_BREAKPOINT_SYNTAX
	//  @copy BACH_DOC_NOTE_SLOTS_SYNTAX
	//  @copy BACH_DOC_NAME_SYNTAX

#define BACH_DOC_NOTE_GATHERED_SYNTAX_SCORE
	// 	For <o>bach.score</o>, the gathered syntax for any note is, in its simplest form <b>(<m>pitch_cents</m> <m>velocity</m> <m>tie?</m> <m>note_flag</m>)</b>
	//  where <m>pitch_cents</m> is the pitch of the note in MIDI cents, the <m>velocity</m>
	//  is a value from 1 to 127 corresponding to the note dynamic, the <m>tie?</m> value is 1 only if the note starts a tie and 0 otherwise, and
	//  the <m>note_flag</m> is an optional bitfield summing values of 1 (if note is locked), 2 (if note is muted), 4 (if note is solo). <br />
	//  In its most general form, each note can have different specifications and attributes, defining one of the possible extras:
	//  graphics, pitch breakpoints, slots, names, articulations.
	//  Each of these specifications is done in the form <b>(<m>specification_name</m> <m>SPECIFICATION CONTENT</m>)</b>, and must be put after the <m>tie?</m>
	//  and before the <m>note_flag</m>. The order in which the specifications are listed is, on the other hand, unimportant. For instance, a note definition might have the form
	//  <b>(7000. 127 1 (graphic 6900 1/2) (slots (1 (0. 112.5 0.) (1. 0. 0.))) (articulation stacc) (name foo) 0)</b>.
	//  <br /> <br />
	//  @copy BACH_DOC_NOTE_GRAPHIC_SYNTAX
	//  @copy BACH_DOC_NOTE_BREAKPOINT_SYNTAX
	//  @copy BACH_DOC_NOTE_SLOTS_SYNTAX
	//  @copy BACH_DOC_NAME_SYNTAX
	//  @copy BACH_DOC_ARTICULATIONS_SYNTAX


#define BACH_DOC_NOTE_GRAPHIC_SYNTAX
	//  The <m>graphic</m> specification informs about the enharmonicity status of a note. 
	//  It is given by an llll in the form <b>(<m>graphic</m> <m>displayed_midicents_ignoring_accidental</m> <m>displayed_accidental</m>)</b>,
	//  where <m>displayed_midicents_ignoring_accidental</m> are the cents of the diatonic displayed note (ignoring any accidental that it might have),
	//  and <m>displayed_accidental</m> is the displayed accidental in rational form (sharp corresponding to 1/2, flat to -1/2, quarterflat to -1/4 and so on).
	//  For instance, a Db just above the middle C would have a graphic specification of <b>(graphics 6200 -1/2)</b>.
	//  <br /> <br />


#define BACH_DOC_NOTE_BREAKPOINT_SYNTAX
	//  The <m>breakpoint</m> specification informs about possible pitch breakpoints that a note duration line has. This is useful to represent glissandi.
	//  It is given by an llll in the form <b>(<m>breakpoints</m> <m>BPT1</m> <m>BPT2</m> <m>BPT3</m>...)</b>,
	//  where each <m>BPT</m> is an llll in the form <b>(<m>relative_x_position</m> <m>delta_midicents</m> <m>slope</m>)</b>, where
	//  <m>relative_x_position</m> is a double precision number from 0 to 1 representing the point where the breakpoint is, 0 corresponding to 
	//  the notehead and 1 corresponding to the note tail; <m>delta_midicents</m> is the pitch difference (in midicents) between the breakpoint pitch and the base note pitch;
	//  <m>slope</m> is a value from -1 to 1 corresponding to the curvature of the segment of duration line preceding the breakpoint (this implies that the slope of the first breakpoint 
	//  is always ignored), as for Max <o>curve</o> object (thus 0 being linear). <br />
	//  Two breakpoints are always present: the first breakpoint corresponds always to (0 0 0), and can never
	//  be different than this; the last breakpoint corresponds always to the note tail, and must always be in the form <b>(1 <m>delta_midicents</m> <m>slope</m>)</b>.
	//  If all breakpoints are trivial (thus if there are just two breakpoints: notehead and tail, and the notetail has <m>delta_midicents</m> = 0), the breakpoint
	//  specification is never given as output. For instance, a note making a glissando upwards and then downwards of 200cents, linear while ascending and exponential in the descent,
	//	will have the breakpoint specification of the form <b>(breakpoints (0 0 0) (0.5 200 0) (1 0 0.5))</b>. <br />
	//  If the <m>breakpointshavevelocity</m> attribute is set to 1, pitch breakpoints also have velocities, thus the complete <m>BPT</m> specification is in the form
	//  (<m>relative_x_position</m> <m>delta_midicents</m> <m>slope</m> <m>velocity</m>),
	//  where <m>velocity</m> is a number from 1 to 127 corresponding to the pitch breakpoint dynamic. If different breapoints have different dynamics, the behavior of
	//  the velocity between them is considered to be interpolatory, for instance by abstractions like <o>bach.dl2line</o> or <o>bach.dl2curve</o>.
	//  <br /> <br />

#define BACH_DOC_NOTE_SLOTS_SYNTAX
	//  The <m>slots</m> specification informs about the content of each one (or a subset) of the slots of a note. 
	//  It is given by an llll in the form <b>(slots <m>SLOT1</m> <m>SLOT2</m>...)</b>,
	//  where each one of the <m>SLOT</m> is an llll containing the information about one slot, in the form
	//	<b>(<m>slot_number</m> <m>SLOT_CONTENT</m>)</b>. <br />
	//  @copy BACH_DOC_NOTE_SLOT_CONTENT


#define BACH_DOC_NOTE_SLOT_CONTENT
	//  The slot content syntax depends on the slot type. <br />
	//  - For slot of type <m>function</m> the content must be in the form: <b><m>POINT1</m> <m>POINT2</m> <m>POINT3</m>...</b> where each
	//  <m>POINT</m> is in turn in the form <b>(<m>x</m> <m>y</m> <m>slope</m>)</b>, where the first two elements are the coordinates of the point, and the last one is 
	//  a slope parameter, from -1 to 1, corresponding to the curvature of the segment preceding the point. <br />
	//  - For slot of type <m>int</m> or <m>float</m> the content must be in the simplest form: <b><m>number</m></b>. <br />
	//  - For slot of type <m>intlist</m> or <m>floatlist</m> the content must be in the form: <b><m>number1</m> <m>number2</m>...</b>. <br />
	//  - For slot of type <m>text</m> the content must be in the form: <b><m>text_as_an_unique_symbol</m></b>. <br />
	//  - For slot of type <m>llll</m> the content must be in the form: <b><m>WRAPPED_LLLL</m></b>, equivalent to <b>(<m>LLLL</m>)</b>.  <br />
	//  - For slot of type <m>filelist</m> the content must be in the form: <b><m>filepath1</m> <m>filepath2</m> <m>filepath3</m>... <m>active_file_index</m></b>, 
	//    where <m>active_file_index</m> is the index of the file which will appear as clicked (active). <br />
	//  - For slot of type <m>spat</m> the content must be in the form: <b><m>SPATPOINT1</m> <m>SPATPOINT2</m> <m>SPATPOINT3</m>...</b> where each
	//  <m>SPATPOINT</m> is in turn in the form <b>(<m>t</m> <m>radius</m> <m>angle</m> <m>interpolation_type</m>)</b>, 
	//  where the first element is the time position (by default, if the domain is temporal, this is between 0 and 1), then comes the radius
	//  (distance of the sound from the listener) and the angle which the sound makes with respect to a reference vertical direction.
	//  Last parameter is an interpolation type, which is 0 (default) for circular spatialization and 1 for linear spatialization. <br />
	//  - For slot of type <m>color</m> the content must be in the form: <b><m>red</m> <m>green</m> <m>blue</m> <m>alpha</m></b>, where
	//  the parameters are the components of the RGBA color representation (from 0. to 1.).  <br />
	//  - For slot of type <m>3dfunction</m> the content must be in the form: <b><m>POINT1</m> <m>POINT2</m> <m>POINT3</m>...</b> where each
	//  <m>POINT</m> is in turn in the form <b>(<m>x</m> <m>y</m> <m>z</m> <m>slope</m>)</b>, where the first three elements are the coordinates of the point, and the last one is 
	//  a slope parameter, from -1 to 1, corresponding to the curvature of the segment preceding the point. <br />
	//  - For slot of type <m>filter</m>, when you need to input content you can use the syntax: 
	//  <b><m>filtertype</m> <m>cutoff_frequency_Hz</m> <m>gain_dB</m> <m>Q_or_slope</m></b>, where <m>filtertype</m> is one of the following symbols:
	//  <m>lowpass</m>, <m>highpass</m>, <m>bandpass</m>, <m>bandstop</m>, <m>peaknotch</m>, <m>lowshelf</m>, <m>highshelf</m>, <m>allpass</m>.
	//  You can equivalently use for input the syntax
	//  <b><m>a0</m> <m>a0</m> <m>a2</m> <m>b1</m> <m>b2</m></b>, where the parameters are the coefficients of a biquad filter, as for <o>biquad~</o>.
	//  Finally, when data is output, the syntax is always a combination of the two:
	//  <b><m>a0</m> <m>a0</m> <m>a2</m> <m>b1</m> <m>b2</m> (<m>filtertype</m> <m>cutoff_frequency_Hz</m> <m>gain_dB</m> <m>Q_or_slope</m>)</b>. <br />
	//  - For slot of type <m>dynfilter</m> the content must be in the form: <b>(<m>t1</m> <m>FILTER1</m>) (<m>t2</m> <m>FILTER2</m>) (<m>t3</m> <m>FILTER3</m>)...</b>, where
	//  each <m>FILTER</m> is in the form defined for slot of type <m>filter</m>, just above. <br />
    //  - For slot of type <m>articulations</m> the content must be in the form: <b><m>art1</m> <m>art2</m>...</b>, i.e. a sequence of
    //  articulations introduced as symbols.
    //  @copy BACH_DOC_ARTICULATIONS_SYMBOLS
    //  Articulation symbols can also be retrieved by hovering on the corresponding element in the slot window. <br />
    //  - For slot of type <m>notehead</m> the content must a single notehead symbol.
    //  @copy BACH_DOC_NOTEHEAD_SYMBOLS
    //  Notehead symbols can also be retrieved by hovering on the corresponding element in the slot window. <br />
	//  - For slot of type <m>togglematrix</m>, <m>intmatrix</m> or <m>floatmatrix</m> the content must be in the form: <b><m>WRAPPED_MATRIX_AS_LLLL</m></b>,
	//  equivalent to <b>(<m>ROW1</m> <m>ROW2</m>...)</b>, where each row is a wrapped llll.
	//  @copy BACH_DOC_MATRIXCALCULUS_MATRIX

#define BACH_DOC_NAME_SYNTAX
	//  The <m>name</m> specification informs us about a possible name (or possibles names) of a notation item.
	//  It is simply given by an llll in the form <b>(name <m>NAME_OR_LLLL_OF_NAMES</m>)</b>,
	//  where <m>NAME_OR_LLLL_OF_NAMES</m> is either a single of symbols or integer, or an llll corresponding to the name(s) of the notation item.
	//  For instance, an item named as "john george" will correspond to the llll <b>(name john george)</b>.
	//  An item named "(high 1) (low 2)" will correspond to the llll <b>(name (high 1) (low 2))</b>.
	//  If an element has no names, the <m>name</m> specification is never given as output.
	//  <br /> <br />

#define BACH_DOC_ARTICULATIONS_SYNTAX
	//  The <m>articulation</m> specification informs us about an articulation assigned either to a chord or to a note.
	//  It is simply given by an llll in the form <b>(articulation <m>ARTICULATION_OR_LIST_OF_ARTICULATIONS</m>)</b>,
	//  where <m>ARTICULATION_OR_LIST_OF_ARTICULATIONS</m> is a list of symbols idenfitying articulations to be added to the notation item.
	//  The symbols of the list are allowed to be the following ones: "staccato" or "stacc", "staccatissimo" or "staccmo", 
	//  "fermata" or "ferm", "portato" or "por", "accent" or "acc", "accentstaccato" or "accstacc", "accentportato" or "accport",
	//  "portatostaccato" or "portstacc", "martellato" or "mart", "martellatostaccato" or "martstacc", "lefthandpizzicato" or "lhpiz",
	//	"trill" or "tr", "gruppetto" or "grupp", "upmordent" or "umord", "downmordent" or "dmord", "doublemordent" or "mmord",
	//  "upbowing" or "ubow", "downbowing" or "dbow", "tremolo" or "trem" (for the tremolo with three slashes), "tremolo2" or "trem2" 
	//  (for the tremolo with two slashes), "tremolo1" or "trem1" (for the tremolo with a single slash), "gruppetto" or "grupp". <br />
	//  The default bach font has all the articulations glyphs; however, not all the other supported fonts do, especially Boulez doesn't have 
	//  a certain number of the previous articulations among its glyphs. If you don't see an articulation as you wish 
	//  (e.g. tremoli with Boulez), it might be because the font doesn't have the proper character, so try to use another font.
	//  <br /> <br />

#define BACH_DOC_ARTICULATIONS_SYMBOLS
    //  The list of the are standard available articulations as symbols is: "staccato" or "stacc", "staccatissimo" or "staccmo",
    //  "fermata" or "ferm", "portato" or "por", "accent" or "acc", "accentstaccato" or "accstacc", "accentportato" or "accport",
    //  "portatostaccato" or "portstacc", "martellato" or "mart", "martellatostaccato" or "martstacc", "lefthandpizzicato" or "lhpiz",
    //	"trill" or "tr", "gruppetto" or "grupp", "upmordent" or "umord", "downmordent" or "dmord", "doublemordent" or "mmord",
    //  "upbowing" or "ubow", "downbowing" or "dbow", "tremolo3" or "trem3" (for the tremolo with three slashes), "tremolo2" or "trem2"
    //  (for the tremolo with two slashes), "tremolo1" or "trem1" (for the tremolo with a single slash).
    //  Notice that the default bach font has all the articulations glyphs; however, not all the other supported fonts do,
    //  in particular Boulez doesn't have a certain number of the previous articulations among its glyphs.
    // If you don't see an articulation as you wish
    //  (e.g. tremoli with Boulez), it might be because the font doesn't have the proper character, so try to use another font.

#define BACH_DOC_NOTEHEAD_SYMBOLS
    //  The list of the standard available noteheads as symbols is: "default", "doublewhole", "whole", "white", "black", "diamond", "cross", "plus",
    //  "none", "accent", "blacksquare", "whitesquare", "square" "blacktriangle", "whitetriangle", "triangle", "blackrhombus", "whiterhombus", "rhombus".
    //  In <o>bach.score</o>, the "square", "triangle" and "rhombus" notehead are black or white depending on the note duration; in <o>bach.roll</o> only
    //  the black flavour is used.
    //  As for articulations, not all fonts support all symbols.

#define BACH_DOC_TEMPO_SYNTAX
    //  A tempo, defined for a measure of a <o>bach.score</o> has one of the following syntaxes: <br />
    //  - <b>(<m>tempo_value</m>)</b> will assign a quarter tempo at the beginning of the measure. For instance <b>(60)</b> will set a 1/4 = 60 tempo. <br />
    //  - <b>(<m>tempo_figure</m> <m>tempo_value</m>)</b> will assign the tempo value to the specified symbolic unit (at the beginning of the measure).
    //  The <m>tempo_figure</m> is indeed the tempo symbolic unit: for instance <b>(3/8 40)</b> will set a tempo of a dotted quarter = 40.<br />
    //  - <b>(<m>tempo_figure</m> <m>tempo_value</m> <m>tempo_sym_onset</m>)</b> will assign the tempo value to the specified symbolic unit and will put the
    //  tempo at the point inside the measure specified by the <m>tempo_sym_onset</m>. For instance <b>(3/8 40 1/4)</b> will set a tempo of a dotted quarter = 40
    //  but not at the beginning of the measure, rather after 1/4 from the beginning.<br />
    //  - <b>(<m>tempo_figure</m> <m>tempo_value</m> <m>tempo_sym_onset</m> <m>interpolation_to_next?</m>)</b> will do exactly as the previous case
    //  but if <m>interpolation_to_next?</m> is non-zero it will also toggle the interpolation from this tempo to the following one,
    //  yielding an accelerando or rallentando (depending if the next tempo is faster or slower). For instance <b>(3/8 40 1/4 1)</b>
    //  will set a tempo of a dotted quarter = 40, after 1/4 from the beginning, and will toggle the tempo interpolation to next tempo.<br />
    //  If more than one tempo need to be assigned to a given measure, one needs to use the general syntax for <m>TEMPO_OR_LIST_OF_TEMPI</m>, which is
    //  <b>(<m>TEMPO1</m> <m>TEMPO2</m> <m>TEMPO3</m>...)</b>, where each tempo must be in one the forms explained above. As an example, consider
    //  <b>((60) (1/4 70 1/16) (1/8 60 1/8 1) (1/8 80 3/8))</b>, where four tempi have been defined. The order of tempi is irrelevant,
    //  only their onset is accounted for. <br />

#define BACH_DOC_MEASUREINFO_SYNTAX
	//	Measureinfo is the information about time signature and tempo, plus some other optional specifications concerning the measure itself.
	//	This can be a single <b><m>TIME_SIGNATURE</m> <m>TEMPO</m></b> valid for all voices and all measures, or a llll containing for each measure and each voice
	//  an llll in the form <b>(<m>TIME_SIGNATURE</m> <m>TEMPO_OR_LIST_OF_TEMPI</m> <m>SPECIFICATION1</m> <m>SPECIFICATION2</m>...)</b>.
	//  All elements except for the <m>TIME_SIGNATURE</m> are optional. <br /> <br />
	//  The <m>TIME_SIGNATURE</m> is an llll containing the measure time signature, in one of the following forms: <br />
	//  - <b>(<m>numerator</m> <m>denominator</m>)</b> for standard time signatures. For instance, <b>(4 4)</b> corresponds to a 4/4 time signature. <br />
	//  - <b>((<m>numerator1</m> <m>numerator2</m> <m>numerator3</m>...) <m>denominator</m>)</b> for time
	//  signatures where the numerator is a sum of numbers.For instance <b>((3 2 3) 8)</b>
	//  corresponds to a (3+2+3)/8 time signature. <br /> <br />
    //  The <m>TEMPO_OR_LIST_OF_TEMPI</m> represent in its simplest form, a single tempo. <br />
    //  @copy BACH_DOC_TEMPO_SYNTAX
	//  Also, one might add an integer number at the beginning of each measure llll to indicate that the given measureinfo reference is valid for a
	//  certain number of measures, such as <b>(<m>how_many_measures</m> <m>TIME_SIGNATURE</m> <m>TEMPO_OR_LIST_OF_TEMPI</m> <m>SPECIFICATION1</m> <m>SPECIFICATION2</m>...)</b>.
	//  For instance <b>(5 (4 4) ((80) (1/4 160 1/2)))</b> creates 5 measures of 4/4, each one starting with quarter = 80, and then each one accelerating
	//  until 1/4 = 160 exactly at half of the measure. For instance
	//  <b> (((4 4) (1/8 60)) ((2 4) (1/4 50 1/4 1)) (4 (4 4)) (nil (180)))</b> means that we start a bar 1 in 4/4 and octave note = 60, then we 
	//  pass at 2/4 and quarter = 50 after 1/4 of measure 2, and at that moment, an accelerando starts. The accelerando lasts during 4 4/4-measures, 
	//  and then ends at the following measure on a new tempo of quarter = 180. <br /> <br />
	//  @copy BACH_DOC_MEASUREINFO_SYNTAX_SINGLE_SPECIFICATION
 
#define BACH_DOC_MEASUREINFO_SYNTAX_SINGLE_SPECIFICATION
	//  Each <m>SPECIFICATION</m> is an optional llll representing a given measure parameter, in the form <b>(<m>parameter_name</m> <m>parameter_value</m>)</b>.
	//  The <m>parameter_name</m> is a symbol identifying the parameter. The complete list of parameters symbols and their corresponding 
	//  values is the following one: <br />
	//  - <b>width</b>: assigns a fixed width to a measure. It expects as value a fixed width in pixels that the measure will have (referred to the default
	//  vertical and horizontal zoom of 100%, and modified accordingly to those). Assigning a <m>width</m> parameter will also lock the measure barline, 
	//  so that the width will remain the same, no matter how many chords and notes the measure does and will contain. Use the "auto" symbol
	//  instead of the fixed width to revert to the automatic measure width assignment (depending on the measure content). <br />
	//  - <b>widthfactor</b>: assigns a local factor for the spacing. It expects as value a multiplier factor, which will be applied to the whole measure 
	//  spacing, and which will compress (for values less than 1) or expand (for values 
	//  greater than 1) the width of the measure and the spacing of its chords accordingly. In this case, the measure barline is not locked, only the 
	//  width factor is changed. <br />
	//  - <b>barline</b>: assigns a specific ending barline to a given measure. It expects a specific letter, representing the barline type. This letter
	//  can be one of the following ones: 'a' = automatic barline (defaul), 'n' = normal barline, 'd' = dashed barline, 'p' = dotted barline (p = "points"),
	//  't' = double barline (t = "two"), 's' = solid barline, 'f' = final barline, 'h' = hidden barline. <br />.
	//  - <b>shownumber</b>: deals with measure numbers. If an "off" symbol is given as value, it means that the measure number of the current measure will 
	//  not be displayed. If a specific number is given, it will be assigned as a forced measure number to be displayed, for instance <b>(shownumber -4)</b> will
	//  show -4 as measure number (also see the attribute <m>measurenumberoffset</m>). If an "auto" symbol is given, it will show the measure's automatically 
	//  assigned measure number (default). <br />
	//  - <b>boxes</b>: assign custom beaming boxes. It expects custom beaming boxes for the measure, as a plain list of rational numbers. 
	//  Custom boxing allows you to handle beam grouping inside the measure differently than beat-wise. 
	//  Each number of the expected list is the symbolic width of each beaming box inside the measure. 
	//  If the given boxes don't fill the whole measure, the last one is padded. For instance, in a 4/4 measure,
	//  <b>(boxes 1/8)</b> will simply use eight 1/8-wide boxes to beam elements inside the measure, instead of the default 1/4 wide ones (beats).
	//  This is equivalent to <b>(boxes 1/8 1/8 1/8 1/8 1/8 1/8 1/8 1/8)</b>. 
	//  Analogously, <b>(boxes 1/2 1/8 1/4 1/8)</b> is a more exotic boxing for the same time signature. <br />
	//  As a final example, (((4 4) (60) (widthfactor 0.5) (barline h) (shownumber off))) for a given measure sets a 4/4 time signature, a quarter = 60 tempo,
	//  compresses the measure by a factor of two, hides its final barline and its number. 
	//  <br /> <br />
	
	
#define BACH_DOC_HEADER_SYNTAX
	//  The header contains meta-information about the score. Such information is given in the form <b>(<m>HEADER_LLLL1</m> <m>HEADER_LLLL2</m>...)</b>
	//  where each <m>HEADER_LLLL</m> is in the form <b>(<m>header_element_name</m> <m>CONTENT</m>)</b>. The complete list of header element names
	//  and the expected content is the following one: <br />
	//  – <b>clefs</b>: introduces the used clefs; one clef symbol for each voice is expected. The number of voices is automatically
	//  updated to the number of clef symbols inserted.
	//  Since clefs can be set both as header element and as attribute, also see the <m>clefs</m> attribute. 
	//  @copy BACH_DOC_CLEFS_SYMBOL
	//  – <b>keys</b>: introduces the used key signatures; one key signature symbol for each voice is expected. If less are given, last one is padded.
	//  Since key signatures can be set both as header element and as attribute, also see the <m>keys</m> attribute. 
	//  @copy BACH_DOC_KEY_SIGNATURE_SYMBOL
	//  – <b>voicenames</b>: introduces the voice names specification, one name (atom) for each voice is expected.
	//  If a voice have more than one name, an llll with the list of names must be introduced. To skip names for a voice use <b>nil</b> or <b>()</b>.
	//  Since voice names can be set both as header element and as attribute, also see the <m>voicenames</m> attribute. 
	//  <br /> <br />
	//  – <b>midichannels</b>: introduces the MIDI channels specification, one integer for each voice is expected.
	//  Since MIDI channels can be set both as header element and as attribute, also see the <m>midichannels</m> attribute. 
	//  <br /> <br />
	//  – <b>stafflines</b>: set the staff lines configurations. A list of elements (one for each voice) is expected. Since staff lines can be set both as header element and 
	//  as attribute, also see the <m>stafflines</m> attribute. Each element can be in one of the following forms:
	//  either <b><m>number_of_stafflines</m></b>, setting the number of stafflines for the voice, which will be distributed evenly around
	//  the middle line of the default staff, or a wrapped llll in the form <b>(<m>index_staff_line1</m> <m>index_staff_line2</m>...)</b>
	//  where each index is the position of a line to be drawn. Line 1 correspond to the bottommost staffline of a standard staff; 
	//  line 5 correspond to the topmost staffline of a standard staff. Integers need not be positive: indices like -2 or 7 will be 
	//  extrapolated from the standard staff. The total number of lines is thus the length of such llll.
	//  <br /> <br />
	//  – <b>markers</b>: specifies the markers. A list of elements (one for each marker) is expected. For <o>bach.roll</o> markers, or for 
	//  <o>bach.score</o> markers attached to milliseconds position, each element
	//  must be in the form <b>(<m>position_ms</m> <m>marker_name(s)</m> <m>role</m> <m>content</m>)</b> where the two last parameters
	//  are optional and only supported by <o>bach.roll</o> (ignore them in <o>bach.score</o>). The <m>position_ms</m> is a floating number
	//  specifying the marker position in milliseconds; the <m>marker_name(s)</m> is either a single symbol, or a wrapped llll, or 
	//  <b>nil</b> or <b>()</b> if marker has no name. For <o>bach.score</o> measure-attached markers the syntax is: <b>(<m>TIMEPOINT</m> <m>marker_name(s)</m>)</b>
	//  where <m>TIMEPOINT</m> identifies a time point.
	// 	@copy BACH_DOC_TIMEPOINT_SYNTAX_SCORE
	//  – <b>slotinfo</b>: specifies the information about the types and the global characteristics of each slot.
	//  @copy BACH_DOC_SLOTINFO_SYNTAX
	//  – <b>commands</b>: specifies the information about the commands. A list of elements (one for each command) is expected.
	//  @copy BACH_DOC_COMMANDS_SYNTAX
	//  – <b>groups</b>: (<o>bach.roll</o> only) specifies the information about the grouped chords.
	//  Although bach.roll syntax, as everything in bach, is transparent (and you are thus allowed to modify any element), 
	//  there are extremely few cases where you might need to set manually the group information in llll form. 
	//  Usually, such information is only dealt with via the interface (i.e. by grouping and ungrouping things), 
	//  and the group header element is only a way to embed or save such information with the object. 
	//  Nevertheless, nothing in principle prevents you from setting groups via message. The syntax is the following one:
	//  <b>(groups <m>GROUP1</m> <m>GROUP2</m>...)</b>, where each <m>GROUP</m> is an llll having the syntax
	//  <b>(<m>ADDRESS_CHORD1</m> <m>ADDRESS_CHORD2</m> <m>ADDRESS_CHORD3</m>...)</b>, where each address llll identifies one of the 
	//  chord inside the groups, via the following syntax: <b>(<m>voice_number</m> <m>chord_index</m>)</b>, 
	//  where the chord index is the position of the chord inside the sequence of chords of the voice (ordered by onsets).
    //  – <b>articulationinfo</b>: specifies the information about custom defined articulation.
    //  @copy BACH_DOC_ARTICULATIONINFO_SYNTAX
    //  – <b>noteheadinfo</b>: specifies the information about custom defined noteheads.
    //  @copy BACH_DOC_NOTEHEADINFO_SYNTAX
    //  – <b>numparts</b>: specifies the information about the part assignment (see <m>numparts</m> attribute).
    //  – <b>loop</b>: specifies the information about the loop, as for the <m>loop</m> attribute, as a starting and ending point (in milliseconds, or as timepoints).

#define BACH_DOC_ARTICULATIONINFO_SYNTAX
    //  The general syntax for the articulationinfo llll in a notation object header is: <b>(articulationinfo <m>CUSTOMARTICULATION1</m> <m>CUSTOMARTICULATION2</m>...)</b>.
    //  Each <m>CUSTOMARTICULATION</m> llll has the form <b>(<m>parameter1</m> <m>content1</m>) (<m>parameter2</m> <m>content2</m>)...</b>, where
    //  each <m>parameter</m> is some propriety of the custom articulation to be defined, followed by its value.
    //  The complete list of parameters symbols and their corresponding expected content is the following one: <br />
    // – <b>fullname</b>: a symbol defining the articulation full name (e.g. "myfermata"). <br />
    // – <b>shortname</b>: a symbol defining the articulation short name (e.g. "myf"). <br />
    // – <b>alias</b>: up to 5 other names which will be mapped on the articulation when found in articulation slots. <br />
    // – <b>font</b>: a symbol containing the font name, or "default" (in order to use the defined "articulationsfont"). <br />
    // – <b>basept</b>: the basic font size (corresponding to a no-vzoom situation). <br />
    // – <b>position</b>: one of the following symbols: "abovenote", "belownote", "noteside", "stemsidenearnotehead", "stemsidenearflag", "manual", determining the position of the articulation. <br />
    // – <b>position</b>: one of the following symbols: "abovenote", "belownote", "noteside", "stemsidenearnotehead", "stemsidenearflag", "manual", determining the position of the articulation. <br />
    // <br />
    // The following specifications determine the characters used:
    // – <b>mainchar</b>: symbol or unicode value determining the main articulation character (above notes). <br />
    // – <b>flippedchar</b>: symbol or unicode value determining the flipped articulation character (below notes). <br />
    // – <b>extchar</b>: symbol or unicode value of the articulation extension, if any (e.g.: the tilde in a trill line). <br />
    // <br />
    // The following specifications will refer to unzoomed situations, and will be scaled according to the zoom:
    // – <b>mainxshift</b>, <b>mainyshift</b>: x and y shift of positioning for the main character (positive y shift moves up). <br />
    // – <b>flippedxshift</b>, <b>flippedyshift</b>: x and y shift of positioning for the flipped character. <br />
    // – <b>mainheight</b>, <b>flippedheight</b>: height of the main and flipped characters. <br />
    // – <b>mainycenter</b>, <b>flippedycenter</b>: position of the vertical center of the articulation for main and flipped char. <br />
    // – <b>outsidestaffynudge</b>: additional y shift to push articulation farther from staff. <br />
    // – <b>extyshift</b>: horizontal offset for the beginning of the articulation extensions. <br />
    // <br />
    // The following specifications will set the markings used when exporting articulations to MusicXML format:
    // – <b>xmlornament</b>: text to be exported as MusicXML ornament whenever the articulation is found, or "none" if no export needed (default). <br />
    // – <b>xmltechnical</b>: text to be exported as MusicXML technical tag whenever the articulation is found,
    // or "none" if no export needed (default), or "custom" if export must be of "other-technical" type, defining a custom technical tag.<br />
    // – <b>xmlarticulations</b>: text to be exported as MusicXML articulation tag whenever the articulation is found,
    // or "none" if no export needed (default), or "custom" if export must be of "other-articulation" type, defining a custom articulation tag.<br />
    // <br />
    // Finally, one can assign an option specification, possibly followed by a list of symbols, to set some flags.
    // Symbols must be among the following ones:<br />
    // · <b>avoidlines</b>: avoid staff lines.<br />
    // · <b>outsidestaff</b>: always place outside staff.<br />
    // · <b>centerovernote</b>: center over the notehead.<br />
    // · <b>centeroverstem</b>: center over the stem.<br />
    // · <b>spanties</b>: articulation extension spans sequences of tied notes.<br />
    // · copywhencloned: copy articulation while copying notes.<br />
    // · copywhenclonedtosamechord: copy articulation while copying notes, and also when copying notes into the same chord.<br />
    // · copywhensplit: copy articulation to all notes when notes are split, or retranscribed as tied sequences.<br />
    // · shiftwithbeams: shift vertically according to beams.<br />
    // <br />


#define BACH_DOC_NOTEHEADINFO_SYNTAX
    //  The general syntax for the articulationinfo llll in a notation object header is: <b>(articulationinfo <m>CUSTOMNOTEHEAD1</m> <m>CUSTOMNOTEHEAD2</m>...)</b>.
    //  Each <m>CUSTOMNOTEHEAD</m> llll has the form <b>(<m>parameter1</m> <m>content1</m>) (<m>parameter2</m> <m>content2</m>)...</b>, where
    //  each <m>parameter</m> is some propriety of the custom notehead to be defined, followed by its value.
    //  The complete list of parameters symbols and their corresponding expected content is the following one: <br />
    // – <b>fullname</b>: a symbol defining the articulation full name (e.g. "curly").<br />
    // – <b>shortname</b>: a symbol defining the articulation short name (e.g. "cr").<br />
    // – <b>alias</b>: up to 5 other names which will be mapped on the articulation when found in articulation slots.<br />
    // – <b>font</b>: a symbol containing the font name, or "default" (in order to use the defined "notationfont").<br />
    // – <b>basept</b>: the basic font size (corresponding to a no-vzoom situation).<br />
    // – <b>char</b>: symbol or unicode value determining the notehead character. If two values are input, they refer respectively to the "black" and "white" flavours
    // (assigned <o>bach.score</o> to black and white notes). If three values are input, they refer respectively to "black", "white" and "whole note" flavours.
    // If four values are input they refer respectively to "black", "white", "whole note" and "double whole note". <br />
    // <br />
    // The following specifications will refer to unzoomed situations, and will be scaled according to the zoom: <br />
    // – <b>xshift</b>: horizontal shift (positive values move right). <br />
    // – <b>yshift</b>: vertical shift (positive values move up). <br />
    // – <b>width</b>: the width of the notehead. <br />
    // – <b>xshiftsmall</b>: same as xshift, but for grace notes. <br />
    // – <b>yshiftsmall</b>: same as yshift, but for grace notes. <br />
    // – <b>dlstartxshift</b>: horizontal offset for the beginning of the duration line. <br />
    // <br />


#define BACH_DOC_COMMANDS_SYNTAX
	//  The general syntax for an llll defining commands in a notation object header is:
	//  <b>(commands (<m>command_num1</m> <m>SPECIFICATIONS1</m>) (<m>command_num2</m> <m>SPECIFICATIONS2</m>)...)</b>
	//  where the <m>command_num1</m> are the command numbers (1 to 30), followed by their corresponding command specification. You don't need to give the information about all slots
	//  at input (only the one that you will use), nor the command numbers have to be sorted in any way. On the other hand, at output, the commands
	//  are always output for all commands, sorted in ascending order.
	//  Each <m>SPECIFICATIONS</m> llll has the form <b>(<m>parameter1</m> <m>content1</m>) (<m>parameter2</m> <m>content2</m>)...</b>, where
	//  each <m>parameter</m> is a symbol followed by some content specifying a field of the commands.
	//  The list of parameters symbols and their corresponding expected content is the following one: <br />
	//  – <b>note</b>: expects the symbol which will replace the "note" symbol in the playout (given as a unique symbol). <br />
	//  – <b>chord</b>: expects the symbol which will replace the "chord" symbol in the playout (given as a unique symbol). <br />
	//  – <b>rest</b>: expects the symbol which will replace the "rest" symbol in the playout (given as a unique symbol). <br />
	//  – <b>key</b>: expects the character or the ASCII value of a key to be mapped as a hotkey for the slot. <br />
	//  <br /> <br />

#define BACH_DOC_SLOTINFO_SYNTAX
	//  The general syntax for a slotinfo llll in a notation object header is: <b>(slotinfo (<m>slot_num1</m> <m>SPECIFICATIONS1</m>) (<m>slot_num2</m> <m>SPECIFICATIONS2</m>)...)</b>,
	//  where the <m>slot_num</m> are the slot numbers (1 to 30), followed by their corresponding slotinfo specification. You don't need to give the information about all slots
	//  at input (only the one that you will use), nor the slot numbers have to be sorted in any way. On the other hand, at output, the slotinfo
	//  is always output for all slots, sorted in ascending order.
	//  Each <m>SPECIFICATIONS</m> llll has the form <b>(<m>parameter1</m> <m>content1</m>) (<m>parameter2</m> <m>content2</m>)...</b>, where
	//  each <m>parameter</m> is a symbol followed by some content specifying a field of the slotinfo.
	//  The complete list of parameters symbols and their corresponding expected content is the following one: <br />
	//  – <b>name</b>: expects the name you want to give to the slot (given as a unique symbol). <br />
	//  – <b>type</b>: expects one of the following symbols, defining the slot type: "function", "int", "float", "intlist", "floatlist", "text", 
	//  "filelist", "llll", "spat", "togglematrix", "intmatrix", "floatmatrix", "filter, "dynfilter", "color", "3dfunction",
    // "articulations", "notehead, "dynamics", "none".  <br />
    //  - <b>access</b>: sets the slot accessibility, and expects a symbol. Default is "readandwrite" (slot is readable and writable);
    // you can also use "readonly" (slot is only readable, not writable via interface), or "none" (slot window can't even be opened, slot
    // content cannot be accessed).<br />
	//  – <b>range</b>: followed by two numbers, sets the minimum and maximum values the slot range (vertical axis for function and 3dfunction slots, or number
	//  range for number slots) may assume. <br />
	//  – <b>key</b>: expects the character or the ASCII value of a key to be mapped as a hotkey for the slot. <br />
	//  – <b>slope</b>: expects a parameter (-1 to 1, 0 = linear) to exponentially represent the displayed range values of the slot. <br />
	//  – <b>width</b>: expects a value determining the width of the slot window (scaled according to the object's vertical zoom). You can also put "temporal" 
	//  if you want the window to correspond exactly to the note length, which is handy when dealing e.g. with envelopes or spatializations. <br />
	//  – <b>height</b>: a value determining the height of the slot window (scaled according to the object's vertical zoom). You can also put "auto" 
	//  if you want to leave an automatically calculated height (default). <br />
	//  – <b>ysnap</b>: sets, for function or 3dfunction slots, some privileged Y points to which the points will be snapped
	//  upon Shift+Alt+mousedrag. <br />
	//  – <b>zsnap</b>: sets, for 3function slots, some privileged Z points to which the points will be snapped
	//  upon Shift+Ctrl+Alt+mousedrag (mac). <br />
	//  – <b>domain</b>: followed by two numbers, for function and 3dfunction slots, replaces the standard 0 to 1 domain with any input domain (input numbers 
	//  are minimum and maximum). <br />
	//  – <b>domainslope</b>: a slope (-1 to 1, 0 = linear) to exponentially rescale the domain display. <br />
	//  – <b>default</b>: a numeric value (for numeric slots) determining the slot default value. <br />
	//  – <b>representation</b>: it could expect one of the following things. 1: Symbols defining units of measurement (e.g. "Hz", "ms"...), for numeric 
	//  slots one symbol is expected, for function slots if one symbol is given, it is applied to the Y axis, if two symbols are given they are 
	//  applied to the X and Y axis, for 3dfunction slots up to three symbols can be given, the third one referring to the Z axis, use <b>nil</b> or
	//  <b>()</b> to skip assignment for an axis. For filter and dynfilter slots, you can assign "Hz" or "cents" as unit of measurement
	//  and it will be used to display the cutoff frequency accordingly. 2: An enumeration list (only for int 
	//  and intlist slots), mapping each integer to an element of this enumeration list (e.g. in an int slot from 1 to 3, a 
	//  slot_representation "(one two three)" will display "one" at the place of 1, "two" at the place of 2, "three" at the place of 3). 
	//  These symbols will never be output upon dump or play, they will be just displayed. 3: 
	//  For matrix-typed slots, it can be either a llll containing the number of rows and columns, such as (3 4), or a llll containing 
	//   the names of the rows and columns, such as ((or fee foo) (col1 col2 col3)). To give units to different axes, just list them, such as: Hz dB.
	//  – <b>zrange</b>: as "range", but for the Z spatial dimension (used by the 3dfunction slot: the Z dimension is the one "coming out" from the screen). <br />
	//  – <b>zslope</b>: as "slope", but for the Z spatial dimention (used by the 3dfunction slot). <br />
	//  – <b>singleslotfortiednotes</b>: (for bach.score only) tells whether tied sequences of notes have just one slot, the one corresponding 
	//  to the first note of the sequence. <br />
    //  – <b>copywhensplit</b>: tells whether this slot should be copied when a note is split into a sequence of multiple notes (e.g. via quantization). <br />
    //  - <b>follownotehead</b>: forces to automatically modify the value of the slot depending on the notehead trimming (useful if the slot
    //   value is something associated to the notehead, such as the starting point for reading a sample).<br />
	//  <br />
	//  You are not obliged to input all the fields: you can give as input only the required fields.
	//  Also at output, only the needed fields are given (e.g. the "zrange" is only output for 3dfunction slots, and so on).
	//  Setting an individual field for a given will not change any other field, unless the type is changed, in which case
	//  a conversion on all the slots is performed (if possible, i.e. if slots are compatible) otherwise the slot data of the given slot is lost.
	//  While converting slots, also some other fields may be changed to default values for the new slot type. <br />
	//  Some more fields can be set via the slotinfo. These fields are never retrieved when the slotinfo is queried via a 
	//  <m>dump</m> message, since they correspond to standard attribute values of the notation object: <br />
	//  - <b>background</b>: this should be set to 1 if one needs the slot to be constantly painted in the background or 0 otherwise. 
	//  This information is constantly synchronized with the <m>bgslots</m> attribute. <br />
	//  - <b>popup</b> (except bach.slot): this should be set to 1 if one needs the slot to show up in the note+popup+menu, or to 0 otherwise. 
	//  This information is constantly synchronized with the <m>popupmenuslots</m> attribute. <br />
	//  - <b>rightclick</b> (except bach.slot): this should be set to 1 if one wants that the right click (or two-fingers tap) on a note head directly 
	//  pops up the slot window of the current slot, or to 0 otherwise.
	//  This information is constantly synchronized with the <m>rightclickslot</m> attribute. <br />
	//  - <b>linkto</b> (except bach.slot): this field defines the possible slot linkage. Slot linkage is a way to entangle some notation or 
	//  display features to the content of a given slot. You can specify here to which feature the slot should be linked, 
	//  via one of the following symbols: "none", "lyrics", "notecolor", "noteheadadjust", "noteheadchar", "noteheadfont", "notesize". <br />
	//  <br />
	

#define BACH_DOC_COMMANDS_GENERAL
	// Commands are a mechanism to output selected content with given labels. 
	// You can define up to 5 user commands which will send user-defined messages upon a note or chord evaluation.
	// The idea is that you can map each command to a hotkey: if one triggers the hot key (when something is selected), 
	// this will cause the output of the notes/chord content from the playouts, exactly as if such notes/chords were played. 
	// The only difference with the simple play situation, is that the router of those messages is not the "note" or "chord" symbol, 
	// but rather the custom symbol defined at the command declaration. This allows you to properly detect and route the message.
	// <br /> <br />

#define BACH_DOC_SLOTINFO_GENERAL
	// The slotinfo is the information about the types, ranges and many further characteristics of each one of the slots.
	// For bach.roll and bach.score, it is a global information: changing the slotinfo for a given slot will 
	// affect such slot for all the notes inside the notation object. See the <m>llll</m> method to know more about its syntax.
	
#define BACH_DOC_RESET_SLOTINFO
	// A <m>resetslotinfo</m> message will reset the all the <m>slotinfo</m> to the original one. 
	// Beware that this may entail slot type conversions, which might result in loss of data if slot types are not compatible.
	// @copy BACH_DOC_SLOTINFO_GENERAL

#define BACH_DOC_RESET_ARTICULATIONINFO
    // A <m>resetarticulationinfo</m> message will reset the all the <m>articulationinfo</m> to the original one, i.e. will delete
    // all the user-defined articulations.

#define BACH_DOC_RESET_NOTEHEADINFO
    // A <m>resetnoteheadinfo</m> message will reset the all the <m>noteheadinfo</m> to the original one, i.e. will delete
    // all the user-defined noteheads.

#define BACH_DOC_ASCII_ACCIDENTALS_SYNTAX
	// Accidentals are defined as string of ASCII characters, each identifying one accidental.
	// The list of allowed characters is the following one: <br />
	// "n" = natural <br />
	// "#" = sharp (+1/2 tone) <br />
	// "x" = double sharp (+ 1 tone) <br />
	// "+" = monesis = quarter sharp (+1/4 tone) <br />
	// "^" = +1/8 tone <br />
	// "b" = flat (-1/2 tone) <br />
	// "d" or "-" = mobemol = quarter flat (-1/4 tone) <br />
	// "v" = -1/8 tone <br />
	// If no accidental is defined, the natural is used by default.
	// <br /> <br />

#define BACH_DOC_KEY_SIGNATURE_SYMBOL
	// The syntax for the single key signature must be an unique symbol (no spaces) with: 
	// <b><m>notename</m>-<m>optional:accidental</m>-<m>optional:mode</m></b>.
	// Dashes are only set in order to separate parts of the symbol, but must not be included in the symbol. <br /> <br />
	// Note names are allowed both in anglo-saxon (C, D, E...) and in latin (Do, Re, Mi) format. In both ways,
	// they are case insensitive ("c" or "C", "do" or "DO" is the same). <br /> <br />
	// @copy BACH_DOC_ASCII_ACCIDENTALS_SYNTAX
	// The mode can be either "M" (major) or "m" minor. If no mode is defined, the major is used by default.
	// <br /> <br />

#define BACH_DOC_CLEFS_SYMBOL
	// Each clef symbol can be one of the following: "G", "F", "FG", "FGG", "FFG", "FFGG", "G8va", "G15ma", "G8vb", "G15mb", "F8va", "F15ma", "F8vb", "F15mb",
	// "Soprano", "Mezzo", "Alto", "Tenor", "Soprano", "Mezzo", "Tenor", "Alto", "Barytone", "Percussion", "None". <br />
	// Clefs such as "FGG" correspond to multiple-staff voices: for instance, in this case, we have a standard piano staff ("FG") with an additional 
	// G clef superposed (transposed a 15ma above). The "G8va", "G15ma", "G8vb", "G15mb", "F8va", "F15ma", "F8vb", "F15mb" symbols correspond to
    // octave-transposed clefs. For instance, "G8va" is the G clef, transposed one octave above, whereas "F15mb" is the F clef transposed two octaves below.
	// <br /> <br />

#define BACH_DOC_CLEFS
	// Sets the clefs. A list of symbols is expected, the length of the list will also automatically change the <m>numvoices</m> attribute
	// and update the number of voices.
	// @copy BACH_DOC_CLEFS_SYMBOL
	// A special message <b>clefs auto</b> will detect automatically the most appropriate clefs to display
	// the musical content, and will set them: such message will apply to all the existing voices, and will not change the number of voices.
	// You can use the "auto" symbol instead of any symbol in order to have bach detect automatically the most appropriate clefs
	// for the given voice, depending on its notes (e.g. <b>clefs auto G FG</b>). However, in this case the message will also change the
	// <m>numvoices</m> attribute, as for the standard case.
	// <br /> <br />

#define BACH_DOC_VOICENAMES
	// Sets the voice names. An llll containing as many elements as the number of voices is expected,
	// if less elements are input, the last one is padded.
	// Each voice name can be either a single symbol, or a wrapped llll, for multiple naming (if you want to assign
	// more than one name to the same voice).
	// Use the <b>()</b> or <b>nil</b> list to skip the naming for a voice.
	// For instance: <b>voicenames Foo (John Ringo) () "Electric Piano"</b> sets "Foo" as name for the first voice,
	// sets both "John" and "Ringo" as names for the second one, leaves the third voice without name, and sets "Electric Piano"
	// (as a single symbol) as name for the fourth voice. 
	// <br /> <br />

#define BACH_DOC_STAFFLINES
	// Sets the staff lines. An llll containing as many elements as the number of voices is expected, 
	// if less elements are input, the last one is padded.
	// Each staff line element (for the given voice) can be either an integer number,
	// representing the number of stafflines the voice will have (e.g. <b>3</b>, meaning: just 3 stafflines, 
	// located around the middle line of a standard 5-lines-staff), or an llll, containing the explicit
	// indices of the lines to be displayed. In this case, 1 correspond to the bottommost staffline of 
	// the standard 5-lines-staff, 5 to the topmost one, and all other numbers work accordingly.
	// Zero or negative indices are also allowed. For instance, <b>(0 5 6)</b> will set as stafflines the one below
	// the bottommost default one, the topmost line of a default staff, and the one above.
	// Use <b>0</b> or <b>nil</b> or <b>()</b> to hide all the stafflines of a staff. 
	// <br /> <br />


#define BACH_DOC_KEYS
	// Sets the key signatures. A list of symbols is expected, one symbol for each voice.
	// If less symbols are entered, the last one is padded.
	// @copy BACH_DOC_KEY_SIGNATURE_SYMBOL 

#define BACH_DOC_VOICESPACING
	// Sets the spaces between voices. A list of floating numbers is expected, one more than the number of voices.
	// Indeed the first number will correspond to the blank space above the first voice, the second one to the space 
	// between the first and second voice, and so on, till the last one which will correspond to the space below
	// the last voice. Numbers are pixel distances (rescaled with respect to the <m>vzoom</m> attribute).
	// <br /> <br />

#define BACH_DOC_ZOOM
	// Sets the horizontal zoom percentage (100 being the default value).
	// <br /> <br />

#define BACH_DOC_VZOOM
	// Sets the vertical zoom percentage (<b>auto</b> being the default value).
	// This factor is actually a global zoom factor, according to which every displayed element is rescaled. 
	// This means, for instance that the distance between elements (and not only the size of elements) 
	// changes as this <m>vzoom</m> is changed.
	// A fixed value such as <m>100</m> will keep the global zoom fixed as the object vertical size changes.
	// Use the <b>auto</b> symbol to link the vertical zoom to the object box height. 
	// In this case you can retrieve the vertical
	// zoom via <m>getvzoom</m>.
	// <br /> <br />

#define BACH_DOC_ROLL_START_PAD
	// In <o>bach.roll</o>, this pad is extremely useful if you have chords around 0ms
	// having a lot of accidentals. In this case you can shift, via this pad, the position of the 0ms on the screen, so that all accidentals
	// are correctly displayed. Also see the message <m>adjustadditionalstartpad</m>.
	// <br /> <br />
	
#define BACH_DOC_STAFFLINE_STEP
	// A step is half of the vertical distance between two stafflines. 
	// It corresponds the the vertical distance between the notehead centers of two subsequent diatonic notes. <br /> <br />
	// <br /> <br />
	
	
#define BACH_DOC_SCORE_LEVELTYPE
	// Level type information concerns the "life" of the rhythmic levels inside a given measure. Indeed, some of those levels may have been
	// created by the user, some other levels may have been refined by <o>bach.score</o>, some other again may correspond to beats, and may been created to make
	// the rhythmic tree compatible with the time signature (see <m>maketreecompatiblewithts</m>). All such differences are important to <o>bach.score</o>,
	// in order to know how it should behave towards such levels: it'll take great care of the level you've introduced yourself, while it'll 
	// bother less to modify levels it had refined itself, and so on. This information is thus useful for a correct handling of the score interface. <br />
	// Level type information can only be stored in gathered-syntax lllls, at the beginning of each level in an llll of the following form: 
	// <b>(leveltype <m>type</m>)</b>, where <m>type</m> is an integer defining the type of the level.
	// Such integer is undocumented, and you should always consider level types as being opaque for the user: never set them "manually", only
	// deal with them at output or while saving the content. Removing leveltype lllls yields a perfectly valid <o>bach.score</o> llll.
	// <br /> <br />

#define BACH_DOC_SCORE_SYNCOPATION
	// A syncopation can be either tied or merged, depending, respectively, if it is represented by two tied chords, or by a single (larger) chord, 
	// placed across a given beat. Syncopations are characterized in <o>bach.score</o> by a precise position inside the measure, which is the symbolic onset 
	// (with respect to the measure) of the beat across which the syncopation happens. Once we have such position, one can see the two 
	// sides of the syncopation: a left and a right side, each characterized by their duration. 
	// <br /> <br />


#define BACH_DOC_RELATIVE_MODIFICATIONS
	// All parameters, except for <o>bach.score</o>'s timepoints, also support a relative modification syntax, which modifies the existing values instead
	// Relative modifications of a parameter are handled via lllls of the type <b>(<m>value</m> <m>function</m>)</b>, where
	// the <m>function</m> is one of the following symbols: "plus", "minus", "times", "div". Such modification applies the corresponding
	// function to the current value of the parameter and the inserted <m>value</m>. For instance, <b>(100 minus)</b> removes 100 to the current
	// value of the parameter, while <b>(2. times)</b> multiplies it by two.
	// <br /> <br />


#define BACH_DOC_EQUATION_MODIFICATIONS
	// All separate parameters, except for measureinfo, ties and slots, can also be modified via a generic equation. In order to do so,
	// the message symbol must be followed by an <m>=</m> sign (with spaces before and after it), and then by the desired equation. 
	// The standard symbolic variables are available. <br />
	// @copy BACH_DOC_SYMBOLIC_VARIABLES
	// For instance, one could define <b>velocity = duration / 100. + onset * 0.01</b> or <b>cents = cents + 200</b>, or
	// <b>onset = (cents - 6000) / 100 + 2000 * (voice - 1)</b>.
	// The equation syntax extends in a sense the relative modification syntax; however it is applied to the globality of the selection, and 
	// one cannot apply different equations to different notes inside the chord.
	// <br /> <br />

#define BACH_DOC_SYMBOLIC_VARIABLES
	// Symbolic variables are variables that can be used in the conditional selection or parameter modification processes. 
	// These are: <m>onset</m> (in ms), <m>duration</m> (in ms), <m>velocity</m>, <m>cents</m>, <m>tail</m> (position of the 
	// note end, in ms), <m>voice</m> (voice number). For <o>bach.score</o> you can also use: <m>symduration</m> (symbolic rational duration), 
	// <m>symonset</m> (symbolic rational onset inside the measure), <m>symtail</m> (sum of the two previous), <m>measure</m> (the measure number)
	// and <m>tie</m> (which is 1 if a tie starts, 2 if a tie ends and 3 if a tie both starts and ends, 0 otherwise). <br />
	// In addition, you also have the <m>index</m> symbol, corresponding to the index of the item: the index of the note in the chord (bottom-up),
	// the index of the chord in the measure or voice (left to right), the index of the measures, voices, markers, pitch breakpoints, etc.
    // (all left to right). In case you need to distinguish between chord index and note index, for a given note, you can explicitly use the
    // <m>chordindex</m> or <m>noteindex</m> symbols. <br />


#define BACH_DOC_SLOT_EDIT_MOUSE_COMMANDS
	// Common commands for all slots: <br />
	// • <m>doubleclick</m> on the slot window header (e.g. on the slot name): Edit the slot content in external editor. <br /> 
	// • <m>Cmd+doubleclick</m> on the slot window header (e.g. on the slot name): Erase all the slot content. <br /> 
	// <br />
	// For slots of type "function" and "3dfunction": <br />
	// • <m>click</m> inside the active part of the slot window: Add a point. <br />
	// • <m>Shift+click+drag</m>: Draw a rectangle to add/remove points to the current selection. <br />
	// • <m>click</m> on the slot window header (upper strip): Clear current selection. <br />
	// • <m>Cmd+click</m> (mac) or <m>Ctrl+click</m> (win) on a point: Delete clicked point (or all selected points, if point was selected). <br />
	// • <m>click+drag</m> on a point: Change the position of the point (or all selected points, if point was selected). <br />
	//    ↪ Add the <m>Shift</m> key to change either the horizontal or the vertical coordinate. <br />
	//    ↪ Add the <m>Shift+Alt</m> keys and drag vertically to snap the Y coordinate of the point to one of the previously defined <m>ysnap</m> values (in the <m>slotinfo</m>). <br />
	//    ↪ Add the <m>Shift+Ctrl</m> keys (mac) to move the point together with all the following ones. <br />
	//    ↪ Add the <m>Alt</m> key to delete all neighbours points while dragging. <br />
	// • <m>click+drag</m> on a segment: Change the vertical position of the segment ("function" slot only). <br />
	// • <m>Ctrl+click+drag</m> (mac) or <m>Shift+Ctrl+click+drag</m> (win) on a segment ("function" slot only) or 
	// on the ending point of a segment (also "3dfunction" slot): Change the slope of the segment. <br />
	// • <m>doubleclick</m> on a point: snap it to the average position between the previous and the next point. <br />
	//    ↪ Add the <m>Shift</m> key to snap the point to the Y value of the previous one. <br />
	//    ↪ Add the <m>Alt</m> key to snap the point to the Y value of the next one. <br />
	// • <m>Ctrl+Alt+click+drag</m> (mac) or <m>Shift+Ctrl+Alt+click+drag</m> (win) on a point: drag up/down to change its Z coordinate ("3dfunction" slot only). <br /> 
	//    ↪ Add the <m>Shift</m> key to snap the Z coordinate of the point to one of the previously defined <m>zsnap</m> values ("3dfunction" only). <br />
	// <br />
	// For slots of type "int", "float": <br />
	// • <m>click</m> on the strip: Add or modify existing number. <br />
	// • <m>click+drag</m> on the handle: Modify existing number. <br />
	//    ↪ Add the <m>Shift+Cmd</m> (mac) keys to enter the fine editing mode (only for cutoff frequency change). <br />
	// • <m>Cmd+Alt+click</m> (mac) or <m>Ctrl+Alt+click</m> (win) on the strip: Revert the number to the <m>default</m> field defined in the <m>slotinfo</m>. <br />
	// • <m>Cmd+click</m> on a strip: Delete the number <br />
    // • <m>doubleclick</m> on the displayed number: Type in new number directly <br />
	// <br />
    // For slots of type "intlist" and "floatlist": <br />
    // • <m>click</m> on a strip: Add or modify existing number. <br />
    // • <m>click+drag</m> on the handle: Modify existing number. <br />
    //    ↪ Add the <m>Shift+Cmd</m> (mac) keys to enter the fine editing mode (only for cutoff frequency change). <br />
    // • <m>Cmd+Alt+click</m> (mac) or <m>Ctrl+Alt+click</m> (win) on a strip: Revert the number to the <m>default</m> field defined in the <m>slotinfo</m>. <br />
    // • <m>Cmd+click</m> on a strip: Delete the number <br />
    // • <m>click</m> on the "add number..." label: Append a number to the list (slot "intlist" and "floatlist" only). <br />
    // <br />
	// For slots of type "text" and "llll": <br />
	// • <m>doubleclick</m> on the slot window: Edit text or llll directly. <br />
	// <br />
	// For slots of type "filelist": <br />
	// • <m>click</m> on the "add file..." label: Append a file to the list (choosen via a dialog box). <br />
	// • <m>Shift+click</m> on a file name: Replace the file witha  new one (choosen via a dialog box). <br />
	// • <m>click</m> on a file name: Make it active. <br />
	// • <m>Cmd+click</m> on a file name: Delete the file. <br />
	// <br />
	// For slots of type "color": <br />
	// • <m>doubleclick</m>: Start defining a color (if slot is empty). <br />
	// • <m>click</m> or <m>click+drag</m>: Change the color or the hue (if clicking on the side bar). <br />
	//    ↪ Add the <m>Shift+Cmd</m> (mac) keys to enter the fine editing mode (only for cutoff frequency change). <br />
	// • <m>Ctrl+click+drag</m> (mac) or <m>Shift+Ctrl+click+drag</m> (win) on the main rectangle: Change alpha value (transparency) by dragging up or down. <br />
	// <br />
	// For slots of type "spat": <br />
	// • <m>click</m>: Add a spat point. <br />
	// • <m>Cmd+click</m> (mac) or <m>Ctrl+click</m> (win) on a spat point: Delete clicked spat point. <br />
	// • <m>click+drag</m> on a point: Change the position of the point. <br />
	//    ↪ Add the <m>Shift</m> key to change either the horizontal or the vertical coordinate. <br />
	//    ↪ Add the <m>Shift+Ctrl</m> keys (mac) to move the spat point together with all the following ones. <br />
	//    ↪ Add the <m>Alt</m> key to delete all neighbours spat points while dragging. <br />
	// • <m>Ctrl+click+drag</m> (mac) or <m>Shift+Ctrl+click+drag</m> (win) on a spat point: Drag up or down to change the angle. <br />
	// • <m>Alt+click</m> on a spat point: Switch interpolation type (from linear to circular or vice versa). <br />
	// <br />
	// For slots of type "togglematrix": <br />
	// • <m>click</m> on a cell: Toggle the cell value <br />
	// <br />
	// For slots of type "intmatrix", "floatmatrix": <br />
	// • <m>click</m> or <m>click+drag</m> on a cell: Change the cell value <br />
	//    ↪ Add the <m>Shift+Cmd</m> (mac) keys to enter the fine editing mode (only for cutoff frequency change). <br />
	// • <m>Cmd+Alt+click</m> (mac) or <m>Ctrl+Alt+click</m> (win) on a cell: Revert the number to the <m>default</m> field defined in the <m>slotinfo</m>. <br />
	// <br />
	// For slots of type "filter": <br />
	// • <m>rightclick</m> or <m>twofingerstap</m>: Choose or change the filter type. <br />
	// • <m>click+drag</m> left or right: Change cutoff frequency. <br />
	//    ↪ Add the <m>Shift+Cmd</m> (mac) or <m>Shift+Ctrl</m> (win) keys to enter the fine editing mode. <br />
	// • <m>Ctrl+click+drag</m> (mac) or <m>Shift+Ctrl+click+drag</m> (win) up or down: Change Q (or slope). <br />
	// • <m>Shift+click+drag</m> up or down: Change gain. <br />
	// • <m>Cmd+Alt+click</m> (mac) or <m>Ctrl+Alt+click</m> (win): Revert gain to 0dB. <br />
	// <br />
	// For slots of type "dynfilter": <br />
	// • <m>doubleclick</m>: Add a filter at the click position <br />
	// • <m>rightclick</m> or <m>twofingerstap</m> on a filter column: Choose or change the filter type. <br />
	// • <m>Cmd+click</m> (mac) or <m>Ctrl+click</m> on a filter column: Delete filter. <br />
	// • <m>click+drag</m> on a filter column: Change filter cutoff frequency by dragging up or down. <br />
	// • <m>click+drag</m> on a red square: Change filter cutoff frequency by dragging up or down, change temporal position by dragging left or right. <br />
	//    ↪ Add the <m>Shift</m> key to change either the horizontal or the vertical coordinate. <br />
	//    ↪ Add the <m>Shift+Cmd</m> (mac) keys to enter the fine editing mode (only for cutoff frequency change). <br />
	// • <m>Ctrl+click+drag</m> (mac) or <m>Shift+Ctrl+click+drag</m> (win) on a filter column: Change Q (or slope) by dragging up or down. <br />
	// • <m>Shift+Ctrl+click+drag</m> (mac) on a filter column: Change gain by dragging up or down. <br />
	// • <m>Cmd+Alt+click</m> (mac) or <m>Ctrl+Alt+click</m> (win) on a filter column: Revert gain to 0dB. <br />
	// <br />
    // For slots of type "articulations": <br />
    // • <m>click</m>: Add an articulation. <br />
    // • <m>Cmd+click</m> (mac) or <m>Ctrl+click</m> (win): Delete an articulation. <br />
    // <br />
    // For slots of type "notehead": <br />
    // • <m>click</m>: Change notehead. <br />
    // • <m>Cmd+click</m> (mac) or <m>Ctrl+click</m> (win): Delete notehead, i.e. revert to default notehead. <br />
    // <br />
    // For slots of type "dynamics": <br />
    // • <m>double click</m>: Edit dynamics. <br />
    // • <m>Cmd+click</m> (mac) or <m>Ctrl+click</m> (win): Delete dynamics. <br />

#define BACH_DOC_SLOT_EDIT_KEYBOARD_COMMANDS
	// • <m>1</m>, <m>2</m>, <m>3</m>, <m>4</m>, <m>5</m>, <m>6</m>, <m>7</m>, <m>8</m>, <m>9</m>, <m>0</m>: Open
	// corresponding slot window (1 meaning: first slot, 2 meaning: second slot, and so on, with 0 meaning: tenth slot) <br />
	// • Press a slot hot key to open the corresponding slot window. All slots can be assigned a given slot key via 
	// the <m>key</m> specification in the slotinfo (see <m>llll</m> message to know more). <br />
	// • <m>Shift+Tab</m>: Open next slot window (if a slot window is open). <br />
	// • <m>Shift+Alt+Tab</m>: Open previous slot window (if a slot window is open). <br />
	// • <m>Enter</m>: For "text" and "llll" slots: enter the introduced text or llll. <br />
	// • <m>Backspace</m>: For "function" slots: deletes the selected slot points. <br />
	// <br />
	// Slot copy/paste: <br />
	// • <m>Cmd+C</m> (mac) or <m>Ctrl+C</m> (win): Copy the slot content. <br />
	//    ↪ If some points in a slot of type function are selected, only those points are copied; otherwise all the content of the active slot is copied. <br />
	// • <m>Cmd+X</m> (mac) or <m>Ctrl+X</m> (win): Cut the slot content. <br />
	//    ↪ If some points in a slot of type function are selected, only those points are cut; otherwise all the content of the active slot is cut. <br />
	// • <m>Cmd+Shift+C</m> (mac) or <m>Ctrl+Shift+C</m> (win): Copy the content of all slots (not only the possibly open one). <br />
	// • <m>Cmd+V</m> (mac) or <m>Ctrl+V</m> (win): Paste the copied content to every selected note. <br />
	//    ↪ If the copied content are some selected points of a slot of type function, only those points are pasted at the current mouse position in the open slot. <br />
	//      ↪ Add the <m>Ctrl</m> key (mac) or <m>Shift</m> key (win) to avoid deletion of existing intermediate points. <br />
	// <br />

#define BACH_DOC_MESSAGE_GETCURRENTCHORD
	// The word <m>getcurrentchord</m> outputs from the playout the pitches and velocities of the 
	// notes being played at the cursor position. The output syntax is: <b>currentchord <m>PITCHES</m> <m>VELOCITIES</m></b>,
	// where <m>PITCHES</m> and <m>VELOCITIES</m> are respectively wrapped lists containing the midicents and the corresponding
	// velocities of the notes being played at the cursor position. <br /> This is a rather quick'n'dirty method to have
    // pitch and velocity information; if you need any more information at a specific timepoint, see the <m>interp</m> and
    // <m>sample</m> messages.

#define BACH_DOC_MESSAGE_CLEARSELECTION
	// The word <m>clearselection</m> removes all items from the selection (without deleting them),
	// yielding a situation where no notation item is selected. If an integer is given as argument, 
	// it specifies a voice number for which the selection should be cleared (and will be kept for all other voices)

#define BACH_DOC_MESSAGE_RESPELL
	// The <m>respell</m> message reset the enharmonicity ("graphics") specification of each selected note to a default one.
    // Three algorithms are available, which can be set using the "algorithm" message attribute: a default algorithm,
    // the algorithm provided by Chew and Chen, and an algorithm targeting atonal diatonic behaviors. The three algorithms
    // are described below. For the two non-trivial algorithms some additional attributes may fine tune respelling properties: <br />
    // • "selection" (int, default 0): toggles the ability to operate on selection only (also works for default algorithm); <br />
    // • "voicewise" (int, default 1): toggles the ability to respell one voice at a time; <br />
    // • "sharpest" (symbol/pitch, default: B#): sets the "sharpest" note available (the farthest right on the line of fifths); <br />
    // • "flattest" (symbol/pitch, default: Fb): sets the "flattest" note available (the farthest left on the line of fifths); <br />
    // • "verbose" (int, default: 0): toggle a verbose mode (mostly for debug). <br />
    // The algorithms characteristics are the following ones:
    // - Default algorithm ("default"): just respell the notes according to the current key and enharmonicity tables. <br />
    // - Chew and Chen algorithm ("chewandchen"): implements the algorithm provided by Chew and Chen in the article
    // "Determining Context-Defining Windows: Pitch Spelling using the Spiral Array". Additional parameters, defined via message attributes,
    // are: <br />
    //   • "winsize" (double, default: 500): window size in milliseconds; <br />
    //   • "spiralr" (double, default: sqrt(2)): spiral radius; <br />
    //   • "spiralh" (double, default: sqrt(15)): spiral vertical step (i.e. the distance parallel to the axis of the helix corresponding
    // to one step along the spiral array; <br />
    //   • "numsliding" (int, default: 8): number of sliding windows; <br />
    //   • "numselfreferential" (int, default: 2): number of self referential windows (see article); <br />
    //   • "locality" (double, default: 0.5): a value of 1 only takes self-referential window into account, a value of 0 only takes global context
    // into account; any number in between will result in a linear combination of the two (this is the parameter <m>f</m> of the Chew and Chen article); <br />
    // - Atonal algorithm ("atonal"): respell the notes in a tree-like fashion (closest ones first), optimizing their position on the line of fifths. <br />
    //   • "discardalteredrepetitions" (int, default: 1): discard solutions having subsequent repetitions of the same diatonic
    // step with different alterations (e.g. F#4 F4, or Bb5 B5); <br />
    //   • "stdevthresh" (llll/symbol, default: 21/(numnotes+1)): sets a formula for a maximum standard deviation that the group of notes
    // being retranscribed must have (interpreted as their projection onto the line of fifths); <br />



#define BACH_DOC_QUERY_LABELS
	// Moreover, each query can have in bach as very first argument a label, kept inside the query answer, 
	// which can be useful to retrieve queries separately (for instance to keep track of queries coming from different threads). 
	// To assign a label to a query, you have to put as very first argument after the query message (before any other query argument) an llll in the form
	// <b>(label <m>label_name</m>)</b>, where <m>label_name</m> is a symbol you want to assign to the label. 
	// When the answer of a labelled query is output from the playout, after the first router symbol, the label will appear, thus yielding a 
	// general form <b><m>query_router_symbol</m> <m>label_name</m> <m>QUERY_ANSWER</m></b>. Just to make an example, 
	// the answer of <b>pixeltotime (label john) 6000</b> might be something like <b>pixel john 300.</b>.
	// It works accordingly for any other query.
	// <br /> <br /> 


#define BACH_DOC_ROLL_SEPARATE_SYNTAX
	// The separate synax of a given parameter is nothing but an llll containing the value of such parameter for each notation item 
	// to which it can be applied. The llll should be properly structured depending on the hierarchical structure. <br />
	// In <o>bach.roll</o>, onsets are the only parameter assigned chordwise (they are a propriety of chords, rather than notes).
	// The separate syntax for onsets will be thus structured as: an llll for each voice, containing a value for each chord.
	// For instance: <b>(0 1000 2000 3000) (100 400) (250 2500)</b>. <br />
	// Cents, durations, velocities and extras are all assigned notewise in <o>bach.roll</o> (they are propriety of notes, rather than chords).
	// The separate syntax for any of such parameters will be thus structured as: an llll for each voice, containing an llll for each chord,
	// containing a value for each note. For instance, a cents assignment can have the following form: 
	// <b>((6000) (6000 6400) (6200) (6200 6500)) ((7200) (6500 7200 7500)) ((5500) (5400))</b>. <br />
	// While using separate syntax as input, for all notewise parameter, except for extras, a shortcut is tolerated: one can assign a 
	// single value for each chord (and not each note) meaning that such value must be applied to the whole chord. If no chord exists,
	// and such value must create a chord, then a chord with a single note si created. For instance, <o>bach.roll</o> can properly understand
	// <b>(6000 (6000 6400) 6200 (6200 6500)) ((7200) (6500 7200 7500)) (5500 5400)</b>. However, when the separate syntax is retrieven as
	// output, the llll will be always properly shaped, according to the musical hierarchy, without any shortcut. 
	// <br /> <br />


#define BACH_DOC_SCORE_SEPARATE_SYNTAX
	// The separate synax of a given parameter is nothing but an llll containing the value of such parameter for each notation item 
	// to which it can be applied. The llll should be properly structured depending on the hierarchical structure. <br />
	// In <o>bach.score</o>, Measureinfo are assigned measurewise (they are a propriety of measures): an llll for each voice, containing a specification
	// for each measure is expected.  <br />
	// Durations are assigned chordwise (they are symbolic durations: a propriety of chords, rather than notes):
	// the separate syntax for durations will be thus structured as: an llll for each voice, containing an llll for each measure,
	// possibly containing an llll for each rhythmic level (see below), containing a rational value for each chord.
	// For instance: <b>((1/4 1/4 ((1/8 1/16) (1/32 1/32)) -1/4) (1/12 1/12 1/12 -3/4)) ((-1) (1/4 -3/4))</b>. 
	// The symbol "t" is also accepted in input to tie a duration to the following one, e.g. <b>((1/4 t 1/16 -3/16 -2/4))</b>. 
	// If the <m>outputtrees</m> algorithm is set to output trees in all outlets, and if the <m>outputtiesindurationtree</m> is set to 1, 
	// such "t" symbols are also always output in the durations separate syntax. 
	// Grace chords are defined either by setting a rational duration of 0 (converted into 1/8 grace chords) or by setting
	// a rhythmic level starting with a "g" symbol, which will thus contain all grace elements, e.g. <b>((1/4 (g 1/8 1/16 1/16) 1/4 1/4 0 1/4))</b>.
	// If the <m>outputtrees</m> algorithm is set to output trees in all outlets, grace chords are output, in the durations gathered syntax, 
	// with the grace levels syntax, otherwise they are output as chords with 0 duration. <br />
	// Cents, velocities, ties and extras are all assigned notewise in <o>bach.score</o> (they propriety of notes, rather than chords).
	// The separate syntax for any of such parameters will be thus structured as: an llll for each voice, containing an llll for each chord,
	// containing a value for each note. For instance, a cents assignment can have the following form: 
	// <b>(((6000) (6000 6400) (6200) (6200 6500)) ((7200) (6500 7200 7500))) (((5500) (5400)))</b>. <br />
	// While using separate syntax as input, for all notewise parameter, except for extras, a shortcut is tolerated: one can assign a 
	// single value for each chord (and not each note) meaning that such value must be applied to the whole chord. If no chord exists,
	// and such value must create a chord, then a chord with a single note si created. For instance, <o>bach.scire</o> can properly understand
	// <b>((6000 (6000 6400) 6200 (6200 6500)) ((7200) (6500 7200 7500))) ((5500 5400))</b>. However, when the separate syntax is retrieven as
	// output, the llll will be always properly shaped, according to the musical hierarchy, without any shortcut. <br /> <br />
	// <br /> <br />
	
			
#define BACH_DOC_SEPARATE_SYNTAX_EXTRAS
	// Extras are defined in the separate syntax via lllls sent through the Extras inlet, in the form 
	// <b>(<m>extra_name</m> <m>GLOBAL_CONTENT</m>) (<m>extra_name</m> <m>GLOBAL_CONTENT</m>)...</b>
	// where each sublist is thus composed by a name (a symbol identifying the extra, one of the following: "graphics", "breakpoints", "slots") 
	// and a global content, which is just an llll structured exactly according to the object's hierarchy. 
	// This llll is no different than any other separate parameter llll (say: Cents), only instead of having a single element (number) 
	// for each note, an llll is given, specifying the content of the extra associated to each note 
	// (a level of parentheses is needed for each note). If this latter level is dropped, and the information concerns a rest, the extra is assigned to the
    // rest, if applicable (e.g. slots).
    // For instance, the pitch breakpoints specification for a given note may have the form
	// <b>((0. 0. 0.) (0.5 500 0.5) (1. 0. 0.))</b>, whereas a complete list of extras to be introduced in the Extras inlet may have the form
	// <b>(breakpoints (((( 0. 0. 0. ) (0.5 500 0.5) (1. 0. 0.)) (( 0. 0. 0. ) (0.5 -500 0.5) (1. 0. 0.))) ((( 0. 0. 0. ) (0.5 -200 0.1) 
	// (1. 0. 0.)))) (((( 0. 0. 0. ) (0.5 500 0.5) (1. 0. 0.))) ((( 0. 0. 0. ) (0.5 -200 0.1) (1. 0. 0.))))) (slots ( (((3 10 20 30) (4 0.4)) 
	// ((3 10 20 30) (4 0.1))) (())) ())</b>. Notes, chords or voices which don't need a given extras are allowed to be represented as input by
	// an empty <b>()</b> llll. <br />
	// The content of each extra is exactly the same as the gathered syntax of such extra, provided that the starting symbol is dropped.
	// For instance, instead of <b>(graphics 6200 -1/2)</b>, one should just have <b>(6200 -1/2)</b> as graphic content for a given note, and so on.
	// The syntax for the gathered syntax of all extras is provided below. Remember to drop the extra router symbol to obtain the content
	// to be put in the separate syntax llll. <br /> <br />
	//  @copy BACH_DOC_NOTE_GRAPHIC_SYNTAX
	//  @copy BACH_DOC_NOTE_BREAKPOINT_SYNTAX
	//  @copy BACH_DOC_NOTE_SLOTS_SYNTAX
	//  @copy BACH_DOC_ARTICULATIONS_SYNTAX


#define BACH_DOC_MESSAGE_CLEARALL
	// A <m>clearall</m> message will clear the content input in all the separate parameters inlets (all inlets but the first one).
	// This is equivalent to sending a <b>nil</b> or <b>()</b> message in any of such inlets. <br />


#define BACH_DOC_MESSAGE_CLEARMARKERS
	// The <m>clearmarkers</m> simply delets all the markers in the notation object.

	
#define BACH_DOC_MESSAGE_OPENSLOTWINS
	// If a single note is selected, an <m>openslotwin</m> message, followed by the number of the slot whose window should be open,
	// opens the corresponding slot window. If more notes are selected, nothing happens.
	// Instead of the slot number, you can use slot names, so you can set a symbol as argument containing the name of the slot whose window should
	// be open. 


#define BACH_DOC_MESSAGE_FIXVZOOM
	// If the <m>vzoom</m> attribute was set to "auto", the <m>fixvzoom</m> message turns it into the
	// fixed value that the vertical zoom currently have. (The vertical zoom is also a global zoom for any
	// displayed item: see <m>vzoom</m> to know more.)


#define BACH_DOC_MESSAGE_MUTE
	// The <m>mute</m> message will set all selected items as "muted", so that they will not be sequenced while playing.


#define BACH_DOC_MESSAGE_UNMUTE
	// The <m>unmute</m> message will remove the "mute" status to any muted selected items, so that they will be sequenced anew while playing. 

	
#define BACH_DOC_MESSAGE_SOLO
	// The <m>solo</m> message will set all selected items as "solo". If solo items exist, they are the only one sequenced during playing.


#define BACH_DOC_MESSAGE_UNSOLO
	// The <m>unsolo</m> message will remove the "solo" status to any selected items having it.


#define BACH_DOC_MESSAGE_LOCK
	// The <m>lock</m> message will lock all selected items, in order to prevent their editing.


#define BACH_DOC_MESSAGE_UNLOCK
	// The <m>unlock</m> message will unlock all locked selected items, in order to allow their editing anew.


#define BACH_DOC_MESSAGE_DELETE
	// The word <m>delete</m> simply deletes all the currently selected items.


#define BACH_DOC_MESSAGE_SNAPPITCHTOGRID
	// The <m>snappitchtogrid</m> message snaps the midicents of each selected note to the
	// currently active microtonal grid (see the <m>tonedivision</m> attribute).
	
	
#define BACH_DOC_MESSAGE_NAME
	// The word <m>name</m>, followed by a symbol, a number or an llll, assigns such content as names for the
	// selected notation items. <br />
	// If markers are selected, an additional message attribute can be given in order to name them with an incremental naming system,
	// keeping the first one of the introduced names, and then adding an integer as second name, so that the overall name is unique
	// inside the <o>bach.roll</o>. The additional message attribute must be given in the form <b>@incremental 1</b>,
	// to be appended at the end of the message. For instance <b>name foo @incremental 1</b> will name all selected elements as "foo",
	// but will name all selected markers as "foo 1", "foo 2", and so on (unless one of such names was already taken, and thus it is skipped
	// to guarantee the unicity). <br />
	// If a <b>@progeny 1</b> attribute is added and chords are selected, not only the chord name is changed, but also the name of all its notes.
	// This is handy for instance, if one needs to send <b>name @progeny 1</b> to delete all names of selected chords and notes.


#define BACH_DOC_MESSAGE_VELOCITY
	// The word <m>velocity</m>, followed by a number, sets the new velocity (from 1 to 127) for all 
	// the selected notation items. 
	// If a list of numbers is given as arguments, this is applied to selected chords notewise: bottommost note will be assigned
	// the first value, the one above will be assigned the next one, and so on. If less values than selected notes in the chord 
	// are given, last value is padded.
	// Any of the numbers can be replaced by an llll containing a relative modification of the existing velocity. 
	// If a single number is inserted, this can be replaced by a generic equation.
	// @copy BACH_DOC_RELATIVE_MODIFICATIONS
	// @copy BACH_DOC_EQUATION_MODIFICATIONS 


#define BACH_DOC_MESSAGE_TIE
    // The word <m>tie</m>, followed by an integer, sets the new tie status for all the selected notation items.
    // Such integer should be 0 for "no tie", 1 for "tie starts", 2 for "tie ends", 3 for "tie stards and ends".
    // If a list of numbers is given as arguments, this is applied to selected chords notewise: bottommost note will be assigned
    // the first value, the one above will be assigned the next one, and so on. If less values than selected notes in the chord
    // are given, last value is padded.
    // Any of the numbers can be replaced by an llll containing a relative modification of the existing velocity.
    // If a single number is inserted, this can be replaced by a generic equation.
    // @copy BACH_DOC_RELATIVE_MODIFICATIONS
    // @copy BACH_DOC_EQUATION_MODIFICATIONS


#define BACH_DOC_MESSAGE_CENTS
	// The word <m>cents</m>, followed by a number, sets the new pitch, in midicents, for all 
	// the selected notation items. 
	// If a list of numbers is given as arguments, this is applied to selected chords notewise: bottommost note will be assigned
	// the first value, the one above will be assigned the next one, and so on. If less values than selected notes in the chord 
	// are given, last value is padded. <br /> <br />
	// @copy BACH_DOC_PITCHES_ALSO_AS_NOTENAMES
	// Any of the numbers in the cents syntax can be replaced by an llll containing a relative modification of the existing cents.
	// If a single number is inserted, this can be replaced by a generic equation.
	// @copy BACH_DOC_RELATIVE_MODIFICATIONS
	// @copy BACH_DOC_EQUATION_MODIFICATIONS 


#define BACH_DOC_MESSAGE_PITCH
    // The word <m>pitch</m>, followed by a pitch, sets the new pitch, in midicents, for all
    // the selected notation items. Differently from <m>cents</m>, the <m>pitch</m> message preserve diatonic information.
    // If a list of pitches is given as arguments, this is applied to selected chords notewise: bottommost note will be assigned
    // the first value, the one above will be assigned the next one, and so on. If less values than selected notes in the chord
    // are given, last value is padded. <br /> <br />
    // Any of the numbers in the pitch syntax can be replaced by an llll containing a relative modification of the existing pitch.
    // If a single number is inserted, this can be replaced by a generic equation.
    // @copy BACH_DOC_RELATIVE_MODIFICATIONS
    // @copy BACH_DOC_EQUATION_MODIFICATIONS

#define BACH_DOC_MESSAGE_VOICE
	// The word <m>voice</m>, followed by a number, sets the new voice number for all 
	// the selected notes or chords. 
	// Any of the numbers in the voice syntax can be replaced by an llll containing a relative modification of the existing voice. 
	// If a single number is inserted, this can be replaced by a generic equation.
	// @copy BACH_DOC_RELATIVE_MODIFICATIONS
	// @copy BACH_DOC_EQUATION_MODIFICATIONS 


#define BACH_DOC_PITCHES_ALSO_AS_NOTENAMES
    // Instead of MIDIcents (or cents), one can also instert pitches.
	// The syntax for the single note must be an unique symbol (no spaces) with:
	// <b><m>notename</m>-<m>optional:accidental</m>-<m>octave_number</m></b>.
	// Dashes are only set in order to separate parts of the symbol, but must not be included in the symbol. <br /> <br />
	// Names are in anglo-saxon syntax ("C", "D", "E"...), and are case insentitive. Middle C is C5.
    // They and should be immediately followed by the possible accidentals and the
	// octave number, without any space (e.g. <b>D#4</b>). <br />
    // Accidentals are: <b>#</b> (sharp), <b>b</b> (flat), <b>x</b> (double sharp), <b>q</b> (quartertone sharp), <b>d</b> (quartertone flat)
    // One can also extend the accidental by setting a rational specification followed by a <b>t</b>. For instance <b>C5+1/16t</b> is
    // middle C, 1/16 tone up.
	// <br /> <br />
	
	
#define BACH_DOC_MESSAGE_ADDBREAKPOINT
	// Adds a pitch breakpoint to each one of the selected notes.
	// The breakpoint is given by three arguments: <br />
	// - a float number between 0 and 1, setting the relative position of the pitch breakpoint
	// with respect to the note duration line (0 being the note head, 1 being the note tail).
	// 0 and 1 should be avoided (since a notehead and notetail already exists for any note), so the
	// values should be striclty greater than 0 and strictly less than 1. <br />
	// - a number setting the pitch difference (in midicents) of the breakpoint with respect to the main
	// note's pitch.
	// - an optional slope parameter, between -1 and 1, setting the slope of the segment of duration line preceding the breakpoint
	// (0 being linear, default).
	// - an optional velocity parameter, between 1 and 127, but only if the <m>breakpointshavevelocity</m> attribute is active.
	
	
#define BACH_DOC_MESSAGE_ERASEBREAKPOINTS
	// The <m>erasebreakpoints</m> message deletes all the pitch breakpoints of the selected notes.


#define BACH_DOC_MESSAGE_ADDSLOT
	// An <m>addslot</m> message will replace the content of one or more slots, for all the selected notes.
	// The syntax is <b>addslot (<m>slot_number</m> <m>SLOT_CONTENT</m>) (<m>slot_number</m> <m>SLOT_CONTENT</m>)...</b>. <br />
	// @copy BACH_DOC_NOTE_SLOT_CONTENT


#define BACH_DOC_MESSAGE_ERASESLOT
	// An <m>eraseslot</m> message will clear the content of a specific slot for any selected note. 
	// The slot number of the slot to clear is given as argument.
	// Instead of the slot number, you can use slot names, or you can the word "active" to refer to the currently open slot. 

#define BACH_DOC_MESSAGE_MOVESLOT
    // A <m>moveslot</m> message will move the content of a given slot to another slot for any selected note.
    // The slot number of the source slot and of the target slot are given as arguments.
    // Instead of the slot numbers, you can use slot names, or you can the word "active" to refer to the currently open slot.

#define BACH_DOC_MESSAGE_COPYSLOT
    // A <m>copyslot</m> message will copy the content of a given slot to another slot for any selected note.
    // The slot number of the source slot and of the target slot are given as arguments.
    // Instead of the slot numbers, you can use slot names, or you can the word "active" to refer to the currently open slot.


#define BACH_DOC_MESSAGE_CHANGESLOTVALUE
	// A <m>changeslotvalue</m> message will change a specific value inside a slot (possibly containing more than one element, such as
	// a <m>function</m> slot, or an <m>intlist</m> slot...) of any selected note.
	// The syntax is <b>changeslotvalue <m>slot_number</m> <m>element_index</m> <m>SLOT_ELEMENT_CONTENT</m></b>. <br />
	// Instead of the slot number, you can use slot names, or you can the word "active" to refer to the currently open slot. 
	// The <m>element_index</m> is the number identifying the position of the element to be changed (e.g., for a <m>function</m> slot: 1 for the first point, 2 for the second, and so on).
    // The symbol "all" can replace the element index, in order to change all elements. 
	// The element content is a single element in the lists of the slot content syntax: a single point for a slot <m>function</m>, a single number for an <m>intlist</m> or <m>floatlist</m> slot,
	// and so on. Such element must be unwrapped from its outer level of parentheses (if any). For instance, for a function,
	// a good syntax is <b>changeslotvalue 2 3 0.5 20 0</b> which will change the 3rd point of the function contained in the second slot
	// to the point <b>(0.5 20 0)</b>. <br />
	// @copy BACH_DOC_NOTE_SLOT_CONTENT
	
	
#define BACH_DOC_MESSAGE_LAMBDA
	// The <m>lambda</m> message is a general router which can be prepended to all the following operations:
	// <m>cents</m>, <m>velocity</m>, <m>onset</m>, <m>tail</m>, <m>duration</m>, <m>voice</m>, <m>addbreakpoint</m>, <m>erasebreakpoint</m>,
    // <m>addslot</m>, <m>changeslotvalue</m>, <m>eraseslot</m>, <m>name</m>.
	// If such router is prepended, the corresponding operation will apply on the currently output selected item.
	// The idea is that when a selection dump is asked or a command is sent (also see <m>dumpselection</m> or <m>sendcommand</m>), the notation
	// elements are output one by one from the playout (notewise or chordwise depending on the <m>playmode</m>): if you put a feedback loop from the playout
	// to the <o>bach.roll</o>, changing one of the previously defined parameter, but prepending the "lambda" symbol inside the message,
	// such modification will not apply to the whole selection, but only to the item currently being output. In such a way, you can modify
	// chords one by one, depending on their parameters, even by performing a collective selection dump.
	// Such feedback cycle must not have any <o>delay</o> nor <o>pipe</o> nor <o>defer</o> nor <o>deferlow</o>, nor anything which may change the thread
	// or defer the modification operation. See #lambda+operation in the help center to have some examples of usage.


#define BACH_DOC_MESSAGE_DUMPVOICEPIXELPOS
	// The <m>dumpvoicepixelpos</m> message retrieves the pixel position of any voices, and outputs it from the playout.
	// The output answer has the syntax: 
	// <b>voicepixelpos <m>VOICE1</m> <m>VOICE2</m>...</b>, where each <m>VOICE</m> is an llll of the form
	// <b>(<m>y_pixel_middleC</m> <m>y_pixel_bottom_staffline</m> <m>y-pixel_top_staffline</m>)</b>. The three values are: the vertical position
	// in pixels of the middle C, and the bottommost and topmost staffline position (in pixels). <br />
	// @copy BACH_DOC_QUERY_LABELS
	
	
#define BACH_DOC_MESSAGE_GETVZOOM
	// The <m>getvzoom</m> message retrieves the current value of the vertical zoom. Such value is given as precise percentage value,
	// also in case the <m>vzoom</m> attribute is set to "auto".
	// The output answer is sent through the playout in the form: <b>vzoom <m>current_vzoom_value</m></b>, where the 
	// <m>current_vzoom_value</m> is given as percentage. <br />
	// @copy BACH_DOC_QUERY_LABELS


#define BACH_DOC_MESSAGE_GETZOOM
	// The <m>getzoom</m> message retrieves the current value of the horizontal zoom. 
	// The output answer is sent through the playout in the form: <b>zoom <m>current_zoom_value</m></b>, where the 
	// <m>current_zoom_value</m> is given as percentage. <br />
	// @copy BACH_DOC_QUERY_LABELS
	
	
#define BACH_DOC_MESSAGE_GETLENGTH
	// @description The <m>getlength</m> message forces the notation object to output from the playout the total length of the musical content, 
	// in milliseconds.
	// The syntax of the output answer is: <b>length <m>length_ms</m></b>, where the last element is indeed the total length of the 
	// content in milliseconds. <br />
	// @copy BACH_DOC_QUERY_LABELS


#define BACH_DOC_MESSAGE_HIDECURSOR
	// The <m>hidecursor</m> message hides the playhead cursor, if it was visible.
	// This does not affect the playback behavior: at play time the cursor is always visible.


#define BACH_DOC_MESSAGE_SHOWCURSOR
	// The <m>showcursor</m> message shows the playhead cursor, if it was hidden.
	// In any case, during playback the cursor is always visible.

	
#define BACH_DOC_MESSAGE_DELETEMARKER
	// The <m>deletemarker</m> message deletes a given marker, matching a given name or a llll of names.
	// The name(s) can be introduced as a list, as argument. If more than one marker match such name(s), only the first
	// one (in temporal order) is deleted.


#define BACH_DOC_ROLL_EDIT_MOUSE_COMMANDS
	// Basic commands: <br />
	// • <m>Cmd+Click</m> (mac) or <m>Ctrl+click</m> (win) on a notehead: Delete note <br /> 
	// • <m>Cmd+Click</m> (mac) or <m>Ctrl+click</m> (win) elsewhere: Add a new chord having a note at the clicked position <br /> 
	// • <m>Alt+click+drag</m> on a notehead: Copy the note into a new chord <br /> 
	//    ↪ Add the <m>Shift</m> key to add the new note to the existing chord <br />
	// • <m>click+drag</m> on a notehead or a duration line: Change the note pitch (dragging up/down) and the chord onset (dragging left/right). <br /> 
	//    ↪ Add the <m>Shift</m> key to change either the note pitch or the chord onset <br />
	//    ↪ Add the <m>Shift+Cmd</m> keys (mac) or the <m>Shift+Ctrl</m> keys (win) while dragging up/down to prevent notes from changing voices <br />
	//    ↪ Add the <m>Shift+Cmd</m> keys (mac) or the <m>Shift+Ctrl</m> keys (win) while dragging left/right to finely edit the chord onset. <br />
    //    ↪ Add the <m>Shift+Ctrl</m> key to trim the tail, i.e. to keep the existing absolute pitch breakpoint positions. <br />
	// • <m>click+drag</m> on a note tail: Change the note duration (dragging left/right) and pitch of the note tail (dragging up/down provided that the <m>allowglissandi</m> attribute is set to 1).
	// Possible pitch breakpoint positions as well as temporal slot items are rescaled according to the new duration <br />
	//    ↪ Add the <m>Shift</m> key to change either the note duration or the note tail pitch <br />
	//    ↪ Add the <m>Shift+Cmd</m> keys (mac) or <m>Shift+Ctrl</m> keys (win) to fine edit the position <br />
	//    ↪ Add the <m>Shift+Ctrl</m> key to trim the tail, i.e. to keep the existing absolute pitch breakpoint positions. <br />
	// • <m>doubleclick</m> on voice names, marker names or lyrics: Edit names directly <br />
	// • <m>doubleclick</m> on selected items: Selection off-line play (as the <m>V</m> key), but only if <m>dblclicksendsvalues</m> is set to 1 <br />
	// • <m>Shift+click+drag</m> on a clef (at the beginning of the staff): Move voice vertically (along with all the next ones), i.e.: modify vertical space before clicked voice <br />
	// • <m>Shift+Alt+click+drag</m> on a clef (at the beginning of the staff): Move all following voices vertically (but not the clicked one), i.e.: modify vertical space after clicked voice <br />
	// • <m>right click</m> or <m>two-fingers-tap</m>: Open contextual popup menu. This can be opened by clicking on noteheads (note or selection popup menu), clefs 
	// (voice popup menu) or on the background (backgroun popup menu). <br />
	//
	// <br />
	// Selection, zooming, scrollbar and dilation rectangle: <br />
	// • <m>click</m> on any item: Select item <br />
	//    ↪ Add the <m>Shift</m> key to keep the selection to add/remove other elements to/from it. <br />
	// • <m>click</m> outside any item and <m>drag</m>: Select elements inside the rectangle region (selection rectangle). <br />
	//    ↪ Add the <m>Shift</m> key to keep the selection to add/remove other elements to/from it. <br />
	//    ↪ To select a marker with a selection rectangle, reach the uppermost point of the notation object corresponding to the marker line. <br />
	//    ↪ If, after having clicked but before having released the mouse, you press the <m>Cmd</m> key (mac) or <m>Ctrl</m> key (win), 
	// a dilation rectangle appears: <br />
	//        - <m>click+drag</m> on any on the corners to expand the selection temporally and/or to expand pitches. <br /> 
	//        - <m>click+drag</m> inside the dilation rectangle to move the selected items in time or pitch. <br /> 
	// • <m>Cmd+mousewheel</m> or <m>Cmd+two-fingers-scroll</m> (mac) or <m>Ctrl+mousewheel</m> or <m>Ctrl+two-fingers-scroll</m> (win): Change the <m>zoom</m> attribute (horizontal zoom). Zoom is increased 
	// when rolling the wheel up, decreased when rolling the wheel down. You can substitute the trackpad's <m>two-fingers-scroll</m> to the <m>mousewheel</m>.<br />
	// • <m>Alt+Cmd+click+drag</m> (mac) or <m>Alt+Ctrl+click+drag</m> (win): Zoom into selected region. As you drag, a reddish zooming rectangle is
	// drawn, corresponding (on the temporal axis) to the region into which the notation object will exactly zoom. <br />
	//    ↪ Add the <m>Shift</m> key to zoom out instead. <br />
	// • <m>click+drag</m> on a scrollbar: Change scrollbar position <br />
	// • <m>mousewheel</m> (or trackpad's <m>two-fingers-scroll</m>): Change scrollbar positions <br />
	// • <m>Ctrl+Alt+click+drag</m> (mac) or <m>Shift+Ctrl+Alt+click+drag</m> (win) anywhere: Change scrollbar positions, 
	// via a dragging hand (faster than directly clicking and dragging the scrollbar itself) <br />
	//    ↪ Add the <m>Shift+Cmd</m> key (mac) or the <m>Shift</m> key (win) to change the scrollbar positions more finely <br />
	//
	// <br />
	// Sequencing and loop region: <br />
	// • <m>Ctrl+click+drag</m> (mac) or <m>Shift+Ctrl+click+drag</m> (win): Redefine loop region (if the click is performed
	// on the background, outside any notation item) <br />
	//    ↪ Add the <m>Shift</m> key to auto snap boundaries to existing chord onsets <br />
	// • <m>click+drag</m> on a loop region boundary: Change loop region boundary <br />
	//    ↪ Add the <m>Shift</m> key to auto snap it to existing chord onsets <br />
	// • <m>click+drag</m> on a loop region bottom bar: Globally shift loop region <br />
	//    ↪ Add the <m>Shift</m> key to auto snap boundaries to existing chord onsets <br />
	// • <m>Alt+click</m> when the playhead cursor is visible: Set a new playhead cursor position (but only if the <m>playheaddragmode</m>
	// is set to Absolute, otherwise you have to use <m>Alt+click+drag</m> to change the cursor position) <br />
	// • <m>Alt+click+drag</m> when the playhead cursor is visible: Change cursor position (also depending on the <m>playheaddragmode</m>) <br />
	//
	// <br />
	// For pitch breakpoints (if the <m>allowglissandi</m> attribute is set to 1): <br />
	// • <m>Alt+click</m> on a duration line: Add a pitch breakpoint. <br />
	// • <m>Cmd+click</m> (mac) or <m>Ctrl+click</m> (win) on a pitch breakpoint: Delete pitch breakpoint. <br />
	// • <m>click+drag</m> on a pitch breakpoint: Change pitch (if dragging up/down) or temporal position (if dragging left/right). <br />
	//    ↪ Add the <m>Shift</m> key to change either the pitch or the temporal position. <br />
	//    ↪ Add the <m>Shift+Cmd</m> keys (mac) or <m>Shift+Ctrl</m> keys (win) to fine edit either the pitch or the temporal position (depending on the dragging direction). <br />
	// • <m>Ctrl+click</m> (mac) or <m>Shift+Ctrl+click</m> (win) on a pitch breakpoint and <m>drag</m> up and down: Change breakpoint velocity (if the <m>breakpointshavevelocity</m> attribute is set to 1). <br />
    // • <m>Ctrl+click</m> (mac) on a portion of duration line and <m>drag</m> up and down: Change slope of duration line segment <br />
	//
	// <br />
	// For markers: <br />
	// • <m>Shift+Alt+click</m>: Add a new marker at the click position <br />
	// • <m>Cmd+click</m> (mac) or <m>Ctrl+click</m> (win) on a marker: Delete marker <br />
	// • <m>click+drag</m> on a marker: Change the marker onset <br />
    //    ↪ Add the <m>Shift</m> key to have markers snap to chord onset, note tails or pitch breakpoints <br />
	//    ↪ Add the <m>Shift+Cmd</m> keys (mac) or <m>Shift+Ctrl</m> keys (win) for fine editing <br />
    //    ↪ Add the <m>Ctrl</m> key (mac) in order to move anything beyond the marker while moving the marker <br />
	// • <m>Alt+click+drag</m>: Duplicate the marker into a new one with an unique name <br />
	// • <m>doubleclick</m> on a marker name: Edit marker name <br />
	// 
	// <br />
	// For slots: <br />
	// @copy BACH_DOC_SLOT_EDIT_MOUSE_COMMANDS
    //
    // <br />
    // Linear editing: <br />
    // • <m>Ctrl+click</m> (mac) or <m>Shift+Ctrl+click</m> (win) on a staff, avoiding the noteheads: Enter linear editing mode <br />
    // • <m>click</m> outside the staves while in linear editing mode: Exit linear editing mode <br />



#define BACH_DOC_ROLL_EDIT_KEYBOARD_COMMANDS
	// Basic commands: <br />
	// • <m>Backspace</m>: Delete all selected items, except for selected note tails, for which the backspace key reverts their pitch to the 
	// original notehead pitch (no glissando). <br /> 
	// • <m>→</m>: Shift selection onsets to the right; for selected tails: increase corresponding note duration <br /> 
	// • <m>←</m>: Shift selection onsets to the left; for selected tails: decrease corresponding note duration <br /> 
	// • <m>Alt+→</m>: Increase duration for selected notes (possible breakpoint positions are rescaled). <br /> 
	//    ↪ Add the <m>Shift</m> key to change duration more rapidly. <br />
	// • <m>Alt+←</m>: Decrease duration for selected notes (possible breakpoint positions are rescaled). <br /> 
	//    ↪ Add the <m>Shift</m> key to change duration more rapidly. <br />
	// • <m>Alt+Ctrl+→</m> (mac) or <m>Alt+Shift+Ctrl+→</m> (win): Increase note duration, preserving the absolute position of each pitch breakpoint. <br />
	//    ↪ Add the <m>Shift</m> key (mac) to change duration more rapidly. <br />
	// • <m>Alt+Ctrl+←</m> (mac) or <m>Alt+Shift+Ctrl+←</m> (win): Decrease note duration, preserving the absolute position of each pitch breakpoint. <br />
	//    ↪ Add the <m>Shift</m> key (mac) to change duration more rapidly. <br />
	// • <m>↑</m>: Raise pitch of selection by one step. <br /> 
	//    ↪ Add the <m>Shift</m> key to raise the pitch by one octave. <br />
	//    ↪ Add the <m>Ctrl+Shift</m> key to prevent notes from being assigned to different voices. <br />
	// • <m>↓</m>: Lower pitch of selection by one step. <br /> 
	//    ↪ Add the <m>Shift</m> key to lower the pitch by one octave. <br />
	//    ↪ Add the <m>Ctrl+Shift</m> key to prevent notes from being assigned to different voices. <br />
	// • <m>Cmd+Z</m> (mac) or <m>Ctrl+Z</m> (win): Undo <br />
	// • <m>Cmd+Shift+Z</m> (mac) or <m>Ctrl+Y</m> (win): Redo <br />
	// • <m>Cmd+L</m> (mac) or <m>Ctrl+L</m> (win) when items are selected: Lock/unlock selected items <br />
	// • <m>Cmd+G</m> (mac) or <m>Ctrl+G</m> (win): Group/ungroup selected items <br />
	// • <m>Ctrl+A</m>, <m>Ctrl+B</m>, <m>Ctrl+C</m>, <m>Ctrl+D</m>, <m>Ctrl+E</m>, <m>Ctrl+F</m>, <m>Ctrl+G</m> (mac only):
	// or <m>Shift+Ctrl+Alt+A</m>, <m>Shift+Ctrl+Alt+B</m>, <m>Shift+Ctrl+Alt+C</m>, <m>Shift+Ctrl+Alt+D</m>, <m>Shift+Ctrl+Alt+E</m>, <m>Shift+Ctrl+Alt+F</m>, <m>Shift+Ctrl+Alt+G</m> (win):
	// Transform pitches of selected notes into the corresponding pitch (A = La, B = Si, C = Do, and so on). 
	// The octave is chosen to be the one so that the snapped note is as near as possible to the previous note. <br /> 
	//
	// <br />
	// Align operations: <br />
	// • <m>Cmd+Y</m> (mac) or <m>Ctrl+Shift+A</m> (win): Align selected chord onsets (so that they end up having the same onset) <br />
	// • <m>Cmd+F</m> (mac) or <m>Ctrl+Shift+F</m> (win): Distribute selected chords' onsets evenly in time (so that the onset 
	// difference ends up being the same for all selected items) <br />
	//
	// <br />
	// Sequencing, loop region and dump: <br />
	// • <m>Spacebar</m> while not playing: Play (the playing starts from current playhead cursor position) <br />
	// • <m>Spacebar</m> during playback: Stop (the playhead cursor position goes back to the former starting play point) <br />
	// • <m>Shift+Spacebar</m> during playback: Pause (keep the playhead cursor at the last
	// reached position, so that a new <m>play</m> message or a new <m>Spacebar</m> command will
	// start playing from there) <br />
	// • <m>Shift+Spacebar</m> while not playing: Play selection (start playing from the leftmost selected item
	// and only play the selected items) <br />
	// • <m>V</m>: Off-line play, also known as "selection dump" (immediately send the playout syntax of selected elements
	// out the playout, see <m>dumpselection</m> message) <br />
	// • <m>Shift+V</m>: Chordwise off-line play (as the previous command, but if a single note is selected, all its chord content
	// is output through the playout) <br />
	// • <m>Shift+Alt+V</m>: Send whole gathered syntax content out the first outlet (this is equivalent to sending a <m>dump</m> message) <br />
    // • Any defined command key: send command off-line <br />
	// • <m>Cmd+P</m> (mac) or <m>Ctrl+P</m> (win): Show/hide playhead cursor (while not playing: indeed, during playback the cursor is always visible) <br />
	// • <m>Cmd+J</m> (mac) or <m>Ctrl+J</m> (win): Solo/unsolo selected items <br />
	// • <m>Cmd+U</m> (mac) or <m>Ctrl+U</m> (win): Mute/unmute selected items <br />
	// • <m>Return</m>: set the playhead cursor and the scrollbar both at the beginning of the <o>bach.roll</o>, or at the beginning of the loop region (in case it is displayed). <br />
	// • <m>Cmd+L</m> (mac) or <m>Ctrl+L</m> (win) when nothing is selected: Show/hide loop region <br />
	// • <m>Cmd+Shift+L</m> (mac) or <m>Ctrl+Shift+L</m> (win) when nothing is selected: Activate/deactivate loop region <br />
	//
	// <br />
	// Inspector, selection and navigation: <br />
	// • <m>Cmd+I</m> (mac) or <m>Ctrl+Alt+I</m> (win): Open inspector for selected item (if a single item is selected), or for slotinfo (if a slot window is open). <br />
	// • <m>→</m>, <m>←</m>, <m>↑</m>, <m>↓</m>, <m>Enter</m>, <m>Esc</m>: Navigate inside the score while inspecting elements (i.e. while the bach inspector has the focus).
	// See the indication at the bottom of each inspector screen in order to know how to use such keyboard commands. In general <m>←</m> and <m>→</m> move 
	// respectively to previous and next element, <m>↑</m> and <m>↓</m> to the elements above or below, <m>Enter</m> moves to the first "son" of the
	// element and <m>Esc</m> to the element's "father" (in the score hierarchy).
	// • <m>Cmd+→</m>, <m>Cmd+←</m>, <m>Cmd+↑</m>, <m>Cmd+↓</m> (mac) or 
	// <m>Ctrl+→</m>, <m>Ctrl+←</m>, <m>Ctrl+↑</m>, <m>Ctrl+↓</m> (win): Navigate inside the score, respectively selecting the element at right,
	// left, above or below with respect to the currently selected item. 
	// If no item is selected, the first two commands will move the horizontal scrollbar, if any (left or right).<br />
	// • <m>Cmd+A</m> (mac) or <m>Ctrl+A</m> (win): Select all items <br />
	//
	// <br />
	// Copy/paste actions (these work also from a <o>bach.roll</o> to another one): <br />
	// • <m>Cmd+C</m> (mac) or <m>Ctrl+C</m> (win): Copy selected content, or slot content if a slot window is open. <br />
	// • <m>Cmd+Shift+C</m> (mac) or <m>Ctrl+Shift+C</m> (win): If a slot window is open, copy the content of 
	// all the slots of the note whose slot window is open; otherwise simply copy selected content. <br />
	// • <m>Cmd+X</m> (mac) or <m>Ctrl+X</m> (win): Cut selected content, or slot content if a slot window is open. <br />
	// • <m>Cmd+V</m> (mac) or <m>Ctrl+V</m> (win): If the content in the clipboard are chords, paste chords at the current mouse position.
	// If the content is a slot content, assign such slot content to all selected notes. <br />
	// • <m>Cmd+Shift+V</m> (mac) or <m>Ctrl+Shift+V</m> (win): Paste in-place. If the content in the clipboard are chords, paste chords at the original position
	// (so that they overlap with the existing ones, unless these latter have been deleted). <br />
    // • <m>Cmd+Alt+V</m> (mac) or <m>Ctrl+Shift+V</m> (win): Paste replace. If the content in the clipboard are chords, paste chords at the place of the currently selected items
    // (i.e. deletes the current selection and replaces it with the clipboard content) <br />
	//
	// <br />
	// For pitch breakpoints: <br />
	// • <m>Esc</m>: Revert slope to 1 for selected breakpoints (the slope refers to the duration line segment preceding the breakpoints). <br />
	//
	// <br />
	// Lyrics and dynamics: <br />
	// • <m>Cmd+Shift+L</m> (mac) or <m>Ctrl+Shift+L</m> (win): Start editing lyrics for the leftmost selected chord, or for the selected lyrics <br />
    // • <m>Cmd+Shift+D</m> (mac) or <m>Ctrl+Shift+D</m> (win): Start editing dynamics for the leftmost selected chord, or for the selected dynamics <br />
	// • <m>Tab</m> while editing: Move to next chord's lyrics <br />
	// • <m>Shift+Tab</m> while editing: Move to previous chord's lyrics <br />
	// • <m>-</m>: For lyrics: end a syllable with "-" in order to create a dashed line reaching the next piece of lyrics <br />
	// • <m>Esc</m>: End editing <br />
	// 
	// <br />
	// For slots: <br />
	// @copy BACH_DOC_SLOT_EDIT_KEYBOARD_COMMANDS
    //
    // <br />
    // Linear editing (these commands are valid when only in linear editing mode): <br />
    // • <m>↑</m>, <m>↓</m>: Move position of the pitch cursor of one step up or down (respectively) <br />
    //    ↪ Add the <m>Shift</m> key to move the pitch cursor by one octave. <br />
    // • <m>→</m>, <m>←</m>: Move cursor right/left by the amount specified by the <m>linearedittimestep</m> attribute.
    //    ↪ Add the <m>Shift</m> key move 4x faster (unless the grid snapping is on, via the <m>snaplinearedit</m> attribute,
    // in which case it will move as the main grid, and not the subdivision grid) <br />
    //    ↪ Add the <m>Alt</m> key to move by 1 millisecond only <br />
    //       ↪ Furtherly add the <m>Shift</m> keys to move by 10 milliseconds <br />
    // • <m>Cmd+→</m>, <m>Cmd+←</m> (mac) or <m>Ctrl+→</m>, <m>Ctrl+←</m> (win): Navigate by chords (i.e. go to next/prev chord onset, or chord longest
    // note's tail). <br />
    // • <m>Cmd+↑</m>, <m>Cmd+↓</m> (mac) or <m>Ctrl+↑</m>, <m>Ctrl+↓</m> (win): Go to previous/next voice. <br />
    // • <m>1</m>, <m>2</m>, <m>3</m>, <m>4</m>, <m>5</m>, <m>6</m>, <m>7</m>, <m>8</m>, <m>9</m>, <m>0</m>:
    // Insert chord at cursor position with a given duration (if the cursor is not on any chord), or modify duration of chord at cursor.
    // Durations are mapped on numbers as multipliers of the <m>linearedittimestep</m> attribute. The multipliers are defined
    // via the <m>linearedittimemultipliers</m> attribute (by default are the numbers themselves, with 0 meaning 10). <br />
    // • <m>A</m>, <m>B</m>, <m>C</m>, <m>D</m>, <m>E</m>, <m>F</m>, <m>G</m>:
    // Insert note at cursor position with a given pitch (if the cursor is not on any chord), or modify pitch of note at cursor.
    // Pitches are trivially mapped as in the anglo-saxon syntax. If a new chord is inserted, this will have the duration of the last
    // inserted one (by default 4 times the <m>linearedittimestep</m>). <br />
    // • <m>N</m>: Add a new note at cursor position (if cursor is on a chord) <br />
    // • <m>+</m>, <m>-</m>: raise or lower pitch of chord or note at cursor (if any) <br />
    //    ↪ Add the <m>Control</m> key to change durations. <br />
    //      If a chord is under the cursor, then its notes are lengthened/shortened by 1 ms, otherwise the time step itself is
    //      lengthened/shortened by 1 ms<br />
    //       ↪ Furtherly add the <m>Shift</m> keys to lengthen/shorten by 10 milliseconds <br />
    //       ↪ Furtherly add the <m>Alt</m> keys to have the length be double/halved <br />
    // • <m>Backspace</m>: Delete chord at cursor position (if any)<br />
    // • <m>Shift+Backspace</m>: Delete note at cursor position (cursor must be aligned also vertically with the note to delete)<br />
    // • <m>Esc</m>: Exit linear editing mode <br />


#define BACH_DOC_SCORE_EDIT_MOUSE_COMMANDS
	// Basic commands: <br />
	// • <m>Cmd+Click</m> (mac) or <m>Ctrl+click</m> (win) on a rest: Turn rest into note <br /> 
	// • <m>Cmd+Click</m> (mac) or <m>Ctrl+click</m> (win) on a note: Delete note (if no notes are left in the chord, the chord is turned into a rest) <br /> 
	// • <m>Cmd+Click</m> (mac) or <m>Ctrl+click</m> (win) on a measure or an empty staff: Add a measure <br /> 
	//    ↪ By default the measure is added after the clicked one. Add the <m>Shift</m> key to add the new measure befor the clicked one <br />
	// • <m>Alt+click+drag</m> on a notehead: Duplicate the note (into the same chord) <br /> 
	// • <m>click+drag</m> on a notehead or a duration line: Change the note pitch (dragging up/down) <br /> 
	//    ↪ Add the <m>Shift+Cmd</m> keys (mac) or <m>Shift+Ctrl</m> (win) while dragging up/down to prevent notes from changing voices <br />
	// • <m>click+drag</m> on a note tail: Change the pitch of the note tail (dragging up/down provided that the <m>allowglissandi</m> attribute is set to 1). 
	// Possible pitch breakpoint positions are rescaled <br /> 
	//    ↪ Add the <m>Alt</m> key to keep the existing absolute pitch breakpoint positions <br />
	// • <m>doubleclick</m> on voice names, marker names or lyrics: Edit names directly <br />
	// • <m>doubleclick</m> on selected items: Selection off-line play (as the <m>V</m> key), but only if <m>dblclicksendsvalues</m> is set to 1 <br />
	// • <m>Shift+click+drag</m> on a clef (at the beginning of the staff): Move voice vertically (along with all the next ones), i.e.: modify vertical space before clicked voice <br />
	// • <m>Shift+Alt+click+drag</m> on a clef (at the beginning of the staff): Move all following voices vertically (but not the clicked one), i.e.: modify vertical space after clicked voice <br />
	// • <m>right click</m> or <m>two-fingers-tap</m>: Open contextual popup menu. This can be opened by clicking on noteheads (note or selection popup menu), clefs 
	// (voice popup menu), measure (measure popup menu), measure barlines (barline popup menu) or on the background (backgroun popup menu). <br />
	//
	// <br />
	// Selection, zooming, scrollbar and dilation rectangle: <br />
	// • <m>click</m> on any item: Select item <br />
    //    ↪ click again to select a single note from a tie sequence, or a single chord from a tied chord sequence, or a single note from a chord. <br />
	//    ↪ Add the <m>Shift</m> key to keep the selection to add/remove other elements to/from it. <br />
	// • <m>click</m> outside any item and <m>drag</m>: Select chord and notes inside the rectangle region (selection rectangle). <br />
	//    ↪ Add the <m>Shift</m> key to keep the selection to add/remove other elements to/from it. <br />
	//    ↪ To select a marker with a selection rectangle, reach the uppermost point of the notation object corresponding to the marker line. <br />
	//    ↪ If, after having clicked but before having released the mouse, you press the <m>Cmd</m> key (mac) or <m>Ctrl</m> key (win), 
	// a dilation rectangle appears: <br />
	//        - <m>click+drag</m> on any on the corners to expand the pitches. <br /> 
	//        - <m>click+drag</m> inside the dilation rectangle to globally shift the selected items's pitches. <br /> 
	// • <m>Cmd+mousewheel</m> or <m>Cmd+two-fingers-scroll</m> (mac) or <m>Ctrl+mousewheel</m> or <m>Ctrl+two-fingers-scroll</m> (win): Change the <m>zoom</m> attribute (horizontal zoom). Zoom is increased 
	// when rolling the wheel up, decreased when rolling the wheel down. You can substitute the trackpad's <m>two-fingers-scroll</m> to the <m>mousewheel</m>.<br />
	// • <m>Alt+Cmd+click+drag</m> (mac) or <m>Alt+Ctrl+click+drag</m> (win): Zoom into selected region. As you drag, a reddish zooming rectangle is
	// drawn, corresponding (on the temporal axis) to the region into which the notation object will exactly zoom. <br />
	//    ↪ Add the <m>Shift</m> key to zoom out instead. <br />
	// • <m>click+drag</m> on a scrollbar: Change scrollbar position <br />
	// • <m>mousewheel</m> (or trackpad's <m>two-fingers-scroll</m>): Change scrollbar positions <br />
	// • <m>Ctrl+Alt+click+drag</m> (mac) or <m>Shift+Ctrl+Alt+click+drag</m> (win) anywhere: Change scrollbar positions, 
	// via a dragging hand (faster than directly clicking and dragging the scrollbar itself) <br />
	//    ↪ Add the <m>Shift+Cmd</m> key (mac) or the <m>Shift</m> key (win) to change the scrollbar positions more finely <br />
	//
	// <br />
	// Tempi: <br />
	// • <m>Ctrl+click+drag</m> (mac) or <m>Shift+Ctrl+click+drag</m> (win) on the tempo value: Change tempo value (increase by dragging up, by while dragging down) <br />
	// • <m>Cmd+Alt+click</m> (mac) or <m>Ctrl+Alt+click</m> (win) inside a staff avoiding all noteheads: Pop up tempo at clicked position <br />
	//
	// <br />
	// Measure widths and spacing: <br />
	// • <m>Shift+click+drag</m> on a barline: Change barline position (i.e. previous measure width).
	// If the barline is locked, the measure width is changed; if the barline is unlocked, the measure width factor is changed
	// (locally changing the spacing width).  
	//
	// <br />
	// Sequencing and loop region: <br />
	// • <m>Ctrl+click+drag</m> (mac) or <m>Shift+Ctrl+click+drag</m> (win): Redefine loop region (if the click is performed
	// on the background, outside any notation item) by default snapping extremes to existing chord onsets or measure barlines <br />
	//    ↪ Add the <m>Shift</m> key to deactivate the automatic snapping to chord onsets or measure barlines<br />
	// • <m>click+drag</m> on a loop region boundary: Change loop region boundary, by default snapping it to existing chord onsets or measure barlines <br />
	//    ↪ Add the <m>Shift</m> key to deactivate the automatic snapping to chord onsets or measure barlines<br />
	// • <m>click+drag</m> on a loop region bottom bar: Globally shift loop region, by default snapping extremes to existing chord onsets or measure barlines <br />
	//    ↪ Add the <m>Shift</m> key to deactivate the automatic snapping to chord onsets or measure barlines<br />
	// • <m>Alt+click</m> when the playhead cursor is visible: Set a new playhead cursor position (but only if the <m>playheaddragmode</m>
	// is set to Absolute, otherwise you have to use <m>Alt+click+drag</m> to change the cursor position) <br />
	// • <m>Alt+click+drag</m> when the playhead cursor is visible: Change cursor position (also depending on the <m>playheaddragmode</m>) <br />
	//
	// <br />
	// For pitch breakpoints (if the <m>allowglissandi</m> attribute is set to 1): <br />
	// • <m>Alt+click</m> on a duration line: Add a pitch breakpoint. <br />
	// • <m>Cmd+click</m> (mac) or <m>Ctrl+click</m> (win) on a pitch breakpoint: Delete pitch breakpoint. <br />
	// • <m>click+drag</m> on a pitch breakpoint: Change pitch (if dragging up/down) or temporal position (if dragging left/right). <br />
	//    ↪ Add the <m>Shift</m> key to change either the pitch or the temporal position. <br />
	//    ↪ Add the <m>Shift+Cmd</m> keys (mac) or <m>Shift+Ctrl</m> keys (win) to fine edit either the pitch or the temporal position (depending on the dragging direction). <br />
	// • <m>Ctrl+click</m> (mac) or <m>Shift+Ctrl+click</m> (win) on a pitch breakpoint and <m>drag</m> up and down: Change breakpoint velocity (if the <m>breakpointshavevelocity</m> attribute is set to 1). <br />
	// • <m>Ctrl+click</m> (mac) on a portion of duration line and <m>drag</m> up and down: Change slope of duration line segment <br />
	//
	// <br />
	// For markers: <br />
	// • <m>Shift+Alt+click</m> outside staves: Add a new measure-attached marker <br />
	// • <m>Shift+Ctrl+Alt+click</m> outside staves: Add a new millisecond position-attached marker <br />
	// • <m>Ctrl+click</m> (mac) or <m>Shift+Ctrl+click</m> (win) on a marker, outside staves: Switch assignment type (from measure-attached to millisecond
	// position-attached, and vice versa). In case the marker is turned into a measure-attached marker, the voice to which the marker will be attached
	// is the one nearest to the click point. <br />
	// • <m>Cmd+click</m> (mac) or <m>Ctrl+click</m> (win) on a marker: Delete marker <br />
	// • <m>click+drag</m> on a marker: Change the marker onset <br />
	//    ↪ Measure-attached markers are by default snapped to existing chord onsets or measure barlines; add the <m>Shift</m> key to remove the snapping<br />
    //    ↪ Add the <m>Shift</m> key milliseconds-attached markers snap to chord onsets <br />
	//    ↪ For millisecond position-attached markers, add the <m>Shift+Cmd</m> keys (mac) or <m>Shift+Ctrl</m> keys (win) to fine editing their onset <br />
	// • <m>Alt+click+drag</m>: Duplicate the marker into a new one with an unique name <br />
	// • <m>doubleclick</m> on a marker name: Edit marker name <br />
	// 
	// <br />
	// Linear editing: <br />
	// • <m>Ctrl+click</m> (mac) or <m>Shift+Ctrl+click</m> (win) on a measure avoiding all noteheads: Enter linear editing mode <br />
	// • <m>click</m> outside the staves while in linear editing mode: Exit linear editing mode <br />
	//
	// <br />
	// For slots: <br />
	// @copy BACH_DOC_SLOT_EDIT_MOUSE_COMMANDS


#define BACH_DOC_SCORE_EDIT_KEYBOARD_COMMANDS
	// Basic commands: <br />
	// • <m>Backspace</m>: Delete all selected items, except for selected note tails, for which the backspace key reverts their pitch to the 
	// original notehead pitch (no glissando). <br /> 
    //    ↪ Add the <m>Shift</m> key to delete selected measures; otherwise simple <m>Backspace</m> will clear the measure content. <br />
	// • <m>→</m>: Shift selection onsets to the right; for selected tails: increase corresponding note duration <br />
	// • <m>←</m>: Shift selection onsets to the left; for selected tails: decrease corresponding note duration <br /> 
	// • <m>↑</m>: Raise pitch of selection by one step. <br /> 
	//    ↪ Add the <m>Shift</m> key to raise the pitch by one octave. <br />
	//    ↪ Add the <m>Ctrl+Shift</m> key to prevent notes from being assigned to different voices. <br />
	// • <m>↓</m>: Lower pitch of selection by one step. <br /> 
	//    ↪ Add the <m>Shift</m> key to lower the pitch by one octave. <br />
	//    ↪ Add the <m>Ctrl+Shift</m> key to prevent notes from being assigned to different voices. <br />
	// • <m>Cmd+Z</m> (mac) or <m>Ctrl+Z</m> (win): Undo <br />
	// • <m>Cmd+Shift+Z</m> (mac) or <m>Ctrl+Y</m> (win): Redo <br />
	// • <m>Cmd+L</m> (mac) or <m>Ctrl+L</m> (win): Lock/unlock items <br />
	// • <m>Ctrl+A</m>, <m>Ctrl+B</m>, <m>Ctrl+C</m>, <m>Ctrl+D</m>, <m>Ctrl+E</m>, <m>Ctrl+F</m>, <m>Ctrl+G</m> (mac) or
	// <m>Shift+Ctrl+A</m>, <m>Shift+Ctrl+B</m>, <m>Shift+Ctrl+C</m>, <m>Shift+Ctrl+D</m>, <m>Shift+Ctrl+E</m>, <m>Shift+Ctrl+F</m>, <m>Shift+Ctrl+G</m> (win):
	// Transform pitches of selected notes into the corresponding pitch (A = La, B = Si, C = Do, and so on). 
	// The octave is chosen to be the one so that the snapped note is as near as possible to the previous note. <br /> 
	// 
	// <br />
	// Splitting, merging and ties: <br />
	// • <m>Cmd+2</m>, <m>Cmd+3</m>, <m>Cmd+4</m>, <m>Cmd+5</m>, <m>Cmd+6</m>, <m>Cmd+7</m>, <m>Cmd+8</m>, <m>Cmd+9</m> (mac) or 
	// <m>Ctrl+2</m>, <m>Ctrl+3</m>, <m>Ctrl+4</m>, <m>Ctrl+5</m>, <m>Ctrl+6</m>, <m>Ctrl+7</m>, <m>Ctrl+8</m>, <m>Ctrl+9</m> (win):
	// Split selected chords into the given number of pieces (2, 3, 4...). <br />
	//    ↪ By default tied sequencies are split in their entiredy; add the <m>Alt</m> key to always split each selected chord singularly. <br />
	// • <m>Cmd+Shift+Y</m> (mac) or <m>Ctrl+Shift+Y</m> (win): Merge selected chords <br />
	// • <m>Cmd+T</m> (mac) or <m>Ctrl+T</m> (win): Tie selected chords to the following ones <br />
	// 
	// <br />
	// Measure widths and spacing: <br />
	// • <m>Cmd+Shift+L</m> (mac) or <m>Ctrl+Shift+L</m> (win) when measures are selected: Lock/unlock measure barlines 
	// (toggle preventing measure widths from floating) <br />
	// • <m>Shift+Backspace</m> when a barline is selected: Revert measure width factor to 1 <br />
	//
	// <br />
	// Tempi: <br />
	// • <m>Cmd+Alt+Shift+I</m> (mac) or <m>Ctrl+Alt+Shift+I</m> (win) when a tempo is selected: Toggle interpolation towards next tempo (rallentando
	// or accelerando, depending on next tempo value)<br />
	//
	// <br />
	// Sequencing and dump: <br />
	// • <m>Spacebar</m> while not playing: Play (the playing starts from current playhead cursor position) <br />
	// • <m>Spacebar</m> during playback: Stop (the playhead cursor position goes back to the former starting play point) <br />
	// • <m>Shift+Spacebar</m> during playback: Pause (keep the playhead cursor at the last
	// reached position, so that a new <m>play</m> message or a new <m>Spacebar</m> command will
	// start playing from there) <br />
	// • <m>Shift+Spacebar</m> while not playing: Play selection (start playing from the leftmost selected item
	// and only play the selected items) <br />
	// • <m>V</m>: Off-line play, also known as "selection dump" (immediately send the playout syntax of selected elements
	// out the playout, see <m>dumpselection</m> message) <br />
	// • <m>Shift+V</m>: Chordwise off-line play (as the previous command, but if a single note is selected, all its chord content
	// is output through the playout) <br />
	// • <m>Shift+Alt+V</m>: Send whole gathered syntax content out the first outlet (this is equivalent to sending a <m>dump</m> message) <br />
	// • <m>Cmd+P</m> (mac) or <m>Ctrl+P</m> (win): Show/hide playhead cursor (while not playing: indeed, during playback the cursor is always visible) <br />
    // • Any defined command key: send command off-line <br />
	// • <m>Cmd+J</m> (mac) or <m>Ctrl+J</m> (win): Solo/unsolo items <br />
	// • <m>Cmd+U</m> (mac) or <m>Ctrl+U</m> (win): Mute/unmute items <br />
	// • <m>Return</m>: set the playhead cursor and the scrollbar both at the beginning of the <o>bach.score</o>, or at the beginning of the loop region (in case it is displayed). <br />
	// • <m>Cmd+L</m> (mac) or <m>Ctrl+L</m> (win) when nothing is selected: Show/hide loop region <br />
	// • <m>Cmd+Shift+L</m> (mac) or <m>Ctrl+Shift+L</m> (win) when nothing is selected: Activate/deactivate loop region <br />
	//
	// <br />
	// Inspector, selection and navigation: <br />
	// • <m>Cmd+I</m> (mac) or <m>Ctrl+I</m> (win): Open inspector for selected item (if a single item is selected), or for slotinfo (if a slot window is open). <br />
	// • <m>→</m>, <m>←</m>, <m>↑</m>, <m>↓</m>, <m>Enter</m>, <m>Esc</m>: Navigate inside the score while inspecting elements (i.e. while the bach inspector has the focus).
	// See the indication at the bottom of each inspector screen in order to know how to use such keyboard commands. In general <m>←</m> and <m>→</m> move 
	// respectively to previous and next element, <m>↑</m> and <m>↓</m> to the elements above or below, <m>Enter</m> moves to the first "son" of the
	// element and <m>Esc</m> to the element's "father" (in the score hierarchy).
	// • <m>Cmd+→</m>, <m>Cmd+←</m>, <m>Cmd+↑</m>, <m>Cmd+↓</m> (mac) or 
	// <m>Ctrl+→</m>, <m>Ctrl+←</m>, <m>Ctrl+↑</m>, <m>Ctrl+↓</m> (win): Navigate inside the score, respectively selecting the element at right,
	// left, above or below with respect to the currently selected item.<br />
	// If no item is selected, the first two commands will move the horizontal scrollbar, if any (left or right).<br />
	// • <m>Cmd+A</m> (mac) or <m>Ctrl+A</m> (win): Select all items <br />
	//
	// <br />
	// Copy/paste actions (these work also from a <o>bach.score</o> to another one): <br />
	// • <m>Cmd+C</m> (mac) or <m>Ctrl+C</m> (win): Copy selected measures, or slot content if a slot window is open. <br />
	// • <m>Cmd+Shift+C</m> (mac) or <m>Ctrl+Shift+C</m> (win): If a slot window is open, copy the content of 
	// all the slots of the note whose slot window is open; otherwise simply copy selected measures. <br />
	// • <m>Cmd+X</m> (mac) or <m>Ctrl+X</m> (win): Cut selected measures, or slot content if a slot window is open. <br />
	// • <m>Cmd+V</m> (mac) or <m>Ctrl+V</m> (win): If the content in the clipboard are measures, paste measures over the currectly selected ones.
	// If the content is a slot content, assign such slot content to all selected notes. <br />
	//
	// <br />
	// For pitch breakpoints: <br />
	// • <m>Esc</m>: Revert slope to 1 for selected breakpoints (the slope refers to the duration line segment preceding the breakpoints). <br />
	//
	// <br />
	// Linear editing (these commands are valid when only in linear editing mode): <br />
	// • <m>↑</m>, <m>↓</m>: Move position of the pitch cursor of one step up or down (respectively) <br />
	//    ↪ Add the <m>Shift</m> key to move the pitch cursor by one octave. <br />
	// • <m>1</m>, <m>2</m>, <m>3</m>, <m>4</m>, <m>5</m>, <m>6</m>, <m>7</m>, <m>8</m>: 
	// Insert chord at cursor position with a given duration (if the cursor is not on any chord), or modify duration of chord at cursor.
	// Durations are mapped on numbers in the following way: <m>5</m> is a 1/4 chord. Higher values are diadic larger multiples:
	// <m>6</m> is a 1/2 chord, <m>7</m> is a 1/1 chord, <m>8</m> is a 2/1 chord. Smaller values are diadic subdivisions: <m>4</m> is a 1/8 chord,
	// <m>3</m> is a 1/16 chord, <m>2</m> is a 1/32 chord, <m>1</m> is a 1/64 chord. <br />
	//    ↪ Add the <m>Ctrl</m> key (mac) or <m>Shift+Ctrl</m> key (win) to add the chord before the cursor, if the cursor is on a given chord. <br />
	// • <m>A</m>, <m>B</m>, <m>C</m>, <m>D</m>, <m>E</m>, <m>F</m>, <m>G</m>: 
	// Insert note at cursor position with a given pitch (if the cursor is not on any chord), or modify pitch of note at cursor.
	// Pitches are trivially mapped as in the anglo-saxon syntax. If a new chord is inserted, this will have the duration of the last 
	// inserted one (by default 1/8). <br />
	// • <m>N</m>: Add a new note at cursor position <br />
	// • <m>X</m>: Turn the chord at cursor position into a grace chord and vice versa (or to the previous chord, if cursor position does not lie on any chord) <br />
	// • <m>.</m>: Add a dot to the chord at cursor position (or to the previous one, if cursor position does not lie on any chord) <br />
	// • <m>T</m>: Add/remove tie to the note at cursor position (cursor must be aligned also vertically with the note, if no chord lies on the
	// cursor position horizontally, the previous chord is considered) <br />
	// • <m>Backspace</m>: Delete chord at cursor position<br />
	// • <m>Shift+Backspace</m>: Delete note at cursor position (cursor must be aligned also vertically with the note to delete)<br />
	// • <m>Alt+3</m>, <m>Alt+5</m>, <m>Alt+6</m>, <m>Alt+7</m>, <m>Alt+9</m>: Start inserting a tuplet (respectively: a triplet, a 5-plets, 
	// a 6-plet, a 7-plet and a 9-plet). Then ordinary numeric keys are expected to assign the elements of the tuplet. For instance,
	// Alt+3 and then 4, 4, 4, will insert a 8th notes triplet. <br />
    // • <m>+</m>, <m>-</m>: raise or lower pitch of chord or note at cursor (if any) <br />
	// • <m>Cmd+→</m>, <m>Cmd+←</m>, <m>Cmd+↑</m>, <m>Cmd+↓</m> (mac) or
	// <m>Ctrl+→</m>, <m>Ctrl+←</m>, <m>Ctrl+↑</m>, <m>Ctrl+↓</m> (win): Navigate inside the measures <br />
	// • <m>Esc</m>: Exit linear editing mode <br />
	//
	// <br />
	// Rhythm, beams and rhythmic tree levels: <br />
	// • <m>Tab</m>: Rebeam selection automatically <br />
	//    ↪ By default, the rebeaming keeps untouched the information about existing tuplet levels; add the <m>Shift</m> key to reparse all tuplets <br />
	// • <m>Cmd+Shift+T</m> (mac) or <m>Ctrl+Shift+T</m> (win): Lock/unlock measure rhythmic tree <br />
	// • <m>Cmd+Shift+J</m> (mac) or <m>Ctrl+Shift+J</m> (win): Destroy all rhythmic tree levels for selection <br />
	// • <m>Cmd+Shift+H</m> (mac) or <m>Ctrl+Shift+H</m> (win): Destroy outermost selection tree level (just one) <br />
	// • <m>Cmd+Shift+G</m> (mac) or <m>Ctrl+Shift+G</m> (win): Add a rhythmic tree level around the selected content <br />
	// • <m>Cmd+Shift+F</m> (mac) or <m>Ctrl+Shift+F</m> (win): Fix levels of selection as "original" levels <br />
	//
	// <br />
	// Lyrics: <br />
    // Lyrics and dynamics: <br />
    // • <m>Cmd+Shift+L</m> (mac) or <m>Ctrl+Shift+L</m> (win): Start editing lyrics for the leftmost selected chord, or for the selected lyrics <br />
    // • <m>Cmd+Shift+D</m> (mac) or <m>Ctrl+Shift+D</m> (win): Start editing dynamics for the leftmost selected chord, or for the selected dynamics <br />
    // • <m>Tab</m> while editing: Move to next chord's lyrics <br />
    // • <m>Shift+Tab</m> while editing: Move to previous chord's lyrics <br />
    // • <m>-</m>: For lyrics: end a syllable with "-" in order to create a dashed line reaching the next piece of lyrics <br />
    // • <m>Esc</m>: End editing <br />
	//
	// <br />
	// Articulations: <br />
	// • <m>Backspace</m>: Delete selected articulations <br />
	// • <m>Alt+Backspace</m>: Delete articulations of all selected notes <br />
	// • <m>Alt+S</m>: Add "staccato" articulation to selection <br />
	// • <m>Alt+Shift+S</m>: Add "staccatissimo" articulation to selection <br />
	// • <m>Alt+F</m>: Add "fermata" articulation to selection <br />
	// • <m>Alt+P</m>: Add "portato" articulation to selection <br />
	// • <m>Alt+A</m>: Add "accent" articulation to selection <br />
	// • <m>Alt+Z</m>: Add "accent+staccato" articulation to selection <br />
	// • <m>Alt+Shift+Z</m>: Add "accent+portato" articulation to selection <br />
	// • <m>Alt+W</m>: Add "portato+staccato" articulation to selection <br />
	// • <m>Alt+J</m>: Add "martellato" articulation to selection <br />
	// • <m>Alt+Shift+J</m>: Add "martellato+staccato" articulation to selection <br />
	// • <m>Alt++</m>: Add "left hand pizziacto" articulation to selection <br />
	// • <m>Alt+T</m>: Add "trill" articulation to selection <br />
	// • <m>Alt+G</m>: Add "gruppetto" articulation to selection <br />
	// • <m>Alt+M</m>: Add "upward mordent" articulation to selection <br />
	// • <m>Alt+Shift+M</m>: Add "downward mordent" articulation to selection <br />
	// • <m>Alt+N</m>: Add "double mordent" articulation to selection <br />
	// • <m>Alt+B</m>: Add "upward bowing" articulation to selection <br />
	// • <m>Alt+Shift+N</m>: Add "downward bowing" articulation to selection <br />
	// • <m>Alt+R</m>: Add "3-slash-tremolo" articulation to selection<br />
	// • <m>Alt+Shift+R</m>: Add "2-slash-tremolo" articulation to selection<br />
	// • <m>Alt+Ctrl+Shift+R</m>: Add "1-slash-tremolo" articulation to selection<br />
	// N.B.: the default font support all glyphs, however not all the other supported fonts do. 
	// Especially, Boulez doesn't have a certain number of the 
	// previous articulations among its glyphs. If you don't see an articulation as you wish (e.g. tremoli with Boulez), 
	// it might be because the font doesn't have the proper character, so try to use another font, if you can. <br />
	//
	// <br />
	// For slots: <br />
	// @copy BACH_DOC_SLOT_EDIT_KEYBOARD_COMMANDS
	
#define BACH_DOC_OPERATION_ABSTRACTIONS_LLLL_AND_NUMBERS_REMARK
	// Unless one of the two operand lllls is a number, the operation is intended to be 
	// element-wise: position of elements of left and right elements must match in operations, 
	// both left and right lllls must have the same shape.
	// If one of the two lllls is a single number, such number is used in the operation against 
	// all elements of the other llll (as when the <m>scalarmode</m> attribute is set to 1 
	// in <o>bach.expr</o>).
	// <br /> <br />

#define BACH_DOC_SETTHEORY_CHROMA
	// The chroma of a certain pitch-class set is a vector having as entries one coefficient for 
	// each note of the temperament, representing the "amount" of presence of such note inside the pitch-class set,
	// from 0 (pitch-class is not present) to 1 (pitch-class is "fully" present).
	// For instance, in standard semitonal system the chroma <b>1 0 0.2 0 1 0 0 1 0 0 0.5 0</b> 
	// represents a C major triad with a little bit of Bb and just a touch of D. <br />
	// <br /> <br />

#define BACH_DOC_SETTHEORY_CHROMA_TONAL_TRANSFORM
	// The tonal trasform of a chroma vector, essentially, projects the vector into three spaces (depending on some projection radii): 
	// respectively one generated by fifths, one generated by minor thirds, and one generated by major thirds. 
	// For each of these three spaces, two coordinates are output (so 6 coordinates are globally output).
	// Each couple of coordinates represents X and Y coordinates of a point inside the unit circle.
	// Also see: Harte and Sandler,	http://www.ofai.at/~martin.gasser/papers/oefai-tr-2006-13.pdf 
	// <br /> <br />


#define BACH_DOC_SETTHEORY_DIATONIC_INTERVALS_SYNTAX
	// A diatonic interval is by default characterized by a couple of integer numbers (list form of diatonic intervals): the width of the interval
	// in diatonic steps, and the width of the interval in chromatic steps. The number of diatonic steps in an octave
	// is always 7, while the number of chromatic steps depends on the modulo; by default, in the semitonal system, it is 12.
	// In such system, for instance, an ascending major third will be represented by <b>2 4</b>, since we need 2 diatonic steps 
	// and 4 chromatic steps to get from the bottom to the top note. As further examples, the interval between C5 and D#5 is <b>1 3</b>,
	// and the interval between E#4 and Fb5 is <b>8 11</b>. <br />
	// You can usually specify the diatonic interval also by directly inputting the width of the interval in midicents.
	// However this is always ambiguous, and bach will chose one of the infinite diatonic ways to interpret such interval - ideally, the 
	// "simplest" one: 700 is a major fifth, 300 is a minor third (and not an augmented second), and so on. 
	// <br /> <br />	
	// @copy BACH_DOC_SETTHEORY_MODULO

#define BACH_DOC_SETTHEORY_TONNETZ_COORDINATES
	// The coordinate of a point of the tonnetz is the position of such point in the oblique grid created by the horizontal axis, passing
	// for the tonnetz center, and the diagonal axis, at 60° counterclockwise from the horizontal one, again passing for the tonnetz center.
	// Coordinates above the center and at right have positive values, below and at left have negative ones. Each point can be uniquely determined
	// by the amount of steps one must take rightwards from the center (coordinate 1) and diagonlly upwards at 60° (coordinate 2) in order to 
	// get to the point.
	// <br /> <br />

#define BACH_DOC_SETTHEORY_TONNETZ_COMPLETE_POINT_INFORMATION
	// The complete point information syntax is the form in which point data is output 
	// from the query outlet. Up to a custom initial router, it has the following form:
	// <b><m>cents</m> <m>pitch-class</m> <m>WRAPPED_DIATONIC_INTERVAL_FROM_CENTER</m> <m>WRAPPED_COORDINATES</m></b>,
	// where <m>WRAPPED_DIATONIC_INTERVAL_FROM_CENTER</m> is in the llll diatonic intervals syntax, and <m>WRAPPED_COORDINATES</m>
	// are the coordinates to get to the tonnetz point from the tonnetz center.
	// <br /> <br />
	// @copy BACH_DOC_SETTHEORY_DIATONIC_INTERVALS_SYNTAX
	// @copy BACH_DOC_SETTHEORY_TONNETZ_COORDINATES

#define BACH_DOC_NORM_P_ATTRIBUTE_FOR_VECTORS
	// Sets the value of the index <m>p</m>, 
	// determining the type of norm. Such value can be an
	// integer greater or equal than 1, or can be the
	// symbol "inf", for the infinite norm.
	// In general, the p-norm of a vector is calculated by 
	// raising all the absolute values of the elements 
	// to the <m>p</m>-th power, summing all values, and taking
	// the <m>p</m>-th root (i.e. raising to 1/<m>p</m>).
	// The inf-norm, on the other hand, is the absolute value
	// of the maximum element in the llll.
	// <br /> <br />


#define BACH_DOC_NORM_P_ATTRIBUTE_FOR_FUNCTIONS
	// Sets the value of the index <m>p</m>, determining the type of norm. Such value can be an integer greater or equal than 1, or can be the
	// symbol "inf", for the infinite norm. In general, the p-norm of a function is calculated by taking the <m>p</m>-th root of the integral of the 
	// absolute value of the function raised to the <m>p</m>-th power.
	// The inf-norm, on the other hand, is the absolute value of the "sup" of the function (which coincides with the function maximum for breakpoint functions).
	// <br /> <br />

#define BACH_DOC_NOTATION_FONT
	// @description Sets the font used to display all notation elements except accidentals. 
	// The official notation bach font is "November for bach", created by Robert Piéchaud (www.poeticprocessing.net) and 
	// automatically loaded at bach startup. "November for bach" is a light version of the famous November font. 
	// The full November font covers a wide range of music symbols, from Renaissance to the XXI century, and gives a unique, 
	// warm and lively look to your music scores. It is fully compatible with Finale, Sibelius and other notation softwares. 
	// You can purchase November from this web address: www.klemm-music.de/notation/november/.
	// Other supported fonts are: Boulez, Maestro, Petrucci, Engraver Font Set.

#define BACH_DOC_ACCIDENTALS_FONT
	// @description Sets the font used to display accidentals. 
	// The official notation bach font is "November for bach", created by Robert Piéchaud (www.poeticprocessing.net) and 
	// automatically loaded at bach startup. "November for bach" is a light version of the famous November font. 
	// The full November font covers a wide range of music symbols, from Renaissance to the XXI century, and gives a unique, 
	// warm and lively look to your music scores. It is fully compatible with Finale, Sibelius and other notation softwares. 
	// You can purchase November from this web address: www.klemm-music.de/notation/november/.
	// Other supported fonts are: Accidentals (up to the eighth-tones), Tamburo (up to the quartertones), 
	// Maestro, Petrucci, Boulez, Engraver Font Set (up to the semitones).

#define BACH_DOC_ARTICULATIONS_FONT
    // @description Sets the font used to display articulations.
    // The official notation bach font is "November for bach", created by Robert Piéchaud (www.poeticprocessing.net) and
    // automatically loaded at bach startup. "November for bach" is a light version of the famous November font.
    // The full November font covers a wide range of music symbols, from Renaissance to the XXI century, and gives a unique,
    // warm and lively look to your music scores. It is fully compatible with Finale, Sibelius and other notation softwares.
    // You can purchase November from this web address: www.klemm-music.de/notation/november/.
    // Other supported fonts are: Boulez, Maestro, Petrucci, Engraver Font Set. Not all articulations are supported by all fonts.
    // You can however always define custom articulations with any font of your choice.

#define BACH_DOC_DYNAMICS_SPECTRUM
    // The dynamics spectrum is the sequence of standard dynamics in the piano-to-forte range.
    // It is characterized by its "maxchars", i.e. the maximum number of p's and f's of the elements it contains ("mp" and "mf"
    // are considered as having 0 p's and f's).
    // For instance, the collection of
    // {"pp", "p", "mp", "mf", "f", "ff"} makes for a spectrum of <m>maxchars</m> = 2.
    // The "maxchars" property of the dynamic spectrum will factor into different conversions between dynamics and velocities,
    // in combination with a conversion exponent.
    // The dynamic range is set via the "maxchars" parameter, while the exponent is set via the "exp" parameter (greater than 0. and less or equal to 1.).
    // If "exp" is 1., the velocity range is divided linearly between the dynamics in the spectrum; otherwise an exponential scaling is applied.
    // Default exponent is 0.8, and default range width is 5 (from "pppp" to "ffff").
    // Any dynamic marking outside the spectrum will be clipped to the spectrum during conversion.
    // The dynamics are scaled so that "mp" will always correspond to velocity = 64.
    // If i is the index of the
    // If <m>i</m> is the 1-based index of the element of a spectrum containing 2D elements <br />
    // vel(i) = 128 * ((1 + sgn(-1+2i/(2D+1))*|-1+2i/(2D+1)|^a)/2)^b <br />
    // More clearly, once set x = x(i, D) = -1+2i/(2D+1), between -1 and 1, one has <br />
    // vel(i) = 128 * ((1 + sgn(x)*|x|^a)/2)^b. <br />
    // This function assumes values between 0. and 1., for x in [-1, 1].
    // In any case vel(i) is clipped to 127 (128 won't be allowed).
    // The parameter <m>a</m> is the "exp" parameter defined above. The parameter <m>b</m> is chosen so that vel("mp") = vel(D) = 64, which yields <br />
    // b = 1/(1 - log2(1 - 1/((2D+1)^a))) <br />
    // As an example, if "exp" (i.e. <m>a</m>) is 0.8 (hence <m>b</m> is about 0.745),
    // consider the spectrum {"pp", "p", "mp", "mf", "f", "ff"}, having <m>maxchars</m> = 2 and <m>D</m> = 3 (containing <m>2D</m> = 6 elements).
    // The dynamics "f" has index 5, hence x = x(5, 3) = -1+2i/(2D+1) = -1 + 10/7 = 3/7, hence <br />
    // vel("f") = vel(5) = 128 * ((1 + (3/7)^a)/2)^b ~ 128 * 0.810 ~ 103, <br />
    // while within the broader spectrum {"pppp", "ppp", "pp", "p", "mp", "mf", "f", "ff", "fff", "ffff"}, having <m>maxchars</m> = 4 and <m>D</m> = 5,
    // one has x = x(7, 5) = -1+2i/(2D+1) = -1 + 14/11 = 3/11
    // vel("f") = vel(7) = 128 * ((1 + (3/11)^a)/2)^b ~ 128 * 0.748 ~ 96. <br />
