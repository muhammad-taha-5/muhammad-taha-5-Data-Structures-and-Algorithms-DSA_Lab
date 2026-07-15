//# include<iostream>
//#include<string>
//using  namespace std;
//class node {
//public:
//	int id; 
//	string  type;
//	string  borrower;
//	node* next; 
// };
//
//class devices_list {
//private:
//	
//	node* head;
//public :
//	devices_list() {
//		head = NULL;
//	}
//	// for  adding at last                            // kist  using  stack  
//	void addDevice(int i, string t, string  b) {
//		node* newnode = new node;
//		newnode->id = i;
//		newnode->type = t;
//		newnode->borrower = b;
//		newnode->next = NULL;
//
//		if (head== NULL) {
//			head = newnode;
//		}
//		else {
//			node* temp = head;
//			while (temp->next != NULL) {
//				temp = temp->next;
//			}
//			temp->next = newnode;
//
//		}
//	}
//	// this for the  removing  from  the  end                             // kist  using  stack  
//	 
//	void  recallDevice(int  id) {
//		if (head==NULL) {
//			cout << "queeu is  already  im" << endl; 
//			return; 
//	    }
//		else{
//			if (head->id = id){
//				node* temp = head;
//				head = head->next;
//				delete temp;
//				return;
//			}
//		}
//
//		node* pre = head ;
//		node* curr = head->next;
//		while ( curr != NULL) {
//			if (curr->id = id ) {
//				pre->next = curr->next;
//				delete curr ;
//				return;
//			}
//			pre = curr;
//			curr = curr->next;
//		}
//		
//	 }
//
//	void display() {
//		node* temp = head;  
//		while (temp != NULL) {
//			cout << " id : " << temp->id << " type :" << temp->type << " borrower "<<   temp ->borrower<<endl; 
//			temp = temp-> next;
//		}
//		
//	 }
//
//};
//int main() {
//
//	devices_list l;
//
//
//	l.addDevice(101, "apple", "5 days uml");
//	l.addDevice(102, "apple", "5 days uml");
//	l.addDevice(103, "apple", "5 days uml");
//	l.addDevice(104, "apple", "5 days uml");
//	l.addDevice(105, "apple", "5 days uml");
//	l.display();
//	cout << "-----------------------------" << endl; 
//	l.recallDevice(103);
//	l.display();
//	return 0; 
// }