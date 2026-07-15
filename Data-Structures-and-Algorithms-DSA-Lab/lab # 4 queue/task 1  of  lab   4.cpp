//#include <iostream>
//using namespace std; 
//template < class T>
//
//class  AbstractQueue {
//public:
//	
//	virtual void enQueue(T value) = 0;
//	virtual T deQueue() = 0;
//      virtual T front() const = 0;
//	virtual bool isEmpty() const = 0;
//	virtual bool isFull() const = 0;
//	virtual void display() = 0;
//	virtual ~AbstractQueue() {}
//};
//
//template < class T>
//class  myQueue : public AbstractQueue <T>{
//private :
//	int size;
//	T * arr;
//	int  front_Index;
//	int  rear;
//public:  
//	myQueue( int  s ){
//		size = s; 
//		arr = new T[size]; 
//		front_Index =0;
//		rear = -1;
//	}
//	void enQueue(T value) {
//		if (isFull()){
//			cout << "  is full " << endl; 
//			return;
//		}
//		else {
//			arr[++rear] = value;
//			
// 		}
//	}
//
//	T deQueue() {
//		if (isEmpty()){
//			cout << " is  Empty  " << endl; 
//			return -1;
//		}
//		 
//		T value = arr[front_Index++];
//		if (front_Index > rear) {
//			front_Index = 0;
//			rear = -1;
//		}
//		return  value;
//	}
//	T front() const {
//		if (isEmpty()) {
//
//			cout << " is  Empty  " << endl;
//			return T();
//		}
//		return arr[front_Index];
//
//	}
//	bool isEmpty() const {
//		return  (front_Index > rear);
//	}
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
//	~myQueue() {
//		delete[] arr;
//	}
//
//	friend int remainingSpace(myQueue <T>q);
//
//};
//
////  this the  I made the  
//int  remainingSpace(myQueue <int>q){
//	if (q.isEmpty()) return q.size;
//	return q.size - (q.rear - q.front_Index + 1);
//}
//
//
//int  main(){
//
//	int  s;  
//	cout << "Enter size of queue: ";
//	cin >> s;
//
//	myQueue<int> q(s);
//
//	int choice, value;
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
//			cout << "Enter value: ";
//			cin >> value;
//			q.enQueue(value);
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
//			 cout<< " remainingSpace "<< remainingSpace(q);
//			break;
//
//		case 5:
//			if (q.isFull()) {
//				cout << "Queue is Full\n";
//				cout << " remainingSpace " << remainingSpace(q);
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
//
//
//
