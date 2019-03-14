#include <iostream>
#include "ext.cpp"
#include <ql/quantlib.hpp>


using namespace QuantLib;
using namespace std;

// Date, Calendar Classes and Day Counters

// Part 3: DayCounter
// Date Initialization - Example by Dimitri Reiswich

void dayCounterTesting1(){
	DayCounter dc = Thirty360();
	Date d1(1,Oct,2009);
	Date d2 = d1 + 2*Months;

	cout << "Days between d1/d2 is: " << dc.dayCount(d1,d2) << endl;
	cout << "Year Fraction d1/d2 is: " << dc.yearFraction(d1,d2) << endl;


}

// Part 4: DateGeneration class


int main()
{
	dayCounterTesting1();
	return 0;
}
