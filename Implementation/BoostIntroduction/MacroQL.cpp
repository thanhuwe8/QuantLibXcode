#include <iostream>
#include "ext.cpp"
#include <ql/quantlib.hpp>


using namespace QuantLib;
using namespace std;

// Part 0: Important Macros for QuantLib

// 1. Exceptional handling with QL_REQUIRE
void testingMacros1(){
	double x = 0.0;
	QL_REQUIRE(x!=0, "Zero number!");
}

void testingMacros2(){
	QL_FAIL("Failed!");
}


// 2.

int main()
{
	try{
		testingMacros1();
		testingMacros2();

	} catch (std::exception& e){
		cout << e.what() << endl;
	} catch (...){
		cout << "unknown error" << endl;
		return 1;
	}
}
