#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class ProducerConsumer {
	public:
		/* lambda */
		ProducerConsumer(int id):
			myid(id), thread([this]{ Run();  }) { }
		~ProducerConsumer() { thread.join(); }
	protected:
		int myid;
		thread thread;
		virtual void Run();	
};

void
ProducerConsumer::Run()
{
	while (1) {
		cout << "Hello Run Invoked" << endl;
		this_thread::sleep_for(chrono::seconds(1));		
	}
}

int
main()
{
	ProducerConsumer p(1);
}
