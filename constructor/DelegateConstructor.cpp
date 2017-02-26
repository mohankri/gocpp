#include <iostream>

using namespace std;

class DeletegateCell {
	public:
		DeletegateCell() = default;
		DeletegateCell(int d);
};

DeletegateCell::DeletegateCell(int d)
{

}

class DelegateConstructor {
	public:
		DelegateConstructor() = delete; /* default constructor not supported */
		DelegateConstructor(int val);
		DelegateConstructor(int val, int data);
	protected:
		int data;
		string str; /* initialize by ctor initializer */
		DeletegateCell cell;
		string name="testing c++";  /* In-Class Member Initializers, to avoid ctor initialization */
};

/* default constructor is marked as delete */
/*
DelegateConstructor::DelegateConstructor() {
	cout << "DelegateConstructor " << "\n";
}
*/

/*
DelegateConstructor::DelegateConstructor(int val):str("Hello"), cell(4) {
	cout << "Value " << val << "\n";
	cout << "String " << str << "\n";
} */

DelegateConstructor::DelegateConstructor(int val, int data)
{
	cout << "Invoked from delegation " << val << " " << data << "\n";
	cout << "Name " << name << "\n";
}

DelegateConstructor::DelegateConstructor(int val)
			: DelegateConstructor(val, 5) {
}

int
main()
{
	//DelegateConstructor dCons;
	DelegateConstructor dCons1(4);
	
}
