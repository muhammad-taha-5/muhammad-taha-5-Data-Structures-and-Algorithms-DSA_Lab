#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class DeliveryQueue {
	int size;
	int* id;
	char (*address)[50];
	int* start_time;
	int* end_time;

	int front_Index;
	int rear;

public:
	DeliveryQueue(int s) {
		size = s;

		id = new int[size];
		address = new char[size][50];
		start_time = new int[size];
		end_time = new int[size];

		front_Index = 0;
		rear = -1;
	}

	void enqueue(int tid, char addr[], int st, int et) {
		if (isFull()) {
			cout << "Queue is Full\n";
			return;
		}

		rear++;
		id[rear] = tid;
		strcpy(address[rear], addr);
		start_time[rear] = st;
		end_time[rear] = et;

		cout << "Package Added\n";
	}

	void dequeue(int current_time) {
		if (isEmpty()) {
			cout << "No packages\n";
			return;
		}

		if (current_time >= start_time[front_Index] && current_time <= end_time[front_Index]) {
			cout << "Delivered Package ID: " << id[front_Index] << endl;
		}
		else {
			cout << "Expired Package ID: " << id[front_Index] << endl;
		}

		front_Index++;

		if (front_Index > rear) {
			front_Index = 0;
			rear = -1;
		}
	}

	void front() {
		if (isEmpty()) {
			cout << "Queue Empty\n";
			return;
		}

		cout << "Front Package -> ID: " << id[front_Index]
			<< " Address: " << address[front_Index]
			<< " Time: " << start_time[front_Index]
			<< "-" << end_time[front_Index] << endl;
	}

	bool isEmpty() {
		return (front_Index > rear);
	}

	bool isFull() {
		return (rear == size - 1);
	}

	void display() {
		if (isEmpty()) {
			cout << "No Packages\n";
			return;
		}

		cout << "Packages in Queue:\n";
		for (int i = front_Index; i <= rear; i++) {
			cout << "ID: " << id[i]
				<< " Address: " << address[i]
				<< " Time: " << start_time[i]
				<< "-" << end_time[i] << endl;
		}
	}

	~DeliveryQueue() {
		delete[] id;
		delete[] address;
		delete[] start_time;
		delete[] end_time;
	}
};


int main() {
	int size;
	cout << "Enter queue size: ";
	cin >> size;

	DeliveryQueue q(size);

	int choice;

	do {
		cout << "\n1.Add Package\n2.Process Package\n3.View Front\n4.Display\n0.Exit\n";
		cin >> choice;

		if (choice == 1) {
			int id, st, et;
			char addr[50];

			cout << "Enter ID: ";
			cin >> id;
			cout << "Enter Address: ";
			cin >> addr;
			cout << "Start Time: ";
			cin >> st;
			cout << "End Time: ";
			cin >> et;

			q.enqueue(id, addr, st, et);
		}

		else if (choice == 2) {
			int current_time;
			cout << "Enter Current Time: ";
			cin >> current_time;

			q.dequeue(current_time);
		}

		else if (choice == 3) {
			q.front();
		}

		else if (choice == 4) {
			q.display();
		}

	} while (choice != 0);

	return 0;
}