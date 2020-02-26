/* Gary Zeri
   ID: 2321569 
   zeri@chapman.edu
   CPSC 350-02
   Assignment 1
*/

//Helpful Methods class that contains very useful methods that do not particluary fit well into another class that currently exists for this project

#ifndef HELPFUL_METHODS_H_
#define HELPFUL_METHODS_H_

#include<iostream>
#include<fstream>

using namespace std;

class HelpfulMethods{

	public:
		static string LowerString(string str);
		static string UpperString(string str);
		static bool FileExists(string fileName);
	private:
		static string ModifyString(string str, int (*modifier)(int));
};

#endif //HELPFUL_METHODS_H_
