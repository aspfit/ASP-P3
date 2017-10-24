#include <iostream>
using namespace std;

class Queue {
	int counter;
	int * qArray;
	
public:
	Queue() {
		this->counter = 0;
		this->qArray = nullptr;
	}
	~Queue() {
		delete[]this->qArray;
	}
	void Enque(int data) {
		this->counter++;
		if (this->counter > 1) {
			int *tempArray = new int[this->counter];
			tempArray[this->counter-1] = data;
			for (int i = 0; i < this->counter - 1; i++) {
				tempArray[i] = this->qArray[i];
			}
			delete[]this->qArray;
			this->qArray = tempArray;
		}
		else {
			this->qArray = new int[1];
			this->qArray[0] = data;
		}
	}
	int Deque() {
		if (this->counter != 0) {
			this->counter--;
			int toDeque = this->qArray[0];

			if (this->counter == 0) {
				delete[]this->qArray;
				this->qArray = nullptr;
				return toDeque;
			}
			int *tempArray = new int[this->counter];
			for (int i = 0; i < this->counter + 1; i++) {
				tempArray[i] = this->qArray[i + 1];
			}
			this->qArray = tempArray;
			return toDeque;
		}
		return -1;
	}
	int Size() {
		return this->counter;
	}
	void Print() {
		for (int i = this->counter-1; i >= 0; i--)
			cout << this->qArray[i] << endl;
	}
};

int main() {
	Queue newQ;
	newQ.Enque(3);
	newQ.Enque(2);
	newQ.Enque(1);
	newQ.Print();
	cout << "Dequed: " << newQ.Deque() << endl;
	newQ.Print();
	cout << "Size: " << newQ.Size() << endl;
	newQ.Print();

	getchar();
	return 0;
}
