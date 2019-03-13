#include <iostream>
#include "ext.cpp"
#include <ql/quantlib.hpp>


using namespace QuantLib;
using namespace std;

// Date, Calendar Classes and Day Counters

// Part 1: Date
// Date Initialization - Example by Dimitri Reiswich
void DateTesting1 (){
	Date myDate (12 , Aug ,2009);
	std :: cout << myDate << std :: endl ;
	myDate ++;
	std :: cout << myDate << std :: endl ;
	myDate +=12* Days ;
	std :: cout << myDate << std :: endl ;
	myDate -=2* Months ;
	std :: cout << myDate << std :: endl ;
	myDate --;
	std :: cout << myDate << std :: endl ;
	Period myP (10 , Weeks );
	myDate += myP ;
	std :: cout << myDate << std :: endl ;
}

// Example by Thanh Nguyen Minh
void DateTesting2(){
	// Date type
	Date myDate(13, Mar, 2019);
	cout << myDate << endl;
	// Operator for Date object
	myDate++;
	cout << myDate << endl;

	// Operator with Days type
	myDate+= 12*Days;
	cout << myDate << endl;

	// Period object
	Period myP(6, Weeks);

	myDate += myP;
	cout << myDate << endl;
}

// Date member function - Example by Dimitri Reiswich
void DateTesting3(){
	Date myDate(12, Aug, 2009);
	cout << "Original Date: " << myDate << endl;

	cout << "Weekday is: " << myDate.weekday() << endl;
	cout << "Day of the month: " << myDate.dayOfMonth() << endl;
	cout << "Day of the year: " << myDate.dayOfYear() << endl;
	cout << "Month is:" << myDate.month() << endl;

	// extract month from "myDate" object
	int month = myDate.month();
	cout << "Integer month is: " << month << endl;

	// extract day from "myDate" object
	int year = myDate.year();
	cout << "Integer year is: " << year << endl;

	int serialNum = myDate.serialNumber();
	cout << "Serial number is: " << serialNum << endl;

}

// Date class static function - Example by Dimitri Reiswich
void DateTesting4(){
	cout << "Today date is: " << Date::todaysDate() << endl;
	cout << "Min date in QuantLib is: " << Date::minDate() << endl;
	cout << "Max date in QuantLib is: " << Date::maxDate() << endl;
	cout << "Is 2019 a leap year: " << Date::isLeap(2019) << endl;
	cout << "End of month August 2019: " << Date::endOfMonth(Date(14,Mar,2019)) << endl;
	cout << "Next WD friday of 13/3/2019 is: " << Date::nextWeekday(Date(13,Mar,2019), Friday) << endl;
	cout << "3rd Wednesday of March 2019 is: " << Date::nthWeekday(3, Wed, Mar, 2019) << endl;
}

// Evaluation date - Example by Dimitri Reiswich
void DateTesting5(){
	// Current Evaluation Date - evaluation date stored in Settings::instance().evaluationDate()
	Date d = Settings::instance().evaluationDate();
	cout << "Evaluation date is: " << d << endl;

	//Setting New Evaluation Date
	Settings::instance().evaluationDate() = Date(5,Jan,2018);
	d = Settings::instance().evaluationDate();
	cout << "New Evaluation date is: " << d << endl;
}

// Calendar for the respective country - Example by Dimitri Reiswich
void CalendarTesting1(){
	Calendar frankfurtCal = Germany(Germany::FrankfurtStockExchange);
	Date newyear = Date(31,Dec, 2019);

	cout << "Is BD: " << frankfurtCal.isBusinessDay(newyear) << endl;
	cout << "Is Holiday: " << frankfurtCal.isHoliday(newyear) << endl;
	cout << "Is end of the month: " << frankfurtCal.isEndOfMonth(newyear) << endl;
	cout << "Last Business Days: " << frankfurtCal.endOfMonth(newyear) << endl;

}

// Member function of Calendar
void CalendarTesting2(){
	Calendar Arab = SaudiArabia();
	Date d1(24,Dec, 2019), d2(30, Dec, 2019), d3(31,Dec,2019);

	Arab.addHoliday(d2);
	Arab.removeHoliday(d3);

	cout << "Is Business Day: " << Arab.isBusinessDay(d2) << endl;
	cout << "Is Business Day: " << Arab.isBusinessDay(d3) << endl;

	// d1 = datefrom, d2 = dateto
	vector<Date> holidayVec = Arab.holidayList(Arab, d1, d2, false);
	cout << "________" << endl;

}

int main()
{
	CalendarTesting2();
	return 0;
}
