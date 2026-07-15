//#include<iostream>
//using namespace std;
//
//template <class T>
//class AbstractStack {
//public:
//    virtual void push(T value) = 0;
//    virtual T pop() = 0;
//    virtual T top() const = 0;
//    virtual bool isEmpty() const = 0;
//    virtual bool isFull() const = 0;
//    virtual void display() const = 0;
//    virtual ~AbstractStack() {}
//};
//
//template <class t>
//class myStack : public AbstractStack<t> {
//
//private:
//    t* arr;         // main stack
//    t* minArr;      // stack to track minimum elements
//    int topindex;
//    int minTop;
//    int size;
//
//
//
//public:
//    myStack(int s) {
//        size = s;
//        arr = new t[size];
//        minArr = new t[size];  
//        topindex = -1;
//        minTop = -1;
//    }
//
//    ~myStack() {
//        delete[] arr;
//        delete[] minArr;
//    }
//
//    void push(t value) {
//        if (isFull()) {
//            cout << "Stack Overflow\n";
//            return;
//        }
//        arr[++topindex] = value;
//
//        // Maintain min stack
//        if (minTop == -1 || value <= minArr[minTop]) {
//            minArr[++minTop] = value;
//        }
//    }
//
//    t pop() {
//        if (isEmpty()) {
//            cout << "Stack Underflow\n";
//            return t();
//        }
//        t popped = arr[topindex--];
//
//        // Update min stack if needed
//        if (popped == minArr[minTop]) {
//            minTop--;
//        }
//
//        return popped;
//    }
//
//    t top() const {
//        if (isEmpty()) {
//            cout << "Stack is Empty\n";
//            return t();
//        }
//        return arr[topindex];
//    }
//
//    bool isEmpty() const {
//        return (topindex == -1);
//    }
//
//    bool isFull() const {
//        return (topindex == size - 1);
//    }
// 
//    //   current minimum element
//    t getMin() const {
//
//        if (isEmpty()) {
//            cout << "Stack is Empty\n";
//            return t();
//        }
//          return minArr[minTop];
//    }
//
//
//
//    void display() const {
//        if (isEmpty()) {
//            cout << "Stack is Empty\n";
//            return;
//        }
//
//        cout << "Stack (top to bottom): ";
//        for (int i = topindex; i >= 0; i--) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//int  main() {
//
//    myStack<int> s(5);
//    s.push(5);
//    s.push(15);
//    s.push(10);
//    s.push(20);
//    s.push(30);
//    s.display();
//    cout << "Top: " << s.top() << endl;
//
//    cout << "Popped: " << s.pop() << endl;
//    cout << "------------------" << endl;
//    s.display();
//    cout << "------------------" << endl; 
//    cout << "Top after pop: " << s.top() << endl; // this the   second  top 
//    cout << "Popped: " << s.pop() << endl;
//    cout << "   this the  smalllest  one  in the  sake  " << s.getMin() <<"\n------------------" << endl;
//    s.display();
//    return 0;
//}