#include <iostream>

using namespace std;

class CopyConstructorAssignObject {
	protected:
		int data;
	public:
		CopyConstructorAssignObject() = default;
		CopyConstructorAssignObject(int d);
		/* Copy Constructor Declartion */
		CopyConstructorAssignObject(const CopyConstructorAssignObject& src);

		/* Assignment Operator declaration */
		CopyConstructorAssignObject& operator=(const CopyConstructorAssignObject& rhs);
		int GetData();
};

CopyConstructorAssignObject::CopyConstructorAssignObject(int d):data(d) {
	cout << "Data is " << data << "\n";
}

int
CopyConstructorAssignObject::GetData()
{
	return data;
}

/* using const reference avoid overhead of copy */
/* passing object by reference is more efficient then passing by value, as only address is copied
   not the entire content of object 
*/
CopyConstructorAssignObject::CopyConstructorAssignObject(const CopyConstructorAssignObject &src):
	data(src.data+1) {
	cout << "Copy Constructor New Data " << data << "\n";
}

CopyConstructorAssignObject & CopyConstructorAssignObject::operator=(const CopyConstructorAssignObject &rhs)
{
	cout << "Assignment operator called " << "\n";
	if (this == &rhs)
		return *this;
	else 
		this->data = rhs.data;
	return *this;
}

/*
 * Assignment Operator is another way to copy or perform assignment from one
 * object to another.
 * Copy Constructor also does the same but it's perform during object creation.
 * If you want to perform/copy object at later time assignment operator can be used.
 * 
 * It's an overloading of = operator in the class.
 */
int
main()
{
	CopyConstructorAssignObject obj(5);
	CopyConstructorAssignObject obj1(obj);
	 /* Here Copy Constructor will be invoked, as it's done at declaration time */
	CopyConstructorAssignObject obj3 = obj1;
	CopyConstructorAssignObject obj4;
	cout << "Get data after assignment " << obj3.GetData() << "\n";
	/* Assignment Operator will be invoked, as it's done at declaration time */
	obj4 = obj1;
	cout << "Get data after assignment " << obj4.GetData() << "\n";
}
