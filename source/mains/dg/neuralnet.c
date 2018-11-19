/**
    @file
    neuralnet.c
    
    @name 
    bach.neuralnet
    
    @realname 
    bach.neuralnet

    @type
    object
    
    @module
    bach

    @author
    bachproject
    
    @status
    hidden

    @digest 
    Feed-forward or recurrent neural networks
    
    @description
    Implements a feed-forwards or recurrent neural network with an arbitrary number of layers
    
    @discussion
    The training is achieved via feed forwarding and then backpropagation through gradient descent.
    The algorithm can operate both in stochastic and in batch mode.
    Even for recurrent neural networks, currently, only standard backpropagation is used (no backpropagation through time).
    
    @category
    bach, bach objects, bach llll

    @keywords
    neural, neuron, network, net, perceptron, machine learning, backpropagation, feed, feedforward, recurrent, batch, stochastic, layer, train

    @seealso
    bach.constraints
    
    @owner
    Daniele Ghisi
*/

#include "neuralNetwork.h"
#include "dataReader.h"
#include "llll_commons_ext.h"
#include "llll_files.h"


typedef struct _neuralnet
{
    struct llllobj_object     n_ob;
    
    void                    *n_proxy[2];
    long                    n_in;

    
    neuralNetwork    *nn;
    
    char            recurrent; // recurrent network?
    
    long            network_in;
    long            newtork_num_hidden;
    long            *network_hidden;
    long            network_out;
    
    double            learning_rate;
    double            momentum;
    
    double            classification_tolerance;
    double            desired_accuracy;
    double            desired_mse;
    
    long            max_epochs;
    char            batch_learning;
    long            bptt_num_steps; // number steps of backpropagation through time, only for recurrent networks
    
    char            activation_function;

    char            verbose;
    char            embed;
    
    // dataset
    double            dataset_split[2];
    char            dataset_mode;
    double            dataset_step;
    double            dataset_win;
    
    // parallel processing
    t_systhread                n_thread;
    char                    parallel;
    t_qelem                    n_waitbar_qelem;
    t_qelem                    n_verbose_qelem;

    t_bach_atomic_lock        n_inuse;

} t_neuralnet;


void neuralnet_assist(t_neuralnet *x, void *b, long m, long a, char *s);
void neuralnet_inletinfo(t_neuralnet *x, void *b, long a, char *t);
void neuralnet_appendtodictionary(t_neuralnet *x, t_dictionary *d);
void neuralnet_stop(t_neuralnet *x);

t_neuralnet *neuralnet_new(t_symbol *s, short ac, t_atom *av);
void neuralnet_free(t_neuralnet *x);

void neuralnet_bang(t_neuralnet *x);
void neuralnet_int(t_neuralnet *x, t_atom_long num);
void neuralnet_float(t_neuralnet *x, double num);
void neuralnet_anything(t_neuralnet *x, t_symbol *msg, long ac, t_atom *av);

void neuralnet_waitbar_qelem_do(t_neuralnet *x);
void neuralnet_verbose_qelem_do(t_neuralnet *x);
void neuralnet_read(t_neuralnet *x, t_symbol *s);
void neuralnet_write(t_neuralnet *x, t_symbol *s, long argc, t_atom *argv);
void neuralnet_writetxt(t_neuralnet *x, t_symbol *s, long argc, t_atom *argv);
void neuralnet_return(t_neuralnet *x, t_llll *ll);

/*
t_max_err neuralnet_setattr_learningrate(t_neuralnet *x, t_object *attr, long ac, t_atom *av);
t_max_err neuralnet_setattr_momentum(t_neuralnet *x, t_object *attr, long ac, t_atom *av);
t_max_err neuralnet_setattr_desiredaccuracy(t_neuralnet *x, t_object *attr, long ac, t_atom *av);
t_max_err neuralnet_setattr_maxepochs(t_neuralnet *x, t_object *attr, long ac, t_atom *av);
t_max_err neuralnet_setattr_verbose(t_neuralnet *x, t_object *attr, long ac, t_atom *av);
t_max_err neuralnet_setattr_batchlearning(t_neuralnet *x, t_object *attr, long ac, t_atom *av);
t_max_err neuralnet_setattr_activationfunction(t_neuralnet *x, void *attr, long ac, t_atom *av);
*/

//// ACCESSORS 

t_max_err neuralnet_setattr_momentum(t_neuralnet *x, void *attr, long ac, t_atom *av)
{
    x->momentum = (ac && av && is_atom_number(av)) ? atom_getfloat(av) : NEURALNET_DEFAULT_MOMENTUM;
    x->nn->setLearningParameters(x->learning_rate, x->momentum);
    return MAX_ERR_NONE;
}

t_max_err neuralnet_setattr_classificationtolerance(t_neuralnet *x, void *attr, long ac, t_atom *av)
{
    x->classification_tolerance = (ac && av && is_atom_number(av)) ? atom_getfloat(av) : NEURALNET_DEFAULT_CLASSIFICATION_TOLERANCE;
    x->nn->setClassificationTolerance(x->classification_tolerance);
    return MAX_ERR_NONE;
}

t_max_err neuralnet_setattr_desiredaccuracy(t_neuralnet *x, void *attr, long ac, t_atom *av)
{
    x->desired_accuracy = (ac && av && is_atom_number(av)) ? atom_getfloat(av) : NEURALNET_DEFAULT_DESIRED_ACCURACY;
    x->nn->setDesiredAccuracy(x->desired_accuracy);
    return MAX_ERR_NONE;
}

t_max_err neuralnet_setattr_desiredmse(t_neuralnet *x, void *attr, long ac, t_atom *av)
{
    x->desired_mse = (ac && av && is_atom_number(av)) ? atom_getfloat(av) : NEURALNET_DEFAULT_DESIRED_ACCURACY;
    x->nn->setDesiredMSE(x->desired_mse);
    return MAX_ERR_NONE;
}

t_max_err neuralnet_setattr_maxepochs(t_neuralnet *x, void *attr, long ac, t_atom *av)
{
    x->max_epochs = (ac && av && is_atom_number(av)) ? atom_getlong(av) : NEURALNET_DEFAULT_MAX_EPOCHS;
    x->nn->setMaxEpochs(x->max_epochs);
    return MAX_ERR_NONE;
}

t_max_err neuralnet_setattr_verbose(t_neuralnet *x, void *attr, long ac, t_atom *av)
{
    x->verbose = (ac && av && is_atom_number(av)) ? atom_getlong(av) : NEURALNET_DEFAULT_VERBOSE;
    x->nn->setVerbose(x->verbose);
    return MAX_ERR_NONE;
}

t_max_err neuralnet_setattr_activationfunction(t_neuralnet *x, void *attr, long ac, t_atom *av)
{
    x->activation_function = (ac && av && is_atom_number(av)) ? atom_getlong(av) : NEURALNET_DEFAULT_ACTIVATION_FUNCTION;
    x->nn->setActivationFunction(x->activation_function);
    return MAX_ERR_NONE;
}

t_max_err neuralnet_setattr_batchlearning(t_neuralnet *x, void *attr, long ac, t_atom *av)
{
    x->batch_learning = (ac && av && is_atom_number(av)) ? atom_getlong(av) : NEURALNET_DEFAULT_BATCH_LEARNING;
    if (x->batch_learning)
        x->nn->useBatchLearning();
    else
        x->nn->useStochasticLearning();
    return MAX_ERR_NONE;
}


t_max_err neuralnet_setattr_learningrate(t_neuralnet *x, void *attr, long ac, t_atom *av)
{
    x->learning_rate = (ac && av && is_atom_number(av)) ? atom_getfloat(av) : NEURALNET_DEFAULT_LEARNING_RATE;
    x->nn->setLearningParameters(x->learning_rate, x->momentum);
    return MAX_ERR_NONE;
}

t_max_err neuralnet_setattr_bpttsteps(t_neuralnet *x, void *attr, long ac, t_atom *av)
{
    x->bptt_num_steps = CLAMP((ac && av && is_atom_number(av)) ? atom_getlong(av) : NEURALNET_DEFAULT_NUM_BPTT_STEPS, 2, NEURALNET_MAX_BPTT_STEPS);
    x->nn->setNumBpttSteps(x->bptt_num_steps);
    return MAX_ERR_NONE;
}




t_class *neuralnet_class;

int T_EXPORT main()
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    c = class_new("bach.neuralnet", (method)neuralnet_new, (method)neuralnet_free, (short)sizeof(t_neuralnet), 0L, A_GIMME, 0);
    
    // @method llll @digest Train or feed network
    // @description An <m>llll</m> in first inlet is considered as a list of input values to be fed to the network. 
    // The corresponding output values are output from the first outlet. An <m>llll</m> in second inlet is considered as a list of 
    // training items; each item must be in the form <b>((<m>input1</m> <m>input2</m>...) (<m>target1</m> <m>target2</m>...))</b>
    // containing the inputs and the expected targets for such inputs. Once the training is over, a message containing the results is output
    // through the third outlet (see outlet documentation for more information).
    class_addmethod(c, (method)neuralnet_anything,                    "anything",                A_GIMME,    0);
    class_addmethod(c, (method)neuralnet_int,                        "int",                    A_LONG,        0);
    class_addmethod(c, (method)neuralnet_float,                        "float",                A_FLOAT,    0);
    class_addmethod(c, (method)neuralnet_anything,                    "list",                    A_GIMME,    0);
    class_addmethod(c, (method)neuralnet_appendtodictionary,        "appendtodictionary",    A_CANT, 0);

    
    
    // @method read @digest Read network state from disk
    // @description The specified file is read from disk and the llll it contains is considered to be the model (network state)
    // The input model must be an llll of the same form as the one output by the <m>dump</m> message (see <m>dump</m> for more information).
    // @marg 0 @name file_name @optional 1 @type symbol
    class_addmethod(c, (method)neuralnet_read,        "read",            A_DEFSYM,    0);

    
    // @method write @digest Save network state in native format
    // @description A <m>write</m> message will save the network state in a file, in native format. 
    // If an argument is given, this is the filename (if the file is in the search path 
    // or in the same folder) or the full file path. If no argument is given, a dialog window pops up.
    // @marg 0 @name file @optional 1 @type symbol
    class_addmethod(c, (method) neuralnet_write, "write", A_GIMME, 0);
    
    
    // @method writetxt @digest Save network state in text format
    // @description A <m>writetxt</m> message will save the network state (as llll) in a file, in readable text format.
    // @copy BACH_DOC_WRITETXT_TEXT_FORMAT_AND_ARGUMENTS
    // @example writetxt @caption export the network as a text file, opening a dialog box for the file name
    // @example writetxt myfile.txt @caption export the network as a text file with the provided file name
    // @example writetxt myfile.txt [maxdecimals 3] @caption export the network with a floating-point precision of 3 decimal digits
    // @example writetxt myfile.txt [maxdecimals 3] [wrap 40] @caption as the above, limiting the length of each line to 40 characters
    // @example writetxt myfile.txt [indent 1] @caption export the network indenting each sublist by one space per depth level
    // @example writetxt myfile.txt [indent 1] [maxdepth 2] @caption as the above, but only first-level sublists are placed on new lines
    // @example writetxt myfile.txt [maxdepth 1] @caption no indentation is performed
    // @marg 0 @name filename @optional 1 @type symbol
    // @marg 1 @name specifications @optional 1 @type llll
    // @seealso read, write
    class_addmethod(c, (method) neuralnet_writetxt, "writetxt", A_GIMME, 0);

    
    
    // @method dump @digest Dump network state
    // @description The <m>dump</m> message dumps the network state (model) from the second outlet. This is an llll having the form
    // <b><m>NEURONS</m> <m>WEIGHTS</m></b>. The <m>NEURONS</m> llll is in the form <b>(<m>INPUT</m> <m>HIDDENLAYER1</m> <m>HIDDENLAYER2</m>... <m>OUTPUT</m>)</b>
    // and contains the wrapped lists of the activation values of all neurons in each one of the layers. 
    // If the network is not recurrent, the <m>WEIGHTS</m> llll is in the form <b>(<m>InputToHidden1</m> <m>Hidden1ToHidden2</m> ... <m>LastHiddenLayerToOutput</m>)</b>
    // where each one of the sub elements is indeed a matrix containing all the weights to pass from a given layer to the next one. 
    // If the network is recurrent, between any two elements of such lists are interleaved the weights for passing from a layer to itself, yielding the form
    // <b>(<m>InputToHidden1</m> <m>Hidden1ToHidden1</m> <m>Hidden1ToHidden2</m> <m>Hidden2ToHidden2</m> ... <m>LastHiddenLayerToLastHiddenLayer</m> <m>LastHiddenLayerToOutput</m>)</b>
    class_addmethod(c, (method)neuralnet_anything,                    "dump",                    A_GIMME,    0);

    // @method setstate @digest Set network state
    // @description An <m>llll</m> after the <m>setstate</m> message sets the state to the network to the input model.
    // The input model must be an llll of the same form as the one output by the <m>dump</m> message (see <m>dump</m> for more information).
    class_addmethod(c, (method)neuralnet_anything,                    "setstate",                    A_GIMME,    0);

    // @method reset @digest Reset network
    // @description The <m>reset</m> message in the second inlet resets the weights of the network to random values, the neurons activation values to 0, and 
    // resets the obtained training results.
    // If the <m>reset</m> message is followed by one of the symbols <m>weights</m>, <m>neurons</m>, <m>results</m>, only the corresponding data is reset,
    // while the others are preserved.
    // @marg 0 @name what @optional 1 @type symbol
    class_addmethod(c, (method)neuralnet_anything,                    "reset",                    A_GIMME,    0);
    
    // @method stop @digest Stop training
    // @description A <m>stop</m> message will cause the training to stop immediately.
    class_addmethod(c, (method)neuralnet_stop,                        "stop",                    A_GIMME,    0);
    
    // @method bang @digest Train network with last used training data.
    // @description A bang in the second inlet will train the network with the last used training data.
    class_addmethod(c, (method)neuralnet_bang,                        "bang",        0);
    
    class_addmethod(c, (method)neuralnet_assist,        "assist",        A_CANT,        0);
    class_addmethod(c, (method)neuralnet_inletinfo,    "inletinfo",    A_CANT,        0);

    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

    
    
    CLASS_STICKY_ATTR(c, "category", 0, "Training");

    CLASS_ATTR_DOUBLE(c, "learningrate", 0, t_neuralnet, learning_rate);
    CLASS_ATTR_ACCESSORS(c, "learningrate", (method)NULL, (method)neuralnet_setattr_learningrate);
    CLASS_ATTR_STYLE_LABEL(c, "learningrate", 0, "text", "Learning Rate");
    CLASS_ATTR_BASIC(c, "learningrate", 0);
    // @description Sets the learning rate for the neural net, defaults to 0.001.
    
    CLASS_ATTR_DOUBLE(c, "momentum", 0, t_neuralnet, momentum);
    CLASS_ATTR_STYLE_LABEL(c, "momentum", 0, "text", "Momentum");
    CLASS_ATTR_ACCESSORS(c, "momentum", (method)NULL, (method)neuralnet_setattr_momentum);
    CLASS_ATTR_BASIC(c, "momentum", 0);
    // @description Sets the momentum for the neural net, defaults to 0.9.
    
    CLASS_ATTR_CHAR(c, "batchlearning", 0, t_neuralnet, batch_learning);
    CLASS_ATTR_STYLE_LABEL(c, "batchlearning", 0, "onoff", "Use Batch Learning");
    CLASS_ATTR_ACCESSORS(c, "batchlearning", (method)NULL, (method)neuralnet_setattr_batchlearning);
    // @description Toggles the ability to operate in batch learning mode.
    
    CLASS_ATTR_CHAR(c, "activationfunction", 0, t_neuralnet, activation_function);
    CLASS_ATTR_STYLE_LABEL(c, "activationfunction", 0, "enumindex", "Activation Function");
    CLASS_ATTR_ENUMINDEX(c, "activationfunction", 0, "Logistic Sigmoid Hyperbolic Tangent Step");
    CLASS_ATTR_ACCESSORS(c, "activationfunction", (method)NULL, (method)neuralnet_setattr_activationfunction);
    // @description Chooses the activation function for each neuron.
    
    CLASS_ATTR_DOUBLE(c, "classificationtolerance", 0, t_neuralnet, classification_tolerance);
    CLASS_ATTR_STYLE_LABEL(c, "classificationtolerance", 0, "text", "Classification Tolerance");
    CLASS_ATTR_ACCESSORS(c, "classificationtolerance", (method)NULL, (method)neuralnet_setattr_classificationtolerance);
    // @description Sets the maximum tolerance allowed for validity check in classification problems.
    // For instance, if <m>classificationtolerance</m> is 0.1 (default), an output value of 0.09 will be considered correct
    // in case the target value should have been 0. This is used in order to determine whether a pattern is correctly classified
    // in order to properly compute the accuracy ration (also see <m>desiredaccuracy</m>).
    
    CLASS_ATTR_DOUBLE(c, "desiredaccuracy", 0, t_neuralnet, desired_accuracy);
    CLASS_ATTR_STYLE_LABEL(c, "desiredaccuracy", 0, "text", "Desired Accuracy");
    CLASS_ATTR_ACCESSORS(c, "desiredaccuracy", (method)NULL, (method)neuralnet_setattr_desiredaccuracy);
    // @description Sets the desired accuracy for the training and generalization sets. The accuracy is the ratio between correctly classified
    // patterns and whole training/generalization patterns. Once the training has reached
    // the <m>desiredaccuracy</m> on both training and generalization sets, the training ends, even if <m>maxepochs</m> is not yet
    // reached. Set this attribute to 0 (default) if you simply want to run the training in any case till <m>maxepochs</m> is reached (or till <m>desiredmse</m> is reached, if set).
    
    CLASS_ATTR_DOUBLE(c, "desiredmse", 0, t_neuralnet, desired_mse);
    CLASS_ATTR_STYLE_LABEL(c, "desiredmse", 0, "text", "Desired Mean Squared Error");
    CLASS_ATTR_ACCESSORS(c, "desiredmse", (method)NULL, (method)neuralnet_setattr_desiredmse);
    // @description Sets the desired mean squared error for the training and generalization sets. The mean squared error is
    // is the average of the sum of the squared errors (desired – actual) for each pattern in the training/generalization set. 
    // Once the training has reached the <m>desiredmse</m> on both training and generalization sets, the training ends, even if <m>maxepochs</m> is not yet
    // reached. Set this attribute to 0 (default) if you simply want to run the training in any case till <m>maxepochs</m> is reached (or till <m>desiredaccuracy</m> is reached, if set).
    
    CLASS_ATTR_LONG(c, "maxepochs", 0, t_neuralnet, max_epochs);
    CLASS_ATTR_STYLE_LABEL(c, "maxepochs", 0, "text", "Maximum Number of Training Epochs");
    CLASS_ATTR_ACCESSORS(c, "maxepochs", (method)NULL, (method)neuralnet_setattr_maxepochs);
    CLASS_ATTR_BASIC(c, "maxepochs", 0);
    // @description Sets the maximum number of epochs to be run while training.
    
    CLASS_ATTR_LONG(c, "bpttsteps", 0, t_neuralnet, bptt_num_steps);
    CLASS_ATTR_ACCESSORS(c, "bpttsteps", (method)NULL, (method)neuralnet_setattr_bpttsteps);
    CLASS_ATTR_STYLE_LABEL(c, "bpttsteps", 0, "text", "Backpropagation Through Time Memory");
    CLASS_ATTR_INVISIBLE(c, "bpttsteps", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE); // just for now, it's not working yet
    // @description Sets the length of the history for backpropagation through time (only used by recurrent networks).
    
    
    CLASS_STICKY_ATTR_CLEAR(c, "category");

    
    CLASS_STICKY_ATTR(c, "category", 0, "Behavior");

    CLASS_ATTR_CHAR(c, "embed",    0,    t_neuralnet, embed);
    CLASS_ATTR_FILTER_CLIP(c, "embed", 0, 1);
    CLASS_ATTR_LABEL(c, "embed", 0, "Save Trained Model With Patcher");
    CLASS_ATTR_STYLE(c, "embed", 0, "onoff");
    CLASS_ATTR_SAVE(c, "embed", 0);
    CLASS_ATTR_BASIC(c, "embed", 0);
    // @description When set to 1, the trained model is saved with the patcher
    // and will be available, already charged, next time the patch is loaded.


    CLASS_ATTR_CHAR(c, "verbose", 0, t_neuralnet, verbose);
    CLASS_ATTR_STYLE_LABEL(c, "verbose", 0, "enumindex", "Verbose Training");
    CLASS_ATTR_ENUMINDEX(c, "verbose", 0, "None Max Window Last Outlet");
    CLASS_ATTR_ACCESSORS(c, "verbose", (method)NULL, (method)neuralnet_setattr_verbose);
    // @description Toggles the ability to verbosely print training information in the Max window (if verbose == 1) or from the 
    // last outlet, in the form <b>verbose <m>epoch</m> (<m>TSaccuracy</m> <m>TSmeansquarederror</m>) (<m>GSaccuracy</m> <m>GSmeansquarederror</m>)</b>.
    // Some acronyms are used, namely: TS = Training Set, GS = Generalization Set, VS = Validation Set. 
    
    
    CLASS_ATTR_CHAR(c, "parallel",    0,    t_neuralnet, parallel);
    CLASS_ATTR_LABEL(c, "parallel", 0, "Parallel");
    CLASS_ATTR_FILTER_CLIP(c, "parallel", 0, 1);
    CLASS_ATTR_STYLE(c, "parallel", 0, "onoff");
    // @description When set to 1, the training is performed in a separate thread.
    // This means that the normal Max operation is not interrupted.
    // The <m>parallel</m> attribute is highly experimental and can lead to serious problems,
    // including data corruption and crashes.
    // In general, it is essential that the patch is not saved or closed
    // as long as the search is going on. Such operations are more than likely to crash Max.

    CLASS_STICKY_ATTR_CLEAR(c, "category");

    
    CLASS_STICKY_ATTR(c, "category", 0, "Dataset");
    
    CLASS_ATTR_DOUBLE_ARRAY(c,"datasetsplit",0, t_neuralnet, dataset_split, 2);
    CLASS_ATTR_STYLE_LABEL(c, "datasetsplit", 0, "text", "Dataset Split");
    CLASS_ATTR_BASIC(c, "datasetsplit", 0);
    // @description Sets the splitting ratios for generalization and validation segments of the dataset.
    // For instance, <b>0.6 0.9</b> means that the 60% of the databased is used for training, the following 30%
    // is used for generalization and the last 10% is used for validation
    
    CLASS_ATTR_CHAR(c,"datasetmode",0, t_neuralnet, dataset_mode);
    CLASS_ATTR_STYLE_LABEL(c, "datasetmode", 0, "enumindex", "Dataset Mode");
    CLASS_ATTR_ENUMINDEX(c, "datasetmode", 0, "Static Growing Windowing");
    // @description Sets the approach to building the dataset starting from the training data: <br />
    // <m>Static</m>: The database is built  <br />
    // <m>Growing</m>: The dat<br />
    // <m>Selected</m>: Only show numbers when the corresponding point is selected<br />
    // <m>Always</m>: Always show all the numbers
    
    CLASS_ATTR_DOUBLE(c,"datasetstep",0, t_neuralnet, dataset_step);
    CLASS_ATTR_STYLE_LABEL(c, "datasetstep", 0, "text", "Dataset Step Size");
    // @description Sets the ratio of the database representing the database growth (for Growing <m>datasetmode</m>) or
    // the dataset shift (for Windowing <m>datasetmode</m>). This attribute is ignored with Static <m>datasetmode</m>.

    CLASS_ATTR_DOUBLE(c,"datasetwin",0, t_neuralnet, dataset_win);
    CLASS_ATTR_STYLE_LABEL(c, "datasetwin", 0, "text", "Dataset Window Size");
    // @description Sets the size of the window for Windowing <m>datasetmode</m>, as a ratio on the whole training data.
    // Must be bigger or equal to <m>datasetstep</m> size.
    
    CLASS_STICKY_ATTR_CLEAR(c, "category");
    
    
    
    
    class_register(CLASS_BOX, c);
    neuralnet_class = c;
    
    dev_post("bach.neuralnet compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}


void send_done_llll(t_neuralnet *x)
{
    t_llll *done = llll_get();
    llll_appendsym(done, _sym_done, 0, WHITENULL_llll);
    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 3, done);
    llll_free(done);
}

void neuralnet_return(t_neuralnet *x, t_llll *ll)
{
    if (!ll) {
        object_error((t_object *) x, "Bad input file");
        return;
    }
    if (x->nn->setState(ll))
        object_error((t_object *)x, "Error in setting networks state - wrong syntax!");
    else
        send_done_llll(x);
    
    llll_free(ll);
    return;

}

void neuralnet_read(t_neuralnet *x, t_symbol *s)
{
    llll_read((t_object *) x, s, (read_fn) neuralnet_return);    
}


void neuralnet_write(t_neuralnet *x, t_symbol *s, long argc, t_atom *argv){
    t_llll *state_ll = x->nn->getState();
    t_symbol *filename = NULL;
    if ((argc >= 1) && (atom_gettype(argv) == A_SYM))
        filename = atom_getsym(argv);
    llll_writenative((t_object *) x, filename, state_ll);
}

void neuralnet_writetxt(t_neuralnet *x, t_symbol *s, long argc, t_atom *argv){
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc, argv, LLLL_PARSE_CLONE);
    t_llll *state_ll = x->nn->getState();
    llll_writetxt((t_object *) x, state_ll, arguments, BACH_DEFAULT_MAXDECIMALS, 0, "\t", -1, LLLL_T_NONE, LLLL_TE_SMART, LLLL_TB_SMART);
}





void neuralnet_waitbar_qelem_do(t_neuralnet *x)
{
    llllobj_outlet_float((t_object *) x, LLLL_OBJ_VANILLA, 2, x->nn->waitbar);
}


void neuralnet_verbose_qelem_do(t_neuralnet *x)
{
    t_llll *ll = llll_clone(x->nn->verbose_llll);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 3, ll);
    llll_free(ll);
}


t_max_err neuralnet_train_wrapped(t_neuralnet *x, t_llll *data, t_llll *res)
{
    char scramble = false;
    if (data->l_head && hatom_gettype(&data->l_head->l_hatom) == H_LONG){
        scramble = (hatom_getlong(&data->l_head->l_hatom) != 0);
        llll_behead(data);
    }
    
    dataReader d = dataReader();
    d.loadLlll(data, x->network_in, x->network_out, scramble);
    d.setCreationApproach(x->dataset_mode, x->dataset_step, x->dataset_win);
    d.setSplitPts(x->dataset_split[0], x->dataset_split[1]);
    
    //dataset
    dataSet* dset;        
    long num_datasets = d.nDataSets();
    for (long i=0; i < num_datasets; i++){
        dset = d.getDataSet();    
        x->nn->trainNetwork(dset->trainingSet, dset->generalizationSet, dset->validationSet);
    }
    return MAX_ERR_NONE;
}


void neuralnet_output(t_neuralnet *x, t_llll *solutions, t_max_err err)
{
    x->n_thread = NULL;
    bach_atomic_unlock(&x->n_inuse);

    // output training results 
    t_llll *output_data = x->nn->getAccuracyAndMSE(true, true, true);
    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 3, output_data);
    llll_free(output_data);
}




void neuralnet_appendtodictionary(t_neuralnet *x, t_dictionary *d)
{
    if (x->embed) {
        t_llll *state = x->nn->getState();
        llll_store_in_dictionary(state, d, "neuralnet_state", NULL);
        llll_free(state);
    }
}

void neuralnet_stop(t_neuralnet *x)
{
    x->nn->stopTraining();
}

void neuralnet_bang(t_neuralnet *x)
{
    neuralnet_anything(x, _sym_bang, 0, NULL);
}

void neuralnet_int(t_neuralnet *x, t_atom_long num){
    t_atom argv[1]; 
    atom_setlong(argv, num);
    neuralnet_anything(x, _llllobj_sym_list, 1, argv);
}

void neuralnet_float(t_neuralnet *x, double num){
    t_atom argv[1]; 
    atom_setfloat(argv, num);
    neuralnet_anything(x, _llllobj_sym_list, 1, argv);
}

void neuralnet_anything(t_neuralnet *x, t_symbol *msg, long ac, t_atom *av)
{
    long inlet = proxy_getinlet((t_object *) x);
    
    if (msg == _sym_clear) {
        llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), inlet);
        return;
    }
    
    if (inlet == 0 && msg == _sym_dump) {
        //dump state
        t_llll *ll = x->nn->getState();
        llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 1, ll);
        llll_free(ll);
        return;
    }

    if (inlet == 0 && msg == gensym("setstate")) {
        //set state
        t_llll *ll = llllobj_parse_llll((t_object *)x, LLLL_OBJ_VANILLA, NULL, ac, av, LLLL_PARSE_RETAIN);
        if (x->nn->setState(ll))
            object_error((t_object *)x, "Error in setting networks state - wrong syntax!");
        else
            send_done_llll(x);
        llll_free(ll);
        return;
    }

    if (msg != _sym_bang && msg != _sym_clear && msg != _sym_reset) {
        llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
    }

    if (inlet == 0) {
        t_llll *res;
        
        // feed net and obtain result
        t_llll *input_ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
        
        // copying data in double array
        double *input = (double *)bach_newptr((x->network_in) * sizeof(double));
        t_llllelem *elem;
        long i;
        for (i = 0, elem = input_ll->l_head; i < x->network_in; i++, elem = (elem ? elem->l_next : NULL))
            input[i] = (elem && is_hatom_number(&elem->l_hatom)) ? hatom_getdouble(&elem->l_hatom) : 0;
        
        if (bach_atomic_trylock(&x->n_inuse)) {
            object_error((t_object *) x, "Training is running, stop training before feeding network.");
            return;
        }

        x->nn->feedInput(input);
        res = x->nn->getOutput();
        
        bach_atomic_unlock(&x->n_inuse);
        
        llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, res);
        llll_free(res);
        bach_freeptr(input);
        
    } if (inlet == 1) {
        
        if (msg == _sym_reset) {
            if (ac && atom_gettype(av) == H_SYM && atom_getsym(av) == gensym("weights"))
                x->nn->resetWeights();
            else if (ac && atom_gettype(av) == H_SYM && atom_getsym(av) == gensym("neurons"))
                x->nn->resetNeurons();
            else if (ac && atom_gettype(av) == H_SYM && atom_getsym(av) == gensym("results"))
                x->nn->resetAccuracyAndMseResults();
            else
                x->nn->reset();
            return;
        }

        
        if (bach_atomic_trylock(&x->n_inuse)) {
            object_error((t_object *) x, "Already running");
            return;
        }

        // training
        t_llll *input_set = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 0);
        
        if (!x->parallel) {
            //load data reader
            dataReader d = dataReader();
            d.loadLlll(input_set, x->network_in, x->network_out, msg != _sym_bang && (!x->recurrent));
            d.setCreationApproach(x->dataset_mode, x->dataset_step, x->dataset_win);
            d.setSplitPts(x->dataset_split[0], x->dataset_split[1]);
            
            //dataset
            dataSet* dset;        
            long num_datasets = d.nDataSets();
            for (long i=0; i < num_datasets; i++){
                dset = d.getDataSet();    
                x->nn->trainNetwork(dset->trainingSet, dset->generalizationSet, dset->validationSet);
            }
            bach_atomic_unlock(&x->n_inuse);
        } else {
            // parallel threading: training happens in a new thread
            llll_prependlong(input_set, msg != _sym_bang && (!x->recurrent), 0, WHITENULL_llll);
            bach_thread_start((t_object *) x, LLLL_OBJ_VANILLA, input_set, 0, (thread_task_fn) neuralnet_train_wrapped, (thread_end_fn) neuralnet_output, &x->n_thread);
            return; // input_set is freed by bach_thread
        }
        
        // output training results 
        t_llll *output_data = x->nn->getAccuracyAndMSE(true, true, true);
        llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 3, output_data);
        
        llll_free(input_set);
    }
}


void neuralnet_assist(t_neuralnet *x, void *b, long m, long a, char *s)
{    
    if (m == ASSIST_INLET) { 
        if (a == 0)
            sprintf(s, "llll: Feed Input"); // @in 0 @type list/llll @digest The values of the input nodes, to be feeded to the network
        else
            sprintf(s, "llll: Training Data"); // @in 1 @type llll @digest The training data in llll form
                                                // @discussion The correct syntax is <b>((<m>input1</m> <m>input2</m>...) (<m>target1</m> <m>target2</m>...))</b>
                                                // for each training event.
    } else {
        char *type = NULL; 
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        if (a == 0)
            sprintf(s, "llll (%s): Output", type); // @out 0 @type llll @digest The output data for the incoming input data
        else if (a == 1)
            sprintf(s, "llll (%s): Dump Outlet", type); // @out 1 @type llll @digest Dump outlet for the state of the network
        else if (a == 2)
            sprintf(s, "float: Advancement"); // @out 2 @type float @digest Advancement during training 
        else                                  // @description The advancement is a floating point value between 0 (training starts) and 1 (training ends)
            sprintf(s, "llll (%s): Training Results", type); // @out 3 @type llll @digest Output training results when training has ended
                                                            // @description The output message is in the form 
                                                            // <b>(<m>TS_accuracy</m> <m>GS_accuracy</m> <m>VS_accuracy</m>) (<m>TS_mse</m> <m>GS_mse</m> <m>VS_mse</m>)</b>
                                                            // where TS is the training set, GS is the generalization set, VS is the validation set,
                                                            // and mse is the mean squared error.
    }
}

void neuralnet_inletinfo(t_neuralnet *x, void *b, long a, char *t)
{
    *t = 1;    // even the training inlet is somehow "hot" (is it?)
//    if (a)
//        *t = 1;
}


void neuralnet_free(t_neuralnet *x)
{    
    long i;
    
    if (x->nn && x->n_thread) {
        unsigned int rv;
        x->nn->stopTraining();
        systhread_join(x->n_thread, &rv);
        dev_post("thread exited with return value %u");
    }

    qelem_free_debug(x->n_waitbar_qelem);
    qelem_free_debug(x->n_verbose_qelem);

    for (i = 1; i > 0; i--)
        object_free_debug(x->n_proxy[i]);
    
    if (x->nn)
        delete x->nn;
    
    llllobj_obj_free((t_llllobj_object *) x);
}

t_neuralnet *neuralnet_new(t_symbol *s, short ac, t_atom *av)
{
    t_neuralnet *x = NULL;
    t_max_err err = MAX_ERR_NONE;
    
    long true_ac = attr_args_offset(ac, av);

    if ((x = (t_neuralnet *) object_alloc_debug(neuralnet_class))) {
        // @arg 0 @name recurrent @optional 1 @type symbol @digest Recurrent
        // @description If the first argument is the symbole "recurrent", the neural network will be instantiated as a RNN (recurrent neural network),
        // otherwise it will be a feed-forward neural network (default).

        // @arg 1 @name in @optional 0 @type int @digest Number of input nodes
        // @description Sets the number of nodes in the input layer of the neural network.

        // @arg 2 @name hidden @optional 0 @type list @digest Number of hidden nodes for each inner layer
        // @description Sets the number of nodes in each of the hidden layers of the neural network (the number of layers will match the number of integers)

        // @arg 3 @name out @optional 0 @type int @digest Number of output nodes
        // @description Sets the number of nodes in the output layer of the neural network.

        x->embed = 0;
        x->parallel = 0;
        x->recurrent = NEURALNET_DEFAULT_RECURRENT;
        x->dataset_mode = NEURALNET_DATASET_STATIC;
        x->dataset_split[0] = 0.6;
        x->dataset_split[1] = 0.8;
        x->dataset_step = 0.1;
        x->dataset_win = 0.2;
        
        if (true_ac && atom_gettype(av) == A_SYM) {
            if (atom_getsym(av) == gensym("recurrent"))
                x->recurrent = true;
            else
                x->recurrent = false;
            true_ac -= 1;
            av++;
        }
        
        x->n_waitbar_qelem = qelem_new_debug(x, (method) neuralnet_waitbar_qelem_do);
        x->n_verbose_qelem = qelem_new_debug(x, (method) neuralnet_verbose_qelem_do);

        if (true_ac < 3) {
            object_error((t_object *) x, "Missing arguments");
            dev_object_warn((t_object *) x, "--- nevermind if a blue line follows, it's allright");
            object_free_debug(x);
            return NULL;
        }

        x->network_in = MAX(1, atom_getlong(av));
        x->newtork_num_hidden = true_ac - 2;
        x->network_hidden = (long *)bach_newptr((true_ac - 2) * sizeof(long));
        for (long i = 1; i < true_ac - 1; i++)
             x->network_hidden[i-1] = MAX(1, atom_getlong(av + i));
        x->network_out = MAX(1, atom_getlong(av + true_ac - 1));
        
        x->batch_learning = NEURALNET_DEFAULT_BATCH_LEARNING;
        x->desired_accuracy = NEURALNET_DEFAULT_DESIRED_ACCURACY;
        x->max_epochs = NEURALNET_DEFAULT_MAX_EPOCHS;
        x->learning_rate = NEURALNET_DEFAULT_LEARNING_RATE;
        x->momentum = NEURALNET_DEFAULT_MOMENTUM;
        x->verbose = NEURALNET_DEFAULT_VERBOSE;
        x->classification_tolerance = NEURALNET_DEFAULT_CLASSIFICATION_TOLERANCE;
        x->bptt_num_steps = NEURALNET_DEFAULT_NUM_BPTT_STEPS;

        x->nn = new neuralNetwork((t_object *)x, x->n_thread, x->n_waitbar_qelem, x->n_verbose_qelem, x->newtork_num_hidden, x->network_in, x->network_hidden, x->network_out, x->recurrent);
        
        x->nn->setVerbose(x->verbose);
        x->nn->setLearningParameters(x->learning_rate, x->momentum);
        x->nn->setDesiredAccuracy(x->desired_accuracy);
        x->nn->setMaxEpochs(x->max_epochs);
        x->nn->setClassificationTolerance(x->classification_tolerance);
        x->nn->setNumBpttSteps(x->bptt_num_steps);
        
        attr_args_process(x, ac, av);
        llllobj_obj_setup((t_llllobj_object *) x, 2, "4f44");

        long i;
        for (i = 1; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
        
        
        t_dictionary *d = (t_dictionary *)gensym("#D")->s_thing;
        if (d) {
            t_llll *defll = llll_retrieve_from_dictionary(d, "neuralnet_state");
            if (defll) {
                llll_retain(defll);
//                dev_llll_print(defll, NULL, 1, 2, NULL);
                x->nn->setState(defll);
                llll_free(defll);
                x->embed = 1;
            }
        }
        
    } else 
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x);
    return NULL;
}

