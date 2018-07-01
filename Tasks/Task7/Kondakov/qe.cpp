#include <iostream>
using namespace std;
class Queue
{
	int* queue;
	int SIZE, head = 0, tail = -1;
public:
	int pushElement(int element);
	Queue(int n);
	int length();
	int popElement();
	void printAll();
	int print();
	Queue(const  Queue & q);
	void operator = (Queue & q);

	~Queue() {
		delete[] queue;
	}
};

Queue::Queue(int n) {

	SIZE = n;
	queue = new int[n];

}

Queue::Queue(const  Queue & q) {
	this->SIZE = q.SIZE;
	this->queue = new int[SIZE];
	this->head = q.head;
	this->tail = q.tail;
	for (int i = 0; i < SIZE; i++) this->queue[i] = q.queue[i];
}
void  Queue:: operator = (Queue & q) {
	this->SIZE = q.SIZE;
	this->head = q.head;
	this->tail = q.tail;
	for (int i = 0; i < SIZE; i++) this->queue[i] = q.queue[i];
}

int Queue::print() {
	if (length()) {
		if (tail >= head) {
			for (int i = head; i <= tail; i++) cout << queue[i] << " ";
		}
		else {
			for (int i = head; i < SIZE; i++) cout << queue[i] << " ";
			for (int i = 0; i <= tail; i++) cout << queue[i] << " ";
		}
		cout << endl;
		return 0;
	}
	else return 1;
}
void Queue::printAll() {

	for (int i = 0; i < SIZE; i++) cout << queue[i] << " ";
	cout << endl << "H = " << head << " T = " << tail << endl;
}
int Queue::popElement() {
	if (length()) {
		int i = head;
		if (tail == head) {
			tail = -1;
			head = 0;
		}
		else {
			head++;
			if (head == SIZE) head = 0;
		}
		return  queue[i];
	}
	else return  queue[head]; // что вернуть если очередь пуста?
}
int Queue::length() {
	if (tail == -1) {
		return 0;
	}
	else if (tail >= head) {
		return tail - head + 1;
	}
	else return SIZE - head + tail + 1;
}


int Queue::pushElement(int element) {
	if (length() != SIZE) {
		tail++;
		if (tail == SIZE) tail = 0;
		queue[tail] = element;
		return 0;
	}
	else return 1;
}

int main() {
	Queue q(10);
	Queue q1(10);
	q.printAll();
	cout << q.length() << endl;

	for (int i = 1; i <= 10; i++) q.pushElement(i);
	q.print();
	cout << q.length() << endl;


	for (int i = 1; i <= 7; i++) q.popElement();
	q.print();
	cout << q.length() << endl;

	for (int i = 1; i <= 8; i++) q.pushElement(i);
	q.print();
	cout << q.length() << endl;

	q1 = q;

	q1.print();
	cout << q1.length() << endl;

	system("pause");
	return 0;
}