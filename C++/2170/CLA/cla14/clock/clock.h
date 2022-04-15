//File:	   inlab6a.h
//
//This file contains the Clock class definition section.

//Eliminate the problem of multiple inclusions
#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
using namespace std;

//The Clock class definition starts here.
class Clock
{
  private:
     //declarations of data members that are private
     int hour;           //an hour in the range 1 - 12
     int minute;         //a minute in the range 0 - 59
     int second;         //a second in the range 0 - 59
     string meridian;    // AM or PM 

  public:
     //function prototypes of member functions (methods)

     //Set the clock to the specified time
     void setClock (int h, int m, int s, string mer);

     //Display the time in standard notation 
     void displayStandard();

     //Display the time in military notation
     void displayMilitary();
};
//The Clock class definition ends with the closing brace and semicolon.
#endif
