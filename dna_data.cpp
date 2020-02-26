/* Gary Zeri
   ID: 2321569 
   zeri@chapman.edu
   CPSC 350-02
   Assignment 1
*/

#include "dna_data.h"

using namespace std;

DnaData::DnaData(){}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*UpdateDnaCount Function 
  Updates the current count of dna nucleotides and bigrams given a dna string
  dna: string of dna to add to the bigram and sole nucleotide computation
*/
bool DnaData::UpdateDnaCount(string dna){

	double *data = GetData(dna);

	if(data == NULL)
		return false;

	++(*data);
	lengthSum += dna.size();		
	return true;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*ComputeDnaStatistics Function
  Coputes Statistics for the DNA 
*/
string DnaData::ComputeDnaStatistics(){
	
	string bigramStats = "DNA Relative Probability \n\n";

	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
	
			string dna;
			dna = kNUCLEOTIDES.at(j); 
			dna +=  kNUCLEOTIDES.at(i);
	
			bigramStats += dna + ": " + to_string(DnaStatistic(dna)) + "\n";
		}
	}

	return bigramStats;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*GetLengthSum Function
*/
int DnaData::GetLengthSum(){ return lengthSum; }

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*GenerateDna Function  
  Generates Random DNA sequences according to the statistics of the original DNA Input
  dnaStringsFilename: File Name for the file containing numbers of the size of each dna string to generate
  totalNucleotides: integer of the total nucleotides for all the random DNA strigns to be generated
*/
string DnaData::GenerateDna(string dnaStringsFileName, int totalNucleotides){

	double lastBigramNumber=0;
	double currentBigramNumber;
	fstream dnaStringsFile;
 
	dnaStringsFile.open(dnaStringsFileName, ios::in);

	//Set up data for computing statistics of the DNA
	largestBigramAmount = 0;	
	for(int i=0; i<4; i++){
		for(int j=0; j<4; ++j){
	
			string dna;
			dna = kNUCLEOTIDES.at(i);
			dna += kNUCLEOTIDES.at(j);

			//get Bigram/Nucleotide Amount variable and 
			//set it equal to the amount of that specific
			//nucleotide or bigram needed to have the same 
			//statistical distribution as the original DNA distribution	
			double *data = GetData(dna + "Amount"); 
		        *data = DnaStatistic(dna) * totalNucleotides;
	
			if(*data > largestBigramAmount)
				largestBigramAmount = *data;
		}
	}

	//Begin Computation of the Random DNA Strings
	string line;
	string dnaStrings = "";
	
	while(getline(dnaStringsFile, line)){

		int dnaLength = stoi(line);

		//check if the line is composed of an odd or even amount of nucleotides
		//if even, then just addd in the correct amount of bigrams
		//if odd, then add in the as many bigrams as possible, and then end with
		//a single nucleotide to get the odd number
		if(dnaLength % 2 != 0){
			dnaStrings += GenerateBigrams((dnaLength-1) / 2);
			dnaStrings += GenerateNucleotide();
		}
		else
			dnaStrings += GenerateBigrams(dnaLength / 2);
		
		dnaStrings += "\n";
	}

	dnaStringsFile.close();

	return dnaStrings;	
}

//----------------------------------------------------------------------------------

/*DnaStatistic Function 
  Computes the relative frequency of the specifed DNA nucleotide or Bigram
  dna: string of the DNA nucleotide or bigram whose relative frequency should be computed. 
*/
double DnaData::DnaStatistic(string dna){
	
	double totalBigrams = (lengthSum - A - G - T - C) / 2;
	
	//determein if working with a single nucleotide or a Bigram, and proceeed accordingly
	if(dna.size() == 1){
		if("A"==dna)
			return A/(A + 2*AA + AT + AG + AC + TA + GA + CA);
		else if("G"==dna)
			return G/(G + 2*GG + GT + GC + GA + TG + AG + CG);
		else if("T"==dna)
			return T/(T + 2*TT + TA + TG + TC + AT + GT + CT);
		else if("C"==dna)
			return C/(C + 2*CC + CT + CG + CA + TC + GC + AC);
	}
	else
		return *GetData(dna) / totalBigrams;
}

//----------------------------------------------------------------------------------

/*GenerateBigrams Function 
  Function to Generate Bigrams according to the statistics of the input file
  bigramSize: int representing the number of bigrams to produce in this DNA string
*/
string DnaData::GenerateBigrams(int bigramSize){

	int oldBigramsStringSize = 0;
	string bigrams = "";
	
	while(bigrams.size() / 2 < bigramSize){

		for(int i=0; i<4; ++i){
			for(int j=0; j<4; ++j){
				
				string bigramName;
				bigramName = kNUCLEOTIDES.at(i);
				bigramName += kNUCLEOTIDES.at(j); 
				
				double *bigram = GetData(bigramName + "Amount");
				
				//Check whether the current bigram has the highest 
				//probabillity at appearing in this DNA String
				if(*bigram >= largestBigramAmount){
					bigrams += bigramName;
					--(*bigram);
				}
			
				//return the bigrams string when the 
				//correct amount of bigrmas have been generated
				if(bigrams.size() / 2 == bigramSize)
					return bigrams;
			} 
		}
		
		//If there has been no update to the amount of 
		//bigrams added to the DNA string, then
		//decrease the min probability the bigram 
		//must have to join the string
		if(oldBigramsStringSize == bigrams.size())
			largestBigramAmount /= 2;
		else
			oldBigramsStringSize = bigrams.size();
	}
	
	return bigrams;
}

//----------------------------------------------------------------------------------

/*GenerateNucleotide Function 
  Generates a Random Nucleotide follwing the distributio statistics of the input file
*/
string DnaData::GenerateNucleotide(){

	double *nucleotide;

	for(int i=0; i<4; ++i){
	
		string nucleotideName;
		nucleotideName = kNUCLEOTIDES.at(i);
		
		nucleotide = GetData(nucleotideName + "Amount");
			
		if(*nucleotide > 0){	
			--(*nucleotide);
			return nucleotideName;
		}
	}
}

//----------------------------------------------------------------------------------

double* DnaData::GetData(string id){
	double *data;
	
	if(id == "AA")
		data = &AA;
	else if(id == "GA")
		data = &AG;
	else if(id == "TA")
		data = &AT;
	else if(id == "CA")
		data = &AC;
	else if(id == "A")
		data = &A;
	else if(id == "AG")
		data = &GA;
	else if(id == "GG")
		data = &GG;
	else if(id == "TG")
		data = &GT;
	else if(id == "CG")
		data = &GC;
	else if(id == "G")
		data = &G;
	else if(id == "AT")
		data = &TA;
	else if(id == "GT")
		data = &TG;
	else if(id == "TT")
		data = &TT;
	else if(id == "CT")
		data = &TC;
	else if(id == "T")
		data = &T;
	else if(id == "AC")
		data = &CA;
	else if(id == "GC")
		data = &CG;
	else if(id == "TC")
		data = &CT;
	else if(id == "CC")
		data = &CC;
	else if(id == "C")
		data = &C;
	else if(id == "A")
		data = &A;
	else if(id == "G")
		data = &G;
	else if(id == "T")
		data = &T;
	else if(id == "C")
		data = &C;
	else if(id == "AAAmount")
		data = &AAAmount;
	else if(id == "GAAmount")
		data = &AGAmount;
	else if(id == "TAAmount")
		data = &ATAmount;
	else if(id == "CAAmount")
		data = &ACAmount;
	else if(id == "AAmount")
		data = &AAmount;
	else if(id == "AGAmount")
		data = &GAAmount;
	else if(id == "GGAmount")
		data = &GGAmount;
	else if(id == "TGAmount")
		data = &GTAmount;
	else if(id == "CGAmount")
		data = &GCAmount;
	else if(id == "GAmount")
		data = &GAmount;
	else if(id == "ATAmount")
		data = &TAAmount;
	else if(id == "GTAmount")
		data = &TGAmount;
	else if(id == "TTAmount")
		data = &TTAmount;
	else if(id == "CTAmount")
		data = &TCAmount;
	else if(id == "TAmount")
		data = &TAmount;
	else if(id == "ACAmount")
		data = &CAAmount;
	else if(id == "GCAmount")
		data = &CGAmount;
	else if(id == "TCAmount")
		data = &CTAmount;
	else if(id == "CCAmount")
		data = &CCAmount;
	else if(id == "CAmount")
		data = &CAmount;
	else if(id == "AAmount")
		data = &AAmount;
	else if(id == "GAmount")
		data = &GAmount;
	else if(id == "TAmount")
		data = &TAmount;
	else if(id == "CAmount")
		data = &CAmount;
	else return NULL;

	return data;
}
