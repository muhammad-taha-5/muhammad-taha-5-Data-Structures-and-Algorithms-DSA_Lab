//#include<iostream>
//using namespace  std;
//
//template <class  T >
//class queue  {
//
//	int size;
//	T* arr;
//	int  front_Index;
//	int  rear;
//
//
//public:
//
//	queue(int s) {
//		size = s;
//		arr = new T[size];
//		front_Index = 0;
//		rear = -1;
//	}
//	void enQueue(T page ) {
//		if (isFull()) {
//			cout << "  is full " << endl;
//			return;
//		}
//		else {
//			arr[++rear] = page;
//		}
//
//	}
//
//	T deQueue() {
//		if (isEmpty()) {
//			cout << " is  Empty  " << endl;
//			return -1;
//		}
//
//		T page = arr[front_Index++];
//		if (front_Index > rear) {
//			front_Index = 0;
//			rear = -1;
//		}
//		return  page;
//	}
//
//
//	T front() const {
//		if (isEmpty()) {
//
//			cout << " is  Empty  " << endl;
//			return T();
//		}
//		return arr[front_Index];
//
//	}
//
//
//	bool isEmpty() const {
//		return  (front_Index > rear);
//	}
//
//
//	bool isFull() const {
//		return (rear == size - 1);
//	}
//
//	void display() {
//		if (isEmpty()) {
//			cout << "Queue is Empty\n";
//			return;
//		}
//		cout << "Queue Elements: ";
//		for (int i = front_Index; i <= rear; i++) {
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//
//	~queue() {}
//
//
//};
//
//
//int  main() {
//
//	int  s;
//	cout << "Enter size of queue: ";
//	cin >> s;
//
//	queue<int> q(s);
//
//	int choice, page;
//	do {
//		cout << "\n--- Queue Menu ---\n";
//		cout << "1. Enqueue\n";
//		cout << "2. Dequeue\n";
//		cout << "3. Front\n";
//		cout << "4. Check Empty\n";
//		cout << "5. Check Full\n";
//		cout << "6. Display\n";
//		cout << "0. Exit\n";
//		cout << "Enter choice: ";
//		cin >> choice;
//
//		switch (choice) {
//		case 1:
//			cout << "page id to print  ";
//			cin >> page;
//			if (page < 1000 || page >= 1){
//				q.enQueue(page);
//			}
//			else {
//				cout << " your  offical document has only  1000 page \n";
//				cout << " chosee  below the it ? \n";
//				
//			}
//			break;
//
//		case 2:
//			cout << "Removed: " << q.deQueue() << endl;
//			break;
//
//		case 3:
//			cout << "Front: " << q.front() << endl;
//			break;
//
//		case 4:
//			if (q.isEmpty())
//				cout << "Queue is Empty\n";
//			else
//				cout << "Queue is Not Empty\n";
//
//			break;
//
//		case 5:
//			if (q.isFull()) {
//				cout << "Queue is Full\n";
//			}
//			else {
//				cout << "Queue is Not Full\n";
//				break;
//			}
//		case 6:
//			q.display();
//			break;
//		}
//
//	} while (choice != 0);
//
//	return 0;
//}
//
