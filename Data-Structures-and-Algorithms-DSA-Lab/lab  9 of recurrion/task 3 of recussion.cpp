//#include <iostream>
//using  namespace std;
//int  maxnum(int  arr[], int size) {
//   
//    if (size == 1){
//        return arr[0];
//    }
//
//    int max = maxnum(arr, size -1);
//
//    if (  max  > arr[size-1]){
//          return max;
//    }
//
//    return arr[size - 1];
//}
//int main() {
//    int size = 5;
//    int  arr[5]{ 1,2,3,4,5 };
//    cout << "max  : " << maxnum(arr, size) << endl;
//    return  0;
//}