//#include<iostream>
//using  namespace std;
//template <class  T >
//class  AbstractStack  {
//
//private :
//
//
//public: 
//	 AbstractStack() {}
//	virtual void push(T value) = 0;
//	virtual T pop() = 0;
//	virtual T top() const = 0;
//	virtual bool isEmpty() const = 0;
//	virtual bool isFull() const = 0;
//	virtual void display() const = 0;
//	virtual ~AbstractStack() {}
//
//};
//
//template < class t>  
//class myStack: public AbstractStack<t> {
//
//private :
//	t arr[5];
//	int topindex;
//
//
//public : 
//	
//	myStack() { // constractor 
//		topindex = -1;
//	}
//	
//	~myStack() {} // destuctor 
//
//	void push(t value){
//		if (isFull()) {
//			cout << " stack  overflow " << endl; 
//			return;
//		}
//		arr[++topindex] = value; // value  is  inserted after per_increment ?  
//	}
//
//	t pop() {
//		if (isEmpty()) {
//			cout << "Stack is Empty \n";
//			return t();
//		}
//		return  arr[topindex--]; //  post decremnt  return  hogaya !!
//
//	}
//	
//	t top() const{
//		if (isEmpty()) {
//			cout << "Stack is Empty\n";
//			return t();   // defalt  val return ?
//
//		}
//		return  arr[topindex];
//	}
//
//// is Empty 
//	bool isEmpty() const {
//		return (topindex == -1);
//	}
//	// isFull 
//	bool isFull() const {
//		return (topindex == 4);
//	}
//
//	void display() const {
//		if (isEmpty()) {
//			cout << "Stack is Empty\n";
//			return;
//		}
//
//		cout << "Stack (top to bottom): ";
//		for (int i = topindex; i >= 0; i--) {
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//
//};
//
//
//
//
//int  main() {
//
//	myStack <int> s;
//	s.push(10);
//	s.push(10);
//	s.push(20);
//	s.push(30);
//	
//	cout << "Top: " << s.top() << endl;
//
//	cout << "Popped: " << s.pop() << endl;
//	s.display();
//	cout << "Top after pop: " << s.top() << endl; // this the   second  top 
//	cout << "Popped: " << s.pop() << endl;
//
//	return 0; 
// }