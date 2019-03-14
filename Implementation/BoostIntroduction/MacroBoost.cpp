#include <iostream>
#include <vector>
#include <boost/current_function.hpp>
#include <boost/foreach.hpp>
#include <boost/static_assert.hpp>
#include <boost/detail/lightweight_test.hpp>

using namespace std;

# define MY_NUM 1300

// BOOST_CURRENT_FUNCTION used to return function name and its input and
// output variables types
void testMacroa(){
	cout << "You have called: " << BOOST_CURRENT_FUNCTION << endl;
}

// BOOST_STATIC_ASSERT generates a compile time error message, if the input
// expression is FALSE
void testMacrob(){
	BOOST_STATIC_ASSERT(MY_NUM!=1400);
}

// BOOST_FOREACH replaces the tedious iteration over containers.
void testMacroc(){
	vector<double> myVec(10);

	// reference on the variable x. Do something with x.
	BOOST_FOREACH(double &x, myVec) x = 10.0;
	BOOST_FOREACH(double x, myVec) cout << x << endl;
}

void testMacrod(){
	// prints an error message with the name and the location of the error
	BOOST_ERROR("Failure of this function");

	// tests if the supplied condition is true and prints an error otherwise
	double x = 0.0;
	BOOST_TEST(x!=0);
}



int main(){
    testMacroa();
    testMacrob();
    testMacroc();

	Preturn 0;
}
