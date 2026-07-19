// #include <iostream>
// #include <cstring>
// using namespace std;


// class Arrays {
// private:
    
//     void displayArray(int arr[], int n) {
//         cout << "Array: ";
//         for (int i = 0; i < n; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }

    
//     void bubbleSort(int arr[], int n) {
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = 0; j < n - i - 1; j++) {
//                 if (arr[j] > arr[j + 1]) {
//                     int temp = arr[j];
//                     arr[j] = arr[j + 1];
//                     arr[j + 1] = temp;
//                 }
//             }
//         }
//     }

// public:
    
//     void TwoSum() {
//         cout << "\n========== TWO SUM (Day 1) ==========\n";
//         cout << "Find two numbers that add up to target\n";
        
//         int arr[] = {2, 7, 11, 15};
//         int n = 4;
//         int target = 9;
        
//         cout << "Array: ";
//         for (int i = 0; i < n; i++) cout << arr[i] << " ";
//         cout << "\nTarget: " << target << endl;
        
//         cout << "\nApproach: Nested Loops (Brute Force)\n";
//         cout << "Time Complexity: O(n^2)\n";
//         cout << "Space Complexity: O(1)\n\n";
        
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (arr[i] + arr[j] == target) {
//                     cout << "✅ Found! Indices: [" << i << ", " << j << "]\n";
//                     cout << "Values: " << arr[i] << " + " << arr[j] << " = " << target << endl;
//                     return;
//                 }
//             }
//         }
        
//         cout << "❌ No pair found\n";
//     }

    
//     void BestTimeToBuyAndSellStock() {
//         cout << "\n========== BEST TIME TO BUY & SELL STOCK (Day 2) ==========\n";
//         cout << "Find maximum profit from buying and selling stock once\n";
        
//         int arr[] = {7, 1, 5, 3, 6, 4};
//         int n = 6;
        
//         displayArray(arr, n);
        
//         cout << "\nApproach: Single Pass with Min Tracking\n";
//         cout << "Time Complexity: O(n)\n";
//         cout << "Space Complexity: O(1)\n\n";
        
//         int minPrice = arr[0];
//         int maxProfit = 0;
        
//         cout << "Iteration:\n";
//         for (int i = 1; i < n; i++) {
//             cout << "  Day " << i << ": Price = " << arr[i];
            
//             if (arr[i] < minPrice) {
//                 minPrice = arr[i];
//                 cout << " | New Min = " << minPrice;
//             }
            
//             int profit = arr[i] - minPrice;
//             if (profit > maxProfit) {
//                 maxProfit = profit;
//                 cout << " | New Max Profit = " << maxProfit;
//             }
//             cout << endl;
//         }
        
//         cout << "\n✅ Maximum Profit = " << maxProfit << endl;
//     }

    
//     void ContainsDuplicate() {
//         cout << "\n========== CONTAINS DUPLICATE (Day 3) ==========\n";
//         cout << "Check if array contains duplicate elements\n";
        
//         int arr[] = {1, 2, 3, 1};
//         int n = 4;
        
//         displayArray(arr, n);
        
//         cout << "\nApproach: Nested Loops (Brute Force)\n";
//         cout << "Time Complexity: O(n^2)\n";
//         cout << "Space Complexity: O(1)\n\n";
        
//         bool duplicate = false;
        
//         for (int i = 0; i < n && !duplicate; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (arr[i] == arr[j]) {
//                     cout << "✅ Duplicate Found: " << arr[i] << " at indices [" 
//                          << i << ", " << j << "]\n";
//                     duplicate = true;
//                     break;
//                 }
//             }
//         }
        
//         if (!duplicate) {
//             cout << "❌ No Duplicates Found\n";
//         }
//     }

    
//     void MoveZeroes() {
//         cout << "\n========== MOVE ZEROES (Day 4) ==========\n";
//         cout << "Move all zeros to the end while maintaining order\n";
        
//         int arr[] = {0, 1, 0, 3, 12};
//         int n = 5;
        
//         cout << "Original Array: ";
//         for (int i = 0; i < n; i++) cout << arr[i] << " ";
//         cout << endl;
        
//         cout << "\nApproach: Two Pointers\n";
//         cout << "Time Complexity: O(n)\n";
//         cout << "Space Complexity: O(1)\n\n";
        
//         int j = 0;
        
//         cout << "Processing:\n";
//         for (int i = 0; i < n; i++) {
//             if (arr[i] != 0) {
//                 cout << "  i=" << i << " (arr[i]=" << arr[i] << "), j=" << j;
//                 swap(arr[i], arr[j]);
//                 cout << " | Swap arr[" << i << "] and arr[" << j << "]\n";
//                 j++;
//             }
//         }
        
//         cout << "\n✅ Result Array: ";
//         for (int i = 0; i < n; i++) cout << arr[i] << " ";
//         cout << endl;
//     }

    
//     void ThreeSum() {
//         cout << "\n========== 3SUM (Day 5) ==========\n";
//         cout << "Find all unique triplets that sum to target (0)\n";
        
//         int arr[] = {-1, 0, 1, 2, -1, -4};
//         int n = 6;
        
//         cout << "Original Array: ";
//         for (int i = 0; i < n; i++) cout << arr[i] << " ";
//         cout << endl;
        
//         cout << "\nApproach: Sorting + Two Pointers\n";
//         cout << "Time Complexity: O(n^2)\n";
//         cout << "Space Complexity: O(1)\n\n";
        
        
//         bubbleSort(arr, n);
//         cout << "Sorted Array: ";
//         for (int i = 0; i < n; i++) cout << arr[i] << " ";
//         cout << endl << endl;
        
//         cout << "Finding triplets that sum to 0:\n";
//         int count = 0;
        
//         for (int i = 0; i < n - 2; i++) {
//             if (i > 0 && arr[i] == arr[i - 1]) continue;
            
//             int left = i + 1;
//             int right = n - 1;
//             int target = -arr[i];
            
//             while (left < right) {
//                 int sum = arr[left] + arr[right];
                
//                 if (sum == target) {
//                     count++;
//                     cout << "  Triplet " << count << ": [" << arr[i] << ", " 
//                          << arr[left] << ", " << arr[right] << "]\n";
//                     left++;
//                     right--;
                    
//                     while (left < right && arr[left] == arr[left - 1]) left++;
//                     while (left < right && arr[right] == arr[right + 1]) right--;
//                 } 
//                 else if (sum < target) {
//                     left++;
//                 } 
//                 else {
//                     right--;
//                 }
//             }
//         }
        
//         cout << "\n✅ Total Triplets Found: " << count << endl;
//     }

    
//     void ContainerWithMostWater() {
//         cout << "\n========== CONTAINER WITH MOST WATER (Day 6) ==========\n";
//         cout << "Find two lines that form maximum area container\n";
        
//         int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
//         int n = 9;
        
//         cout << "Heights: ";
//         for (int i = 0; i < n; i++) cout << height[i] << " ";
//         cout << endl;
        
//         cout << "\nApproach: Two Pointers\n";
//         cout << "Time Complexity: O(n)\n";
//         cout << "Space Complexity: O(1)\n\n";
        
//         int left = 0;
//         int right = n - 1;
//         int maxArea = 0;
//         int bestLeft = 0, bestRight = 0;
        
//         cout << "Iterations:\n";
//         int iter = 0;
        
//         while (left < right) {
//             iter++;
//             int width = right - left;
//             int currentHeight = min(height[left], height[right]);
//             int area = width * currentHeight;
            
//             cout << "  Iter " << iter << ": left=" << left << " (h=" << height[left] 
//                  << "), right=" << right << " (h=" << height[right] 
//                  << ") | width=" << width << ", height=" << currentHeight 
//                  << ", area=" << area;
            
//             if (area > maxArea) {
//                 maxArea = area;
//                 bestLeft = left;
//                 bestRight = right;
//                 cout << " ✓ NEW MAX";
//             }
//             cout << endl;
            
//             if (height[left] < height[right]) {
//                 left++;
//             } else {
//                 right--;
//             }
//         }
        
//         cout << "\n✅ Maximum Area = " << maxArea << " (indices [" << bestLeft 
//              << ", " << bestRight << "])\n";
//     }

    
//     void LongestSubarraySumK() {
//         cout << "\n========== LONGEST SUBARRAY WITH SUM K (Day 7) ==========\n";
//         cout << "Find longest subarray with given sum\n";
        
//         int arr[] = {1, 2, 1, 1, 1};
//         int n = 5;
//         int k = 3;
        
//         cout << "Array: ";
//         for (int i = 0; i < n; i++) cout << arr[i] << " ";
//         cout << "\nTarget Sum K: " << k << endl;
        
//         cout << "\nApproach: Sliding Window\n";
//         cout << "Time Complexity: O(n)\n";
//         cout << "Space Complexity: O(1)\n\n";
        
//         int maxLen = 0;
//         int bestStart = 0;
        
//         cout << "Sliding Window:\n";
        
//         for (int i = 0; i < n; i++) {
//             int sum = 0;
            
//             for (int j = i; j < n; j++) {
//                 sum += arr[j];
//                 int len = j - i + 1;
                
//                 cout << "  Window [" << i << ", " << j << "]: ";
//                 for (int x = i; x <= j; x++) cout << arr[x] << " ";
//                 cout << "| Sum=" << sum << ", Len=" << len;
                
//                 if (sum == k) {
//                     cout << " ✓ MATCH";
//                     if (len > maxLen) {
//                         maxLen = len;
//                         bestStart = i;
//                         cout << " (NEW MAX)";
//                     }
//                 }
//                 cout << endl;
                
//                 if (sum > k) break;
//             }
//         }
        
//         cout << "\n✅ Longest Subarray Length = " << maxLen << endl;
//         if (maxLen > 0) {
//             cout << "  Subarray: ";
//             for (int i = bestStart; i < bestStart + maxLen; i++) {
//                 cout << arr[i] << " ";
//             }
//             cout << endl;
//         }
//     }

    
//     void MaxConsecutiveOnesIII() {
//         cout << "\n========== MAX CONSECUTIVE ONES III (Day 7) ==========\n";
//         cout << "Max consecutive ones after flipping at most K zeros\n";
        
//         int arr[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
//         int n = 11;
//         int k = 2;
        
//         cout << "Array: ";
//         for (int i = 0; i < n; i++) cout << arr[i] << " ";
//         cout << "\nMax Flips K: " << k << endl;
        
//         cout << "\nApproach: Sliding Window\n";
//         cout << "Time Complexity: O(n)\n";
//         cout << "Space Complexity: O(1)\n\n";
        
//         int left = 0;
//         int maxLen = 0;
//         int zeroCount = 0;
        
//         cout << "Sliding Window:\n";
        
//         for (int right = 0; right < n; right++) {
//             if (arr[right] == 0) {
//                 zeroCount++;
//             }
            
//             cout << "  right=" << right << " (arr[" << right << "]=" << arr[right] 
//                  << ") | zeroCount=" << zeroCount;
            
//             while (zeroCount > k) {
//                 if (arr[left] == 0) {
//                     zeroCount--;
//                 }
//                 left++;
//             }
            
//             int len = right - left + 1;
//             if (len > maxLen) {
//                 maxLen = len;
//                 cout << " → NEW MAX (len=" << len << ")";
//             }
//             cout << endl;
//         }
        
//         cout << "\n✅ Maximum Consecutive Ones = " << maxLen << endl;
//     }

    
//     void Menu() {
//         int choice;
//         bool exit_flag = false;
        
//         while (!exit_flag) {
//             cout << "\n\n";
//             cout << "================================\n";
//             cout << "    WEEK 1 - DSA PROBLEMS\n";
//             cout << "================================\n";
//             cout << "1.  Two Sum\n";
//             cout << "2.  Best Time to Buy & Sell Stock\n";
//             cout << "3.  Contains Duplicate\n";
//             cout << "4.  Move Zeroes\n";
//             cout << "5.  3Sum\n";
//             cout << "6.  Container With Most Water\n";
//             cout << "7.  Longest Subarray with Sum K\n";
//             cout << "8.  Max Consecutive Ones III\n";
//             cout << "9.  Exit\n";
//             cout << "================================\n";
//             cout << "Enter your choice (1-9): ";
//             cin >> choice;
            
//             cout << "\n";
            
//             switch (choice) {
//                 case 1:
//                     TwoSum();
//                     break;
//                 case 2:
//                     BestTimeToBuyAndSellStock();
//                     break;
//                 case 3:
//                     ContainsDuplicate();
//                     break;
//                 case 4:
//                     MoveZeroes();
//                     break;
//                 case 5:
//                     ThreeSum();
//                     break;
//                 case 6:
//                     ContainerWithMostWater();
//                     break;
//                 case 7:
//                     LongestSubarraySumK();
//                     break;
//                 case 8:
//                     MaxConsecutiveOnesIII();
//                     break;
//                 case 9:
//                     cout << "========================================\n";
//                     cout << "Thank you for using Week 1 DSA Problems!\n";
//                     cout << "Keep practicing! 🚀\n";
//                     cout << "========================================\n";
//                     exit_flag = true;
//                     break;
//                 default:
//                     cout << "❌ Invalid choice! Please enter 1-9.\n";
//             }
//         }
//     }
// };


// int main() {
//     Arrays dsa;
//     dsa.Menu();
    
//     return 0;
// }