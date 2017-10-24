#include <iostream>
using namespace std;

struct Node {
	int Head;
	Node *Next;

	Node(int info, Node *next) {
		this->Head = info;
		this->Next = next;
	}
};

class LinkedList {
	Node *Head;
public:
	LinkedList() {
		this->Head = nullptr;
	}
	void AddFirst(int data) {
		Node *newNode = new Node(data, this->Head);
		this->Head = newNode;
	}
	int removeLast() {
		if (this->Head->Next == nullptr) {
			int last = this->Head->Head;

			delete Head;
			Head = nullptr;

			return last;
		}

		Node *temp = this->Head;
		Node *previousTemp = nullptr;
		while (temp->Next != nullptr) {
			previousTemp = temp;
			temp = temp->Next;
		}
		previousTemp->Next = nullptr;
		int last = temp->Head;
		delete temp;
		return last;
	}
	int size() {
		if (this->Head == nullptr) {
			return 0;
		}
		int counter = 0;
		Node *temp = this->Head;
		while (temp != nullptr) {
			counter++;
			temp = temp->Next;
		}
		return counter;
	}
	void print() {
		if (this->Head == nullptr) {
			cout << "None to display" << endl;
			return;
		}
		Node *temp = this->Head;
		while (temp != nullptr) {
			cout << temp->Head << endl;
			temp = temp->Next;
		}
	}
};

class Queue {
	LinkedList qArray;
	int counter;
public:
	Queue() {
		this->counter = 0;
	}
	void Enque(int data) {
		this->counter++;
		this->qArray.AddFirst(data);
	}
	int Deque() {
		return this->qArray.removeLast();
	}
	int Size() {
		return this->qArray.size();
	}
	void Print() {
		this->qArray.print();
	}
};

int main() {
	Queue newQ;
	newQ.Enque(1);
	newQ.Enque(2);
	newQ.Enque(3);
	newQ.Print();
	cout << "Size: " << newQ.Size() << endl;
	cout << "Dequeing: " << newQ.Deque() << endl;
	cout << "Size: " << newQ.Size() << endl;
	newQ.Print();
	cout << endl;
	newQ.Enque(10);
	newQ.Enque(11);
	newQ.Print();
	cout << "Dequeing: " << newQ.Deque() << endl;
	cout << "Dequeing: " << newQ.Deque() << endl;
	cout << "Dequeing: " << newQ.Deque() << endl;
	cout << "Dequeing: " << newQ.Deque() << endl;
	cout << "Size: " << newQ.Size() << endl;
	newQ.Print();

	getchar();
	return 0;
}
