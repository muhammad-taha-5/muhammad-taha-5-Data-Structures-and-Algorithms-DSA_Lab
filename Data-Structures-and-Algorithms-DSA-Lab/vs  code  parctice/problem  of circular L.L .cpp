// #include<iostream>
// using namespace std;

// struct node
// {
//     int data;
//     node* next;
// };   
// class CList
// {
//     node* head;
// public:

//     CList()
//     {
//         head = NULL;
//     }

//     void create(int N)
//     {
//         node* temp;
//         node* newnode;

//         for(int i = 1; i <= N; i++)
//         {
//             newnode = new node;
//             newnode->data = i;

//             if(head == NULL)
//             {
//                 head = newnode;
//                 newnode->next = head;
//                 temp = head;
//             }
//             else
//             {
//                 temp->next = newnode;
//                 newnode->next = head;
//                 temp = newnode;
//             }
//         }
//     }

//     void josephus(int M)
//     {
//         node* temp = head;

//         while(temp->next != temp)
//         {
//             for(int i = 1; i < M-1; i++)
//             {
//                 temp = temp->next;
//             }

//             node* del = temp->next;
//             cout << "Removed: " << del->data << endl;

//             temp->next = del->next;
//             delete del;

//             temp = temp->next;
//         }

//         cout << "Leader is: " << temp->data << endl;
//     }
// };

// int main()
// {
//     CList obj;

//     obj.create(10);     // N = 10
//     obj.josephus(3);    // M = 3

//     return 0;
// }