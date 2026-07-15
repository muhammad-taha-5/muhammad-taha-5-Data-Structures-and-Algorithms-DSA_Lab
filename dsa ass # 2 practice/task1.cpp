// #include<iostream>
// using namespace std;
// //C++ program to implement a Queue using an array.
// class Queue {
// private:
//     static const int MAX = 5;
//     int queue[MAX];
//     int front = -1;
//     int rear = -1;
// public:
//     //•	Enqueue (insert element) 
//   void Enqueue(int value){
//   if ( rear ==MAX -1){
//     cout<< "  the  queue  is  full "<< endl; 
//      return; 
//    }
//    if ( front == -1 && rear == -1){
//       front = 0;
//     } 
//     rear++;
//     queue[rear]=value;
//   }
  
// //•	Dequeue (remove element) 
//   void Dequeue(){
//     if ( front == -1 || front > rear){
//       cout<< "  the  queue  is  empty "<< endl; 
//       return; 
//     }
//     cout << queue[front] << " removed from queue." << endl;
//     front++;
//      if (front > rear)
//     {
//         front = -1;
//         rear = -1;
//     }
//     }

//     // display 
// void display()
// {
//     if (front == -1)
//     {
//         cout << "Queue is Empty" << endl;
//         return;
//     }

//     cout << "Queue: ";

//     for (int i = front; i <= rear; i++)
//     {
//         cout << queue[i] << " ";
//     }

//     cout << endl;
// }

// };

// int main  (){
//     Queue q;
//     q.Enqueue(10);
//     q.Enqueue(20);
//     q.Enqueue(30);
//    q.Enqueue(30); 
//     q.display();

//     q.Dequeue();

//     q.display();

//     q.Enqueue(40);
//     q.Enqueue(50);

//     q.display();

    
//     return 0;
// }                                                     