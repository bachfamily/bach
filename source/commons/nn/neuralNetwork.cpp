#include "neuralNetwork.h"
#include "llll_commons_ext.h"


//set learning parameters
void neuralNetwork::stopTraining()
{
	stop = 1;
}


//set learning parameters
void neuralNetwork::setLearningParameters(double lr, double m)
{
	learningRate = lr;		
	momentum = m;
}

//set num bptt steps
void neuralNetwork::setNumBpttSteps(long s)
{
	bptt_num_steps = s;		
}


//set max epoch
void neuralNetwork::setMaxEpochs(long max)
{
	maxEpochs = max;
}

//set desired accuracy 
void neuralNetwork::setClassificationTolerance(double d)
{
	classificationTolerance = d;
}

//set desired accuracy 
void neuralNetwork::setDesiredAccuracy(float d)
{
	desiredAccuracy = d;
}


//set desired mean square error 
void neuralNetwork::setDesiredMSE(float d)
{
	desiredMSE = d;
}


//enable batch learning
void neuralNetwork::useBatchLearning()
{
	useBatch = true;
}


//enable stochastic learning
void neuralNetwork::useStochasticLearning()
{
	useBatch = false;
}


//set verbose
void neuralNetwork::setVerbose(char v)
{
	verbose = v;
}


//set activation function
void neuralNetwork::setActivationFunction(char v)
{
	activationFunction = v;
}

//enable logging of training results
void neuralNetwork::enableLogging(const char* filename, long resolution)
{

}


//resets the accuracy and mse results
void neuralNetwork::resetAccuracyAndMseResults()
{
	trainingSetAccuracy = 0;
	generalizationSetAccuracy = 0;
	validationSetAccuracy = 0;
	
	trainingSetMSE = desiredMSE + 1;
	validationSetMSE = desiredMSE + 1;
	generalizationSetMSE = desiredMSE + 1;
}

//resets the weights
void neuralNetwork::resetWeights()
{
	trainingSetAccuracy = 0;
	generalizationSetAccuracy = 0;
	validationSetAccuracy = 0;
	
	trainingSetMSE = desiredMSE + 1;
	validationSetMSE = desiredMSE + 1;
	generalizationSetMSE = desiredMSE + 1;
	
	//reinitialize weights
	initializeWeights();		
}


//resets the neural network
void neuralNetwork::resetNeurons()
{
	for (long i=0; i < nInput; i++) inputNeurons[i] = 0;
	inputNeurons[nInput] = -1; // bias neuron
	
	if (recurrent) {
		for (long j=0; j < NEURALNET_MAX_BPTT_STEPS; j++) {
			for (long i=0; i < nInput; i++) inputNeurons_history[j][i] = 0;
			inputNeurons_history[j][nInput] = -1; // bias neuron
		}
	}

	for (long i=0; i < nOutput; i++) outputNeurons[i] = 0;

	for (long k=0; k < nHiddenLayers; k++) {
		for (long i=0; i < nHidden[k]; i++) {
			hiddenNeurons[k][i] = 0;
			if (recurrent) {
				hiddenNeurons_copy[k][i] = 0;
				for (long j=0; j < NEURALNET_MAX_BPTT_STEPS; j++)
					hiddenNeurons_history[j][k][i] = 0;
			}
		}
		hiddenNeurons[k][nHidden[k]] = -1;  // bias neuron
		if (recurrent) {
			hiddenNeurons_copy[k][nHidden[k]] = -1;
			for (long j=0; j < NEURALNET_MAX_BPTT_STEPS; j++)
				hiddenNeurons_history[j][k][nHidden[k]] = 0;
		}
	}
}

void neuralNetwork::reset()
{
	resetNeurons();
	resetWeights();
	resetAccuracyAndMseResults();
}

//feed data through network
double* neuralNetwork::feedInput( double* inputs)
{
	//feed data into the network
	feedForward(inputs);
	
	//return results
	return outputNeurons;
}

t_llll *neuralNetwork::getOutput()
{
	return double_array_to_llll(outputNeurons, nOutput);
}


void neuralNetwork::outputAdvancement()
{
	if (!thread)
		llllobj_outlet_float(object, LLLL_OBJ_VANILLA, 2, waitbar);
	else
		qelem_set(waitbar_qelem);
}

void neuralNetwork::outputVerboseTrainingData(long epoch)
{
	llll_free(verbose_llll);
	verbose_llll = getAccuracyAndMSE(true, true, false);
	llll_prependlong(verbose_llll, epoch + 1, 0, WHITENULL_llll);
	llll_prependsym(verbose_llll, gensym("verbose"), 0, WHITENULL_llll);
	
	if (!thread) {
		t_llll *ll = llll_clone(verbose_llll);
		llllobj_outlet_llll(object, LLLL_OBJ_VANILLA, 3, ll);
		llll_free(ll);
	} else
		qelem_set(verbose_qelem);
}

//train the network
void neuralNetwork::trainNetwork( vector<dataEntry*> trainingSet, vector<dataEntry*> generalizationSet, vector<dataEntry*> validationSet )
{
	if (verbose == 1) 
		object_post(object, "TRANING STARTING - LearningRate: %.3f, Momentum: %.3f, MaxEpochs: %d", learningRate, momentum, maxEpochs);
	
	//reset epoch counter
	epoch = 0;
	waitbar = 0;
	outputAdvancement();
	
	//train network using training dataset for training + generalization dataset for testing
	//--------------------------------------------------------------------------------------------------------
	while (epoch < maxEpochs) {			
		
		if (stop) { // aborted by user
			stop = 0;
			break;
		}
			
		// desired accuracy reached
		if ((desiredAccuracy > 0.) && (trainingSetAccuracy < desiredAccuracy || generalizationSetAccuracy < desiredAccuracy))
			break;

		// desired MSE reached
		if ((desiredMSE > 0.) && (trainingSetMSE < desiredMSE || generalizationSetMSE < desiredMSE))
			break;
		
		//use training set to train network
		runTrainingEpoch(trainingSet);
		
		//get generalization set accuracy and MSE
		generalizationSetAccuracy = getSetAccuracy( generalizationSet );
		generalizationSetMSE = getSetMSE( generalizationSet );
		
		if (maxEpochs < 1000 || ((maxEpochs < 10000) && (epoch % 10 == 0)) || ((maxEpochs < 100000) && (epoch % 100 == 0))
			|| ((maxEpochs < 1000000) && (epoch % 1000 == 0)) || ((maxEpochs < 10000000) && (epoch % 10000 == 0))) {
			
			if (verbose == 1)
				object_post(object, "Epoch %d - Accuracy TS %.3f, GS %.3f - MeanSquaredError TS %.3f, GS %.3f", epoch + 1, trainingSetAccuracy, generalizationSetAccuracy, trainingSetMSE, generalizationSetMSE);
			else if (verbose == 2)
				outputVerboseTrainingData(epoch);
			
			// update waitbar and output advancement
			waitbar = ((double)epoch)/(maxEpochs - 1);
			outputAdvancement();
		}
		
		//once training set is complete increment epoch
		epoch++;
		
	}
	
	//get validation set accuracy and MSE
	validationSetAccuracy = getSetAccuracy(validationSet);
	validationSetMSE = getSetMSE(validationSet);

	// output advancement
	waitbar = ((double)epoch)/(maxEpochs - 1);
	outputAdvancement();

	if (verbose == 1) {
		//log end
		object_post(object, "TRAINING ENDED - %d epochs", epoch);
		object_post(object, "- Accuracy TS %.3f, GS %.3f, VS %.3f", trainingSetAccuracy, generalizationSetAccuracy, validationSetAccuracy);
		object_post(object, "- MeanSquaredError TS %.3f, GS %.3f, VS %.3f", trainingSetMSE, generalizationSetMSE, validationSetMSE);
	}
}


//initialize weights and weight changes
void neuralNetwork::initializeWeights()
{
	//init random number generator
	srand( (unsigned int) time(0) );
	
	//set weights between input and hidden to a random value between -0.5 and 0.5
	//--------------------------------------------------------------------------------------------------------
	for(long i = 0; i <= nInput; i++)
	{		
		for(long j = 0; j < nHidden[0]; j++) 
		{
			//set weights to random values
			wInputHidden[i][j] =  ((double)rand() / (double)RAND_MAX) - 0.5;
			
			//create blank delta
			deltaInputHidden[i][j] = 0;
		}
	}
	
	//set weights between hidden and output to a random value between -0.5 and 0.5
	//--------------------------------------------------------------------------------------------------------
	for(long i = 0; i <= nHidden[nHiddenLayers - 1]; i++)
	{		
		for(long j = 0; j < nOutput; j++) 
		{
			//set weights to random values
			wHiddenOutput[i][j] =  ((double)rand() / (double)RAND_MAX) - 0.5;
			
			//create blank delta
			deltaHiddenOutput[i][j] = 0;
		}
	}
	
	// set weights between internal hidden layers
	for (long k = 0; k < nHiddenLayers - 1; k++) {
		for(long i = 0; i <= nHidden[k]; i++) {
			for(long j = 0; j < nHidden[k+1]; j++) {
				//set weights to random values
				wHiddenNext[k][i][j] =  ((double)rand() / (double)RAND_MAX) - 0.5;
				
				//create blank delta
				deltaHiddenNext[k][i][j] = 0;
			}
		}
	}
	
	// set recurrent weights
	if (recurrent) {
		for (long k = 0; k < nHiddenLayers; k++) {
			for(long i = 0; i <= nHidden[k]; i++) {
				for(long j = 0; j < nHidden[k]; j++) {
					//set weights to random values
					wHiddenSelf[k][i][j] =  ((double)rand() / (double)RAND_MAX) - 0.5;
					
					//create blank delta
					deltaHiddenSelf[k][i][j] = 0;
				}
			}
		}
	}
}

//run a single training epoch
void neuralNetwork::runTrainingEpoch( vector<dataEntry*> trainingSet )
{
	//incorrect patterns
	double incorrectPatterns = 0;
	double mse = 0;
	long trainingSetSize = (long) trainingSet.size();
	long tp;
	
	//for every training pattern
	for (tp = 0; tp < trainingSetSize; tp++) {
		
		//feed inputs through network and backpropagate errors
		feedForward(trainingSet[tp]->pattern);
		
		backpropagate(trainingSet[tp]->target);
		
		//pattern correct flag
		bool patternCorrect = true;
		
		//check all outputs from neural network against desired values
		for (long k = 0; k < nOutput; k++) {					
			//pattern incorrect if desired and output differ
			if (fabs(outputNeurons[k] - trainingSet[tp]->target[k]) > classificationTolerance) patternCorrect = false;
			
			//calculate MSE
			mse += pow((outputNeurons[k] - trainingSet[tp]->target[k]), 2);
		}
		
		//if pattern is incorrect add to incorrect count
		if (!patternCorrect) incorrectPatterns++;	
		
	}//end for
	
	//if using batch learning - update the weights
	if (useBatch) 
		updateWeights();
	
	//update training accuracy and MSE
	trainingSetAccuracy = 1. - ((incorrectPatterns * 1.)/trainingSet.size());
	trainingSetMSE = mse / ( nOutput * trainingSet.size() );
}


void neuralNetwork::copyHiddenNeurons()
{
	long k, i;
	for (k = 0; k < nHiddenLayers; k++)
		for (i = 0; i <= nHidden[k]; i++)
			hiddenNeurons_copy[k][i] = hiddenNeurons[k][i];
}

//feed input forward
void neuralNetwork::feedForward( double *inputs )
{
	//set input neurons to input values
	for(long i = 0; i < nInput; i++) 
		inputNeurons[i] = inputs[i];

	
	if (recurrent) copyHiddenNeurons();
	
	//Calculate Hidden Layer values - include bias neuron
	for (long k=0; k < nHiddenLayers; k++) {
		for (long j=0; j < nHidden[k]; j++) {
			//clear value
			hiddenNeurons[k][j] = 0;				
			
			//get weighted sum of inputs and bias neuron
			if (k == 0)
				for (long i=0; i <= nInput; i++) hiddenNeurons[0][j] += inputNeurons[i] * wInputHidden[i][j];
			else
				for (long i=0; i <= nHidden[k-1]; i++) hiddenNeurons[k][j] += hiddenNeurons[k-1][i] * wHiddenNext[k-1][i][j];
			
			if (recurrent) 
				for (long i=0; i <= nHidden[k]; i++) hiddenNeurons[k][j] += hiddenNeurons_copy[k][i] * wHiddenSelf[k][i][j];
			
			//set to result of activation function
			hiddenNeurons[k][j] = applyActivationFunction(hiddenNeurons[k][j]);	
		}
	}
	
	//Calculating Output Layer values - include bias neuron
	for(long k=0; k < nOutput; k++){
		//clear value
		outputNeurons[k] = 0;				
		
		//get weighted sum of inputs and bias neuron
		for(long j=0; j <= nHidden[nHiddenLayers - 1]; j++) outputNeurons[k] += hiddenNeurons[nHiddenLayers - 1][j] * wHiddenOutput[j][k];
		
		//set to result of sigmoid
		outputNeurons[k] = applyActivationFunction(outputNeurons[k]);
	}
	
	if (recurrent && bptt_num_steps > 2)
		updateHistory();
}

//modify weights according to ouput
void neuralNetwork::backpropagate(double* desiredValues)
{		
	//modify deltas between hidden and output layers
	for (long k = 0; k < nOutput; k++)	{
		//get error gradient for every output node
		outputErrorGradients[k] = getOutputErrorGradient(desiredValues[k], outputNeurons[k]);
		
		//for all nodes in hidden layer and bias neuron
		for (long j = 0; j <= nHidden[nHiddenLayers - 1]; j++) {				
			//calculate change in weight
			if (!useBatch) 
				deltaHiddenOutput[j][k] = learningRate * hiddenNeurons[nHiddenLayers - 1][j] * outputErrorGradients[k] + momentum * deltaHiddenOutput[j][k];
			else 
				deltaHiddenOutput[j][k] += learningRate * hiddenNeurons[nHiddenLayers - 1][j] * outputErrorGradients[k];
		}
	}
	
	//modify deltas between hidden layers and previous one
	for (long k = nHiddenLayers - 1; k >= 0; k--) {
		
		for (long j = 0; j < nHidden[k]; j++) //get error gradient for every hidden node
			hiddenErrorGradients[k][j] = getHiddenErrorGradient(k, j);
		
		if (recurrent) { // setting t = 0 for hidden error gradients
			for (long j = 0; j < nHidden[k]; j++)
				hiddenErrorGradients_bptt[0][k][j] = hiddenErrorGradients[k][j];
		}

		if (k > 0) {
			for (long j = 0; j < nHidden[k]; j++) {
				for (long i = 0; i <= nHidden[k-1]; i++) { //for all nodes in input layer and bias neuron
					//calculate change in weight 
					if (!useBatch) 
						deltaHiddenNext[k-1][i][j] = learningRate * hiddenNeurons[k-1][i] * hiddenErrorGradients[k][j] + momentum * deltaHiddenNext[k-1][i][j];
					else 
						deltaHiddenNext[k-1][i][j] += learningRate * hiddenNeurons[k-1][i] * hiddenErrorGradients[k][j]; 
				}
			}
		}

		if (recurrent) {
			for (long j = 0; j < nHidden[k]; j++) {
				for (long i = 0; i < nHidden[k]; i++) { //for all nodes in input layer but NOT bias neuron
					//calculate change in weight 
					if (!useBatch)
						deltaHiddenSelf[k][i][j] = learningRate * hiddenNeurons_copy[k][i] * hiddenErrorGradients[k][j] + momentum * deltaHiddenSelf[k][i][j];
					else 
						deltaHiddenSelf[k][i][j] += learningRate * hiddenNeurons_copy[k][i] * hiddenErrorGradients[k][j]; 
						// hiddenNeurons_copy has been copied before feedforward, hence it refers to the previous state (t-1) of the neurons
						// one might/should replace hiddenNeurons_copy with hiddenNeurson_history[1], which in turns should be updated
						// always, and not only when bptt_num_steps > 2
				}
			}
		}
	}
	
	
	//modify deltas between input and hidden layers
	for (long j = 0; j < nHidden[0]; j++) {
		//get error gradient for every hidden node
		hiddenErrorGradients[0][j] = getHiddenErrorGradient(0, j);
		
		for (long i = 0; i <= nInput; i++) {			//for all nodes in input layer and bias neuron
			//calculate change in weight 
			if (!useBatch)
				deltaInputHidden[i][j] = learningRate * inputNeurons[i] * hiddenErrorGradients[0][j] + momentum * deltaInputHidden[i][j];
			else 
				deltaInputHidden[i][j] += learningRate * inputNeurons[i] * hiddenErrorGradients[0][j]; 
		}
	}
		
		
	
	/// Possibly backpropagate through time
	if (recurrent && bptt_num_steps > 2) {
		// backpropagation through time
		for (long t = 1; t < bptt_num_steps - 1; t++) {
			
			// update deltaHiddenSelf
			for (long k = nHiddenLayers - 1; k >= 0; k--) {
				for (long j = 0; j < nHidden[k]; j++) {
					hiddenErrorGradients_bptt[t][k][j] = getHiddenErrorGradient_bptt(t, k, j);
					
					for (long i = 0; i <= nHidden[k]; i++)
						deltaHiddenSelf[k][i][j] += learningRate * hiddenNeurons_history[t+1][k][i] * hiddenErrorGradients_bptt[t][k][j]; 
				}
			} 
			
			// TO DO: update deltaHiddenNext
			
			// update input -> hidden
			for (long j = 0; j < nHidden[0]; j++) {
				hiddenErrorGradients_bptt[t][0][j] = getHiddenErrorGradient_bptt(t, 0, j);
				
				for (long i = 0; i <= nInput; i++)
					deltaInputHidden[i][j] += learningRate * inputNeurons_history[t][i] * hiddenErrorGradients_bptt[t][0][j]; 
			}
 
		}
	}
	
	
	//if using stochastic learning update the weights immediately
	if (!useBatch) updateWeights();
}



//update weights
void neuralNetwork::updateHistory()
{
	double *temp = inputNeurons_history[bptt_num_steps - 1];
	for (long i = bptt_num_steps - 1; i > 0; i--)
		inputNeurons_history[i] = inputNeurons_history[i-1];
	inputNeurons_history[0] = temp;
	
//	std::rotate(&inputNeurons_history[0], &inputNeurons_history[bptt_num_steps-1], &inputNeurons_history[bptt_num_steps-1]);
	for (long i = 0; i < nInput; i++) 
		inputNeurons_history[0][i] = inputNeurons[i];
	
	//	std::rotate(&hiddenNeurons_history[0], &hiddenNeurons_history[bptt_num_steps-1], &hiddenNeurons_history[bptt_num_steps-1]);
	double **temp2 = hiddenNeurons_history[bptt_num_steps - 1];
	for (long i = bptt_num_steps - 1; i > 0; i--)
		hiddenNeurons_history[i] = hiddenNeurons_history[i-1];
	hiddenNeurons_history[0] = temp2;
	
	for (long k = 0; k < nHiddenLayers; k++) {
		for (long i = 0; i <= nHidden[k]; i++) 
			hiddenNeurons_history[0][k][i] = hiddenNeurons[k][i];
	}
}


//update weights
void neuralNetwork::updateWeights()
{
	//input -> hidden weights
	//--------------------------------------------------------------------------------------------------------
	for (long i = 0; i <= nInput; i++)	{
		for (long j = 0; j < nHidden[0]; j++) {
			//update weight
			wInputHidden[i][j] += deltaInputHidden[i][j];	
			
			//clear delta only if using batch (previous delta is needed for momentum
			if (useBatch) deltaInputHidden[i][j] = 0;				
		}
	}

	//hidden -> next
	//--------------------------------------------------------------------------------------------------------
	for (long k = 0; k < nHiddenLayers - 1; k++) {
		for (long j = 0; j <= nHidden[k]; j++) {
			for (long h = 0; h < nOutput; h++) {
				//update weight
				wHiddenNext[k][j][h] += deltaHiddenNext[k][j][h];
				
				//clear delta only if using batch (previous delta is needed for momentum)
				if (useBatch)deltaHiddenNext[k][j][h] = 0;
			}
		}	
	}

	//hidden -> self
	//--------------------------------------------------------------------------------------------------------
	if (recurrent) {
		for (long k = 0; k < nHiddenLayers; k++) {
			for (long j = 0; j <= nHidden[k]; j++) {
				for (long h = 0; h < nHidden[k]; h++) {
					//update weight
					wHiddenSelf[k][j][h] += deltaHiddenSelf[k][j][h];
					
					//clear delta only if using batch (previous delta is needed for momentum)
					if (useBatch) deltaHiddenSelf[k][j][h] = 0;
				}
			}	
		}
	}
	
	//hidden -> output weights
	//--------------------------------------------------------------------------------------------------------
	for (long j = 0; j <= nHidden[nHiddenLayers - 1]; j++) {
		for (long k = 0; k < nOutput; k++) {					
			//update weight
			wHiddenOutput[j][k] += deltaHiddenOutput[j][k];
			
			//clear delta only if using batch (previous delta is needed for momentum)
			if (useBatch)deltaHiddenOutput[j][k] = 0;
		}
	}
}

//activation function
inline double neuralNetwork::applyActivationFunction( double x )
{
	switch (activationFunction) {
		case NEURALNET_ACTIVATION_FUNCTION_TANH:
			return tanh(x);
			break;
		case NEURALNET_ACTIVATION_FUNCTION_STEP:
			return (x > 0 ? 1 : (x < 0 ? -1 : 0));
			break;
		default:
			//logistic sigmoid function
			return 1/(1+exp(-x));
			break;
	}
}

//get error gradient for ouput layer
inline double neuralNetwork::getOutputErrorGradient(double desiredValue, double outputValue)
{
	//return error gradient
	switch (activationFunction) {
		case NEURALNET_ACTIVATION_FUNCTION_TANH:
			return ( 1 - outputValue * outputValue ) * ( desiredValue - outputValue );
		case NEURALNET_ACTIVATION_FUNCTION_STEP:
			return 0.;
		default: // valid for NEURALNET_ACTIVATION_FUNCTION_LOGISTICSIGMOID and NEURALNET_ACTIVATION_FUNCTION_SOFTMAX 
			return outputValue * ( 1 - outputValue ) * ( desiredValue - outputValue );
	}
}

//get error gradient for hidden layer(s)
double neuralNetwork::getHiddenErrorGradient(long hidden_layer_idx, long j )
{
	double weightedSum = 0;
	if (hidden_layer_idx == nHiddenLayers -1 ) { // get sum of hidden->output weights * output error gradients
		for( long k = 0; k < nOutput; k++ ) 
			weightedSum += wHiddenOutput[j][k] * outputErrorGradients[k];
	} else { // get sum of hidden->next weights * "next" error gradients
		for( long k = 0; k < nHidden[hidden_layer_idx+1]; k++ ) 
			weightedSum += wHiddenNext[hidden_layer_idx][j][k] * hiddenErrorGradients[hidden_layer_idx+1][k];
	}
	
	//return error gradient
	switch (activationFunction) {
		case NEURALNET_ACTIVATION_FUNCTION_TANH:
			return ( 1 - hiddenNeurons[hidden_layer_idx][j] * hiddenNeurons[hidden_layer_idx][j] ) * weightedSum;
		case NEURALNET_ACTIVATION_FUNCTION_STEP:
			return 0.;
		default: // valid for NEURALNET_ACTIVATION_FUNCTION_LOGISTICSIGMOID and NEURALNET_ACTIVATION_FUNCTION_SOFTMAX 
			return hiddenNeurons[hidden_layer_idx][j] * ( 1 - hiddenNeurons[hidden_layer_idx][j] ) * weightedSum;
	}
}


//get error gradient for hidden layer(s) for backpropagation through time (t supposedly > 0 is the step, in backward order)
// i.e. t = 1 is first step backward, and so on) 
double neuralNetwork::getHiddenErrorGradient_bptt(long t, long hidden_layer_idx, long j)
{
	if (t == 0)
		return getHiddenErrorGradient(hidden_layer_idx, j);
	
	double weightedSum = 0;
	for (long k = 0; k < nHidden[hidden_layer_idx]; k++) 
		weightedSum += wHiddenSelf[hidden_layer_idx][j][k] * hiddenErrorGradients_bptt[t-1][hidden_layer_idx][k]; // TO DO: check
	
	//return error gradient
	switch (activationFunction) {
		case NEURALNET_ACTIVATION_FUNCTION_TANH:
			return ( 1 - hiddenNeurons_history[t][hidden_layer_idx][j] * hiddenNeurons_history[t][hidden_layer_idx][j] ) * weightedSum;
		case NEURALNET_ACTIVATION_FUNCTION_STEP:
			return 0.;
		default: // valid for NEURALNET_ACTIVATION_FUNCTION_LOGISTICSIGMOID and NEURALNET_ACTIVATION_FUNCTION_SOFTMAX 
			return hiddenNeurons_history[t][hidden_layer_idx][j] * ( 1 - hiddenNeurons_history[t][hidden_layer_idx][j] ) * weightedSum;
	}
}

//feed forward set of patterns and return error
double neuralNetwork::getSetAccuracy(vector<dataEntry*> set)
{
	double incorrectResults = 0;
	
	//for every training input array
	long set_size = (long) set.size();
	for (long tp = 0; tp < set_size; tp++) {		
		
		//feed inputs through network and backpropagate errors
		feedForward(set[tp]->pattern);
		
		//correct pattern flag
		bool correctResult = true;
		
		//check all outputs against desired output values
		for (long k = 0; k < nOutput; k++) {
			//set flag to false if desired and output differ
			if (fabs(outputNeurons[k] - set[tp]->target[k]) > classificationTolerance)
				correctResult = false;
		}
		
		//inc training error for a incorrect result
		if (!correctResult) incorrectResults++;	
		
	}
	
	//calculate error and return as percentage
	return 1. - ((incorrectResults * 1.)/set.size());
}

//feed forward set of patterns and return MSE
double neuralNetwork::getSetMSE ( vector<dataEntry*> set )
{
	double mse = 0;
	
	//for every training input array
	for (long tp = 0; tp < (long) set.size(); tp++) {						
		//feed inputs through network
		feedForward( set[tp]->pattern );
		
		//check all outputs against desired output values
		for (long k = 0; k < nOutput; k++) {					
			//sum all the MSEs together
			mse += pow((outputNeurons[k] - set[tp]->target[k]), 2);
		}		
		
	}
	
	//calculate error and return as percentage
	return mse/(nOutput * set.size());
}

t_llll* neuralNetwork::getAccuracyAndMSE(char forTS, char forGS, char forVS)
{
	t_llll *output_data = llll_get();
	t_llll *accuracy_ll = llll_get();
	t_llll *mse_ll = llll_get();
	if (forTS) llll_appenddouble(accuracy_ll, trainingSetAccuracy, 0, WHITENULL_llll);
	if (forGS) llll_appenddouble(accuracy_ll, generalizationSetAccuracy, 0, WHITENULL_llll);
	if (forVS) llll_appenddouble(accuracy_ll, validationSetAccuracy, 0, WHITENULL_llll);
	if (forTS) llll_appenddouble(mse_ll, trainingSetMSE, 0, WHITENULL_llll);
	if (forGS) llll_appenddouble(mse_ll, generalizationSetMSE, 0, WHITENULL_llll);
	if (forVS) llll_appenddouble(mse_ll, validationSetMSE, 0, WHITENULL_llll);
	
	llll_appendllll(output_data, accuracy_ll, 0, WHITENULL_llll);
	llll_appendllll(output_data, mse_ll, 0, WHITENULL_llll);
	
	return output_data;
}

t_llll* neuralNetwork::getState()
{
	t_llll *state = llll_get();
	t_llll *nodes = llll_get();
	t_llll *weights = llll_get();
	
	// nodes
	llll_appendllll(nodes, double_array_to_llll(inputNeurons, nInput), 0, WHITENULL_llll);
	for (long k=0; k < nHiddenLayers; k++)
		llll_appendllll(nodes, double_array_to_llll(hiddenNeurons[k], nHidden[k]), 0, WHITENULL_llll);
	llll_appendllll(nodes, double_array_to_llll(outputNeurons, nOutput), 0, WHITENULL_llll);

	// weights
	t_llll *wInputHidden_ll = llll_get();
	for ( long i=0; i <= nInput; i++ ) 
	{
		t_llll *subll = llll_get();
		for ( long j=0; j < nHidden[0]; j++ ) 
			llll_appenddouble(subll, wInputHidden[i][j], 0, WHITENULL_llll);		
		llll_appendllll(wInputHidden_ll, subll, 0, WHITENULL_llll);
	}
	llll_appendllll(weights, wInputHidden_ll, 0, WHITENULL_llll);


	for (long k=0; k < nHiddenLayers; k++) {

		if (recurrent) {
			t_llll *wHiddenSelf_ll = llll_get();
			for (long i=0; i <= nHidden[k]; i++) {
				t_llll *subll = llll_get();
				for (long j=0; j < nHidden[k]; j++) 
					llll_appenddouble(subll, wHiddenSelf[k][i][j], 0, WHITENULL_llll);		
				llll_appendllll(wHiddenSelf_ll, subll, 0, WHITENULL_llll);
			}
			llll_appendllll(weights, wHiddenSelf_ll, 0, WHITENULL_llll);
		}
		
		if (k < nHiddenLayers - 1) {
			t_llll *wHiddenNext_ll = llll_get();
			for (long i = 0; i <= nHidden[k]; i++) {
				t_llll *subll = llll_get();
				for (long j = 0; j < nHidden[k+1]; j++) 
					llll_appenddouble(subll, wHiddenNext[k][i][j], 0, WHITENULL_llll);		
				llll_appendllll(wHiddenNext_ll, subll, 0, WHITENULL_llll);
			}
			llll_appendllll(weights, wHiddenNext_ll, 0, WHITENULL_llll);
		}
	}

	t_llll *wHiddenOutput_ll = llll_get();
	for (long i=0; i <= nHidden[nHiddenLayers-1]; i++) {
		t_llll *subll = llll_get();
		for (long j=0; j < nOutput; j++) 
			llll_appenddouble(subll, wHiddenOutput[i][j], 0, WHITENULL_llll);		
		llll_appendllll(wHiddenOutput_ll, subll, 0, WHITENULL_llll);
	}
	llll_appendllll(weights, wHiddenOutput_ll, 0, WHITENULL_llll);


	llll_appendllll(state, nodes, 0, WHITENULL_llll);
	llll_appendllll(state, weights, 0, WHITENULL_llll);
	
	return state;
}


void fill_double_array_from_llll(t_llll *ll, double *ar, long ar_size)
{
	long i;
	t_llllelem *elem;
	for (i = 0, elem = ll->l_head; i < ar_size && elem; i++, elem = elem->l_next) {
		if (is_hatom_number(&elem->l_hatom))
			ar[i] = hatom_getdouble(&elem->l_hatom);
	}
}

void fill_double_matrix_from_llll(t_llll *ll, double **m, long m_lines, long m_columns)
{
	long i, j;
	t_llllelem *line, *cell;
	for (i = 0, line = ll->l_head; i < m_lines && line; i++, line = line->l_next) {
		if (hatom_gettype(&line->l_hatom) == H_LLLL) {
			for (j = 0, cell = hatom_getllll(&line->l_hatom)->l_head; j < m_columns && cell; j++, cell = cell->l_next) {
				if (is_hatom_number(&cell->l_hatom))
					m[i][j] = hatom_getdouble(&cell->l_hatom);
			}
		}
	}
}

long neuralNetwork::setState(t_llll *state)
{
	if (!state || !state->l_head || hatom_gettype(&state->l_head->l_hatom) != H_LLLL ||
		(state->l_head->l_next && hatom_gettype(&state->l_head->l_next->l_hatom) != H_LLLL)) 
		return 1;


	t_llll *nodes = hatom_getllll(&state->l_head->l_hatom); // neurons values
	t_llll *weights = state->l_head->l_next ? hatom_getllll(&state->l_head->l_next->l_hatom) : NULL;
	
	if (nodes) {
		t_llllelem *temp = nodes->l_head;
		long count = 0; 
		while (temp && count < nHiddenLayers + 2) {
			if (hatom_gettype(&temp->l_hatom) != H_LLLL)
				return 1;
			
			if (count == 0) // input neurons
				fill_double_array_from_llll(hatom_getllll(&temp->l_hatom), inputNeurons, nInput);
			else if (count == nHiddenLayers + 1) // output neurons
				fill_double_array_from_llll(hatom_getllll(&temp->l_hatom), outputNeurons, nOutput);
			else // hidden neurons
				fill_double_array_from_llll(hatom_getllll(&temp->l_hatom), hiddenNeurons[count-1], nHidden[count-1]);
				
			count ++;
			temp = temp->l_next;
		}
	}
	
	if (weights) {
		t_llllelem *temp = weights->l_head;
		long count = 0; 
		
		long index_hidden_output = (recurrent ? (2 * nHiddenLayers - 1) : (nHiddenLayers - 1)) + 1;

		while (temp) {
			if (hatom_gettype(&temp->l_hatom) != H_LLLL)
				return 1;
			
			if (count == 0) // input > hidden
				fill_double_matrix_from_llll(hatom_getllll(&temp->l_hatom), wInputHidden, nInput + 1, nHidden[0]);
			else if (count == index_hidden_output) // hidden > output
				fill_double_matrix_from_llll(hatom_getllll(&temp->l_hatom), wHiddenOutput, nHidden[nHiddenLayers-1] + 1, nOutput);
			else {
				long idx = count - 1;
				if (recurrent) {
					if (idx < 2 * nHiddenLayers - 1) {
						long idx_div_2 = idx / 2;
						if (idx % 2 == 0) {
							fill_double_matrix_from_llll(hatom_getllll(&temp->l_hatom), wHiddenSelf[idx_div_2], nHidden[idx_div_2] + 1, nHidden[idx_div_2]);
						} else if (idx_div_2 < nHiddenLayers - 1)
							fill_double_matrix_from_llll(hatom_getllll(&temp->l_hatom), wHiddenNext[idx_div_2], nHidden[idx_div_2] + 1, nHidden[idx_div_2 + 1]);
					}
				} else {
					if (idx < nHiddenLayers - 1)
						fill_double_matrix_from_llll(hatom_getllll(&temp->l_hatom), wHiddenNext[idx], nHidden[idx] + 1, nHidden[idx + 1]);
				}
			}
			
			count ++;
			temp = temp->l_next;

		}	
	}
	
	return 0;
}

	
