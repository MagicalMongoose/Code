#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
	private:
		int month;
		int day;
		int year;

	public:
		void setDate(int m, int d, int y)
		{
			month = m;
			day = d;
			year = y;
		};
		void displayDate()
		{
			cout << month << "/" << day << "/" << year;
		}; 
};
#endif
