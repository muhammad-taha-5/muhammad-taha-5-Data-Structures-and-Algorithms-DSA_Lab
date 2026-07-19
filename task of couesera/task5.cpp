// // WEEK 5 DSA PRACTICE PROJECT - Binary Trees & Binary Search Trees (OOP, menu-driven)

// #include <iostream>
// #include <queue>
// #include <string>
// #include <climits>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// // TreeNode: single node of a binary tree
// class TreeNode {
// public:
//     int data;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
// };

// // ---------------------------------------------------------------
// // BinarySearchTreeAlgorithms
// // Owns the tree (root) and implements everything that builds or
// // mutates it: create, insert, search, delete, validate, min/max,
// // display, clear.
// // ---------------------------------------------------------------
// class BinarySearchTreeAlgorithms {
// private:
//     TreeNode* root;

//     // Recursively insert val, printing the left/right decision at each step
//     TreeNode* insertHelper(TreeNode* node, int val) {
//         if (node == nullptr) {
//             cout << "  Empty spot found -> insert " << val << " here" << endl;
//             return new TreeNode(val);
//         }
//         if (val == node->data) {
//             cout << "  " << val << " already exists -> duplicate ignored" << endl;
//             return node;
//         }
//         if (val < node->data) {
//             cout << "  " << val << " < " << node->data << " -> go left" << endl;
//             node->left = insertHelper(node->left, val);
//         } else {
//             cout << "  " << val << " > " << node->data << " -> go right" << endl;
//             node->right = insertHelper(node->right, val);
//         }
//         return node;
//     }

//     TreeNode* findMinNode(TreeNode* node) {
//         while (node->left != nullptr) node = node->left;
//         return node;
//     }

//     // Recursively delete val, handling leaf / one-child / two-children cases
//     TreeNode* deleteHelper(TreeNode* node, int val, bool& found) {
//         if (node == nullptr) return nullptr;
//         if (val < node->data) {
//             cout << "  " << val << " < " << node->data << " -> go left" << endl;
//             node->left = deleteHelper(node->left, val, found);
//         } else if (val > node->data) {
//             cout << "  " << val << " > " << node->data << " -> go right" << endl;
//             node->right = deleteHelper(node->right, val, found);
//         } else {
//             found = true;
//             cout << "  Found " << val << endl;
//             if (node->left == nullptr && node->right == nullptr) {
//                 cout << "  Case: leaf node -> delete directly" << endl;
//                 delete node;
//                 return nullptr;
//             } else if (node->left == nullptr) {
//                 cout << "  Case: only right child -> replace node with it" << endl;
//                 TreeNode* temp = node->right;
//                 delete node;
//                 return temp;
//             } else if (node->right == nullptr) {
//                 cout << "  Case: only left child -> replace node with it" << endl;
//                 TreeNode* temp = node->left;
//                 delete node;
//                 return temp;
//             } else {
//                 TreeNode* successor = findMinNode(node->right);
//                 cout << "  Case: two children -> inorder successor = " << successor->data << endl;
//                 node->data = successor->data;
//                 node->right = deleteHelper(node->right, successor->data, found);
//             }
//         }
//         return node;
//     }

//     bool searchHelper(TreeNode* node, int val) {
//         if (node == nullptr) {
//             cout << "  Reached empty spot -> not found" << endl;
//             return false;
//         }
//         cout << "  Visiting " << node->data << endl;
//         if (val == node->data) { cout << "  Match found!" << endl; return true; }
//         if (val < node->data) {
//             cout << "  " << val << " < " << node->data << " -> go left" << endl;
//             return searchHelper(node->left, val);
//         }
//         cout << "  " << val << " > " << node->data << " -> go right" << endl;
//         return searchHelper(node->right, val);
//     }

//     bool validateHelper(TreeNode* node, long long minVal, long long maxVal) {
//         if (node == nullptr) return true;
//         if (node->data <= minVal || node->data >= maxVal) return false;
//         return validateHelper(node->left, minVal, node->data) &&
//                validateHelper(node->right, node->data, maxVal);
//     }

//     void printTreeHelper(TreeNode* node, int space) {
//         const int GAP = 6;
//         if (node == nullptr) return;
//         space += GAP;
//         printTreeHelper(node->right, space);
//         cout << endl;
//         for (int i = GAP; i < space; i++) cout << " ";
//         cout << node->data << endl;
//         printTreeHelper(node->left, space);
//     }

//     void clearHelper(TreeNode* node) {
//         if (node == nullptr) return;
//         clearHelper(node->left);
//         clearHelper(node->right);
//         delete node;
//     }

// public:
//     BinarySearchTreeAlgorithms() : root(nullptr) {}

//     TreeNode* getRoot() { return root; }
//     void setRoot(TreeNode* newRoot) { root = newRoot; }

//     /* Function 1: Create Binary Search Tree
//        Objective: Build a fresh BST from a batch of user values.
//        Algorithm: Discard any existing tree, then insert each new
//        value one at a time using standard BST insertion.
//        Input: count + that many integers. Output: the built tree.
//        Time: O(n*h) average O(n log n). Space: O(h) recursion stack. */
//     void createBST() {
//         cout << endl << "========== CREATE BINARY SEARCH TREE ==========" << endl;
//         clearHelper(root);
//         root = nullptr;
//         int n;
//         cout << "Enter number of values: ";
//         cin >> n;
//         if (n <= 0) { cout << "Invalid count." << endl; return; }
//         for (int i = 0; i < n; i++) {
//             int val;
//             cout << "Value " << i + 1 << ": ";
//             cin >> val;
//             cout << "Inserting " << val << ":" << endl;
//             root = insertHelper(root, val);
//         }
//         cout << endl << "--- Resulting Tree ---" << endl;
//         printTreeHelper(root, 0);
//         cout << endl << "Time Complexity: O(n log n) average, O(n^2) worst case" << endl;
//         cout << "Space Complexity: O(h) recursion stack" << endl;
//     }

//     /* Function 2: Insert Node
//        Objective: Add a single value into the existing BST.
//        Algorithm: Compare with each node, go left if smaller,
//        right if larger, insert at the first empty spot.
//        Input: one integer. Output: updated tree.
//        Time: O(h). Space: O(h). */
//     void insertNode() {
//         cout << endl << "========== INSERT NODE ==========" << endl;
//         cout << "Current Tree:" << endl;
//         printTreeHelper(root, 0);
//         if (root == nullptr) cout << "(empty)" << endl;

//         int val;
//         cout << "Enter value to insert: ";
//         cin >> val;
//         cout << "Insertion Steps:" << endl;
//         root = insertHelper(root, val);

//         cout << endl << "--- Resulting Tree ---" << endl;
//         printTreeHelper(root, 0);
//         cout << endl << "Time Complexity: O(h)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }

//     /* Function 3: Search Node
//        Objective: Check whether a value exists in the BST.
//        Algorithm: Compare with current node and move left/right
//        until found or an empty spot is reached.
//        Input: one integer. Output: found/not found.
//        Time: O(h). Space: O(h). */
//     void searchNode() {
//         cout << endl << "========== SEARCH NODE ==========" << endl;
//         if (root == nullptr) { cout << "Tree is empty." << endl; return; }
//         int val;
//         cout << "Enter value to search: ";
//         cin >> val;
//         cout << "Search Steps:" << endl;
//         bool found = searchHelper(root, val);
//         cout << endl << "--- Result ---" << endl;
//         cout << (found ? "Found" : "Not Found") << endl;
//         cout << endl << "Time Complexity: O(h)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }

//     /* Function 4: Delete Node
//        Objective: Remove a value from the BST while keeping the
//        BST property intact.
//        Algorithm: Locate the node, then handle 3 cases: leaf,
//        one child, or two children (replace with inorder successor).
//        Input: one integer. Output: updated tree.
//        Time: O(h). Space: O(h). */
//     void deleteNode() {
//         cout << endl << "========== DELETE NODE ==========" << endl;
//         if (root == nullptr) { cout << "Tree is empty." << endl; return; }
//         cout << "Current Tree:" << endl;
//         printTreeHelper(root, 0);

//         int val;
//         cout << "Enter value to delete: ";
//         cin >> val;
//         bool found = false;
//         cout << "Deletion Steps:" << endl;
//         root = deleteHelper(root, val, found);

//         cout << endl << "--- Result ---" << endl;
//         if (!found) {
//             cout << "Value not found - nothing deleted." << endl;
//         } else {
//             cout << "Resulting Tree:" << endl;
//             printTreeHelper(root, 0);
//             if (root == nullptr) cout << "(empty)" << endl;
//         }
//         cout << endl << "Time Complexity: O(h)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }

//     /* Function: Validate BST
//        Objective: Confirm the tree satisfies the BST property.
//        Algorithm: Recursively check each node's value lies within
//        a valid (min, max) range inherited from its ancestors.
//        Input: none (uses current tree). Output: valid/invalid.
//        Time: O(n). Space: O(h). */
//     void validateBST() {
//         cout << endl << "========== VALIDATE BST ==========" << endl;
//         if (root == nullptr) { cout << "Tree is empty - considered a valid BST." << endl; return; }
//         bool valid = validateHelper(root, LLONG_MIN, LLONG_MAX);
//         cout << "Result: " << (valid ? "Valid BST" : "NOT a valid BST") << endl;
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }

//     /* Function: Find Minimum Value
//        Objective: Find the smallest value in the BST.
//        Algorithm: Keep moving left until there is no left child.
//        Time: O(h). Space: O(1). */
//     void findMinValue() {
//         cout << endl << "========== FIND MINIMUM VALUE ==========" << endl;
//         if (root == nullptr) { cout << "Tree is empty." << endl; return; }
//         TreeNode* node = root;
//         while (node->left != nullptr) {
//             cout << "  " << node->data << " -> go left" << endl;
//             node = node->left;
//         }
//         cout << "Minimum Value: " << node->data << endl;
//         cout << endl << "Time Complexity: O(h)" << endl;
//         cout << "Space Complexity: O(1)" << endl;
//     }

//     /* Function: Find Maximum Value
//        Objective: Find the largest value in the BST.
//        Algorithm: Keep moving right until there is no right child.
//        Time: O(h). Space: O(1). */
//     void findMaxValue() {
//         cout << endl << "========== FIND MAXIMUM VALUE ==========" << endl;
//         if (root == nullptr) { cout << "Tree is empty." << endl; return; }
//         TreeNode* node = root;
//         while (node->right != nullptr) {
//             cout << "  " << node->data << " -> go right" << endl;
//             node = node->right;
//         }
//         cout << "Maximum Value: " << node->data << endl;
//         cout << endl << "Time Complexity: O(h)" << endl;
//         cout << "Space Complexity: O(1)" << endl;
//     }

//     /* Function: Display Tree
//        Objective: Show the tree in a readable, indented format.
//        Algorithm: Rotated print - recurse right, then print node
//        indented by its depth, then recurse left.
//        Time: O(n). Space: O(h). */
//     void displayTree() {
//         cout << endl << "========== DISPLAY TREE ==========" << endl;
//         if (root == nullptr) { cout << "Tree is empty." << endl; return; }
//         printTreeHelper(root, 0);
//     }

//     /* Function: Clear Tree
//        Objective: Free every node safely.
//        Algorithm: Postorder deletion (children first, then node).
//        Time: O(n). Space: O(h). */
//     void clearTree() {
//         cout << endl << "========== CLEAR TREE ==========" << endl;
//         clearHelper(root);
//         root = nullptr;
//         cout << "All nodes deleted successfully." << endl;
//         cout << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }
// };

// // ---------------------------------------------------------------
// // BinaryTreeAlgorithms
// // Generic tree algorithms that just need a root pointer: they
// // don't need to "own" the tree. Invert returns a new root, which
// // the Menu writes back into BinarySearchTreeAlgorithms.
// // ---------------------------------------------------------------
// class BinaryTreeAlgorithms {
// private:
//     void inorderHelper(TreeNode* node) {
//         if (node == nullptr) return;
//         inorderHelper(node->left);
//         cout << node->data << " ";
//         inorderHelper(node->right);
//     }
//     void preorderHelper(TreeNode* node) {
//         if (node == nullptr) return;
//         cout << node->data << " ";
//         preorderHelper(node->left);
//         preorderHelper(node->right);
//     }
//     void postorderHelper(TreeNode* node) {
//         if (node == nullptr) return;
//         postorderHelper(node->left);
//         postorderHelper(node->right);
//         cout << node->data << " ";
//     }
//     int countNodesHelper(TreeNode* node) {
//         if (node == nullptr) return 0;
//         return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
//     }
//     int countLeavesHelper(TreeNode* node) {
//         if (node == nullptr) return 0;
//         if (node->left == nullptr && node->right == nullptr) return 1;
//         return countLeavesHelper(node->left) + countLeavesHelper(node->right);
//     }
//     int heightHelper(TreeNode* node) { // height in edges, empty = -1
//         if (node == nullptr) return -1;
//         return 1 + max(heightHelper(node->left), heightHelper(node->right));
//     }
//     int depthHelper(TreeNode* node) { // depth in nodes, empty = 0
//         if (node == nullptr) return 0;
//         return 1 + max(depthHelper(node->left), depthHelper(node->right));
//     }
//     TreeNode* lcaHelper(TreeNode* node, int v1, int v2) {
//         if (node == nullptr) return nullptr;
//         if (v1 < node->data && v2 < node->data) {
//             cout << "  Both < " << node->data << " -> go left" << endl;
//             return lcaHelper(node->left, v1, v2);
//         }
//         if (v1 > node->data && v2 > node->data) {
//             cout << "  Both > " << node->data << " -> go right" << endl;
//             return lcaHelper(node->right, v1, v2);
//         }
//         cout << "  Values split here -> " << node->data << " is the LCA" << endl;
//         return node;
//     }
//     TreeNode* invertHelper(TreeNode* node) {
//         if (node == nullptr) return nullptr;
//         TreeNode* newLeft = invertHelper(node->right);
//         TreeNode* newRight = invertHelper(node->left);
//         node->left = newLeft;
//         node->right = newRight;
//         return node;
//     }
//     int diameterHelper(TreeNode* node, int& diameter) {
//         if (node == nullptr) return 0;
//         int lh = diameterHelper(node->left, diameter);
//         int rh = diameterHelper(node->right, diameter);
//         diameter = max(diameter, lh + rh);
//         return 1 + max(lh, rh);
//     }
//     int balancedHelper(TreeNode* node, bool& balanced) {
//         if (node == nullptr || !balanced) return 0;
//         int lh = balancedHelper(node->left, balanced);
//         int rh = balancedHelper(node->right, balanced);
//         if (abs(lh - rh) > 1) balanced = false;
//         return 1 + max(lh, rh);
//     }
//     // simple one-line view of the tree, used to show "original tree" before an op
//     void printSimple(TreeNode* root) {
//         if (root == nullptr) { cout << "(empty)" << endl; return; }
//         queue<TreeNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             TreeNode* node = q.front(); q.pop();
//             cout << node->data << " ";
//             if (node->left) q.push(node->left);
//             if (node->right) q.push(node->right);
//         }
//         cout << endl;
//     }

// public:
//     /* Function: Inorder Traversal
//        Objective: Visit nodes in ascending order for a BST.
//        Algorithm: Recurse left, visit node, recurse right.
//        Time: O(n). Space: O(h). */
//     void inorderTraversal(TreeNode* root) {
//         cout << endl << "========== INORDER TRAVERSAL ==========" << endl;
//         cout << "Original Tree (level order): "; printSimple(root);
//         if (root == nullptr) return;
//         cout << "Result: "; inorderHelper(root); cout << endl;
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }

//     /* Function: Preorder Traversal
//        Objective: Visit node before its children (useful for copying a tree).
//        Algorithm: Visit node, recurse left, recurse right.
//        Time: O(n). Space: O(h). */
//     void preorderTraversal(TreeNode* root) {
//         cout << endl << "========== PREORDER TRAVERSAL ==========" << endl;
//         cout << "Original Tree (level order): "; printSimple(root);
//         if (root == nullptr) return;
//         cout << "Result: "; preorderHelper(root); cout << endl;
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }

//     /* Function: Postorder Traversal
//        Objective: Visit children before the node (useful for deleting a tree).
//        Algorithm: Recurse left, recurse right, visit node.
//        Time: O(n). Space: O(h). */
//     void postorderTraversal(TreeNode* root) {
//         cout << endl << "========== POSTORDER TRAVERSAL ==========" << endl;
//         cout << "Original Tree (level order): "; printSimple(root);
//         if (root == nullptr) return;
//         cout << "Result: "; postorderHelper(root); cout << endl;
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }

//     /* Function: Level Order Traversal
//        Objective: Visit nodes level by level, top to bottom.
//        Algorithm: BFS using a queue; print each level on its own line.
//        Time: O(n). Space: O(n) for the queue. */
//     void levelOrderTraversal(TreeNode* root) {
//         cout << endl << "========== LEVEL ORDER TRAVERSAL ==========" << endl;
//         if (root == nullptr) { cout << "Tree is empty." << endl; return; }
//         queue<TreeNode*> q;
//         q.push(root);
//         int level = 0;
//         while (!q.empty()) {
//             int size = q.size();
//             cout << "Level " << level << ": ";
//             for (int i = 0; i < size; i++) {
//                 TreeNode* node = q.front(); q.pop();
//                 cout << node->data << " ";
//                 if (node->left) q.push(node->left);
//                 if (node->right) q.push(node->right);
//             }
//             cout << endl;
//             level++;
//         }
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(n)" << endl;
//     }

//     /* Function: Calculate Height
//        Objective: Find the number of edges on the longest root-to-leaf path.
//        Algorithm: Recursively take 1 + max(height(left), height(right)); empty = -1.
//        Time: O(n). Space: O(h). */
//     void calculateHeight(TreeNode* root) {
//         cout << endl << "========== CALCULATE HEIGHT ==========" << endl;
//         cout << "Original Tree (level order): "; printSimple(root);
//         cout << "Height (edges): " << heightHelper(root) << endl;
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }

//     /* Function: Count Total Nodes
//        Objective: Count every node in the tree.
//        Algorithm: Recursively 1 + count(left) + count(right).
//        Time: O(n). Space: O(h). */
//     void countTotalNodes(TreeNode* root) {
//         cout << endl << "========== COUNT TOTAL NODES ==========" << endl;
//         cout << "Original Tree (level order): "; printSimple(root);
//         cout << "Total Nodes: " << countNodesHelper(root) << endl;
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }

//     /* Function: Count Leaf Nodes
//        Objective: Count nodes with no children.
//        Algorithm: Recursively check if a node has no left/right child.
//        Time: O(n). Space: O(h). */
//     void countLeafNodes(TreeNode* root) {
//         cout << endl << "========== COUNT LEAF NODES ==========" << endl;
//         cout << "Original Tree (level order): "; printSimple(root);
//         cout << "Leaf Nodes: " << countLeavesHelper(root) << endl;
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }

//     /* Function: Lowest Common Ancestor (LCA)
//        Objective: Find the deepest node that is an ancestor of both given values.
//        Algorithm: Use the BST property - if both values are smaller, go
//        left; if both larger, go right; otherwise current node is the LCA.
//        Input: two integers. Output: the LCA value.
//        Time: O(h). Space: O(h). */
//     void lowestCommonAncestor(TreeNode* root) {
//         cout << endl << "========== LOWEST COMMON ANCESTOR ==========" << endl;
//         if (root == nullptr) { cout << "Tree is empty." << endl; return; }
//         cout << "Original Tree (level order): "; printSimple(root);
//         int v1, v2;
//         cout << "Enter first value: "; cin >> v1;
//         cout << "Enter second value: "; cin >> v2;
//         cout << "Steps:" << endl;
//         TreeNode* lca = lcaHelper(root, v1, v2);
//         cout << endl << "--- Result ---" << endl;
//         if (lca) cout << "LCA of " << v1 << " and " << v2 << " is: " << lca->data << endl;
//         else cout << "One or both values not present in tree." << endl;
//         cout << endl << "Time Complexity: O(h)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }

//     /* Function: Invert Binary Tree
//        Objective: Mirror the tree - swap every node's left and right child.
//        Algorithm: Recursively invert left and right subtrees, then swap them.
//        Input: none. Output: new root of the inverted tree.
//        Time: O(n). Space: O(h). */
//     TreeNode* invertBinaryTree(TreeNode* root) {
//         cout << endl << "========== INVERT BINARY TREE ==========" << endl;
//         cout << "Original Tree (level order): "; printSimple(root);
//         TreeNode* newRoot = invertHelper(root);
//         cout << "Tree inverted (all left/right children swapped)." << endl;
//         cout << "Inverted Tree (level order): "; printSimple(newRoot);
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//         return newRoot;
//     }

//     /* Function: Diameter of Binary Tree
//        Objective: Find the longest path between any two nodes (in edges).
//        Algorithm: For every node, longest path through it = left height +
//        right height; track the max while computing heights bottom-up.
//        Time: O(n). Space: O(h). */
//     void diameterOfBinaryTree(TreeNode* root) {
//         cout << endl << "========== DIAMETER OF BINARY TREE ==========" << endl;
//         cout << "Original Tree (level order): "; printSimple(root);
//         int diameter = 0;
//         diameterHelper(root, diameter);
//         cout << "Diameter (longest path in edges): " << diameter << endl;
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }

//     /* Function: Maximum Depth
//        Objective: Find the number of nodes on the longest root-to-leaf path.
//        Algorithm: Recursively take 1 + max(depth(left), depth(right)); empty = 0.
//        Time: O(n). Space: O(h). */
//     void maximumDepth(TreeNode* root) {
//         cout << endl << "========== MAXIMUM DEPTH ==========" << endl;
//         cout << "Original Tree (level order): "; printSimple(root);
//         cout << "Maximum Depth (nodes): " << depthHelper(root) << endl;
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }

//     /* Function: Check Balanced Tree
//        Objective: Determine if the tree is height-balanced (a binary tree
//        where every node's left/right subtree heights differ by at most 1).
//        Algorithm: Bottom-up recursion; return height, flip a flag to false
//        the moment any node's children differ in height by more than 1.
//        Time: O(n). Space: O(h). */
//     void checkBalancedTree(TreeNode* root) {
//         cout << endl << "========== CHECK BALANCED TREE ==========" << endl;
//         cout << "Original Tree (level order): "; printSimple(root);
//         bool balanced = true;
//         balancedHelper(root, balanced);
//         cout << "Result: " << (balanced ? "Balanced" : "Not Balanced") << endl;
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(h)" << endl;
//     }
// };

// // ---------------------------------------------------------------
// // Menu
// // Displays the main menu and dispatches to the right class.
// // Keeps a BinarySearchTreeAlgorithms object as the single source
// // of truth for the tree; BinaryTreeAlgorithms works off its root.
// // ---------------------------------------------------------------
// class Menu {
// private:
//     BinarySearchTreeAlgorithms bstAlgo;
//     BinaryTreeAlgorithms btAlgo;

//     void displayMainMenu() {
//         cout << endl << "=============================================" << endl;
//         cout << " WEEK 5 DSA PRACTICE PROJECT" << endl;
//         cout << " Binary Trees & Binary Search Trees" << endl;
//         cout << "=============================================" << endl << endl;
//         cout << "1.  Create Binary Search Tree" << endl;
//         cout << "2.  Insert Node" << endl;
//         cout << "3.  Search Node" << endl;
//         cout << "4.  Delete Node" << endl;
//         cout << "5.  Inorder Traversal" << endl;
//         cout << "6.  Preorder Traversal" << endl;
//         cout << "7.  Postorder Traversal" << endl;
//         cout << "8.  Level Order Traversal" << endl;
//         cout << "9.  Calculate Height" << endl;
//         cout << "10. Count Total Nodes" << endl;
//         cout << "11. Count Leaf Nodes" << endl;
//         cout << "12. Find Minimum Value" << endl;
//         cout << "13. Find Maximum Value" << endl;
//         cout << "14. Validate BST" << endl;
//         cout << "15. Lowest Common Ancestor (LCA)" << endl;
//         cout << "16. Invert Binary Tree" << endl;
//         cout << "17. Diameter of Binary Tree" << endl;
//         cout << "18. Maximum Depth" << endl;
//         cout << "19. Check Balanced Tree" << endl;
//         cout << "20. Display Tree" << endl;
//         cout << "21. Clear Tree" << endl;
//         cout << "22. Exit" << endl << endl;
//         cout << "Enter Choice: ";
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
//                 cout << "Invalid input! Please enter a number between 1 and 22." << endl;
//                 continue;
//             }

//             switch (choice) {
//                 case 1: bstAlgo.createBST(); break;
//                 case 2: bstAlgo.insertNode(); break;
//                 case 3: bstAlgo.searchNode(); break;
//                 case 4: bstAlgo.deleteNode(); break;
//                 case 5: btAlgo.inorderTraversal(bstAlgo.getRoot()); break;
//                 case 6: btAlgo.preorderTraversal(bstAlgo.getRoot()); break;
//                 case 7: btAlgo.postorderTraversal(bstAlgo.getRoot()); break;
//                 case 8: btAlgo.levelOrderTraversal(bstAlgo.getRoot()); break;
//                 case 9: btAlgo.calculateHeight(bstAlgo.getRoot()); break;
//                 case 10: btAlgo.countTotalNodes(bstAlgo.getRoot()); break;
//                 case 11: btAlgo.countLeafNodes(bstAlgo.getRoot()); break;
//                 case 12: bstAlgo.findMinValue(); break;
//                 case 13: bstAlgo.findMaxValue(); break;
//                 case 14: bstAlgo.validateBST(); break;
//                 case 15: btAlgo.lowestCommonAncestor(bstAlgo.getRoot()); break;
//                 case 16: bstAlgo.setRoot(btAlgo.invertBinaryTree(bstAlgo.getRoot())); break;
//                 case 17: btAlgo.diameterOfBinaryTree(bstAlgo.getRoot()); break;
//                 case 18: btAlgo.maximumDepth(bstAlgo.getRoot()); break;
//                 case 19: btAlgo.checkBalancedTree(bstAlgo.getRoot()); break;
//                 case 20: bstAlgo.displayTree(); break;
//                 case 21: bstAlgo.clearTree(); break;
//                 case 22:
//                     bstAlgo.clearTree(); // free memory before exit
//                     cout << endl << "Thank you for using the Week 5 DSA Practice Project." << endl;
//                     running = false;
//                     break;
//                 default:
//                     cout << "Invalid choice! Please enter a number between 1 and 22." << endl;
//             }
//         }
//     }
// };

// int main() {
//     Menu menu;
//     menu.start();
//     return 0;
// }