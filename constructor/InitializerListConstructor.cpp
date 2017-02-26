#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class InitializerListConstructor {
	protected:
		vector<int> data;
	public:
		 InitializerListConstructor(initializer_list<int> args);
};

InitializerListConstructor::InitializerListConstructor(initializer_list<int> args) {
	for (auto it : args) {
		cout << it << "\n";
		data.push_back(it);
	}	
}

int
main()
{
	InitializerListConstructor p1 = {1, 2, 3};	
}
