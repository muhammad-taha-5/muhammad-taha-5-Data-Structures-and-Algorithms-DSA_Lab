#include<iostream>
#include<stack>
using namespace std; 
class queue_using_stack {
private:
	stack <int> s1;
		stack <int > s2;
		void transfer(){
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
public:

	void enqueue( int value) {
		s1.push(value);
	}

	int  dequeue() {
		if (s2.empty()) {
			if (s1.empty()) {
              cout << "  this the  emptyed  queue" << endl;
			  return -1;
			}
			transfer();
		}
		int  value = s2.top();
		s2.pop();
		return  value; 
	}


	int  front() {
		if (s2.empty()){
			if (s1.empty()) {
				cout << "  both  empty" << endl;  
				return -1;
			 }
			transfer();
		}
		return s2.top();
	}
	void display() {
		if (s1.empty() && s2.empty()) {
			cout << "Queue is empty\n";
			return;
		}

		stack<int> temp_s2 = s2;
		stack<int> temp;

		cout << "Queue elements (front to rear): ";

		while (!temp_s2.empty()) {
			cout << temp_s2.top() << " ";
			temp_s2.pop();
		}

		stack<int> temp_s1 = s1;
		while (!temp_s1.empty()) {
			temp.push(temp_s1.top());
			temp_s1.pop();
		}

		while (!temp.empty()) {
			cout << temp.top() << " ";
			temp.pop();
		}

		cout << endl;
	}
	bool isEmpty() {
		return s1.empty() && s2.empty();
	}
};

int main() {

	queue_using_stack q;
	int choice, value;

	do {
		cout << "\n--- Queue Using Stacks Menu ---\n";
		cout << "1. Enqueue\n";
		cout << "2. Dequeue\n";
		cout << "3. Front\n";
		cout << "4. Display\n";
		cout << "0. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;


		switch (choice) {
		case 1:
			cout << "Enter value to enqueue: ";
			cin >> value;
			q.enqueue(value);
			break;
		case 2:
			value = q.dequeue();
			if (value != -1)
				cout << "Dequeued: " << value << endl;
			break;
		case 3:
			value = q.front();
			if (value != -1)
				cout << "Front element: " << value << endl;
			break;
		case 4:
			q.display();
			break;
		case 0:
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice! Try again.\n";
		}
	} while (choice != 0);



		return  0;

	}