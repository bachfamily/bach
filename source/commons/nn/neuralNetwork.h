#ifndef NNETWORK
#define NNETWORK


//standard libraries
#include <math.h>
#include <ctime>
#include <vector>

//custom includes
#include "dataEntry.h"
#include "llllobj.h"

using namespace std;

// Constant Maxima
#define NEURALNET_MAX_BPTT_STEPS 50 // maximum number of steps for backpropagation through time

// Constant Defaults
#define NEURALNET_DEFAULT_CLASSIFICATION_TOLERANCE 0.1
#define NEURALNET_DEFAULT_LEARNING_RATE 0.001
#define NEURALNET_DEFAULT_MOMENTUM 0.9
#define NEURALNET_DEFAULT_MAX_EPOCHS 1500
#define NEURALNET_DEFAULT_DESIRED_ACCURACY 0. // i.e.: inactive  
#define NEURALNET_DEFAULT_DESIRED_MSE 0. //i.e.: inactive
#define NEURALNET_DEFAULT_BATCH_LEARNING false  
#define NEURALNET_DEFAULT_RECURRENT false 

#ifdef CONFIGURATION_Development
#define NEURALNET_DEFAULT_VERBOSE true 
#else
#define NEURALNET_DEFAULT_VERBOSE false
#endif


typedef enum _neuralnet_activation_functions
{
	NEURALNET_ACTIVATION_FUNCTION_LOGISTICSIGMOID = 0,
	NEURALNET_ACTIVATION_FUNCTION_TANH = 1,
	NEURALNET_ACTIVATION_FUNCTION_STEP = 2,
	NEURALNET_ACTIVATION_FUNCTION_SOFTMAX = 3,
} e_neuralnet_activation_functions;


#define NEURALNET_DEFAULT_ACTIVATION_FUNCTION	NEURALNET_ACTIVATION_FUNCTION_LOGISTICSIGMOID
#define NEURALNET_DEFAULT_NUM_BPTT_STEPS 2 // 2 = no real backpropagation through time by default (just propagating 2 step: t and t-1)

class neuralNetwork
{

public:

	t_object	*object; // Max associated object
	t_systhread thread;
	t_qelem		waitbar_qelem;
	t_qelem		verbose_qelem;
	double		waitbar; // waitbar result for training (0. to 1.)
	t_llll		*verbose_llll;
	
private:
	
	//number of neurons
	long nHiddenLayers;
	long nInput;
	long *nHidden;
	long nOutput;
	
	// net type
	char	recurrent;		// to be set at initialization
	
	//learning parameters
	double learningRate;					// adjusts the step size of the weight update	
	double momentum;						// improves performance of stochastic learning (don't use for batch)

	// activation function
	char activationFunction;
	
	//neurons
	double* inputNeurons;
	double** hiddenNeurons;
	double* outputNeurons;

	// only for recurrent networks:
	double** hiddenNeurons_copy;			// local copy of hidden neurons
	double*** hiddenNeurons_history;		// History of hidden Neurons, for BPTT
	double** inputNeurons_history;			// History of input Neurons, for BPTT
	double ***hiddenErrorGradients_bptt;	
	

	//weights
	double** wInputHidden;
	double*** wHiddenNext;
	double** wHiddenOutput;

	double*** wHiddenSelf;	// only for recurrent networks

	
	//epoch counter
	long epoch;
	long maxEpochs;
	
	//classification parameters to end training
	double classificationTolerance;
	double desiredAccuracy;
	double desiredMSE;

	//change to weights
	double** deltaInputHidden;
	double** deltaHiddenOutput;
	double*** deltaHiddenNext;
	
	double*** deltaHiddenSelf; // only for recurrent networks

	//error gradients
	double** hiddenErrorGradients;
	double* outputErrorGradients;

	//accuracy stats per epoch
	double trainingSetAccuracy;
	double validationSetAccuracy;
	double generalizationSetAccuracy;
	double trainingSetMSE;
	double validationSetMSE;
	double generalizationSetMSE;

	//batch learning flag
	bool useBatch;
	
	//backpropagation through time (only for recurrent networks)
	long bptt_num_steps;
		
	// abort training
	char stop;

	// verbose
	char verbose;
	
//public methods
//----------------------------------------------------------------------------------------------------------------
public:

	//constructor
	neuralNetwork(t_object *ob, t_systhread th, t_qelem progress_waitbar_qelem, t_qelem verbose_out_qelem, long hiddenlayers, long in, long *hidden, long out, char rec) : object(NULL), nInput(in), nHidden(hidden), nOutput(out), recurrent(rec), epoch(0), trainingSetAccuracy(0), validationSetAccuracy(0), generalizationSetAccuracy(0), trainingSetMSE(0), validationSetMSE(0), generalizationSetMSE(0)
	{				
		object = ob;
		thread = th;
		waitbar_qelem = progress_waitbar_qelem;
		verbose_qelem = verbose_out_qelem;
		nHiddenLayers = hiddenlayers;
		recurrent = rec;
		
		verbose_llll = llll_get();
		
		//create neuron lists
		//--------------------------------------------------------------------------------------------------------
		inputNeurons = new double[in + 1];
		for (long i=0; i < in; i++) inputNeurons[i] = 0;
		inputNeurons[in] = -1; // bias neuron
		
		if (recurrent) {
			inputNeurons_history = new(double*[NEURALNET_MAX_BPTT_STEPS]);
			for (long j=0; j < NEURALNET_MAX_BPTT_STEPS; j++) {
				inputNeurons_history[j] = new double[in + 1];
				for (long i=0; i < in; i++) inputNeurons_history[j][i] = 0;
				inputNeurons_history[j][in] = -1; // bias neuron
			}
		}
		
		hiddenNeurons = new double*[hiddenlayers];
		for (long j=0; j < hiddenlayers; j++) {
			hiddenNeurons[j] = new double[hidden[j] + 1];
			for (long i=0; i < hidden[j]; i++) hiddenNeurons[j][i] = 0;
			hiddenNeurons[j][hidden[j]] = -1;  // bias neuron
		}

		if (recurrent) {
			hiddenNeurons_copy = new double*[hiddenlayers];
			for (long j=0; j < hiddenlayers; j++) {
				hiddenNeurons_copy[j] = new double[hidden[j] + 1] ;
				for (long i=0; i < hidden[j]; i++) hiddenNeurons_copy[j][i] = 0;
				hiddenNeurons_copy[j][hidden[j]] = -1;  // bias neuron
			}
			
			hiddenNeurons_history = new double**[NEURALNET_MAX_BPTT_STEPS];
			for (long k = 0; k < NEURALNET_MAX_BPTT_STEPS; k++) {
				hiddenNeurons_history[k] = new double*[hiddenlayers];
				for (long j=0; j < hiddenlayers; j++) {
					hiddenNeurons_history[k][j] = new double[hidden[j] + 1];
					for (long i=0; i < hidden[j]; i++) hiddenNeurons_history[k][j][i] = 0;
					hiddenNeurons_history[k][j][hidden[j]] = -1;  // bias neuron
				}
			}
			
			inputNeurons_history = new double*[NEURALNET_MAX_BPTT_STEPS];
			for (long k = 0; k < NEURALNET_MAX_BPTT_STEPS; k++) 
				inputNeurons_history[k] = new double[in + 1];
		}
		
		
		outputNeurons = new double[out] ;
		for ( long i=0; i < out; i++ ) outputNeurons[i] = 0;
		
		//create weight lists (include bias neuron weights)
		//--------------------------------------------------------------------------------------------------------
		wInputHidden = new double*[in + 1];
		for (long i=0; i <= in; i++) {
			wInputHidden[i] = new double[hidden[0]];
			for ( long j=0; j < hidden[0]; j++ ) wInputHidden[i][j] = 0;		
		}
		
		wHiddenOutput = new double*[hidden[nHiddenLayers - 1] + 1];
		for (long i=0; i <= hidden[nHiddenLayers - 1]; i++) {
			wHiddenOutput[i] = new double[out];
			for ( long j=0; j < out; j++ ) wHiddenOutput[i][j] = 0;		
		}
		
		if (nHiddenLayers > 1) {
			wHiddenNext = new double**[nHiddenLayers - 1];
			for (long k=0; k<nHiddenLayers - 1; k++) {
				wHiddenNext[k] = new double*[hidden[k] + 1];
				for (long i=0; i <= hidden[k]; i++) {
					wHiddenNext[k][i] = new double[hidden[k+1] + 1];
					for (long j=0; j <= hidden[k+1]; j++) wHiddenNext[k][i][j] = 0;		
				}
			}
		}
		
		if (recurrent) {
			wHiddenSelf = new double**[nHiddenLayers];
			for (long k=0; k<nHiddenLayers; k++) {
				wHiddenSelf[k] = new double*[hidden[k] + 1];
				for (long i=0; i <= hidden[k]; i++) {
					wHiddenSelf[k][i] = new double[hidden[k] + 1];
					for ( long j=0; j <= hidden[k]; j++ ) wHiddenSelf[k][i][j] = 0;		
				}
			}
		}
		
		//create delta lists
		//--------------------------------------------------------------------------------------------------------
		deltaInputHidden = new double*[in + 1];
		for (long i=0; i <= in; i++) {
			deltaInputHidden[i] = new double[hidden[0]];
			for (long j=0; j < hidden[0]; j++) deltaInputHidden[i][j] = 0;		
		}
		
		deltaHiddenOutput = new double*[hidden[nHiddenLayers - 1] + 1];
		for ( long i=0; i <= hidden[nHiddenLayers - 1]; i++ ) 
		{
			deltaHiddenOutput[i] = new double[out];
			for ( long j=0; j < out; j++ ) deltaHiddenOutput[i][j] = 0;		
		}
		
		if (nHiddenLayers > 1) {
			deltaHiddenNext = new double**[nHiddenLayers - 1];
			for (long k = 0; k < nHiddenLayers - 1; k++) {
				deltaHiddenNext[k] = new double*[hidden[k] + 1];
				for (long i=0; i <= hidden[k]; i++) {
					deltaHiddenNext[k][i] = new double[hidden[k+1] + 1];	 // should just need hidden[k+1]
					for ( long j=0; j <= hidden[k+1]; j++ ) deltaHiddenNext[k][i][j] = 0;		
				}
			}
		}
		
		if (recurrent) {
			deltaHiddenSelf = new double**[nHiddenLayers];
			for (long k = 0; k < nHiddenLayers; k++) {
				deltaHiddenSelf[k] = new double*[hidden[k] + 1];
				for (long i=0; i <= hidden[k]; i++) {
					deltaHiddenSelf[k][i] = new double[hidden[k] + 1];
					for (long j=0; j <= hidden[k]; j++) deltaHiddenSelf[k][i][j] = 0;		
				}
			}
		}
		
		//create error gradient storage
		//--------------------------------------------------------------------------------------------------------
		hiddenErrorGradients = new double*[nHiddenLayers];
		for (long k = 0; k < nHiddenLayers; k++) {
			hiddenErrorGradients[k] = new double[hidden[k] + 1];
			for (long i=0; i <= hidden[k]; i++) hiddenErrorGradients[k][i] = 0;
		}
		
		outputErrorGradients = new double[out + 1];
		for (long i=0; i <= out; i++) outputErrorGradients[i] = 0;
		
		if (recurrent) {
			hiddenErrorGradients_bptt = new double**[NEURALNET_MAX_BPTT_STEPS];
			for (long k = 0; k < NEURALNET_MAX_BPTT_STEPS; k++) {
				hiddenErrorGradients_bptt[k] = new double*[nHiddenLayers];
				for (long j=0; j < nHiddenLayers; j++) {
					hiddenErrorGradients_bptt[k][j] = new double[hidden[j] + 1];
					for (long i=0; i <= hidden[j]; i++) hiddenErrorGradients_bptt[k][j][i] = 0;
				}
			}
		}
		
		//initialize weights
		initializeWeights();
		
		//default learning parameters
		learningRate = NEURALNET_DEFAULT_LEARNING_RATE; 
		momentum = NEURALNET_DEFAULT_MOMENTUM; 
		
		//use stochastic learning by default
		useBatch = NEURALNET_DEFAULT_BATCH_LEARNING;
		
		//stopping conditions
		maxEpochs = NEURALNET_DEFAULT_MAX_EPOCHS;
		desiredAccuracy = NEURALNET_DEFAULT_DESIRED_ACCURACY;	
		desiredMSE = NEURALNET_DEFAULT_DESIRED_MSE;	
		verbose = NEURALNET_DEFAULT_VERBOSE;
		activationFunction = NEURALNET_DEFAULT_ACTIVATION_FUNCTION;
		classificationTolerance = NEURALNET_DEFAULT_CLASSIFICATION_TOLERANCE;
		bptt_num_steps = NEURALNET_DEFAULT_NUM_BPTT_STEPS;
		
		
		stop = 0;
	}

	//destructor
	~neuralNetwork()
	{
		//delete neurons
		delete[] inputNeurons;
		for (long i=0; i < nHiddenLayers; i++) delete[] hiddenNeurons[i];
		delete[] hiddenNeurons;
		delete[] outputNeurons;

		if (recurrent) {
			delete[] hiddenNeurons_copy;
			
			for (long k=0; k < NEURALNET_MAX_BPTT_STEPS; k++) {
				for (long i=0; i < nHiddenLayers; i++) delete[] hiddenNeurons_history[k][i];
				delete[] hiddenNeurons_history[k];
			}
			delete[] hiddenNeurons_history;
			
			
			for (long k=0; k < NEURALNET_MAX_BPTT_STEPS; k++) {
				delete[] inputNeurons_history[k];
			}
			delete[] inputNeurons_history;
		}
		
		//delete weight storage
		for (long i=0; i <= nInput; i++) delete[] wInputHidden[i];
		delete[] wInputHidden;
		
		for (long j=0; j <= nHidden[nHiddenLayers - 1]; j++) delete[] wHiddenOutput[j];
		delete[] wHiddenOutput;

		if (nHiddenLayers > 1) {
			for (long k=0; k < nHiddenLayers - 1; k++) {
				for (long j=0; j <= nHidden[k]; j++) delete[] wHiddenNext[k][j];
				delete[] wHiddenNext[k];
			}
			delete[] wHiddenNext;
		}
		
		if (recurrent) {
			for (long k=0; k < nHiddenLayers; k++) {
				for (long j=0; j <= nHidden[k]; j++) delete[] wHiddenSelf[k][j];
				delete[] wHiddenSelf[k];
			}
			delete[] wHiddenSelf;
		}

		
		//delete delta storage
		for (long i=0; i <= nInput; i++) delete[] deltaInputHidden[i];
		delete[] deltaInputHidden;
		
		for (long j=0; j <= nHidden[nHiddenLayers - 1]; j++) delete[] deltaHiddenOutput[j];
		delete[] deltaHiddenOutput;
		
		if (nHiddenLayers > 1) {
			for (long k=0; k < nHiddenLayers - 1; k++) {
				for (long j=0; j <= nHidden[k]; j++) delete[] deltaHiddenNext[k][j];
				delete[] deltaHiddenNext[k];
			}
			delete[] deltaHiddenNext;
		}
		
		if (recurrent) {
			for (long k=0; k < nHiddenLayers; k++) {
				for (long j=0; j <= nHidden[k]; j++) delete[] deltaHiddenSelf[k][j];
				delete[] deltaHiddenSelf[k];
			}
			delete[] deltaHiddenSelf;
		}
		
		
		//delete error gradients
		for (long k=0; k < nHiddenLayers; k++) delete[] hiddenErrorGradients[k];
		delete[] hiddenErrorGradients;
		delete[] outputErrorGradients;
		
		if (recurrent) {
			for (long k=0; k < NEURALNET_MAX_BPTT_STEPS; k++) {
				for (long i=0; i < nHiddenLayers; i++) delete[] hiddenErrorGradients_bptt[k][i];
				delete[] hiddenErrorGradients_bptt[k];
			}
			delete[] hiddenErrorGradients_bptt;
		}
		
		llll_free(verbose_llll);
	}
	

	//abort training
	void stopTraining();
	
	
	// output float advancement
	void outputAdvancement();
	
	
	// output training data during training
	void outputVerboseTrainingData(long epoch);


	//set learning parameters
	void setLearningParameters(double lr, double m);
	

	//set max epoch
	void setMaxEpochs(long max);
	

	// set number of backpropagation through time steps (for recurrent nets)
	void setNumBpttSteps(long s);

	
	//set classification tolerance 
	void setClassificationTolerance(double d);

	
	//set desired accuracy 
	void setDesiredAccuracy(float d);


	//set desired mean square error
	void setDesiredMSE(float d);


	//enable batch learning
	void useBatchLearning();
	

	//enable stochastic learning
	void useStochasticLearning();
	
	
	// set verbose
	void setVerbose(char v);

	
	// set activation function
	void setActivationFunction(char v);
	
	
	//enable logging of training results
	void enableLogging(const char* filename, long resolution = 1);
	

	//resets the weights
	void resetWeights();
	
	//resets the activation values for neurons
	void resetNeurons();
	
	//resets the current accuracy and MSE stored values
	void resetAccuracyAndMseResults();
	
	// reset all the neural network
	void reset();

	//feed data through network
	double* feedInput( double* inputs);
	

	// get output in llll form
	t_llll *getOutput();
	
	//train the network
	void trainNetwork( vector<dataEntry*> trainingSet, vector<dataEntry*> generalizationSet, vector<dataEntry*> validationSet );
	

	// get current accuracy and MSE in llll form
	t_llll* getAccuracyAndMSE(char forTS, char forGS, char forVS);

	
	// get current network state (nodes and weights)
	t_llll *getState();

	
	// set current network state (nodes and weights), return 1 if error 
	long setState(t_llll *state);

//private methods
//----------------------------------------------------------------------------------------------------------------
private:

	//initialize weights and weight changes
	void initializeWeights();
	

	//run a single training epoch
	void runTrainingEpoch( vector<dataEntry*> trainingSet );
	
	
	void copyHiddenNeurons();

	
	//feed input forward
	void feedForward(double *inputs);
	

	//modify weights according to ouput
	void backpropagate(double* desiredValues);
	
	
	//update weights
	void updateWeights();
	
	
	//update history (for BPTT only)
	void updateHistory();


	//activation function
	inline double applyActivationFunction(double x);
	

	//get error gradient for ouput layer
	inline double getOutputErrorGradient(double desiredValue, double outputValue);
	

	//get error gradient for hidden layer
	double getHiddenErrorGradient(long hidden_layer_idx, long j);


	//get error gradient for hidden layers for BPTT
	double getHiddenErrorGradient_bptt(long t, long hidden_layer_idx, long j);

	//round up value to get a boolean result
	long getRoundedOutputValue(double x);
	
	
	//feed forward set of patterns and return error
	double getSetAccuracy(vector<dataEntry*> set);
	

	//feed forward set of patterns and return MSE
	double getSetMSE (vector<dataEntry*> set);
	
};

#endif
