//#include <iostream>
//using namespace std;
//
//struct Node
//{
//    int data;
//    Node* next;
//};
//
//// Insert at beginning
//void insertbegin(Node*& head, int value)
//{
//    Node* newnode = new Node;
//    newnode->data = value;
//    newnode->next = head;
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
//        head = newnode;
//        return;
//    }
//
//    insertend(head->next, value);
//}
//
//// Insert at given position recursively
//void insertposition(Node*& head, int value, int position)
//{
//    if (position == 1)
//    {
//        Node* newnode = new Node;
//        newnode->data = value;
//        newnode->next = head;
//        head = newnode;
//        return;
//    }
//
//    if (head == NULL)
//    {
//        return;
//    }
//
//    insertposition(head->next, value, position - 1);
//}
//
//// Delete by value recursively
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
//        head = head->next;
//        delete temp;
//        return;
//    }
//
//    deletevalue(head->next, value);
//}
//
//// Delete by position recursively
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
//        head = head->next;
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
//// Traverse recursively
//void print(Node* head){
//    if (head == NULL){
//        return;
//    }
//    cout << head->data << " ";
//    print(head->next);
//}
//
//int main()
//{
//    Node* head = NULL;
//
//    insertbegin(head, 10);
//    insertbegin(head, 5);
//
//    insertend(head, 20);
//    insertend(head, 30);
//
//    insertposition(head, 15, 3);
//
//    cout << "Linked List : ";
//    print(head);
//
//    cout << endl;
//
//    deletevalue(head, 20);
//
//    cout << "After deleting value 20 : ";
//    print(head);
//
//    cout << endl;
//
//    deleteposition(head, 2);
//
//    cout << "After deleting position 2 : ";
//    print(head);
//
//    cout << endl;
//
//    int pos = search(head, 30);
//
//    if (pos != -1)
//    {
//        cout << "30 found at position : " << pos << endl;
//    }
//    else
//    {
//        cout << "30 not found" << endl;
//    }
//
//    return 0;
//}