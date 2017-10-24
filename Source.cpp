#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

class Queue {
	int qArray[MAX_SIZE];
	int counter;
	int front;
	int rear;
public:
	Queue() {
		this->front = 0;
		this->rear = 0;
		this->counter = 0;
	}
	void Enque(int data) {
		if (this->counter == 10) {
			cout << "Queue is full!" << endl;
			return;
		}
		this->qArray[this->rear] = data;
		this->rear++;
		if (this->rear == 10)
			this->rear = 0;
		this->counter++;
	}
	int Deque() {
		if (this->counter == 0) {
			cout << "Queue is empty! Displaying Error Code (-1)" << endl;
			return -1;
		}
		int firstOut = this->qArray[this->front];
		this->front++;
		this->counter--;
		return firstOut;
	}
	int Size() {
		return this->counter;
	}
	void Print() {
		cout << endl;
		for (int i = 0; i < 10; i++) {
			cout << i << ". " << this->qArray[i] << endl;
		}
	}
};

int main() {
	Queue newQ;
	for (int i = 0; i < 10; i++)
		newQ.Enque(i + 1);

	
	for (int i = 0; i < 4; i++)
		cout << newQ.Deque() << endl;
	newQ.Print();
	newQ.Enque(11);
	newQ.Enque(12);
	newQ.Print();

	getchar();
	return 0;
}

