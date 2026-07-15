// //Write a C++ program to implement a Circular Queue using an array.
// #include<iostream>
// using namespace std;
// class CircularQueue {
// private:
//     static const int MAX = 10;
//     int queue[10];
//     int front = -1;
//     int rear = -1;
// public:
//  //•	Enqueue (insert element) 
//   void Enqueue(int value){
//   if ((rear + 1) % MAX == front){
//     cout<< "  the  queue  is  full "<< endl; 
//      return; 
//    }
//    if ( front == -1 && rear == -1){
//       front = 0;
//     } 
//     rear = (rear + 1) % MAX; // (-1 + 1) % 5 = 0    when rear= 4 /(4 + 1) % 5 = 0
//     queue[rear]=value;
//   }

// // Dequeue (remove element) 
//   void Dequeue(){
//     if ( front == -1){
//       cout<< "  the  queue  is  empty "<< endl; 
//       return; 
//     }
//     cout << queue[front] << " removed from queue." << endl;
//     if (front == rear) {
//         front = -1;
//         rear = -1;
//     } else {
//         front = (front + 1) % MAX;
//     }
// }

//  // display
// void display() {
//     if (front == -1) {
//         cout << "Queue is Empty" << endl;
//         return;
//     }

//     cout << "Queue: ";
//     int i = front;
//     while (i != rear) {
//         cout << queue[i] << " ";
//         i = (i + 1) % MAX;
//     }
//     cout << queue[rear] << endl;
// }

// };


// int main  (){
//     CircularQueue q;

//     q.Enqueue(10);
//     q.Enqueue(20);
//     q.Enqueue(30);
//     q.Enqueue(20);
//     q.Enqueue(30);
//     q.Enqueue(10);
//     q.Enqueue(20);
//     q.Enqueue(10);
//     q.Enqueue(20);
//     q.Enqueue(30);
//     q.display();

//     q.Dequeue();

//     q.display();

//    q.Enqueue(20);
//    q.Enqueue(30);

//     q.display();

    
//     return 0;
// }                                                     