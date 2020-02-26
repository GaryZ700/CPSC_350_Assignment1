/* Gary Zeri
   ID: 2321569 
   zeri@chapman.edu
   CPSC 350-02
   Assignment 1
*/

//Class to Handle maintaince and retrevial of all DNA data

#ifndef DNA_DATA_H_
#define DNA_DATA_H_

#include <iostream>
#include <fstream>

using namespace std;

class DnaData{
	
	public:
		DnaData();
		bool UpdateDnaCount(string dna);
		int GetLengthSum();
		string ComputeDnaStatistics();
		string GenerateDna(string dnaStringsFileName, int totalNucleotides);
	private:
		const string kNUCLEOTIDES = "AGCT";
		
		//Keep track of the number of Bigrams/Nucleotides from the input file
		double AA=0;
		double AG=0;
		double AT=0;
		double AC=0;
		double GA=0;
		double GG=0;
		double GT=0;
		double GC=0;
		double TA=0;
		double TG=0;
		double TT=0;
		double TC=0;
		double CA=0;
		double CG=0;
		double CT=0;
		double CC=0;
		double  A=0;
		double  G=0;
		double  T=0;
		double  C=0;

		int lengthSum = 0;
		int largestBigramAmount;

		//Keep track of the amount of specified Nucleotides/Bigrams to create a new 
		//DNA file of a specifed size with the same nucleotide/bigram relative probability
		double AAAmount;
		double AGAmount;
		double ATAmount;
		double ACAmount;
		double GAAmount;
		double GGAmount;
		double GTAmount;
		double GCAmount;
		double TAAmount;
		double TGAmount;
		double TTAmount;
		double TCAmount;
		double CAAmount;
		double CGAmount;
		double CTAmount;
		double CCAmount;
		double AAmount;
		double GAmount;
		double TAmount;
		double CAmount;

		double* GetData(string id);
		double DnaStatistic(string dna);
		string GenerateBigrams(int bigramSize);
		string GenerateNucleotide();		 
};

#endif //DNA_DATA_H_
