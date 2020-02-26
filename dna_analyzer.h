/* Gary Zeri
   ID: 2321569 
   zeri@chapman.edu
   CPSC 350-02
   Assignment 1
*/

//DNA Analyzer Class designed to perform simple data analysis for CPSC 350 Assignment 2

#ifndef DNA_ANALYSIS_H_
#define DNA_ANALYSIS_H_

#include<iostream>
#include<fstream>
#include<cmath>
#include "dna_data.h"
#include "assignment1_constants.h"
#include "helpful_methods.h" 

using namespace std;

class DnaAnalyzer{

	public:
		DnaAnalyzer();
		bool ParseFile(fstream& inputFile);
		string OutputString();
		string GenerateDna(int numberOfDnaStrings);

	private:
		const string TEMP_PROC_FILENAME="._assignment1_temp_proc_file.dat";
			
		int numberOfDnaStrings=0;
		double lengthMean=0;
		double lengthVariance=0;
		double lengthStdDev=0;
		DnaData dnaData;
	
		void ComputeStatistics(fstream& inputFile);	
};

#endif //DNA_ANALYSIS_H
