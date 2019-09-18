/****************************************************************************
  FileName     [ p2Json.h]
  PackageName  [ p2 ]
  Synopsis     [ Header file for class Json JsonElem ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#ifndef P2_JSON_H
#define P2_JSON_H

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class JsonElem
{
public:
   // TODO: define constructor & member functions on your own
   JsonElem() {}
   JsonElem(const string& k, int v): _key(k), _value(v) {}

   const string& getKey() const;
   int getValue() const;
   friend ostream& operator << (ostream&, const JsonElem&);

private:
   string  _key;   // DO NOT change this definition. Use it to store key.
   int     _value; // DO NOT change this definition. Use it to store value.
};

class Json
{
public:
   // TODO: define constructor & member functions on your own
   enum class command {SUM, AVE, MAX, MIN};
   bool read(const string&);
   void print();
   int sum();
   float average();
   const JsonElem& get_max();
   const JsonElem& get_min();
   void add(string&, int);
   string print_max();
   string print_min();
   bool isValid();
   bool interface(string);

private:
   vector<JsonElem>       _obj;  // DO NOT change this definition.
                                 // Use it to store JSON elements.
};

#endif // P2_TABLE_H
