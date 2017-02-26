#include <iostream>

using namespace std;

class DataMembers {
	public:
		int GetDataMembers();
		static int testStaticMethod(); // Static Method
		int testConstMethod() const; // Const Method 
		static int counter1; // counter1 = 0 allowed in c++11.
		int testInlineWithin () const { return data; }; // inline data member
		int testInlineOutside () const;
	protected:
		static int counter; // counter = 0 allowed in c++11.
		static const int maxwidth = 100; // still at class level but can't be changed. 
		int data = 0;
		mutable int numAccess = 0; // if you really need to modify data member in Const Method.
};

/* 
 * Static Data Members where you don't want to keep a copy of varible for 
 * each object. Static allows it to specific to be at class level.
 */
int DataMembers::counter = 0;  /* it's pre C++11 */
int DataMembers::counter1 = 0;  /* it's pre C++11 */

int
DataMembers::GetDataMembers()
{
	data++;
	return counter++;
}

/*
 * Static Method can't touch data members of an object.
 * Use it for some calculation/conversion that doesn't require object data.
 * example convert number to string.
 */
int
DataMembers::testStaticMethod()
{
	//return data;  not allowed.
	return 100;  
}

int
DataMembers::testConstMethod() const
{
	// data = 0; not allowed
	numAccess++; // allowed because it's defined as mutable.
	return data;
}

inline int DataMembers::testInlineOutside() const 
{
	return data;
}

int
main()
{
	DataMembers data;
	DataMembers data1;
	cout << data.GetDataMembers() << "\n";
	cout << data1.GetDataMembers() << "\n";
	cout << DataMembers::counter1 << "\n";
	cout << data.testStaticMethod() << "\n";
	cout << data.testConstMethod() << "\n";
	
	cout << "Test Inline " << "\n";
	cout << data.testInlineOutside() << "\n";
	cout << data.testInlineWithin() << "\n";
}
