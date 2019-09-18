/****************************************************************************
  FileName     [ p2Json.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define member functions of class Json and JsonElem ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include "p2Json.h"
#include <algorithm>

using namespace std;

// Implement member functions of class Row and Table here
bool
Json::read(const string& jsonFile)
{
   fstream read;
   read.open(jsonFile, ios::in);
   string line;

   while(getline(read, line)){
	   line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
	   if(line=="{" || line=="}" || line=="")
	   	continue;
	   line.erase(remove(line.begin(), line.end(), ','), line.end());
	   line.erase(remove(line.begin(), line.end(), '"'), line.end());
	   string delimeter = ":";
	   string token = line.substr(0, line.find(delimeter));
	   string value = line.substr(line.find(delimeter)+1);

	   const JsonElem tempJsonElem(token, stoi(value));
	   _obj.emplace_back(tempJsonElem );
   }

   return true; // TODO
}

ostream&
operator << (ostream& os, const JsonElem& j)
{
   return (os << "\"" << j._key << "\" : " << j._value);
}

void
Json::print()
{
	cout<<"{"<<endl;
	for(auto it = _obj.begin(); it != _obj.end(); ++it){
		cout<<"  ";
		cout << '"'<<it->getKey() << '"' << " : ";
	       	if (next(it) ==_obj.end())
			cout << it->getValue() << endl;
		else
			cout << it->getValue() << "," <<endl;
	}
	cout<<"}"<<endl;
}

int
Json::sum(){
	int summation = 0;
	for(const auto & item : _obj){
		summation = summation + item.getValue();
	}
	return summation;
}

float
Json::average(){
	return (float)(sum()) / _obj.size();
}

const JsonElem& Json::get_max(){
	int max_index = 0;
	for(int i = 0; i < _obj.size() ; ++i){
		if (_obj[i].getValue() > _obj[max_index].getValue())
			max_index = i;
	}
	return _obj[max_index];
}

const JsonElem& Json::get_min(){
	int min_index = 0;
	for(int i = 0; i < _obj.size() ; ++i){
		if (_obj[i].getValue() < _obj[min_index].getValue())
			min_index = i;
	}
	return _obj[min_index];
}

string Json::print_max(){
	const JsonElem& temp_max = get_max();
	string format_max = "{ \"" + temp_max.getKey() + "\" : " + to_string(temp_max.getValue()) + " }";
	return format_max;
}


string Json::print_min(){
	const JsonElem& temp_min = get_min();
	string format_min = "{ \"" + temp_min.getKey() + "\" : " + to_string(temp_min.getValue()) + " }";
	return format_min;
}

bool Json::isValid(){
	if (_obj.size() == 0 )
		return false;
	else
		return true;
}

void Json::add(string& temp_key, int temp_value){
	const JsonElem temp_element(temp_key, temp_value);
	_obj.emplace_back(temp_element);
}

const string& JsonElem::getKey() const
{
	return _key;
}

int JsonElem::getValue() const
{
	return _value;
}

bool Json::interface(string command){
	bool exit = false;

	bool valid = isValid();
	if (!valid && !( command == "ADD" || command == "PRINT")  ){
		cout << "Error: No element found!!"<<endl;
		return exit;
	}


	if(command == "SUM"){
		cout << "The summation of the values is : "<<sum()<<"."<<endl;
	} else if(command == "AVE"){
		cout << "The average of the values is: ";
		cout << fixed << setprecision(1) << average()<<"."<<endl;

	} else if(command == "MAX"){
		cout << "The maximum element is: " << print_max();
		cout << "." << endl;
	} else if(command == "MIN"){
		cout << "The minimum element is: " << print_min();
		cout << "." << endl;
	} else if(command == "ADD"){
		string add_key;
		int add_value;
		cin >> add_key >> add_value;
		add(add_key, add_value);
	} else if(command == "EXIT"){
		exit = true;
	} else if(command == "PRINT"){
		print();
	};

	return exit;
}
