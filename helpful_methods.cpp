/* Gary Zeri
   ID: 2321569 
   zeri@chapman.edu
   CPSC 350-02
   Assignment 1
*/

#include "helpful_methods.h"

using namespace std;

/*LowerString Function
  str: String that is to be lowercased
*/
string HelpfulMethods::LowerString(string str){
	return ModifyString(str, (int (*)(int))tolower);		
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*UpperString Function
  str: String that is to be uppercased
*/
string HelpfulMethods::UpperString(string str){
	return ModifyString(str, (int (*)(int))toupper);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

string HelpfulMethods::ModifyString(string str, int (*modifier)(int)){
	
	string newStr = "";
	
	for(int i=0; i<str.size(); ++i){
		newStr += modifier(str.at(i));
	}	
	
	return newStr;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*FileExists Function 
  fileName: string of file name to check for existance 
*/
bool HelpfulMethods::FileExists(string fileName){

		fstream file(fileName, ios::in);

		bool existance = file.is_open();

		file.close();
		
		return existance;
}
