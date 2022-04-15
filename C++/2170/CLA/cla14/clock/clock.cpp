//File:	   inlab6a.cpp
//
//This file includes the implementation section for the Clock class.

#include <iostream>     //contains cin & cout
#include "clock.h"      //contains the definition of the Clock class
using namespace std;

//Function:  setClock() 
//Purpose:   This function assigns the time specified by the user.
//           No error checking is done to check for illegal dates.
//           Arguments include the hour (h), minute (m), second(s)
//           and AmOrPm (means AM and PM).
void Clock::setClock(int h, int m, int s, string AmOrPm) 
                     //IN      IN      IN     IN
{
    //hour, minute, second and meridian are private data members
    hour = h;
    minute = m;
    second = s;
    meridian = AmOrPm;
}


//Function:	displayStandard()
//Purpose:	This function displays the clock time in standard format.
//
//Assumption:	The time has been assigned a valid value.
void Clock::displayStandard()
{
     cout <<  hour << ':' << minute << ':' << second << ' ' << meridian;
}

//Function:	displayMilitary()
//Purpose:	This function displays the time in military format.
//
//Assumption:	The Clock has been assigned a valid value.
void Clock::displayMilitary()
{
     int militaryHour = hour;
  
     //if it is pm and it isn't 12:00 noon, then add 
     //12 hours to the time
     if (meridian == "PM" && hour != 12)
          militaryHour += 12;

     //if it is 12:00 midnight, then subtract 12 hours
     if (meridian == "AM" && hour == 12)
          militaryHour -= 12;

     cout << militaryHour << ':' << minute <<  ':' << second;		  
}
