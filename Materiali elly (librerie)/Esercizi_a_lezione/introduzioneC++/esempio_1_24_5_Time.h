#ifndef ESEMPIO_1_24_5
#define ESEMPIO_1_24_5

#include <iostream>

// Time abstract data type (ADT) definition
class Time {
 public:
  Time(); //constructor
  void setTime( int, int, int ); //set hour, minute, second
  void print24H(); //print 24H time format
  void printStandard(); //print standard time format
 private:
  int hour; // 0 - 23
  int minute; // 0 - 59
  int second; // 0 - 59
};

#endif

