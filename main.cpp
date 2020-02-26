/* Gary Zeri
   ID: 2321569 
   zeri@chapman.edu
   CPSC 350-02
   Assignment 1
*/

#include "user_input.h"
#include "assignment1_constants.h"
#include "dna_analyzer.h"
#include "helpful_methods.h"

using namespace std;

//Define All Functions Here
void PrintOutputFile(DnaAnalyzer dnaStats);

/*Main Function 
  argc: int that represent the size of the argv array
  argv: c string array that contains the name of the program and command line parameters
*/
int main(int argc, char* argv[]){
	
	string fileName;
	fstream inputFile;
	UserInput input;
	
	do{
		DnaAnalyzer dnaStats;
		
		//Check to ensure the user has inputted a file name to open 
		//And if a file name has been provided, ensure the file name is valid
		if(argc == 1)
			 inputFile = input.GetFile(kNoCmdLineArg, kBadFileName, ios::in); 
		else if(argc < 0)
			inputFile = input.GetFile(kRerunFileAsk, kBadFileName, ios::in);
		else
			 inputFile.open(argv[1]);
			 
		//Compute the statistics from the DNA File
		//and checks whether or not the dna data has been inputted correctly
		while(!dnaStats.ParseFile(inputFile)){
		
			//Prompt User whther to input new file name or quit 
			//if the dna file was formatted incorrectly			
			if(input.GetStr(kQuitOrNewFile) == "1")
				inputFile = input.GetFile(kNoCmdLineArg, kBadFileName, ios::in);
			else
				inputFile.close();
				return 0;			
		}	

		inputFile.close();

		PrintOutputFile(dnaStats);
		
		//Used to tell the program that it should be expecting any command line arguments
		argc=-1;

	} while(input.GetBool(kCompleteAnalysis,"Reurn Another Computation", "Quit the Program"));

	cout << endl << endl << kFortune;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////

/*PrintOutputFile Function 
  Prints an output file with all the statistics gnerated by the Dna_Analyzer Class
*/
void PrintOutputFile(DnaAnalyzer dnaStats){

	fstream outFile;

	if(!HelpfulMethods::FileExists("garyzeri.out")){
		outFile.open("garyzeri.out", ios::out);
		outFile << kOutFileHeader;
	}	
	else
		outFile.open("garyzeri.out", ios::app);

	outFile << endl << endl;

	outFile << dnaStats.OutputString();

	outFile << endl << endl << "1,000 DNA Strings Following the Statistics Above" << endl << endl;
	
	outFile << dnaStats.GenerateDna(1000); 

	outFile.close(); 		
}
