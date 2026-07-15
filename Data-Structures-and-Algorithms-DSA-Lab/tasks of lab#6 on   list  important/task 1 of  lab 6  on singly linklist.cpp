#include<iostream>
using namespace   std;
class node {
public:
	int  data;
	node* next;

};
class singly_link_list {
private:
	node* head;
public:

	singly_link_list() {
		head = NULL;
	}
	void create_node(int value) {
		node* temp = new node;
		node* curr = head;
		temp->data = value;
		temp->next = NULL;

		if (head == NULL) {
			head = temp;
		}
		else {
			while (curr->next != NULL) {    //  when  this  conditions  false  then  it 
				curr = curr->next;
			}
			curr->next = temp;

		}

	}

	void add_at_start(int  v) {
		node* temp = new node;
		temp->data = v;
		temp->next = head;
		head = temp;


	}

	void at_position(int p, int v) {
		node* curr = head;
		node* pre = curr;

		for (int i = 0; i < p; i++) {
			pre = curr;
			curr = curr->next;
		}
		node* temp = new  node;
		temp->data = v;
		pre->next = temp;
		temp->next = curr;
	}


	void delete_from_star() {
		if (head == NULL) {
			cout << "empty linklist " << endl;
			return;
		}
		else {
			node* curr = head;
			head = head->next;
			delete curr;
		}
	}

	void delete_end() {

		if (head->next == NULL) {   // only one node
			delete head;
			head = NULL;
			return;
		}

		if (head == NULL) {
			cout << " list  is Empty" << endl;
			return;
		}
		else {
			node* curr = head;
			node* pre = curr;
			while (curr->next != NULL) {
				pre = curr;
				curr = curr->next;
			}
			pre->next = NULL;
			delete curr;
		}
	}

	void delte_posi(int p) {

		if (head == NULL) {
			cout << "empty" << endl;
			return;
		}
		node* curr = head;
		node* pre = curr;

		for (int i = 0; i < p; i++) {
			pre = curr;
			curr = curr->next;
		}
		pre->next = curr->next;
		delete curr;
	}

	// now  make the  link list  circular 
	
	void circular_list(int v) {
		node* temp = new  node;
		temp->data = v;
		node* curr = head; 

		if (head == NULL) {
			cout << " empty " <<endl; 
			head = temp;
			temp->next = head; 
		}
		else {
			while( curr ->next != NULL) {

				curr = curr->next;
			}
			curr->next = temp;
			temp->next = head; 
		}
	 }




	// now  for the  searching
	bool  searching(node* n){
		node* curr = head;
		node* temp = new node;
		if (head == NULL) {
			cout << " empty" << endl; 
		}
		else {
			while (curr !=  NULL){
				if (curr->data == n->data) {
					cout << "  found" << endl;
					temp = curr;
					return true;
				}
				curr = curr->next;
			} 
			cout << "  not  found  " << endl; 
			return false;
		}
		delete temp;

	}




	void display() {
		node* curr = head;
		int  count = 0;
		if (curr == NULL) {
			cout << " queue is  still  Empty " << endl;
			return;
		}
		else {
			while (curr != NULL) {
				count++;
				cout << " data :" << curr->data << endl;

				curr = curr->next;
			}
			cout << " these   are  the  total  number  of the data : " << count << " : ----------" << endl;
		}
	}
};


int main() {
	singly_link_list l;
	l.create_node(1);
	l.create_node(2);
	l.create_node(3);
	l.create_node(4);
	l.create_node(5);

	l.display();
	cout << "------------" << endl;
	l.add_at_start(10);
	l.display();
	cout << "------------" << endl;

	l.at_position(3, 20);
	l.display();
	cout << "------------" << endl;

	l.delete_from_star();
	l.display();
	cout << "------------" << endl;

	l.delete_end();
	l.display();
	cout << "------------" << endl;

	l.delte_posi(3);
	l.display();
	cout << "------------" << endl;
	
	node* temp = new node;
	temp->data = 5;
	l.searching(temp);
	return 0;
}