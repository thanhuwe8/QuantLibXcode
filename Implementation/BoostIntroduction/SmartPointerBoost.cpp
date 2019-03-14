#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>

using namespace std;

class A{

private:

	double myValue_;

public:

	A(const double& myValue):myValue_(myValue){
		cout << "Constructor of A" << endl;
	}

	~A(){
		cout << "Destructor of A" << endl;
	}

	// const after function makes a compiler error for the class function to change a
	// member variable of the class. Reading of a class variables is okay inside the function
	// , but writing inside the function will generate a compiler error.
	double getValue() const {return myValue_;}
};

// standard pointer by C++
void testSharedptrA(){
	A* ptr_myA = new A(1.0);
	delete ptr_myA;
}

void testSharedptrA2(){
	A* ptr_myA = new A(1.0);
	throw "Error occured for class A";
	//delete ptr_myA;
}

// using smart pointer by BOOST library
void testSharedPtr(){
	boost::shared_ptr<A> bptr_myA(new A(1.0));

	A* ptr_myA2 = new A(1.0);
	boost::shared_ptr<A> bptr_myA2(ptr_myA2);

	// smart pointer could be used with arrow operator.
	cout << bptr_myA2->getValue() << endl;
}

void testSharedPtr2(){
	boost::shared_ptr<A> bptr_myA(new A(1.0));
	throw "Error occured for class A";
}

void testSharedPtr3(){

	boost::shared_ptr<A> bptr_myA(new A(1.0));
	bptr_myA.reset(new A(2.0));
}



int main(){
	// A is destroyed at the end of function
	testSharedptrA();

	// A is not destroyed at the end of function
	testSharedptrA2();

	// A is destroyed with smart pointer
	testSharedPtr();

	// A is detroyed before error happened.
	testSharedPtr2();

	// first object is destroyed when it points to other object.
	testSharedPtr3();

    return 0;
}
