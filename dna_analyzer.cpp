/* Gary Zeri
   ID: 2321569 
   zeri@chapman.edu
   CPSC 350-02
   Assignment 1
*/

#include "dna_analyzer.h"

using namespace std;

DnaAnalyzer::DnaAnalyzer(){}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*ParseFile Function 
  Parse DNA stats from a text file, returns true if parsing was sucessful, returns false if file was incorrectly formatted
  inputFile: fstream that is the file to open for parsing
*/
bool DnaAnalyzer::ParseFile(fstream& inputFile){

	string dnaString;			

	//loop to parse all dna data from the file
	while( getline(inputFile, dnaString) ){
	
		int lineSize = dnaString.size();

		//account for any empty lines that may be in the file
		if(dnaString.size() == 0)
			continue;
			
		//Ensure that the size of line is even to ensure that all pairs of two are picked out
		//Even if line contains an odd number of DAN nucleotides, the string.substr() methods will get the single last character
		if(lineSize %2 != 0)
			lineSize++;
	
		//increment number of DNA string parsed
		numberOfDnaStrings++;	
		
		//Loop over all DNA Bigrams in the data
		for(int i=0; i<lineSize / 2; ++i){
	
			string dnaBigram = HelpfulMethods::UpperString(dnaString.substr(2*i, 2));
	
			//check to handle incorrectly formatted DNA Files	
			if(!dnaData.UpdateDnaCount(dnaBigram)){
				cout << kBadDnaFileFormat << " " << to_string(numberOfDnaStrings) << ": " << dnaString << endl;
				return false;
			}
		}		
	}
	
	//reset the input file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	
	//compute the DNA Statistics based on the input file
	ComputeStatistics(inputFile);		

	inputFile.close();
		
	return true;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*OutputString Function
  Creates a nicely formatted string of all the statistics data from this object
*/
string DnaAnalyzer::OutputString(){
		
	string output = "";

	output += "Sum of DNA String Lengths: " + to_string(dnaData.GetLengthSum()) + "\n";
	output += "Mean of DNA String Length: " + to_string(lengthMean) + "\n";
	output += "Variance of DNA String Length: " + to_string(lengthVariance) + "\n";
	output += "Standard Deviation of DNA String Length: " + to_string(lengthStdDev) + "\n";

	output += dnaData.ComputeDnaStatistics() + "\n"; 

	return output;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*GenerateDna Function 
  Generates DNA Strings following the statistics that have computed from another preexisting DNA input file
  numberOfDnaStrings: int representing the number of DNA string to compute 
*/
string DnaAnalyzer::GenerateDna(int numberOfDnaStrings){	

	int nucleotideNumber = 0;
	double a;
	double b;
	double C;
	double remainder;
	string dnaStrings;
	fstream dnaStringsFile;
	
	dnaStringsFile.open(kWorkspaceFilename, ios::out);
	
	for(int i=0; i<numberOfDnaStrings; ++i){

		int length=0;
			
		//get 2 random numbers between [0,1)
		a = double(rand()) / RAND_MAX;	
		b = double(rand()) / RAND_MAX;
	
		C = sqrt( -2 * log(a)) * cos(2*M_PI*b);

		//Round number to account for fact that the length of a DNA string can not be a decimal value	
		length = abs(round(lengthStdDev * C + lengthMean));

		nucleotideNumber += length;

		dnaStringsFile << length << endl;
	}
	
	dnaStringsFile.close();

	dnaStrings = dnaData.GenerateDna(kWorkspaceFilename, nucleotideNumber);
	
	remove(kWorkspaceFilename.c_str());

	return dnaStrings;
}

//----------------------------------------------------------------------------------

/*ComputeStatistics Functions computes the dna statistics for this object
  inputFile: fstream file object to access the file containing the DNA data
*/
void DnaAnalyzer::ComputeStatistics(fstream& inputFile){

	//compute the length mean	
	lengthMean = double(dnaData.GetLengthSum()) / double(numberOfDnaStrings);
	
	//compute the length variance 
	string dnaString;
	while(getline(inputFile, dnaString)){
		if(dnaString.size()==0)
			continue;
		lengthVariance += pow(dnaString.size() - lengthMean, 2);	
	}
	lengthVariance /= double(numberOfDnaStrings);
	
	//Reset the input file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	//compute the length standard deviation
	lengthStdDev = sqrt(lengthVariance);
}
