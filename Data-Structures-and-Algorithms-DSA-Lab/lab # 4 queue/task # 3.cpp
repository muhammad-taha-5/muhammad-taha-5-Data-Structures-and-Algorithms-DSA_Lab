//#include <iostream>
//#include <stack>
//using namespace std;
//
//template < class T>
//class  AbstractQueue {
//public:
//	virtual void enQueue(T value) = 0;
//	virtual T deQueue() = 0;
//	virtual bool isEmpty() const = 0;
//	virtual bool isFull() const = 0;
//	virtual T front() const = 0;
//	virtual void display() = 0;
//	virtual ~AbstractQueue() {}
//
//};
//template < class T>
//class  myQueue : public AbstractQueue <T> {
//private:
//	int size;
//	T* arr;
//	int  front_Index;
//	int  rear;
//public:
//	myQueue(int  s) {
//		size = s;
//		arr = new T[size];
//		front_Index = 0;
//		rear = -1;
//	}
//	void enQueue(T value) {
//		if (isFull()) {
//			cout << "  is full " << endl;
//			return;
//		}
//		else {
//			arr[++rear] = value;
//
//		}
//	}
//
//	T deQueue() {
//		if (isEmpty()) {
//			cout << " is  Empty  " << endl;
//			return T();
//		}
//
//		T value = arr[front_Index++];
//
//		return  value;
//	}
//	T front() const {
//		if (isEmpty()) {
//			cout << "Queue is Empty\n";
//			return T();   
//		}
//		return arr[front_Index];
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
//		for (int i = front_Index; i <= size-1 ; i++) {
//			cout << arr[i] << " ";
//		}
//
//	}
//
//	~myQueue() {
//		delete[] arr;
//	}
//
//	void reverseK(int k) {
//		if (k <= 1 || isEmpty()) return;
//
//		int n = (rear - front_Index) + 1;
//		if (k > n) k = n; 
//		stack <T> st;
//
//		for (int i = 0; i < k; i++){
//			st.push(deQueue());
//		}
//		shiftToFront();
//		while (!st.empty() ){
//			enQueue(st.top());
//			st.pop();
//		}
//
//		for (int i = 0; i < n - k; i++) {
//			enQueue(deQueue());
//		}
//	}
//
//	void shiftToFront() {
//		if (front_Index > 0) {
//			int j = 0;
//			for (int i = front_Index; i <= rear; i++) {
//				arr[j++] = arr[i];
//			}
//			rear = rear - front_Index;
//			front_Index = 0;
//		}
//	}
//};
//
//int main() {
//	myQueue<int> q(5);
//
//	q.enQueue(10);
//	q.enQueue(20);
//	q.enQueue(30);
//	q.enQueue(40);
//	q.enQueue(50);
//
//	cout << "Original: ";
//	q.display();
//    
//	q.reverseK(3);
//	cout << "After ReverseK(3): ";
//
//	q.enQueue(40);
//	q.enQueue(50);
//
//	q.display();
//
//
//	return 0;
//}