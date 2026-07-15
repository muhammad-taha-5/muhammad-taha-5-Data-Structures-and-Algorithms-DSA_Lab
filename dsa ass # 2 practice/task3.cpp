// 
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Stack
{
private:
    static const int MAX = 10;
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (top == MAX - 1)
        {
            cout << " is full Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = value;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << " is Empty Stack Underflow" << endl;
            return -1;
        }

        return arr[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return;
        }

        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack original, reversed;

    original.push(1);
    original.push(2);
    original.push(3);
    original.push(4);

    cout << "Original Stack: ";
    original.display();

    while (!original.isEmpty())
    {
        int value = original.pop();
        reversed.push(value);
    }

    cout << "Reversed Stack: ";
    reversed.display();

    return 0;
}
