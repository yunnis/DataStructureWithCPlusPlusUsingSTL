#ifndef D_DATE_H_INCLUDED
#define D_DATE_H_INCLUDED
#include <iostream>
#include "d_except.h"
class date
{
public:
	date(int mm = 1, int dd = 1, int yy = 1900);
	int daysInMonth();
	int getYear();
	int getMonth();
	bool isLeapYear();
	int numberOfDays();
	void setMonth(int mm);
	void setYear(int yy);
};


#endif // D_DATE_H_INCLUDED
