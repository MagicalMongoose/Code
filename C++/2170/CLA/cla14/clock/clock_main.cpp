#include <iostream>
#include "clock.h"
#include "clock.cpp"
using namespace std;

int main()
{
    //Declare two Clock objects
    Clock myClock, newClock;
   
    //Set the time of myClock to 12:45:30 AM.
    myClock.setClock(12, 45, 30, "AM");
  
    //Set the time of the newClock object to 2:15:30 pm.
    newClock.setClock (2, 15, 30, "PM"); 
   
    //Display the time of myClock in both standard and military format
    cout << "The time on the Digital Clock (in standard form) is: ";
    myClock.displayStandard(); 
    cout << endl;
                                            
    cout << "The time in military format is: ";
    myClock.displayMilitary(); 
    cout << endl;
                                                       
    //Set the two times to the same time
    //myClock = newClock;

    //Display the time of myClock in both standard and military format
    cout << "The time on the Digital Clock (in standard form) is: ";
    newClock.displayStandard(); 
    cout << endl;
                                             
    cout << "The time in military format is: ";
    newClock.displayMilitary(); 
    cout << endl;
    
    return 0; 
}
    
