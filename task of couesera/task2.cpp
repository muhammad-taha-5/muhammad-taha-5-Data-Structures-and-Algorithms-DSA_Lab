// #include <iostream>
// #include <cstring>
// using namespace std;

// // ============= ARRAY ALGORITHMS CLASS =============
// class ArrayAlgorithms {
// private:
//     // Maximum array size
//     static const int MAX_SIZE = 100;

//     // Helper function to display array
//     void displayArray(int arr[], int n, const char* label = "Array") {
//         cout << label << ": ";
//         for (int i = 0; i < n; i++) {
//             cout << arr[i];
//             if (i < n - 1) cout << " ";
//         }
//         cout << endl;
//     }

//     // Helper function to input array with validation
//     bool inputArray(int arr[], int& n) {
//         cout << "Enter array size (1-" << MAX_SIZE << "): ";
//         cin >> n;
        
//         if (n <= 0 || n > MAX_SIZE) {
//             cout << "❌ Invalid size! Please enter between 1 and " << MAX_SIZE << endl;
//             return false;
//         }
        
//         cout << "Enter " << n << " array elements:\n";
//         for (int i = 0; i < n; i++) {
//             cout << "Element " << i << ": ";
//             cin >> arr[i];
//         }
        
//         return true;
//     }

// public:
//     // ============= FUNCTION 1: BINARY SEARCH =============
//     void binarySearch() {
//         cout << "\n========== BINARY SEARCH ==========\n";
        
//         int arr[MAX_SIZE];
//         int n, target;
        
//         if (!inputArray(arr, n)) return;
        
//         // Sort array (bubble sort for simplicity)
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = 0; j < n - i - 1; j++) {
//                 if (arr[j] > arr[j + 1]) {
//                     int temp = arr[j];
//                     arr[j] = arr[j + 1];
//                     arr[j + 1] = temp;
//                 }
//             }
//         }
        
//         displayArray(arr, n, "Sorted Array");
        
//         cout << "Enter target value to search: ";
//         cin >> target;
        
//         cout << "\n--- Binary Search Process ---\n";
        
//         int left = 0, right = n - 1, found = -1;
//         int iterations = 0;
        
//         while (left <= right) {
//             iterations++;
//             int mid = left + (right - left) / 2;
            
//             cout << "Iteration " << iterations << ": ";
//             cout << "left=" << left << ", right=" << right << ", mid=" << mid;
//             cout << " (arr[mid]=" << arr[mid] << ")\n";
            
//             if (arr[mid] == target) {
//                 found = mid;
//                 cout << "✓ Target found at index " << mid << endl;
//                 break;
//             } 
//             else if (arr[mid] < target) {
//                 cout << "  → Target is larger, search right half\n";
//                 left = mid + 1;
//             } 
//             else {
//                 cout << "  → Target is smaller, search left half\n";
//                 right = mid - 1;
//             }
//         }
        
//         cout << "\n--- Result ---\n";
//         if (found != -1) {
//             cout << "✅ Element " << target << " found at index: " << found << endl;
//         } else {
//             cout << "❌ Element " << target << " not found in array\n";
//         }
        
//         cout << "\nTime Complexity: O(log n)\n";
//         cout << "Space Complexity: O(1)\n";
//     }

//     // ============= FUNCTION 2: RUNNING SUM OF 1D ARRAY =============
//     void runningSumArray() {
//         cout << "\n========== RUNNING SUM OF 1D ARRAY ==========\n";
        
//         int arr[MAX_SIZE];
//         int n;
        
//         if (!inputArray(arr, n)) return;
        
//         displayArray(arr, n);
        
//         cout << "\n--- Running Sum Calculation ---\n";
//         int runningSum[MAX_SIZE];
//         runningSum[0] = arr[0];
//         cout << "Index 0: " << arr[0] << " → Running Sum[0] = " << runningSum[0] << endl;
        
//         for (int i = 1; i < n; i++) {
//             runningSum[i] = runningSum[i - 1] + arr[i];
//             cout << "Index " << i << ": " << runningSum[i - 1] << " + " << arr[i];
//             cout << " → Running Sum[" << i << "] = " << runningSum[i] << endl;
//         }
        
//         cout << "\n--- Result ---\n";
//         displayArray(runningSum, n, "Running Sum Array");
        
//         cout << "\nTime Complexity: O(n)\n";
//         cout << "Space Complexity: O(n)\n";
//     }

//     // ============= FUNCTION 3: FIND PIVOT INDEX =============
//     void findPivotIndex() {
//         cout << "\n========== FIND PIVOT INDEX ==========\n";
//         cout << "Pivot Index: Index where Left Sum == Right Sum\n\n";
        
//         int arr[MAX_SIZE];
//         int n;
        
//         if (!inputArray(arr, n)) return;
        
//         displayArray(arr, n);
        
//         cout << "\n--- Checking Each Index ---\n";
//         int pivotIdx = -1;
        
//         for (int i = 0; i < n; i++) {
//             int leftSum = 0, rightSum = 0;
            
//             // Calculate left sum
//             for (int j = 0; j < i; j++) {
//                 leftSum += arr[j];
//             }
            
//             // Calculate right sum
//             for (int j = i + 1; j < n; j++) {
//                 rightSum += arr[j];
//             }
            
//             cout << "Index " << i << ": ";
//             cout << "Left Sum = " << leftSum << ", Right Sum = " << rightSum;
            
//             if (leftSum == rightSum) {
//                 cout << " ✓ PIVOT FOUND!\n";
//                 pivotIdx = i;
//                 break;
//             } else {
//                 cout << endl;
//             }
//         }
        
//         cout << "\n--- Result ---\n";
//         if (pivotIdx != -1) {
//             cout << "✅ Pivot Index = " << pivotIdx << endl;
//         } else {
//             cout << "❌ No pivot index found\n";
//         }
        
//         cout << "\nTime Complexity: O(n²)\n";
//         cout << "Space Complexity: O(1)\n";
//     }

//     // ============= FUNCTION 4: MAXIMUM SUBARRAY (KADANE'S ALGORITHM) =============
//     void maximumSubarray() {
//         cout << "\n========== MAXIMUM SUBARRAY (KADANE'S ALGORITHM) ==========\n";
        
//         int arr[MAX_SIZE];
//         int n;
        
//         if (!inputArray(arr, n)) return;
        
//         displayArray(arr, n);
        
//         cout << "\n--- Kadane's Algorithm Process ---\n";
//         int currentSum = arr[0];
//         int maxSum = arr[0];
//         int start = 0, end = 0, tempStart = 0;
        
//         cout << "Index 0: currentSum = " << currentSum << ", maxSum = " << maxSum << endl;
        
//         for (int i = 1; i < n; i++) {
//             // Decide to extend or start new
//             if (currentSum + arr[i] >= arr[i]) {
//                 currentSum = currentSum + arr[i];
//                 cout << "Index " << i << ": Extend subarray: " << currentSum - arr[i] 
//                      << " + " << arr[i] << " = " << currentSum;
//             } else {
//                 currentSum = arr[i];
//                 tempStart = i;
//                 cout << "Index " << i << ": Start new: " << arr[i];
//             }
            
//             // Update max if needed
//             if (currentSum > maxSum) {
//                 maxSum = currentSum;
//                 start = tempStart;
//                 end = i;
//                 cout << " → NEW MAX = " << maxSum;
//             }
//             cout << endl;
//         }
        
//         cout << "\n--- Result ---\n";
//         cout << "✅ Maximum Sum = " << maxSum << endl;
//         cout << "   Subarray from index " << start << " to " << end << ": ";
//         for (int i = start; i <= end; i++) {
//             cout << arr[i];
//             if (i < end) cout << " ";
//         }
//         cout << endl;
        
//         cout << "\nTime Complexity: O(n)\n";
//         cout << "Space Complexity: O(1)\n";
//     }

//     // ============= FUNCTION 5: PRODUCT OF ARRAY EXCEPT SELF =============
//     void productOfArrayExceptSelf() {
//         cout << "\n========== PRODUCT OF ARRAY EXCEPT SELF ==========\n";
//         cout << "Find product of all elements except current element (No Division)\n\n";
        
//         int arr[MAX_SIZE];
//         int n;
        
//         if (!inputArray(arr, n)) return;
        
//         displayArray(arr, n);
        
//         if (n < 2) {
//             cout << "❌ Array size must be at least 2\n";
//             return;
//         }
        
//         int prefix[MAX_SIZE], suffix[MAX_SIZE], result[MAX_SIZE];
        
//         // Calculate prefix product
//         cout << "\n--- Prefix Products ---\n";
//         prefix[0] = 1;
//         cout << "prefix[0] = 1\n";
//         for (int i = 1; i < n; i++) {
//             prefix[i] = prefix[i - 1] * arr[i - 1];
//             cout << "prefix[" << i << "] = " << prefix[i] << endl;
//         }
        
//         // Calculate suffix product
//         cout << "\n--- Suffix Products ---\n";
//         suffix[n - 1] = 1;
//         cout << "suffix[" << n - 1 << "] = 1\n";
//         for (int i = n - 2; i >= 0; i--) {
//             suffix[i] = suffix[i + 1] * arr[i + 1];
//             cout << "suffix[" << i << "] = " << suffix[i] << endl;
//         }
        
//         // Calculate result
//         cout << "\n--- Result Calculation ---\n";
//         for (int i = 0; i < n; i++) {
//             result[i] = prefix[i] * suffix[i];
//             cout << "result[" << i << "] = " << prefix[i] << " × " << suffix[i] 
//                  << " = " << result[i] << endl;
//         }
        
//         cout << "\n--- Final Result ---\n";
//         displayArray(result, n, "Product of Array Except Self");
        
//         cout << "\nTime Complexity: O(n)\n";
//         cout << "Space Complexity: O(n)\n";
//     }

//     // ============= FUNCTION 6: FIND MINIMUM IN ROTATED SORTED ARRAY =============
//     void findMinInRotatedArray() {
//         cout << "\n========== FIND MINIMUM IN ROTATED SORTED ARRAY ==========\n";
        
//         int arr[MAX_SIZE];
//         int n;
        
//         if (!inputArray(arr, n)) return;
        
//         displayArray(arr, n);
        
//         cout << "\n--- Binary Search for Minimum ---\n";
//         int left = 0, right = n - 1;
//         int minVal = arr[0];
//         int iterations = 0;
        
//         while (left < right) {
//             iterations++;
//             int mid = left + (right - left) / 2;
            
//             cout << "Iteration " << iterations << ": ";
//             cout << "left=" << left << ", mid=" << mid << ", right=" << right;
//             cout << " | arr[mid]=" << arr[mid] << ", arr[right]=" << arr[right] << endl;
            
//             if (arr[mid] > arr[right]) {
//                 cout << "  → Minimum is in right half\n";
//                 left = mid + 1;
//             } else {
//                 cout << "  → Minimum is in left half (including mid)\n";
//                 right = mid;
//             }
//         }
        
//         minVal = arr[left];
        
//         cout << "\n--- Result ---\n";
//         cout << "✅ Minimum = " << minVal << " at index " << left << endl;
        
//         cout << "\nTime Complexity: O(log n)\n";
//         cout << "Space Complexity: O(1)\n";
//     }

//     // ============= FUNCTION 7: SEARCH IN ROTATED SORTED ARRAY =============
//     void searchInRotatedArray() {
//         cout << "\n========== SEARCH IN ROTATED SORTED ARRAY ==========\n";
        
//         int arr[MAX_SIZE];
//         int n, target;
        
//         if (!inputArray(arr, n)) return;
        
//         displayArray(arr, n);
        
//         cout << "Enter target value to search: ";
//         cin >> target;
        
//         cout << "\n--- Binary Search Process ---\n";
//         int left = 0, right = n - 1;
//         int found = -1;
//         int iterations = 0;
        
//         while (left <= right) {
//             iterations++;
//             int mid = left + (right - left) / 2;
            
//             cout << "Iteration " << iterations << ": ";
//             cout << "left=" << left << ", mid=" << mid << ", right=" << right;
//             cout << " | arr[mid]=" << arr[mid] << endl;
            
//             if (arr[mid] == target) {
//                 found = mid;
//                 cout << "✓ Target found at index " << mid << endl;
//                 break;
//             }
            
//             // Determine which half is sorted
//             if (arr[left] <= arr[mid]) {
//                 // Left half is sorted
//                 cout << "  → Left half is sorted\n";
//                 if (target >= arr[left] && target < arr[mid]) {
//                     cout << "     Target is in left half\n";
//                     right = mid - 1;
//                 } else {
//                     cout << "     Target is in right half\n";
//                     left = mid + 1;
//                 }
//             } else {
//                 // Right half is sorted
//                 cout << "  → Right half is sorted\n";
//                 if (target > arr[mid] && target <= arr[right]) {
//                     cout << "     Target is in right half\n";
//                     left = mid + 1;
//                 } else {
//                     cout << "     Target is in left half\n";
//                     right = mid - 1;
//                 }
//             }
//         }
        
//         cout << "\n--- Result ---\n";
//         if (found != -1) {
//             cout << "✅ Element " << target << " found at index: " << found << endl;
//         } else {
//             cout << "❌ Element " << target << " not found in array\n";
//         }
        
//         cout << "\nTime Complexity: O(log n)\n";
//         cout << "Space Complexity: O(1)\n";
//     }

//     // ============= FUNCTION 8: FIRST MISSING POSITIVE =============
//     void firstMissingPositive() {
//         cout << "\n========== FIRST MISSING POSITIVE ==========\n";
        
//         int arr[MAX_SIZE];
//         int n;
        
//         if (!inputArray(arr, n)) return;
        
//         displayArray(arr, n);
        
//         cout << "\n--- Finding First Missing Positive ---\n";
        
//         // Make a copy for tracking
//         int copy[MAX_SIZE];
//         for (int i = 0; i < n; i++) {
//             copy[i] = arr[i];
//         }
        
//         cout << "Checking positive integers starting from 1:\n";
//         for (int num = 1; num <= n + 1; num++) {
//             bool found = false;
//             cout << "Checking " << num << ": ";
            
//             for (int i = 0; i < n; i++) {
//                 if (arr[i] == num) {
//                     found = true;
//                     cout << "Found at index " << i << endl;
//                     break;
//                 }
//             }
            
//             if (!found) {
//                 cout << "NOT FOUND ✓\n";
//                 cout << "\n--- Result ---\n";
//                 cout << "✅ First Missing Positive = " << num << endl;
//                 break;
//             }
//         }
        
//         cout << "\nTime Complexity: O(n²)\n";
//         cout << "Space Complexity: O(1)\n";
//     }

//     // ============= FUNCTION 9: MEDIAN OF TWO SORTED ARRAYS =============
//     void medianOfTwoSortedArrays() {
//         cout << "\n========== MEDIAN OF TWO SORTED ARRAYS ==========\n";
        
//         int arr1[MAX_SIZE], arr2[MAX_SIZE];
//         int n1, n2;
        
//         cout << "\n--- First Array ---\n";
//         if (!inputArray(arr1, n1)) return;
        
//         cout << "\n--- Second Array ---\n";
//         if (!inputArray(arr2, n2)) return;
        
//         displayArray(arr1, n1, "Array 1");
//         displayArray(arr2, n2, "Array 2");
        
//         // Merge arrays
//         int merged[MAX_SIZE];
//         int totalLen = n1 + n2;
//         int i = 0, j = 0, k = 0;
        
//         cout << "\n--- Merging Process ---\n";
//         while (i < n1 && j < n2) {
//             if (arr1[i] <= arr2[j]) {
//                 merged[k++] = arr1[i];
//                 cout << "Merge arr1[" << i << "]=" << arr1[i] << endl;
//                 i++;
//             } else {
//                 merged[k++] = arr2[j];
//                 cout << "Merge arr2[" << j << "]=" << arr2[j] << endl;
//                 j++;
//             }
//         }
        
//         while (i < n1) {
//             merged[k++] = arr1[i];
//             cout << "Merge arr1[" << i << "]=" << arr1[i] << endl;
//             i++;
//         }
        
//         while (j < n2) {
//             merged[k++] = arr2[j];
//             cout << "Merge arr2[" << j << "]=" << arr2[j] << endl;
//             j++;
//         }
        
//         displayArray(merged, totalLen, "Merged Sorted Array");
        
//         cout << "\n--- Median Calculation ---\n";
//         double median;
//         if (totalLen % 2 == 1) {
//             int midIdx = totalLen / 2;
//             median = merged[midIdx];
//             cout << "Total elements: " << totalLen << " (odd)\n";
//             cout << "Median position: index " << midIdx << endl;
//             cout << "Median = " << merged[midIdx] << endl;
//         } else {
//             int mid1 = totalLen / 2 - 1;
//             int mid2 = totalLen / 2;
//             median = (merged[mid1] + merged[mid2]) / 2.0;
//             cout << "Total elements: " << totalLen << " (even)\n";
//             cout << "Median positions: indices " << mid1 << " and " << mid2 << endl;
//             cout << "Median = (" << merged[mid1] << " + " << merged[mid2] << ") / 2 = " << median << endl;
//         }
        
//         cout << "\n--- Result ---\n";
//         cout << "✅ Median = " << median << endl;
        
//         cout << "\nTime Complexity: O(n + m)\n";
//         cout << "Space Complexity: O(n + m)\n";
//     }
// };

// // ============= MENU CLASS =============
// class Menu {
// private:
//     ArrayAlgorithms algorithms;

//     void displayMainMenu() {
//         cout << "\n==============================\n";
//         cout << " WEEK 2 DSA PRACTICE PROJECT\n";
//         cout << "==============================\n\n";
//         cout << "1. Binary Search\n";
//         cout << "2. Running Sum of 1D Array\n";
//         cout << "3. Find Pivot Index\n";
//         cout << "4. Maximum Subarray (Kadane's Algorithm)\n";
//         cout << "5. Product of Array Except Self\n";
//         cout << "6. Find Minimum in Rotated Sorted Array\n";
//         cout << "7. Search in Rotated Sorted Array\n";
//         cout << "8. First Missing Positive\n";
//         cout << "9. Median of Two Sorted Arrays\n";
//         cout << "0. Exit\n\n";
//         cout << "Enter your choice (0-9): ";
//     }

// public:
//     void start() {
//         int choice;
//         bool running = true;
        
//         while (running) {
//             displayMainMenu();
//             cin >> choice;
            
//             if (cin.fail()) {
//                 cin.clear();
//                 cin.ignore(100, '\n');
//                 cout << "❌ Invalid input! Please enter a number between 0 and 9.\n";
//                 continue;
//             }
            
//             switch (choice) {
//                 case 1:
//                     algorithms.binarySearch();
//                     break;
//                 case 2:
//                     algorithms.runningSumArray();
//                     break;
//                 case 3:
//                     algorithms.findPivotIndex();
//                     break;
//                 case 4:
//                     algorithms.maximumSubarray();
//                     break;
//                 case 5:
//                     algorithms.productOfArrayExceptSelf();
//                     break;
//                 case 6:
//                     algorithms.findMinInRotatedArray();
//                     break;
//                 case 7:
//                     algorithms.searchInRotatedArray();
//                     break;
//                 case 8:
//                     algorithms.firstMissingPositive();
//                     break;
//                 case 9:
//                     algorithms.medianOfTwoSortedArrays();
//                     break;
//                 case 0:
//                     cout << "\n========================================\n";
//                     cout << "Thank you for using Week 2 DSA Practice!\n";
//                     cout << "Keep learning and practicing! 🚀\n";
//                     cout << "========================================\n\n";
//                     running = false;
//                     break;
//                 default:
//                     cout << "❌ Invalid choice! Please enter a number between 0 and 9.\n";
//             }
//         }
//     }
// };

// // ============= MAIN FUNCTION =============
// int main() {
//     Menu menu;
//     menu.start();
    
//     return 0;
// }