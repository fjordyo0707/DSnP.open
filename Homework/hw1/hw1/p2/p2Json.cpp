/****************************************************************************
  FileName     [ p2Json.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define member functions of class Json and JsonElem ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
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
	   cout<<line<<endl;
	   line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
	   if(line=="{" || line=="}" || line=="")
	   	continue;
	   line.erase(remove(line.begin(), line.end(), ','), line.end());
	   line.erase(remove(line.begin(), line.end(), '"'), line.end());
	   string delimeter = ":";
	   string token = line.substr(0, line.find(delimeter));
	   cout<< token << endl;
	   string value = line.substr(line.find(delimeter)+1);
	   cout<< value << endl;

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

int Json::get_max_index(){
	int max_index = 0;
	for(int i = 0; i < _obj.size() ; ++i){
		if (_obj[i].getValue() > _obj[max_index].getValue())
			max_index = i;
	}
	return max_index;
}

int Json::get_min_index(){
	int min_index = 0;
	for(int i = 0; i < _obj.size() ; ++i){
		if (_obj[i].getValue() < _obj[min_index].getValue())
			min_index = i;
	}
	return min_index;
}

const JsonElem& Json::max(){
	return _obj[get_max_index()];
}

const JsonElem& Json::min(){
	return _obj[get_min_index()];
}

bool Json::isValid(){
	if (_obj.size() == 0 )
		return false;
	else
		return true;
}

const string& JsonElem::getKey() const
{
	return _key;
}

int JsonElem::getValue() const
{
	return _value;
}


