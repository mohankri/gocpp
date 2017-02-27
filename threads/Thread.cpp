#include <iostream>
#include <thread>

using namespace std;

class counter {
	public:
		counter(int id, int iter);
		void operator()() const;
	protected:
		int mid;
		int mnumIter;			
};

counter::counter(int id, int iter)
	:mid(id), mnumIter(iter)
{
}

void
counter::operator()() const
{
	cout << " Operator " << endl;

	for (int i = 0; i < mnumIter; i++) {
		cout << mid << " Operator " << i << endl;
	}

}

void test_counter(int id, int iter)
{
	for (int i = 0; i < iter; i++) {
		cout << id << " has value " << i << endl;
	}

}

int
main()
{
	cout.sync_with_stdio(true);
	thread t1(test_counter, 1, 6);
	thread t2(test_counter, 2, 4);
	thread t3(counter(2, 4));
	t1.join();
	t2.join();
	t3.join();
	return 0;
}
