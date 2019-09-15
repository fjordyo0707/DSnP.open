/****************************************************************************
  FileName     [ p2Main.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define main() function ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2016-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
#include <string>
#include "p2Json.h"
#include <iomanip>

using namespace std;

int main()
{
   Json json;

   // Read in the csv file. Do NOT change this part of code.
   string jsonFile;
   cout << "Please enter the file name: ";
   cin >> jsonFile;
   if (json.read(jsonFile))
      cout << "File \"" << jsonFile << "\" was read in successfully." << endl;
   else {
      cerr << "Failed to read in file \"" << jsonFile << "\"!" << endl;
      exit(-1); // jsonFile does not exist.
   }

   // TODO read and execute commands
   // cout << "Enter command: ";
   string sUserCommand = "Nothing";
   bool  bExit;
   while (true) {
      // cout << "Enter command: ";
      json.print();
      cout << " sum is " << json.sum() << endl;
      cout << " ave is " << fixed <<  setprecision(1) << json.average() <<endl;
      cout << json.max().getValue() << endl;
      cout << json.min().getValue() << endl;
      break;
   }
}
