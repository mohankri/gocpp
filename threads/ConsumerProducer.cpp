#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

class buffer {
	public:
		void add(int id);
		int remove();
	protected:
		vector<int> data;	
};

void
buffer::add(int id)
{
	data.push_back(id);
}

int
buffer::remove()
{
	int id = data.front();
	data.pop_back();
	return id;
}

class producer {
	public:
		producer(buffer *buf)
			:_data(buf)
			 {}
		~producer() {
		}
		void start();
	protected:
		buffer *_data;		
};

class consumer {
	public:
		consumer(buffer *buf)
			:_data(buf) {}
		~consumer() {
		}
		void start();
	protected:
		buffer *_data;	
};

void
producer::start()
{
	cout << "Start Producer Thread" << endl;
	while (1) {
		int data = rand()%100;
		cout << "Data Added " << data << endl;
		_data->add(data);
		this_thread::sleep_for(chrono::seconds(1));
	}
}

void
consumer::start()
{
	cout << "Start Consumer Thread" << endl;
	while (1) {
		int data = _data->remove();
		cout << "Data Removed " << data << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
}

int
main()
{
	buffer buf;
	producer p(&buf);
	consumer c(&buf);

	thread prod_thread(&producer::start, &p);
	thread cons_thread(&consumer::start, &c);
	prod_thread.join();
	cons_thread.join();
}
