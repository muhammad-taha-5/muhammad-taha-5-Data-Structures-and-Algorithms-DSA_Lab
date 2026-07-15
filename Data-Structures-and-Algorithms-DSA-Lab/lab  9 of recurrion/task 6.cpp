//#include <iostream>
//using namespace std;
//
//struct Node
//{
//    int data;
//    Node* next;
//    Node* prev;
//};
//
//// Insert at beginning
//void insertbegin(Node*& head, int value)
//{
//    Node* newnode = new Node;
//    newnode->data = value;
//    newnode->next = head;
//    newnode->prev = NULL;
//
//    if (head != NULL)
//    {
//        head->prev = newnode;
//    }
//
//    head = newnode;
//}
//
//// Insert at end recursively
//void insertend(Node*& head, int value)
//{
//    if (head == NULL)
//    {
//        Node* newnode = new Node;
//        newnode->data = value;
//        newnode->next = NULL;
//        newnode->prev = NULL;
//        head = newnode;
//        return;
//    }
//
//    if (head->next == NULL)
//    {
//        Node* newnode = new Node;
//        newnode->data = value;
//        newnode->next = NULL;
//        newnode->prev = head;
//        head->next = newnode;
//        return;
//    }
//
//    insertend(head->next, value);
//}
//
//// Insert at specific position
//void insertposition(Node*& head, int value, int position)
//{
//    if (position == 1)
//    {
//        insertbegin(head, value);
//        return;
//    }
//
//    if (head == NULL)
//    {
//        return;
//    }
//
//    if (position == 2)
//    {
//        Node* newnode = new Node;
//        newnode->data = value;
//
//        newnode->next = head->next;
//        newnode->prev = head;
//
//        if (head->next != NULL)
//        {
//            head->next->prev = newnode;
//        }
//
//        head->next = newnode;
//        return;
//    }
//
//    insertposition(head->next, value, position - 1);
//}
//
//// Delete by value
//void deletevalue(Node*& head, int value)
//{
//    if (head == NULL)
//    {
//        return;
//    }
//
//    if (head->data == value)
//    {
//        Node* temp = head;
//
//        head = head->next;
//
//        if (head != NULL)
//        {
//            head->prev = NULL;
//        }
//
//        delete temp;
//        return;
//    }
//
//    if (head->next != NULL && head->next->data == value)
//    {
//        Node* temp = head->next;
//
//        head->next = temp->next;
//
//        if (temp->next != NULL)
//        {
//            temp->next->prev = head;
//        }
//
//        delete temp;
//        return;
//    }
//
//    deletevalue(head->next, value);
//}
//
//// Delete at position
//void deleteposition(Node*& head, int position)
//{
//    if (head == NULL)
//    {
//        return;
//    }
//
//    if (position == 1)
//    {
//        Node* temp = head;
//
//        head = head->next;
//
//        if (head != NULL)
//        {
//            head->prev = NULL;
//        }
//
//        delete temp;
//        return;
//    }
//
//    if (position == 2 && head->next != NULL)
//    {
//        Node* temp = head->next;
//
//        head->next = temp->next;
//
//        if (temp->next != NULL)
//        {
//            temp->next->prev = head;
//        }
//
//        delete temp;
//        return;
//    }
//
//    deleteposition(head->next, position - 1);
//}
//
//// Search recursively
//int search(Node* head, int value, int position = 1)
//{
//    if (head == NULL)
//    {
//        return -1;
//    }
//
//    if (head->data == value)
//    {
//        return position;
//    }
//
//    return search(head->next, value, position + 1);
//}
//
//// Print forward
//void printforward(Node* head)
//{
//    if (head == NULL)
//    {
//        return;
//    }
//
//    cout << head->data << " ";
//
//    printforward(head->next);
//}
//
//// Print reverse
//void printreverse(Node* tail)
//{
//    if (tail == NULL)
//    {
//        return;
//    }
//
//    cout << tail->data << " ";
//
//    printreverse(tail->prev);
//}
//
//// Find tail recursively
//Node* gettail(Node* head)
//{
//    if (head == NULL || head->next == NULL)
//    {
//        return head;
//    }
//
//    return gettail(head->next);
//}
//
//// Palindrome check recursively
//bool palindrome(Node* left, Node* right)
//{
//    if (left == NULL || right == NULL)
//    {
//        return true;
//    }
//
//    if (left == right || left->prev == right)
//    {
//        return true;
//    }
//
//    if (left->data != right->data)
//    {
//        return false;
//    }
//
//    return palindrome(left->next, right->prev);
//}
//
//int main()
//{
//    Node* head = NULL;
//
//    insertend(head, 1);
//    insertend(head, 2);
//    insertend(head, 3);
//    insertend(head, 2);
//    insertend(head, 1);
//
//    cout << "Forward : ";
//    printforward(head);
//
//    cout << endl;
//
//    Node* tail = gettail(head);
//
//    cout << "Reverse : ";
//    printreverse(tail);
//
//    cout << endl;
//
//    insertposition(head, 10, 3);
//
//    cout << "After insertion : ";
//    printforward(head);
//
//    cout << endl;
//
//    deletevalue(head, 10);
//
//    cout << "After deleting value 10 : ";
//    printforward(head);
//
//    cout << endl;
//
//    deleteposition(head, 2);
//
//    cout << "After deleting position 2 : ";
//    printforward(head);
//
//    cout << endl;
//
//    int pos = search(head, 3);
//
//    cout << "Position of 3 : " << pos << endl;
//
//    tail = gettail(head);
//
//    if (palindrome(head, tail))
//    {
//        cout << "List is Palindrome" << endl;
//    }
//    else
//    {
//        cout << "List is not Palindrome" << endl;
//    }
//
//    return 0;
//}