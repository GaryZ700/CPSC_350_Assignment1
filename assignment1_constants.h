/* Gary Zeri
   ID: 2321569 
   zeri@chapman.edu
   CPSC 350-02
   Assignment 1
*/

//This header files defines several constant strings as error messages to be used in Assignment 1

#ifndef ERROR_CODES_H_
#define ERROR_CODES_H_

#include <iostream>
#include <exception>

using namespace std;

const string kWorkspaceFilename = "._assignment1_workspace_file_.dat"; 

const string kOutFileHeader = "Gary Zeri\nID: 2321569\nzeri@chapman.edu\nCPSC350-02\nAssignment 1\n";

const string kQuitOrNewFile = "Please enter 1 to input a new file name, or press any other key to terminate the program: ";

const string kNoCmdLineArg = "\n\nWhoa whoa whoa!! What do you think you're doing?!?! One does not simply run Assignment 1 in CPSC 350 without passing in a command line argument! \n\n *Phew* Let's try this again? You know, for most people I would I simply would have SEGMENTATION_FAULT_CORE_DUMPED. But you know what? \n\n I like you, I think you're a nice guy, and you know what I'm going to do for you? I'm going to handle this gracefully, (as much as it may hurt my virtual pride), and I'm going to let you give a file name here and now. \n\n Please enter a file name for a file containing DNA data: ";

const string kBadFileName = "Gosh Darn It....I just blew up a memory register...you really need to be mroe careful with file names ya' know. Let's try this again..., what is the name of a VALID and EXISTING file containing DNA data? \n Please enter the file name below: "; 

const string kBadDnaFileFormat = "Holy Greasy Bacon Smokes and Mother of Flying Potbelly Pigs! \nYour DNA File is Incorrectly Formatted.\nThe error is on line ";

const string kCompleteAnalysis = "YEE-YAW Pard'ner!! Your computation's been completed! Time to celebrate with a good 'ol fashioned Barn Raising and square dance!\n What's the next step?";

const string kFortune = "Dear Valued User,\n We would like to take the time ot thank you for your interest in this software and offer you a FREE** Limited Edition Digital Fortune Cookie!! Please see your fortunue below!\n\n(**Physical Fortune Cookie Sold Separately.)\n\nYour Complimentary Fortune: There will many SEGMENTATION_FAULT_CORE_DUMPEDs in your future.\n\n";

const string kRerunFileAsk = "(: YAY!! You're back!! :) It gets soooooo lonely being a C++ Terminal Application. Nobody wants to execute you becuase you're too \"retro\" and its \"hard\" to use a command line. But at least you're back!!!\n Now, just enter in the name of a DNA file to parse and I'll analyze it and append it onto the output file.";
#endif //ERROR_CODES_H_
