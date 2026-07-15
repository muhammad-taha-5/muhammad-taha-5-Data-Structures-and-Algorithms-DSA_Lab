//#include<iostream>
//using namespace  std;
//
//template<class T>
//class  ticket_system_using_queue  {
//public:
//	
//	virtual void enQueue(T ticket_id) = 0;
//	virtual T deQueue() = 0;
//	virtual bool isEmpty() const = 0;
//	virtual bool isFull() const = 0;
//	virtual T front() const = 0;
//	virtual void display() = 0;
//	virtual ~ticket_system_using_queue() {};
//
//};
//
//
//template <class  T >
//class queue : public ticket_system_using_queue <T>{
//
//	int size;
//	T * arr;
//	int  front_Index;
//     int  rear;
//	 
//
//public:
//
//	queue(int s) {
//		size = s;
//		arr = new T[size]; 
//		front_Index =0;
//		rear = -1;
//	}
//	void enQueue(T ticket_id) {
//		if (isFull()) {
//			cout << "  is full " << endl; 
//	     	return;
//			}
//		else {
//			arr[++rear] = ticket_id;
//		}
//	
//	}
//
//	T deQueue() {
//				if (isEmpty()){
//					cout << " is  Empty  " << endl; 
//					return -1;
//				}
//				 
//				T ticket_id = arr[front_Index++];
//				if (front_Index > rear) {
//					front_Index = 0;
//					rear = -1;
//				}
//				return  ticket_id;
//	}
//		 
//		 
//		T front() const {
//		if (isEmpty()) {
//
//			cout << " is  Empty  " << endl;
//			return T();
//		}
//		return arr[front_Index];
//
//	    }
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
//	~queue(){}
//
//
//};
//
//
//int  main(){
//
//	int  s;  
//	cout << "Enter size of queue: ";
//	cin >> s;
//
//	queue<int> q(s);
//
//	int choice, ticket_id;
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
//			cout << "Enter 4-digit Ticket ID: ";
//			cin >> ticket_id;
//			if (ticket_id < 1000 || ticket_id > 9999) {
//				cout << "Invalid Ticket ID (must be 4 digits)\n";
//			}
//			else {
//				q.enQueue(ticket_id);
//			}
//		break;
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
////
