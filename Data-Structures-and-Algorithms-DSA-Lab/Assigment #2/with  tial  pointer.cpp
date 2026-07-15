//#include <iostream>
//#include <string>
//using namespace std;
//
//class node {
//public:
//    int id;
//    string type;
//    string borrower;
//    node* next;
//};
//
//class devices_list {
//private:
//    node* head;
//    node* tail;
//public:
//    devices_list() {
//        head = NULL;
//        tail = NULL;
//    }
//
//    void addDevice(int i, string t, string b) {
//        node* newnode = new node;
//        newnode->id = i;
//        newnode->type = t;
//        newnode->borrower = b;
//        newnode->next = NULL;
//
//        if (head == NULL) {
//            head = tail = newnode;
//        }
//        else {
//            tail->next = newnode;
//            tail = newnode;
//        }
//    }
//
//    void recallDevice(int id) {
//        if (head == NULL) {
//            cout << "Queue is already empty" << endl;
//            return;
//        }
//
//        if (head->id == id) {
//            node* temp = head;
//            head = head->next;
//            if (head == NULL) tail = NULL;
//            delete temp;
//            return;
//        }
//
//        node* pre = head;
//        node* curr = head->next;
//        while (curr != NULL) {
//            if (curr->id == id) {
//                pre->next = curr->next;
//                if (curr == tail) tail = pre;
//                delete curr;
//                return;
//            }
//            pre = curr;
//            curr = curr->next;
//        }
//    }
//
//    void display() {
//        node* temp = head;
//        if (temp == NULL) {
//            cout << "Queue is empty" << endl;
//            return;
//        }
//        while (temp != NULL) {
//            cout << "id: " << temp->id << " type: " << temp->type << " borrower: " << temp->borrower << endl;
//            temp = temp->next;
//        }
//    }
//};
//
//int main() {
//    devices_list l;
//
//    l.addDevice(101, "apple", "5 days uml");
//    l.addDevice(102, "apple", "5 days uml");
//    l.addDevice(103, "apple", "5 days uml");
//    l.addDevice(104, "apple", "5 days uml");
//    l.addDevice(105, "apple", "5 days uml");
//
//    cout << "Original list:" << endl;
//    l.display();
//
//    cout << "-----------------------------" << endl;
//    l.recallDevice(103);
//
//    cout << "After recalling device 103:" << endl;
//    l.display();
//
//    return 0;
//}