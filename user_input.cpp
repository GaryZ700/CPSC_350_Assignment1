/* Gary Zeri
   ID: 2321569 
   zeri@chapman.edu
   CPSC 350-02
   Assignment 1
*/

#include "user_input.h"

using namespace std;

UserInput::UserInput(){}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Public Methods Defined Here

/*GetBool Function 
  return a bool based on user input
  msg: String to prompt the user with
  trueOption: String to display to the user for the true option
  falseOption: String to display to the user for the false optoin
  errorMsg: String to display the user if they enter an incorrect input
*/
bool UserInput::GetBool(string msg, string trueOption, string falseOption, string errorMsg){

	int input;

	cout << msg << endl;
	cout << "\t" << "1. " << trueOption << endl;
	cout << "\t" << "2. " << falseOption << endl << endl;
	
	cin >> input;

	while(!cin || (input != 1 && input != 2) ){

		cout << errorMsg << endl;
		CinUpdate();
		cin >> input;
		cout << input << endl;
	}
	
	if(input == 1)
		return true;
	else 
		return false;
	
} 

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*GetInt Function 
  return the int the user inputted
  msg: string to prompt the user with 
  error_msg: string to display the user if the incorrect input is provided
*/
int UserInput::GetInt(string msg, string error_msg){

	int input;

	cout << msg; 
	
	cin >> input;

	//do while loop to ensure the user inputs the correct data type being requested		
	while(!cin){
		cout << error_msg << endl;

		CinUpdate();
		cin >> input;
	};

	return input;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*GetStr Function 
  return the string the user inputted
  msg: string to prompt the user with 
*/
string UserInput::GetStr(string msg){

	string input; 

	cout << msg;
	
	getline(cin, input);

	cout << endl;

	return input;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*GetFile Function 
  returns an fstream with an open file that the user provided
  msg: string of a message to display to the user to get a file name
  error_msg: string of a message to display to the user if the file name is invalid  
  mode: openmode that represents the mode that the file should be opened in 
*/

fstream UserInput::GetFile(string msg, string error_msg, ios::openmode mode){
	
	string fileName;
	fstream file;	

	cout << msg; 
	GetLine(fileName);
	cout << endl;
	
	file.open(fileName, mode);
	
	//check to ensure that the file is open
	//if not, keep asking the user until a correct file name is provided
	while(!file.is_open()){
		cout << error_msg;
		GetLine(fileName);
		file.open(fileName);
	}

	return file;
}


//----------------------------------------------------------------------------------

/*GetLine Function 
  Wrapper Function for the getline function used with cin 
  inputString: reference to string outside function scope whose value should modified by getline
*/
void UserInput::GetLine(string& inputString){
	getline(cin, inputString);
} 

//----------------------------------------------------------------------------------

void UserInput::CinUpdate(){
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

////////////////////////////////////////////////////////////////////////////////////
