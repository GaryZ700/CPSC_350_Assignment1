/* Gary Zeri
   ID: 2321569 
   zeri@chapman.edu
   CPSC 350-02
   Assignment 1
*/

#ifndef USER_INPUT_H_
#define USER_INPUT_H_

#include<fstream>
#include<iostream>
#include<climits>

using namespace std;

//Header file for the input class which is used to manage all input between the user 
//and the application to safeguard against user error and possible errors that may occur
//Further Documentation of Methods inlucded in the intput.cpp file

class UserInput{

	public:
	    UserInput();
	    bool GetBool(string msg="Please choose an option: ", string trueOption="True", string falseOption="False", string errorMsg="Please enter only '1' or '2' to choose an option.");
	    int GetInt(string msg="Please enter an integer: ", string error_msg = "Warning!! Please enter an Integer: ");
	    string GetStr(string msg = "Please enter a text response: ");
	    fstream GetFile(string msg="Please enter a file name: ", string error_msg="Invalid File Name! Please enter a new file name: ", ios::openmode mode=ios::in|ios::out);
		
	private:
		void GetLine(string& inputString);
		void CinUpdate();	  
};

#endif //USER_INPUT_H_
