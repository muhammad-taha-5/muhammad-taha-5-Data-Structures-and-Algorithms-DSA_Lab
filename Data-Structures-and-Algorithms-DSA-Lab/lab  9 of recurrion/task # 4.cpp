//#include< iostream>
//using namespace std;
//class node {
//public:
//	node * next;
//	int  data;
//};
//class list {
//private :  
//	node* head;
//public :
//
//	list() {
//		head = NULL;
//	}
//
//    void insertAtEnd(int value) {   
//        node* temp = new node;
//        temp->next = NULL;
//        temp->data = value;
//
//        if (head == NULL) {
//            head = temp;
//            return;
//        }
//        node* curr = head;
//        while (curr->next != NULL) {
//            curr = curr->next; // Move forward
//        }
//        curr->next = temp;
//    }
//
//    void traverse_helper (node* curr){
//        if (curr == NULL) {
//            cout << "null" << endl;
//            return;
//        }
//        cout << curr->data << endl;
//        traverse_helper (curr->next);
//    }
//    void traverse(){
//        if ( head == NULL ){
//            cout << "list is already empty" << endl;
//            return;
//        }
//        else {
//            traverse_helper(head);
//        }
// 
//    }
//
//};
//int  main() {
//    list l;
//     l.insertAtEnd(10);
//     l.insertAtEnd(20);
//     l.insertAtEnd(30);
//     l.insertAtEnd(40);
//     l.insertAtEnd(50);
//     l.insertAtEnd(60);
//    
//    l.traverse();
//
//
//
//	return 0;
// }