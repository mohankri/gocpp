#include <iostream>

using namespace std;

/*
 * :: = Scope Resolution Operator
 */
/*
 * default access specified in struct is public.
 */

struct HelloStruct {
	void printHello();	
};

void
HelloStruct::printHello() {
}

/*
 * default access specifier in class is private.
 *
 */
class Constructor {
	public:
		Constructor();
		Constructor(int val);
		void AccessFunction();
	protected: /* subclass can access protected member */
		int  input;
		void pHello();
		void pthis(Constructor *obj);
	private:  /* subclass can't access private member */
		void printHello();
};

Constructor::Constructor() {
	cout << "Hello from Constructor " << "\n";
}

Constructor::Constructor(int val) {
	cout << "Testing Delegated Constructor " << "\n";
	input = val;
}

void
Constructor::pthis(Constructor *obj)
{
	cout << "Calling pHello again " << "\n";
	obj->pHello();
}

void
Constructor::printHello() {
	cout << "print Hello private member " << "\n";
}

void
Constructor::AccessFunction() {
	cout << "Access Function " << "\n";
	printHello();
	pHello();
	pthis(this);
}

void
Constructor::pHello() {
	cout << "Printing Hello from class object protected member " << "\n";
}

int
main()
{
	/* Object on Stack , construct will be called at  point of declaration */
	Constructor stCons;
	stCons.AccessFunction();  /* . operator with Stack Based Object */

	/* Object on heap, constructor not called at point of declaration */
	Constructor *hCons = nullptr ; 

	/* Object on Heap */
	Constructor *heapCons = new Constructor(); 
	/* can also be called like (*heapCons).AccessFunction */
	heapCons->AccessFunction(); 
	delete(heapCons);
	heapCons = nullptr;

	/* Stack Based Array to invoke individual constructor */
	cout << "Stack Based Array Constructor " << "\n";
	Constructor sHello[3] = {Constructor(), Constructor(), Constructor()};
}
