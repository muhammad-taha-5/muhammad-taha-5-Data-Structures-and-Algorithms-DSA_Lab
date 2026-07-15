//#include<iostream>
//#include <string>
//using namespace std; 
//class node{
//
//public:
// string  name;
// string   topic;
// string  status;
//	node* next;
//
//};
//
//class planner {
//private :
//
//	node* head;
//public:
//
//
//	planner( ){
//		head = NULL;
//	}
//
//   void add_new_lac(string n, string t, string s){
//	   node* temp = new  node;
//	   temp->name = n;
//	   temp->topic=t;
//	   temp->status = s;
//
//	   if (head == NULL) {
//		   cout << "singly is  Empty "<< endl;
//		   head = temp;
//		   return;
//	   }
//	   else{
//		   node* curr = head;
//		   while (curr->next != NULL){
//			   curr = curr->next;
//		   }
//		   curr->next = temp->next;
//		   curr = temp;
//	   }
//   }
//   // now  for  circular 
//   void add(string n, string t, string s){
//	   node*  temp = new node;
//	   temp->name = n;
//	   temp->status = s;
//	   temp->topic = t;
//	  
//	   if (head ==NULL ){
//		   cout << "empty " << endl;
//		   head = temp;
//		   temp->next = head;
//	   }
//	   else{
//		   node* curr = head;
//
//		   while(curr->next!=head){
//
//			   curr = curr->next;
//		   }
//		   curr->next = temp;
//		   temp->next = head;
//	   }
//
//   }
//   void removing_lecturer( string n ){
//	   
//		   if (head == NULL) {
//			   cout << " empty " << endl;
//			   return;
//		   }if (head->name == n) {
//			   cout << "found " << endl;
//			   delete head;
//			   head = NULL;
//		   }
//		   else {
//			   node* curr = head;
//			   node* pre = NULL;
//			   while (curr->next != NULL) {
//				   if (curr->name == n) {
//					   cout << "found " << endl;
//					   pre->next = curr->next;
//					   delete curr;
//					   return;
//
//				   }
//				   pre = curr;
//				   curr = curr->next;
//			   }
//
//		   }
//   }
//   // now  for the  removing from the   circular  list
//   void  remove(string n) {
//
//	   if (head == NULL) {
//		   cout << " EMPTY " << endl;
//		   return;
//	   }
//	   node* pre=head;
//	   node* curr= head;
//	   do {
//		   if (head->name == n) {
//
//			   if (curr= head ) {
//				   node* tail=head;
//				   while (tail->next!=head) {
//					   tail = tail->next;
//				   }
//				   if (head->next == head ) {
//					   head = NULL;
//				   }
//				   else {
//					   head = head->next;
//					   tail->next = head;
//
//				   }
//			   }
//			   else {
//				   pre->next = curr->next;
//			   }
//			   delete curr;
//			   cout << "remved " << endl;
//			   return;
//		   }
//		   pre = curr;
//		   curr = curr->next;
//
//
//	   } while (curr!=head);
//
//   }
//   // display
//   void display() {
//	   if (head == NULL) {
//		   cout << "Empty\n";
//		   return;
//	   }
//
//	   node* temp = head;
//	   do {
//		   cout << temp->name << " | "
//			   << temp->topic << " | "
//			   << temp->status << endl;
//		   temp = temp->next;
//	   } while (temp != head);
//   }
//
//   //stumilate  next  4 
//   void nextLectures(string  n){
//	   if ( head  == NULL) {
//		   cout << "list  is  already Empty " << endl;
//		   return;
//	   }
//	   else {
//		   node* temp = head;
//		   int  c = 0;
//		   for (int i = 0; i < 4;) {
//			   if (temp->status == "Available") {
//				   cout << temp->name << " (" << temp->topic << ")\n";
//				   c++;
//				   i = c;
//			   }
//			   
//			   temp = temp->next;
//			}
//
//	   }
//   }
//
//
//
//
//
//};
//
//
//
//int  main() {
//
//	planner p;
//
//	p.add("Ali", "AI", "Available");
//	p.add("Sara", "DSA", "Not Available");
//	p.add("Ahmed", "DB", "Available");
//	p.add("Zain", "Networks", "Available");
//
//	cout << "\nAll Lecturers:\n";
//	p.display();
//
//	cout << "\nNext 4 Lectures from Ahmed:\n";
//	p.nextLectures("Ahmed");
//
//	cout << "\nRemoving Sara:\n";
//	p.remove("Sara");
//
//	cout << "\nUpdated List:\n";
//	p.display();
//
//
//	return 0; 
// }