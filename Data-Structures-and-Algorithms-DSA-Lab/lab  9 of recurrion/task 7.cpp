//#include <iostream>
//using namespace std;
//
//// Find largest number recursively
//int findmax(int arr[], int size, int index = 1, int maxx = 0)
//{
//    if (index == size)
//    {
//        return maxx;
//    }
//    if (arr[index] > arr[maxx])
//    {
//        maxx = index;
//    }
//    return findmax(arr, size, index + 1, maxx);
//}
//
//// Recursive subset sum check
//bool subsetsum(int arr[], int size, int target, int index)
//{
//    // target achieved
//    if (target == 0)
//    {
//        return true;
//    }
//    // end of array
//    if (index == size || target < 0)
//    {
//        return false;
//    }
//
//    // include current element
//    bool include = subsetsum(arr, size, target - arr[index], index + 1);
//
//    // exclude current element
//    bool exclude = subsetsum(arr, size, target, index + 1);
//
//    return include || exclude;
//}
//
//// Recursive magic number finder
//int magicnumber(int arr[], int size)
//{
//    if (size <= 1)
//    {
//        return -1;
//    }
//
//    // find largest element index
//    int maxindex = findmax(arr, size);
//
//    int maxvalue = arr[maxindex];
//
//    // create remaining array
//    int* temp = new int[size - 1];
//
//    int k = 0;
//
//    for (int i = 0; i < size; i++)
//    {
//        if (i != maxindex)
//        {
//            temp[k] = arr[i];
//            k++;
//        }
//    }
//
//    // check subset sum
//    if (subsetsum(temp, size - 1, maxvalue, 0))
//    {
//        delete[] temp;
//        return maxvalue;
//    }
//
//    // remove largest and try again
//    int result = magicnumber(temp, size - 1);
//
//    delete[] temp;
//
//    return result;
//}
//
//int main()
//{
//    int arr[] = { 2, 3, 5, 8, 13 };
//
//    int size = 5;
//
//    int result = magicnumber(arr, size);
//
//    if (result != -1)
//    {
//        cout << "Magic Number : " << result << endl;
//    }
//    else
//    {
//        cout << "No Magic Number Found" << endl;
//    }
//
//    return 0;
//}