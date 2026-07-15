#include<iostream>
using namespace std;

template <class T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual void display() const = 0;
    virtual ~AbstractStack() {}
};

template <class t>
class myStack : public AbstractStack<t> {

private:
    t* arr;        // dynamic array
    int topindex;
    int size;      // max size

public:
    // Constructor with size
    myStack(int s) {
        size = s;
        arr = new t[size];   // dynamic allocation
        topindex = -1;
    }

    // Destructor
    ~myStack() {
    }

    void push(t value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topindex] = value;
    }

    t pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return t();
        }
        return arr[topindex--];
    }

    t top() const {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return t();
        }
        return arr[topindex];
    }

    bool isEmpty() const {
        return (topindex == -1);
    }

    bool isFull() const {
        return (topindex == size - 1);
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Stack (top to bottom): ";
        for (int i = topindex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int  main() {

    myStack<int> s(5);
    s.push(10);
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;

    cout << "Popped: " << s.pop() << endl;
    s.display();
    cout << "Top after pop: " << s.top() << endl; // this the   second  top 
    cout << "Popped: " << s.pop() << endl;

    return 0;
}