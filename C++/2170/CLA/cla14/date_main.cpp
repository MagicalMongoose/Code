#include <iostream>
#include "date.h"
using namespace std;

int main()
{
    //Declare two Date objects
    Date myDate, newDate;
	
    //Set the time of myDate to 11/30/2001.
    myDate.setDate(11, 30, 2001);

    //Set the time of the newDate object to 5/31/2024.
    newDate.setDate (5, 31, 2024);

    //Display birthdate
    cout << "My birthday is: ";
    myDate.displayDate();
    cout << endl;

    cout << "My graduation date is: ";
    newDate.displayDate();
    cout << endl;

    return 0;
}
