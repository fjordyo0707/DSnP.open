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
   string sUserCommand;

   while (true) {
      cout << "Enter command: ";
      cin >> sUserCommand;
      bool exit = json.interface(sUserCommand);
      // string other_key = "Frank";
      // int other_value = 1000;
      // json.add(other_key, other_value);
      // json.print();
      // cout << " sum is " << json.sum() << endl;
      // cout << " ave is " << fixed <<  setprecision(1) << json.average() <<endl;
      // cout << json.print_min() << endl;
      // cout << json.print_max() << endl;
      if (exit)
		      break;
   }
}
