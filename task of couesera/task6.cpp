// // WEEK 6 DSA PRACTICE PROJECT - Heaps, Priority Queue, Trie & Backtracking (OOP, menu-driven)

// #include <iostream>
// #include <vector>
// #include <string>
// #include <queue>
// #include <algorithm>
// using namespace std;

// // ---------------------------------------------------------------
// // HeapAlgorithms
// // Keeps the last processed array in heapArray so "Display Heap"
// // and "Clear Data Structures" have something to act on.
// // ---------------------------------------------------------------
// class HeapAlgorithms {
// private:
//     vector<int> heapArray; // data behind the most recent heap operation

//     void printArray(const vector<int>& arr, const string& label) {
//         cout << label << ": ";
//         if (arr.empty()) { cout << "(empty)"; }
//         else { for (int v : arr) cout << v << " "; }
//         cout << endl;
//     }

// public:
//     /* Function 1: Kth Largest Element in an Array
//        Objective: Find the k-th largest value in an array.
//        Algorithm: Maintain a min-heap of size k. Push every element;
//        whenever the heap grows past size k, pop the smallest. The
//        heap's top is left holding the k-th largest value.
//        Input: array + k. Output: k-th largest value.
//        Time: O(n log k). Space: O(k). */
//     void kthLargestElement() {
//         cout << endl << "========== KTH LARGEST ELEMENT ==========" << endl;
//         int n;
//         cout << "Enter array size: ";
//         cin >> n;
//         if (n <= 0) { cout << "Invalid size." << endl; return; }
//         vector<int> arr(n);
//         cout << "Enter " << n << " integers: ";
//         for (int i = 0; i < n; i++) cin >> arr[i];

//         int k;
//         cout << "Enter k: ";
//         cin >> k;
//         if (k <= 0 || k > n) { cout << "Invalid k." << endl; return; }

//         heapArray = arr;
//         printArray(arr, "Original Array");

//         priority_queue<int, vector<int>, greater<int>> minHeap; // size-k min-heap
//         cout << endl << "Processing:" << endl;
//         for (int val : arr) {
//             minHeap.push(val);
//             cout << "  Push " << val;
//             if ((int)minHeap.size() > k) {
//                 cout << " -> heap exceeds size " << k << ", pop smallest (" << minHeap.top() << ")";
//                 minHeap.pop();
//             }
//             cout << endl;
//         }

//         cout << endl << "--- Result ---" << endl;
//         cout << k << "-th Largest Element: " << minHeap.top() << endl;
//         cout << endl << "Time Complexity: O(n log k)" << endl;
//         cout << "Space Complexity: O(k)" << endl;
//     }

//     /* Function 2: Last Stone Weight
//        Objective: Repeatedly smash the two heaviest stones until at
//        most one remains.
//        Algorithm: Use a max-heap. Pop the two largest stones y and x;
//        if unequal, push the difference back; if equal, both vanish.
//        Input: array of stone weights. Output: weight of final stone (or 0).
//        Time: O(n log n). Space: O(n). */
//     void lastStoneWeight() {
//         cout << endl << "========== LAST STONE WEIGHT ==========" << endl;
//         int n;
//         cout << "Enter number of stones: ";
//         cin >> n;
//         if (n <= 0) { cout << "Invalid size." << endl; return; }
//         vector<int> stones(n);
//         cout << "Enter " << n << " stone weights: ";
//         for (int i = 0; i < n; i++) cin >> stones[i];

//         heapArray = stones;
//         printArray(stones, "Original Stones");

//         priority_queue<int> maxHeap(stones.begin(), stones.end());
//         cout << endl << "Smashing Process:" << endl;
//         while (maxHeap.size() > 1) {
//             int y = maxHeap.top(); maxHeap.pop();
//             int x = maxHeap.top(); maxHeap.pop();
//             cout << "  Smash " << y << " and " << x;
//             if (y != x) {
//                 int diff = y - x;
//                 cout << " -> remainder " << diff << " pushed back" << endl;
//                 maxHeap.push(diff);
//             } else {
//                 cout << " -> both destroyed completely" << endl;
//             }
//         }

//         int result = maxHeap.empty() ? 0 : maxHeap.top();
//         heapArray = maxHeap.empty() ? vector<int>{} : vector<int>{result};

//         cout << endl << "--- Result ---" << endl;
//         cout << "Last Stone Weight: " << result << endl;
//         cout << endl << "Time Complexity: O(n log n)" << endl;
//         cout << "Space Complexity: O(n)" << endl;
//     }

//     /* Function 3: K Closest Points to Origin
//        Objective: Find the k points closest to (0,0).
//        Algorithm: Maintain a max-heap of size k keyed on squared
//        distance. Push every point; when the heap exceeds size k,
//        pop the farthest point. What remains are the k closest.
//        Input: list of (x,y) points + k. Output: the k closest points.
//        Time: O(n log k). Space: O(k). */
//     void kClosestPoints() {
//         cout << endl << "========== K CLOSEST POINTS TO ORIGIN ==========" << endl;
//         int n;
//         cout << "Enter number of points: ";
//         cin >> n;
//         if (n <= 0) { cout << "Invalid size." << endl; return; }
//         vector<pair<int,int>> points(n);
//         cout << "Enter " << n << " points as x y pairs:" << endl;
//         for (int i = 0; i < n; i++) {
//             cout << "Point " << i + 1 << " (x y): ";
//             cin >> points[i].first >> points[i].second;
//         }

//         int k;
//         cout << "Enter k: ";
//         cin >> k;
//         if (k <= 0 || k > n) { cout << "Invalid k." << endl; return; }

//         cout << endl << "Original Points: ";
//         for (auto& p : points) cout << "(" << p.first << "," << p.second << ") ";
//         cout << endl;

//         // max-heap of (distance^2, index), size capped at k
//         priority_queue<pair<long long,int>> maxHeap;
//         cout << endl << "Processing:" << endl;
//         for (int i = 0; i < n; i++) {
//             long long dist = (long long)points[i].first * points[i].first +
//                               (long long)points[i].second * points[i].second;
//             maxHeap.push({dist, i});
//             cout << "  Push (" << points[i].first << "," << points[i].second
//                  << ") dist^2=" << dist;
//             if ((int)maxHeap.size() > k) {
//                 cout << " -> heap exceeds size " << k << ", pop farthest";
//                 maxHeap.pop();
//             }
//             cout << endl;
//         }

//         vector<pair<long long,int>> closest;
//         heapArray.clear();
//         while (!maxHeap.empty()) { closest.push_back(maxHeap.top()); heapArray.push_back((int)maxHeap.top().first); maxHeap.pop(); }
//         sort(closest.begin(), closest.end());

//         cout << endl << "--- Result ---" << endl;
//         cout << k << " Closest Points: ";
//         for (auto& c : closest) {
//             int idx = c.second;
//             cout << "(" << points[idx].first << "," << points[idx].second << ") ";
//         }
//         cout << endl;
//         cout << endl << "Time Complexity: O(n log k)" << endl;
//         cout << "Space Complexity: O(k)" << endl;
//     }

//     /* Function: Display Heap
//        Objective: Show the data behind the most recent heap operation.
//        Algorithm: Rebuild a max-heap (std::make_heap) over the stored
//        array and print it in array form, since std::priority_queue
//        does not expose iteration directly.
//        Time: O(n). Space: O(1) extra. */
//     void displayHeap() {
//         cout << endl << "========== DISPLAY HEAP ==========" << endl;
//         if (heapArray.empty()) { cout << "No heap data available." << endl; return; }
//         vector<int> copy = heapArray;
//         make_heap(copy.begin(), copy.end());
//         printArray(copy, "Heap (array form, max-heap order)");
//         cout << "Root (largest): " << copy.front() << endl;
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(1) extra" << endl;
//     }

//     /* Function: Clear Heap Data
//        Objective: Discard the stored heap array.
//        Time: O(1). Space: O(1). */
//     void clear() {
//         heapArray.clear();
//     }
// };

// // ---------------------------------------------------------------
// // TrieAlgorithms
// // Standard 26-ary trie for lowercase words.
// // ---------------------------------------------------------------
// struct TrieNode {
//     TrieNode* children[26];
//     bool isEnd;
//     TrieNode() : isEnd(false) {
//         for (int i = 0; i < 26; i++) children[i] = nullptr;
//     }
// };

// class TrieAlgorithms {
// private:
//     TrieNode* root;

//     bool isValidWord(const string& word) {
//         if (word.empty()) return false;
//         for (char c : word) if (c < 'a' || c > 'z') return false;
//         return true;
//     }

//     void collectWords(TrieNode* node, string current, vector<string>& words) {
//         if (node->isEnd) words.push_back(current);
//         for (int i = 0; i < 26; i++) {
//             if (node->children[i]) collectWords(node->children[i], current + char('a' + i), words);
//         }
//     }

//     void clearHelper(TrieNode* node) {
//         if (node == nullptr) return;
//         for (int i = 0; i < 26; i++) clearHelper(node->children[i]);
//         delete node;
//     }

// public:
//     TrieAlgorithms() { root = new TrieNode(); }
//     ~TrieAlgorithms() { clearHelper(root); }

//     /* Function: Insert Word
//        Objective: Add a word into the trie.
//        Algorithm: Walk the word char by char; create a child node
//        when the path does not already exist; mark the last node
//        as a word ending.
//        Input: lowercase word. Output: updated trie.
//        Time: O(L). Space: O(L) worst case new nodes. */
//     void insertWord() {
//         cout << endl << "========== TRIE: INSERT WORD ==========" << endl;
//         string word;
//         cout << "Enter a lowercase word: ";
//         cin >> word;
//         if (!isValidWord(word)) { cout << "Invalid input: use lowercase letters a-z only." << endl; return; }

//         TrieNode* curr = root;
//         cout << "Insertion Steps:" << endl;
//         for (char c : word) {
//             int idx = c - 'a';
//             if (curr->children[idx] == nullptr) {
//                 curr->children[idx] = new TrieNode();
//                 cout << "  '" << c << "' -> create new node" << endl;
//             } else {
//                 cout << "  '" << c << "' -> node already exists, reuse it" << endl;
//             }
//             curr = curr->children[idx];
//         }
//         curr->isEnd = true;
//         cout << endl << "--- Result ---" << endl;
//         cout << "Word \"" << word << "\" inserted." << endl;
//         cout << endl << "Time Complexity: O(L), L = word length" << endl;
//         cout << "Space Complexity: O(L) worst case" << endl;
//     }

//     /* Function: Search Word
//        Objective: Check whether a full word exists in the trie.
//        Algorithm: Follow the word's characters down the trie; if
//        any character is missing, the word is absent; otherwise it
//        exists only if the final node is marked as a word end.
//        Input: word. Output: found/not found.
//        Time: O(L). Space: O(1). */
//     void searchWord() {
//         cout << endl << "========== TRIE: SEARCH WORD ==========" << endl;
//         string word;
//         cout << "Enter a lowercase word: ";
//         cin >> word;
//         if (!isValidWord(word)) { cout << "Invalid input: use lowercase letters a-z only." << endl; return; }

//         TrieNode* curr = root;
//         bool found = true;
//         cout << "Search Steps:" << endl;
//         for (char c : word) {
//             int idx = c - 'a';
//             if (curr->children[idx] == nullptr) {
//                 cout << "  '" << c << "' -> path missing, not found" << endl;
//                 found = false;
//                 break;
//             }
//             cout << "  '" << c << "' -> path exists" << endl;
//             curr = curr->children[idx];
//         }
//         if (found && !curr->isEnd) {
//             cout << "  Path exists but no word ends here" << endl;
//             found = false;
//         }

//         cout << endl << "--- Result ---" << endl;
//         cout << (found ? "Word Found" : "Word Not Found") << endl;
//         cout << endl << "Time Complexity: O(L)" << endl;
//         cout << "Space Complexity: O(1)" << endl;
//     }

//     /* Function: Check Prefix (StartsWith)
//        Objective: Check whether any stored word starts with a prefix.
//        Algorithm: Same walk as search, but does not require the
//        final node to be a word ending - only that the path exists.
//        Input: prefix. Output: exists/does not exist.
//        Time: O(L). Space: O(1). */
//     void startsWith() {
//         cout << endl << "========== TRIE: CHECK PREFIX ==========" << endl;
//         string prefix;
//         cout << "Enter a lowercase prefix: ";
//         cin >> prefix;
//         if (!isValidWord(prefix)) { cout << "Invalid input: use lowercase letters a-z only." << endl; return; }

//         TrieNode* curr = root;
//         bool found = true;
//         cout << "Search Steps:" << endl;
//         for (char c : prefix) {
//             int idx = c - 'a';
//             if (curr->children[idx] == nullptr) {
//                 cout << "  '" << c << "' -> path missing" << endl;
//                 found = false;
//                 break;
//             }
//             cout << "  '" << c << "' -> path exists" << endl;
//             curr = curr->children[idx];
//         }

//         cout << endl << "--- Result ---" << endl;
//         cout << (found ? "Prefix Exists" : "Prefix Does Not Exist") << endl;
//         cout << endl << "Time Complexity: O(L)" << endl;
//         cout << "Space Complexity: O(1)" << endl;
//     }

//     /* Function: Display Trie
//        Objective: Show every word currently stored in the trie.
//        Algorithm: DFS from the root, building up each path's
//        characters, recording a word whenever a node marks isEnd.
//        Time: O(total characters stored). Space: O(total characters). */
//     void displayTrie() {
//         cout << endl << "========== DISPLAY TRIE ==========" << endl;
//         vector<string> words;
//         collectWords(root, "", words);
//         if (words.empty()) { cout << "Trie is empty." << endl; return; }
//         cout << "Stored Words: ";
//         for (auto& w : words) cout << w << " ";
//         cout << endl;
//         cout << endl << "Time Complexity: O(total characters)" << endl;
//         cout << "Space Complexity: O(total characters)" << endl;
//     }

//     /* Function: Clear Trie
//        Objective: Free every trie node safely.
//        Algorithm: Recursively delete all children before the node.
//        Time: O(total nodes). Space: O(depth) recursion. */
//     void clear() {
//         clearHelper(root);
//         root = new TrieNode();
//     }
// };

// // ---------------------------------------------------------------
// // BacktrackingAlgorithms
// // Classic backtracking problems: Word Search, Combination Sum,
// // Subsets, Permutations.
// // ---------------------------------------------------------------
// class BacktrackingAlgorithms {
// private:
//     bool wordSearchHelper(vector<vector<char>>& grid, const string& word, int i, int j,
//                            int idx, vector<vector<bool>>& visited) {
//         if (idx == (int)word.size()) return true;
//         int rows = grid.size(), cols = grid[0].size();
//         if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] || grid[i][j] != word[idx]) return false;

//         cout << "  Visit (" << i << "," << j << ") matches '" << word[idx] << "'" << endl;
//         visited[i][j] = true;

//         bool found = wordSearchHelper(grid, word, i + 1, j, idx + 1, visited) ||
//                      wordSearchHelper(grid, word, i - 1, j, idx + 1, visited) ||
//                      wordSearchHelper(grid, word, i, j + 1, idx + 1, visited) ||
//                      wordSearchHelper(grid, word, i, j - 1, idx + 1, visited);

//         if (!found) {
//             cout << "  Dead end at (" << i << "," << j << ") -> backtrack" << endl;
//             visited[i][j] = false;
//         }
//         return found;
//     }

//     void combinationSumHelper(vector<int>& candidates, int target, int start,
//                                vector<int>& current, vector<vector<int>>& results) {
//         if (target == 0) { results.push_back(current); return; }
//         if (target < 0) return;
//         for (int i = start; i < (int)candidates.size(); i++) {
//             if (candidates[i] > target) continue;
//             current.push_back(candidates[i]);
//             cout << "  Choose " << candidates[i] << ", remaining target=" << target - candidates[i] << endl;
//             combinationSumHelper(candidates, target - candidates[i], i, current, results); // reuse allowed
//             cout << "  Backtrack, remove " << candidates[i] << endl;
//             current.pop_back();
//         }
//     }

//     void subsetsHelper(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& results) {
//         if (index == (int)nums.size()) { results.push_back(current); return; }
//         subsetsHelper(nums, index + 1, current, results); // exclude nums[index]
//         current.push_back(nums[index]);
//         cout << "  Include " << nums[index] << endl;
//         subsetsHelper(nums, index + 1, current, results); // include nums[index]
//         current.pop_back();
//         cout << "  Backtrack, exclude " << nums[index] << endl;
//     }

//     void permutationsHelper(vector<int>& nums, vector<bool>& used, vector<int>& current,
//                              vector<vector<int>>& results) {
//         if ((int)current.size() == (int)nums.size()) { results.push_back(current); return; }
//         for (int i = 0; i < (int)nums.size(); i++) {
//             if (used[i]) continue;
//             used[i] = true;
//             current.push_back(nums[i]);
//             cout << "  Choose " << nums[i] << endl;
//             permutationsHelper(nums, used, current, results);
//             current.pop_back();
//             used[i] = false;
//             cout << "  Backtrack, remove " << nums[i] << endl;
//         }
//     }

// public:
//     /* Function: Word Search
//        Objective: Determine if a word can be formed by moving
//        up/down/left/right through adjacent grid cells (no reuse).
//        Algorithm: DFS + backtracking from every matching starting
//        cell, marking visited cells and unmarking on dead ends.
//        Input: grid + word. Output: found/not found.
//        Time: O(rows*cols*4^L). Space: O(L) recursion + O(rows*cols) visited. */
//     void wordSearch() {
//         cout << endl << "========== WORD SEARCH ==========" << endl;
//         int rows, cols;
//         cout << "Enter grid rows: "; cin >> rows;
//         cout << "Enter grid cols: "; cin >> cols;
//         if (rows <= 0 || cols <= 0) { cout << "Invalid grid size." << endl; return; }

//         vector<vector<char>> grid(rows, vector<char>(cols));
//         cout << "Enter grid characters row by row (no spaces between rows' cells needed, space-separated):" << endl;
//         for (int i = 0; i < rows; i++) {
//             cout << "Row " << i << ": ";
//             for (int j = 0; j < cols; j++) cin >> grid[i][j];
//         }

//         string word;
//         cout << "Enter word to search: ";
//         cin >> word;

//         cout << endl << "Grid:" << endl;
//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) cout << grid[i][j] << " ";
//             cout << endl;
//         }

//         vector<vector<bool>> visited(rows, vector<bool>(cols, false));
//         bool found = false;
//         cout << endl << "Search Steps:" << endl;
//         for (int i = 0; i < rows && !found; i++) {
//             for (int j = 0; j < cols && !found; j++) {
//                 if (grid[i][j] == word[0]) {
//                     found = wordSearchHelper(grid, word, i, j, 0, visited);
//                 }
//             }
//         }

//         cout << endl << "--- Result ---" << endl;
//         cout << (found ? "Word Found" : "Word Not Found") << endl;
//         cout << endl << "Time Complexity: O(rows*cols*4^L)" << endl;
//         cout << "Space Complexity: O(L) recursion + O(rows*cols) visited" << endl;
//     }

//     /* Function: Combination Sum
//        Objective: Find all unique combinations of candidates that
//        sum exactly to a target (each candidate reusable any number
//        of times).
//        Algorithm: Backtrack from each start index, subtracting the
//        chosen candidate from target; reuse the same index to allow
//        repeats, advance for the next candidate to avoid duplicates.
//        Input: candidates + target. Output: all valid combinations.
//        Time: O(2^target) roughly. Space: O(target) recursion depth. */
//     void combinationSum() {
//         cout << endl << "========== COMBINATION SUM ==========" << endl;
//         int n;
//         cout << "Enter number of candidates: ";
//         cin >> n;
//         if (n <= 0) { cout << "Invalid size." << endl; return; }
//         vector<int> candidates(n);
//         cout << "Enter " << n << " positive candidates: ";
//         for (int i = 0; i < n; i++) cin >> candidates[i];

//         int target;
//         cout << "Enter target sum: ";
//         cin >> target;
//         if (target <= 0) { cout << "Invalid target." << endl; return; }

//         sort(candidates.begin(), candidates.end());
//         cout << "Candidates (sorted): ";
//         for (int c : candidates) cout << c << " ";
//         cout << endl << "Target: " << target << endl;

//         vector<vector<int>> results;
//         vector<int> current;
//         cout << endl << "Backtracking Steps:" << endl;
//         combinationSumHelper(candidates, target, 0, current, results);

//         cout << endl << "--- Result ---" << endl;
//         if (results.empty()) cout << "No combinations found." << endl;
//         else {
//             cout << "Combinations Found:" << endl;
//             for (auto& combo : results) {
//                 cout << "  [ ";
//                 for (int v : combo) cout << v << " ";
//                 cout << "]" << endl;
//             }
//         }
//         cout << endl << "Time Complexity: O(2^target) roughly" << endl;
//         cout << "Space Complexity: O(target) recursion depth" << endl;
//     }

//     /* Function: Subsets
//        Objective: Generate every possible subset (the power set)
//        of a given array.
//        Algorithm: For each element, backtrack twice - once
//        excluding it, once including it - covering all 2^n combos.
//        Input: array. Output: all subsets.
//        Time: O(2^n). Space: O(n) recursion + O(2^n * n) output. */
//     void subsets() {
//         cout << endl << "========== SUBSETS ==========" << endl;
//         int n;
//         cout << "Enter array size: ";
//         cin >> n;
//         if (n <= 0) { cout << "Invalid size." << endl; return; }
//         vector<int> nums(n);
//         cout << "Enter " << n << " integers: ";
//         for (int i = 0; i < n; i++) cin >> nums[i];

//         cout << "Original Array: ";
//         for (int v : nums) cout << v << " ";
//         cout << endl;

//         vector<vector<int>> results;
//         vector<int> current;
//         cout << endl << "Backtracking Steps:" << endl;
//         subsetsHelper(nums, 0, current, results);

//         cout << endl << "--- Result ---" << endl;
//         cout << "All Subsets (" << results.size() << " total):" << endl;
//         for (auto& s : results) {
//             cout << "  { ";
//             for (int v : s) cout << v << " ";
//             cout << "}" << endl;
//         }
//         cout << endl << "Time Complexity: O(2^n)" << endl;
//         cout << "Space Complexity: O(n) recursion + O(2^n * n) output" << endl;
//     }

//     /* Function: Permutations
//        Objective: Generate every possible ordering of a given array.
//        Algorithm: Backtrack by choosing each unused element next,
//        marking it used, recursing, then unmarking it (backtrack)
//        before trying the next choice.
//        Input: array. Output: all permutations.
//        Time: O(n!). Space: O(n) recursion + O(n! * n) output. */
//     void permutations() {
//         cout << endl << "========== PERMUTATIONS ==========" << endl;
//         int n;
//         cout << "Enter array size: ";
//         cin >> n;
//         if (n <= 0) { cout << "Invalid size." << endl; return; }
//         vector<int> nums(n);
//         cout << "Enter " << n << " integers: ";
//         for (int i = 0; i < n; i++) cin >> nums[i];

//         cout << "Original Array: ";
//         for (int v : nums) cout << v << " ";
//         cout << endl;

//         vector<vector<int>> results;
//         vector<int> current;
//         vector<bool> used(n, false);
//         cout << endl << "Backtracking Steps:" << endl;
//         permutationsHelper(nums, used, current, results);

//         cout << endl << "--- Result ---" << endl;
//         cout << "All Permutations (" << results.size() << " total):" << endl;
//         for (auto& p : results) {
//             cout << "  [ ";
//             for (int v : p) cout << v << " ";
//             cout << "]" << endl;
//         }
//         cout << endl << "Time Complexity: O(n!)" << endl;
//         cout << "Space Complexity: O(n) recursion + O(n! * n) output" << endl;
//     }
// };

// // ---------------------------------------------------------------
// // Menu
// // Displays the main menu and dispatches to the right class.
// // ---------------------------------------------------------------
// class Menu {
// private:
//     HeapAlgorithms heapAlgo;
//     TrieAlgorithms trieAlgo;
//     BacktrackingAlgorithms backtrackAlgo;

//     void displayMainMenu() {
//         cout << endl << "=============================================" << endl;
//         cout << " WEEK 6 DSA PRACTICE PROJECT" << endl;
//         cout << " Heaps - Priority Queue - Trie - Backtracking" << endl;
//         cout << "=============================================" << endl << endl;
//         cout << "1.  Kth Largest Element in an Array" << endl;
//         cout << "2.  Last Stone Weight" << endl;
//         cout << "3.  K Closest Points to Origin" << endl;
//         cout << "4.  Implement Trie (Insert, Search, Prefix)" << endl;
//         cout << "5.  Word Search" << endl;
//         cout << "6.  Combination Sum" << endl;
//         cout << "7.  Subsets" << endl;
//         cout << "8.  Permutations" << endl;
//         cout << "9.  Display Heap" << endl;
//         cout << "10. Display Trie" << endl;
//         cout << "11. Clear Data Structures" << endl;
//         cout << "12. Exit" << endl << endl;
//         cout << "Enter Choice: ";
//     }

//     // Option 4 groups Insert/Search/Prefix under one Trie sub-menu.
//     void trieSubMenu() {
//         bool back = false;
//         while (!back) {
//             cout << endl << "----- Trie Operations -----" << endl;
//             cout << "1. Insert Word" << endl;
//             cout << "2. Search Word" << endl;
//             cout << "3. Check Prefix (StartsWith)" << endl;
//             cout << "0. Back to Main Menu" << endl;
//             cout << "Enter Choice: ";
//             int choice;
//             cin >> choice;
//             if (cin.fail()) {
//                 cin.clear();
//                 cin.ignore(1000, '\n');
//                 cout << "Invalid input." << endl;
//                 continue;
//             }
//             switch (choice) {
//                 case 1: trieAlgo.insertWord(); break;
//                 case 2: trieAlgo.searchWord(); break;
//                 case 3: trieAlgo.startsWith(); break;
//                 case 0: back = true; break;
//                 default: cout << "Invalid choice." << endl;
//             }
//         }
//     }

// public:
//     void start() {
//         bool running = true;
//         while (running) {
//             displayMainMenu();
//             int choice;
//             cin >> choice;

//             if (cin.fail()) {
//                 cin.clear();
//                 cin.ignore(1000, '\n');
//                 cout << "Invalid input! Please enter a number between 1 and 12." << endl;
//                 continue;
//             }

//             switch (choice) {
//                 case 1: heapAlgo.kthLargestElement(); break;
//                 case 2: heapAlgo.lastStoneWeight(); break;
//                 case 3: heapAlgo.kClosestPoints(); break;
//                 case 4: trieSubMenu(); break;
//                 case 5: backtrackAlgo.wordSearch(); break;
//                 case 6: backtrackAlgo.combinationSum(); break;
//                 case 7: backtrackAlgo.subsets(); break;
//                 case 8: backtrackAlgo.permutations(); break;
//                 case 9: heapAlgo.displayHeap(); break;
//                 case 10: trieAlgo.displayTrie(); break;
//                 case 11:
//                     heapAlgo.clear();
//                     trieAlgo.clear();
//                     cout << endl << "All data structures cleared." << endl;
//                     break;
//                 case 12:
//                     heapAlgo.clear();
//                     trieAlgo.clear();
//                     cout << endl << "Thank you for using the Week 6 DSA Practice Project." << endl;
//                     running = false;
//                     break;
//                 default:
//                     cout << "Invalid choice! Please enter a number between 1 and 12." << endl;
//             }
//         }
//     }
// };

// int main() {
//     Menu menu;
//     menu.start();
//     return 0;
// }