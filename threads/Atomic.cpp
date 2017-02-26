#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

using namespace std;

void increment(atomic<int> &counter)
{
	for (int i = 0; i < 100; i++) {
		counter++;
	}
}

int
main()
{
	atomic<int> counter(0);
	vector<thread> threads;

	for (int i = 0; i < 10; i++) {
		threads.push_back(thread(increment, ref(counter)));
	}
	for (auto &t : threads) {
		t.join();
	}
	cout << "Counter " << counter << "\n";

	atomic<int> value(4);
	int fetch = value.fetch_add(4);
	cout << "Fetch " << fetch << " " << value << endl;
	return (0);
}
