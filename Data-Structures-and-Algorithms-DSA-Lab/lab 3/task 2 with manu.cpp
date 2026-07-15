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
    virtual T getMin() const = 0;
    virtual ~AbstractStack() {}
};

template <class t>
class myStack : public AbstractStack<t> {

private:
    t* arr;
    t* minArr;
    int topindex;
    int minTop;
    int size;

public:
    myStack(int s) {
        size = s;
        arr = new t[size];
        minArr = new t[size];
        topindex = -1;
        minTop = -1;
    }

    ~myStack() {
        delete[] arr;
        delete[] minArr;
    }

    void push(t value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++topindex] = value;

        if (minTop == -1 || value <= minArr[minTop]) {
            minArr[++minTop] = value;
        }
    }

    t pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return t();
        }

        t popped = arr[topindex--];

        if (popped == minArr[minTop]) {
            minTop--;
        }

        return popped;
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

    t getMin() const {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return t();
        }
        return minArr[minTop];
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

int main() {

    int size;
    cout << "Enter stack size: ";
    cin >> size;

    myStack<int> s(size);

    int choice, value;

    do {
        cout << "\n====== STACK MENU ======\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Display\n";
        cout << "5. Get Minimum\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            cout << "Popped: " << s.pop() << endl;
            break;

        case 3:
            cout << "Top: " << s.top() << endl;
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "Minimum: " << s.getMin() << endl;
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}