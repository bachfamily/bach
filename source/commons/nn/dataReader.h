#ifndef _DATAREADER
#define _DATAREADER

//standard libraries
#include <vector>
//#include <string>
#include <math.h>
#include <algorithm>

//custom includes
#include "dataEntry.h"

using namespace std;

//dataset retrieval approach enum
enum { NEURALNET_DATASET_STATIC = 0, NEURALNET_DATASET_GROWING = 1, NEURALNET_DATASET_WINDOWING = 2 };

class dataSet{
public:

	vector<dataEntry*> trainingSet;
	vector<dataEntry*> generalizationSet;
	vector<dataEntry*> validationSet;

	dataSet()
	{		
	}

	~dataSet()
	{
		trainingSet.clear();
		generalizationSet.clear();
		validationSet.clear();
	}

	void clear()
	{
		trainingSet.clear();
		generalizationSet.clear();
		validationSet.clear();
	}
};

class dataReader
{
	
private:

	//data storage
	vector<dataEntry*> data;
	int nInputs;
	int nTargets;

	//current data set
	dataSet dSet;
	double split_pts[2];

	//data set creation approach and total number of dataSets
	int creationApproach;
	int numDataSets;
	int trainingDataEndIndex;

	//creation approach variables
	double growingStepSize;			//step size - percentage of total set
	int growingLastDataIndex;		//last index added to current dataSet
	int windowingSetSize;			//initial size of set
	int windowingStepSize;			//how many entries to move window by
	int windowingStartIndex;		//window start index	
	
public:

	//constructor
	dataReader(): creationApproach(NEURALNET_DATASET_STATIC), numDataSets(-1)
	{				
		split_pts[0] = 0.6;
		split_pts[1] = 0.8;
	}

	//destructor
	~dataReader()
	{
		//clear data
		for (int i=0; i < (int) data.size(); i++ ) delete data[i];		
		data.clear();		 
	}
	
	void setSplitPts(double s1, double s2)
	{
		split_pts[0] = CLAMP(MIN(s1, s2), 0., 1.);		
		split_pts[1] = CLAMP(MAX(s1, s2), 0., 1.);		
	}
	

	//read data from file
	bool loadLlll(t_llll *ll, int nI, int nT, char shuffle_data)
	{
		//clear any previous data
		for (int i=0; i < (int) data.size(); i++) 
			delete data[i];		
		data.clear();
		dSet.clear();
		
		//set number of inputs and outputs
		nInputs = nI;
		nTargets = nT;

		//process llllelems for reading
		t_llllelem *elem;
		for (elem = ll->l_head; elem; elem = elem->l_next) 
			processElement(elem);
		
		//shuffle data
		if (shuffle_data)
			random_shuffle(data.begin(), data.end());
		
		//split data set
		trainingDataEndIndex = (int) (split_pts[0] * data.size());
		int gSize = (int) (ceil((split_pts[1] - split_pts[0]) * data.size()));
//		int vSize = (int) (data.size() - trainingDataEndIndex - gSize);
		
		//generalization set
		for (int i = trainingDataEndIndex; i < trainingDataEndIndex + gSize; i++) 
			dSet.generalizationSet.push_back(data[i]);
		
		//validation set
		for (int i = trainingDataEndIndex + gSize; i < (int) data.size(); i++) 
			dSet.validationSet.push_back(data[i]);
		
		//print success
		dev_post("Data load completed. Patterns Loaded: %ld", data.size());
		
		return true;
	}

	//select dataset approach
	void setCreationApproach(int approach, double param1 = -1, double param2 = -1)
	{
		//static
		if (approach == NEURALNET_DATASET_STATIC) {
			creationApproach = NEURALNET_DATASET_STATIC;
			
			//only 1 data set
			numDataSets = 1;
			
		} else if (approach == NEURALNET_DATASET_GROWING) {			
			if ( param1 <= 1. && param1 > 0) {
				creationApproach = NEURALNET_DATASET_GROWING;
			
				//step size
				growingStepSize = param1;
				growingLastDataIndex = 0;

				//number of sets
				numDataSets = (int) ceil( 1 / growingStepSize );				
			}
			
		} else if (approach == NEURALNET_DATASET_WINDOWING) {
			//if initial size smaller than total entries and step size smaller than set size
			if (param1 < 1. && param1 <= param2) {
				creationApproach = NEURALNET_DATASET_WINDOWING;
				
				//params
				windowingSetSize = (int) param2 * data.size();
				windowingStepSize = (int) param1 * data.size();
				windowingStartIndex = 0;			

				//number of sets
				numDataSets = (int) ceil( (double) (trainingDataEndIndex - windowingSetSize) / windowingStepSize ) + 1;
			}			
		}

	}

	//return number of datasets
	int nDataSets() {
		return numDataSets;
	}
	
	dataSet* getDataSet() {		
		switch (creationApproach) {
			case NEURALNET_DATASET_STATIC : createStaticDataSet(); break;
			case NEURALNET_DATASET_GROWING : createGrowingDataSet(); break;
			case NEURALNET_DATASET_WINDOWING : createWindowingDataSet(); break;
		}
		
		return &dSet;
	}

//private methods
//----------------------------------------------------------------------------------------------------------------
private:
	
	void createStaticDataSet() {
		//training set
		for (int i = 0; i < trainingDataEndIndex; i++) dSet.trainingSet.push_back(data[i]);		
	}

	void createGrowingDataSet() {
		//increase data set by step percentage
		growingLastDataIndex += (int) ceil(growingStepSize * trainingDataEndIndex);		
		if (growingLastDataIndex > (int) trainingDataEndIndex) growingLastDataIndex = trainingDataEndIndex;

		//clear sets
		dSet.trainingSet.clear();
		
		//training set
		for (int i = 0; i < growingLastDataIndex; i++) dSet.trainingSet.push_back(data[i]);			
	}

	void createWindowingDataSet() {
		//create end point
		int endIndex = windowingStartIndex + windowingSetSize;
		if (endIndex > trainingDataEndIndex) endIndex = trainingDataEndIndex;		

		//clear sets
		dSet.trainingSet.clear();
						
		//training set
		for (int i = windowingStartIndex; i < endIndex; i++) dSet.trainingSet.push_back(data[i]);
				
		//increase start index
		windowingStartIndex += windowingStepSize;
	}
	
	void processElement(t_llllelem *elem) {
		//create new pattern and target
		double* pattern = new double[nInputs];
		double* target = new double[nTargets];
		t_llll *subll;
		long i;
		
		for (i = 0; i < nInputs; i++)
			pattern[i] = 0;
		for (i = 0; i < nTargets; i++)
			target[i] = 0;
		
		if (hatom_gettype(&elem->l_hatom) == H_LLLL && (subll = hatom_getllll(&elem->l_hatom)) &&
			subll->l_head && subll->l_head->l_next && hatom_gettype(&subll->l_head->l_hatom) == H_LLLL &&
			hatom_gettype(&subll->l_head->l_next->l_hatom) == H_LLLL) {
			
			t_llll *pattern_ll = hatom_getllll(&subll->l_head->l_hatom);
			t_llll *target_ll = hatom_getllll(&subll->l_head->l_next->l_hatom);
			t_llllelem *temp;
			long i;
			for (i = 0, temp = pattern_ll->l_head; temp && i < nInputs; temp = temp->l_next, i++)
				pattern[i] = hatom_getdouble(&temp->l_hatom);
			for (i = 0, temp = target_ll->l_head; temp && i < nTargets; temp = temp->l_next, i++)
				target[i] = hatom_getdouble(&temp->l_hatom);
		} 
		
		//add to records
		data.push_back( new dataEntry( pattern, target ) );		
	}
};

#endif
