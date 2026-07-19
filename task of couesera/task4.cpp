// // WEEK 4 DSA PRACTICE PROJECT - Linked List, Stack, Queue (OOP, menu-driven)

// #include <iostream>
// #include <vector>
// #include <string>
// #include <stack>
// #include <queue>
// #include <climits>
// using namespace std;

// // Node : single node of a singly linked list
// class Node {
// public:
//     int data;
//     Node* next;
//     Node(int val) : data(val), next(nullptr) {}
// };

// // LinkedListAlgorithms
// class LinkedListAlgorithms {
// private:
//     Node* head; // current working list

//     // Helper: build a linked list from user input, return its head
//     Node* buildListFromInput(const string& label) {
//         int n;
//         cout << "Enter number of nodes for " << label << ": ";
//         cin >> n;
//         if (n <= 0) {
//             cout << "  (empty list)" << endl;
//             return nullptr;
//         }
//         Node* h = nullptr;
//         Node* tail = nullptr;
//         cout << "Enter " << n << " integers for " << label << ": ";
//         for (int i = 0; i < n; i++) {
//             int val;
//             cin >> val;
//             Node* newNode = new Node(val);
//             if (h == nullptr) {
//                 h = newNode;
//                 tail = newNode;
//             } else {
//                 tail->next = newNode;
//                 tail = newNode;
//             }
//         }
//         return h;
//     }

//     // Helper: print any list given its head, without destroying it
//     void printList(Node* h, const string& label) {
//         cout << label << ": ";
//         if (h == nullptr) {
//             cout << "(empty)";
//         } else {
//             Node* temp = h;
//             while (temp != nullptr) {
//                 cout << temp->data;
//                 if (temp->next != nullptr) cout << " -> ";
//                 temp = temp->next;
//             }
//         }
//         cout << endl;
//     }

//     // Helper: count nodes in a list
//     int countNodes(Node* h) {
//         int count = 0;
//         while (h != nullptr) {
//             count++;
//             h = h->next;
//         }
//         return count;
//     }

//     // Helper: delete all nodes of a given list (used internally)
//     void deleteList(Node* h) {
//         while (h != nullptr) {
//             Node* nextNode = h->next;
//             delete h;
//             h = nextNode;
//         }
//     }

// public:
//     LinkedListAlgorithms() : head(nullptr) {}

//     // Function 11: Display Current Linked List
//     void displayCurrentList() {
//         cout << endl << "========== CURRENT LINKED LIST ==========" << endl;
//         printList(head, "Current List");
//         cout << "Number of Nodes: " << countNodes(head) << endl;
//         if (head != nullptr) {
//             Node* tail = head;
//             while (tail->next != nullptr) tail = tail->next;
//             cout << "Head Address: " << head << endl;
//             cout << "Tail Address: " << tail << endl;
//         } else {
//             cout << "Head Address: nullptr" << endl;
//             cout << "Tail Address: nullptr" << endl;
//         }
//     }

//     // Function 12: Clear Linked List
//     void clearList() {
//         cout << endl << "========== CLEAR LINKED LIST ==========" << endl;
//         deleteList(head);
//         head = nullptr;
//         cout << "All nodes deleted successfully." << endl;
//         cout << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(1)" << endl;
//     }

//     // Function 1: Reverse Linked List
//     void reverseList() {
//         cout << endl << "========== REVERSE LINKED LIST ==========" << endl;
//         deleteList(head);
//         head = buildListFromInput("the list");
//         printList(head, "Original List");

//         cout << endl << "Reversal Process:" << endl;
//         Node* prev = nullptr;
//         Node* curr = head;
//         int step = 1;
//         while (curr != nullptr) {
//             Node* nextNode = curr->next;
//             cout << "Step " << step << ": prev=";
//             if (prev) cout << prev->data; else cout << "NULL";
//             cout << ", curr=" << curr->data << ", next=";
//             if (nextNode) cout << nextNode->data; else cout << "NULL";
//             cout << " -> point curr->next to prev" << endl;

//             curr->next = prev;
//             prev = curr;
//             curr = nextNode;
//             step++;
//         }
//         head = prev;

//         cout << endl << "--- Result ---" << endl;
//         printList(head, "Reversed List");
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(1)" << endl;
//     }

//     // Function 2: Merge Two Sorted Linked Lists
//     void mergeTwoSortedLists() {
//         cout << endl << "========== MERGE TWO SORTED LINKED LISTS ==========" << endl;
//         Node* l1 = buildListFromInput("List 1 (must be sorted)");
//         Node* l2 = buildListFromInput("List 2 (must be sorted)");
//         printList(l1, "List 1");
//         printList(l2, "List 2");

//         cout << endl << "Comparison Process:" << endl;
//         Node dummy(0);
//         Node* tail = &dummy;
//         Node* p1 = l1;
//         Node* p2 = l2;

//         while (p1 != nullptr && p2 != nullptr) {
//             if (p1->data <= p2->data) {
//                 cout << "  Pick " << p1->data << " from List 1 (<= " << p2->data << ")" << endl;
//                 tail->next = p1;
//                 p1 = p1->next;
//             } else {
//                 cout << "  Pick " << p2->data << " from List 2 (< " << p1->data << ")" << endl;
//                 tail->next = p2;
//                 p2 = p2->next;
//             }
//             tail = tail->next;
//         }
//         // attach remaining nodes
//         if (p1 != nullptr) { cout << "  Attach remaining nodes from List 1" << endl; tail->next = p1; }
//         if (p2 != nullptr) { cout << "  Attach remaining nodes from List 2" << endl; tail->next = p2; }

//         deleteList(head);
//         head = dummy.next;

//         cout << endl << "--- Result ---" << endl;
//         printList(head, "Merged List");
//         cout << endl << "Time Complexity: O(n+m)" << endl;
//         cout << "Space Complexity: O(1) extra" << endl;
//     }

//     // Function 5: Add Two Numbers
//     void addTwoNumbers() {
//         cout << endl << "========== ADD TWO NUMBERS ==========" << endl;
//         cout << "(Enter digits in reverse order, e.g. 342 -> 2 4 3)" << endl;
//         Node* l1 = buildListFromInput("Number 1 (reversed digits)");
//         Node* l2 = buildListFromInput("Number 2 (reversed digits)");
//         printList(l1, "Number 1");
//         printList(l2, "Number 2");

//         Node dummy(0);
//         Node* tail = &dummy;
//         Node* p1 = l1;
//         Node* p2 = l2;
//         int carry = 0;

//         cout << endl << "Addition Process:" << endl;
//         while (p1 != nullptr || p2 != nullptr || carry != 0) {
//             int v1 = (p1 != nullptr) ? p1->data : 0;
//             int v2 = (p2 != nullptr) ? p2->data : 0;
//             int sum = v1 + v2 + carry;
//             int digit = sum % 10;
//             carry = sum / 10;

//             cout << "  " << v1 << " + " << v2 << " + carry(" << (sum - digit - carry * 10 == 0 ? 0 : 0)
//                  << ") = " << sum << " -> digit=" << digit << ", new carry=" << carry << endl;

//             Node* newNode = new Node(digit);
//             tail->next = newNode;
//             tail = newNode;

//             if (p1 != nullptr) p1 = p1->next;
//             if (p2 != nullptr) p2 = p2->next;
//         }

//         deleteList(head);
//         head = dummy.next;

//         cout << endl << "--- Result ---" << endl;
//         printList(head, "Sum List (reversed digits)");
//         cout << endl << "Time Complexity: O(max(n,m))" << endl;
//         cout << "Space Complexity: O(max(n,m))" << endl;
//     }

//     // Function 6: Reorder List
//     void reorderList() {
//         cout << endl << "========== REORDER LIST ==========" << endl;
//         deleteList(head);
//         head = buildListFromInput("the list");
//         printList(head, "Original List");

//         if (head == nullptr || head->next == nullptr) {
//             cout << "List too short to reorder." << endl;
//             return;
//         }

//         // Step 1: find middle
//         Node* slow = head;
//         Node* fast = head;
//         while (fast->next != nullptr && fast->next->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         cout << endl << "Middle Node: " << slow->data << endl;

//         // Step 2: reverse second half
//         Node* second = slow->next;
//         slow->next = nullptr; // split
//         Node* prev = nullptr;
//         while (second != nullptr) {
//             Node* nextNode = second->next;
//             second->next = prev;
//             prev = second;
//             second = nextNode;
//         }
//         Node* secondHalf = prev;
//         printList(secondHalf, "Reversed Second Half");

//         // Step 3: merge alternately
//         Node* first = head;
//         cout << endl << "Merge Process:" << endl;
//         while (secondHalf != nullptr) {
//             Node* firstNext = first->next;
//             Node* secondNext = secondHalf->next;

//             first->next = secondHalf;
//             if (firstNext != nullptr) {
//                 secondHalf->next = firstNext;
//             }
//             cout << "  Link " << first->data << " -> " << secondHalf->data << endl;

//             first = firstNext;
//             secondHalf = secondNext;
//         }

//         cout << endl << "--- Result ---" << endl;
//         printList(head, "Reordered List");
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(1)" << endl;
//     }

//     // Function 7: Remove Nth Node From End
//     void removeNthFromEnd() {
//         cout << endl << "========== REMOVE NTH NODE FROM END ==========" << endl;
//         deleteList(head);
//         head = buildListFromInput("the list");
//         printList(head, "Original List");

//         int n;
//         cout << "Enter N (position from end to remove): ";
//         cin >> n;

//         Node dummy(0);
//         dummy.next = head;
//         Node* fast = &dummy;
//         Node* slow = &dummy;

//         for (int i = 0; i < n; i++) {
//             if (fast->next == nullptr) {
//                 cout << "Invalid position N=" << n << " (list too short)." << endl;
//                 return;
//             }
//             fast = fast->next;
//             cout << "  Move Fast Pointer forward -> now at "
//                  << (fast->next ? to_string(fast->data) : "END") << endl;
//         }

//         while (fast->next != nullptr) {
//             fast = fast->next;
//             slow = slow->next;
//             cout << "  Fast=" << fast->data << ", Slow=" << slow->data << endl;
//         }

//         Node* toDelete = slow->next;
//         if (toDelete == nullptr) {
//             cout << "Invalid position." << endl;
//             return;
//         }
//         cout << endl << "Deleted Node: " << toDelete->data << endl;
//         slow->next = toDelete->next;
//         delete toDelete;

//         head = dummy.next;
//         cout << endl << "--- Result ---" << endl;
//         printList(head, "Updated List");
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(1)" << endl;
//     }

//     // Function 9: Merge K Sorted Linked Lists | Time: O(N log K) where N = total nodes, K = number of lists Space: O(K) for the heap
//     void mergeKSortedLists() {
//         cout << endl << "========== MERGE K SORTED LINKED LISTS ==========" << endl;
//         int k;
//         cout << "Enter number of lists (K): ";
//         cin >> k;
//         if (k <= 0) {
//             cout << "Invalid K." << endl;
//             return;
//         }

//         vector<Node*> lists(k);
//         for (int i = 0; i < k; i++) {
//             lists[i] = buildListFromInput("List " + to_string(i + 1) + " (must be sorted)");
//         }
//         cout << endl << "Current Lists:" << endl;
//         for (int i = 0; i < k; i++) printList(lists[i], "  List " + to_string(i + 1));

//         // min-heap of pair<value, listIndex>
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
//         for (int i = 0; i < k; i++) {
//             if (lists[i] != nullptr) {
//                 minHeap.push({lists[i]->data, i});
//             }
//         }

//         Node dummy(0);
//         Node* tail = &dummy;

//         cout << endl << "Merge Process:" << endl;
//         while (!minHeap.empty()) {
//             pair<int,int> top = minHeap.top();
//             minHeap.pop();
//             int val = top.first;
//             int idx = top.second;

//             cout << "  Pick " << val << " from List " << (idx + 1) << endl;

//             tail->next = lists[idx];
//             tail = tail->next;
//             lists[idx] = lists[idx]->next;

//             if (lists[idx] != nullptr) {
//                 minHeap.push({lists[idx]->data, idx});
//             }
//         }
//         tail->next = nullptr;

//         deleteList(head);
//         head = dummy.next;

//         cout << endl << "--- Result ---" << endl;
//         printList(head, "Final Merged List");
//         cout << endl << "Time Complexity: O(N log K)" << endl;
//         cout << "Space Complexity: O(K) for the heap" << endl;
//     }

//     // Function 10: Reverse Nodes in K-Group
//     void reverseKGroup() {
//         cout << endl << "========== REVERSE NODES IN K-GROUP ==========" << endl;
//         deleteList(head);
//         head = buildListFromInput("the list");
//         printList(head, "Original List");

//         int k;
//         cout << "Enter K (group size): ";
//         cin >> k;
//         if (k <= 1) {
//             cout << "K must be >= 2 to have any effect." << endl;
//             return;
//         }

//         Node dummy(0);
//         dummy.next = head;
//         Node* groupPrev = &dummy;
//         int groupNum = 1;

//         while (true) {
//             // check if there are at least k nodes left
//             Node* kth = groupPrev;
//             for (int i = 0; i < k && kth != nullptr; i++) kth = kth->next;
//             if (kth == nullptr) {
//                 cout << endl << "Remaining Nodes (fewer than K): kept as-is." << endl;
//                 break;
//             }

//             Node* groupStart = groupPrev->next;
//             cout << endl << "Current Group " << groupNum << ": ";
//             Node* t = groupStart;
//             for (int i = 0; i < k; i++) { cout << t->data << " "; t = t->next; }
//             cout << endl;

//             // reverse this group
//             Node* prev = kth->next; // node after the group
//             Node* curr = groupStart;
//             for (int i = 0; i < k; i++) {
//                 Node* nextNode = curr->next;
//                 curr->next = prev;
//                 prev = curr;
//                 curr = nextNode;
//             }

//             cout << "Reversed Group " << groupNum << ": ";
//             t = prev;
//             for (int i = 0; i < k; i++) { cout << t->data << " "; t = t->next; }
//             cout << endl;

//             Node* temp = groupPrev->next; // old groupStart, now tail of reversed group
//             groupPrev->next = prev;
//             groupPrev = temp;
//             groupNum++;
//         }

//         head = dummy.next;
//         cout << endl << "--- Result ---" << endl;
//         printList(head, "Final List");
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(1)" << endl;
//     }
// };

// // StackAlgorithms
// class StackAlgorithms {
// public:
//     // Function 3: Valid Parentheses
//     void validParentheses() {
//         cout << endl << "========== VALID PARENTHESES ==========" << endl;
//         string s;
//         cout << "Enter a string of brackets (e.g. ({[]})): ";
//         cin >> s;

//         stack<char> st;
//         bool valid = true;

//         for (char c : s) {
//             cout << endl << "Current Character: '" << c << "'" << endl;
//             if (c == '(' || c == '{' || c == '[') {
//                 st.push(c);
//                 cout << "  Push '" << c << "' onto stack" << endl;
//             } else {
//                 if (st.empty()) {
//                     cout << "  Stack empty, cannot match '" << c << "' -> INVALID" << endl;
//                     valid = false;
//                     break;
//                 }
//                 char top = st.top();
//                 bool matches = (c == ')' && top == '(') ||
//                                (c == ']' && top == '[') ||
//                                (c == '}' && top == '{');
//                 if (matches) {
//                     st.pop();
//                     cout << "  Pop '" << top << "' - matches '" << c << "'" << endl;
//                 } else {
//                     cout << "  Top '" << top << "' does not match '" << c << "' -> INVALID" << endl;
//                     valid = false;
//                     break;
//                 }
//             }

//             // display current stack content (bottom -> top)
//             stack<char> copy = st;
//             vector<char> content;
//             while (!copy.empty()) { content.push_back(copy.top()); copy.pop(); }
//             cout << "  Stack Content (bottom->top): ";
//             for (int i = (int)content.size() - 1; i >= 0; i--) cout << content[i] << " ";
//             cout << endl;
//         }

//         if (valid && !st.empty()) {
//             cout << endl << "Unmatched opening brackets remain -> INVALID" << endl;
//             valid = false;
//         }

//         cout << endl << "--- Final Result ---" << endl;
//         cout << (valid ? "Valid" : "Invalid") << endl;
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(n)" << endl;
//     }

//     // Function 8: Daily Temperatures
//     void dailyTemperatures() {
//         cout << endl << "========== DAILY TEMPERATURES ==========" << endl;
//         int n;
//         cout << "Enter number of days: ";
//         cin >> n;
//         if (n <= 0) {
//             cout << "Invalid input." << endl;
//             return;
//         }
//         vector<int> temps(n);
//         cout << "Enter " << n << " temperatures: ";
//         for (int i = 0; i < n; i++) cin >> temps[i];

//         vector<int> result(n, 0);
//         stack<int> indices; // stores indices, temps at these indices are decreasing

//         cout << endl << "Processing:" << endl;
//         for (int i = 0; i < n; i++) {
//             cout << "Day " << i << " (temp=" << temps[i] << ")" << endl;
//             while (!indices.empty() && temps[i] > temps[indices.top()]) {
//                 int prevDay = indices.top();
//                 indices.pop();
//                 result[prevDay] = i - prevDay;
//                 cout << "  Day " << prevDay << " waited " << result[prevDay]
//                      << " day(s) for warmer temp" << endl;
//             }
//             indices.push(i);

//             // show stack content
//             stack<int> copy = indices;
//             vector<int> content;
//             while (!copy.empty()) { content.push_back(copy.top()); copy.pop(); }
//             cout << "  Stack (day indices, bottom->top): ";
//             for (int j = (int)content.size() - 1; j >= 0; j--) cout << content[j] << " ";
//             cout << endl;
//         }

//         cout << endl << "--- Result ---" << endl;
//         cout << "Waiting Days Array: ";
//         for (int i = 0; i < n; i++) cout << result[i] << " ";
//         cout << endl;

//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(n)" << endl;
//     }
// };

// // Function 4: Implement Queue Using Two Stacks.
// class QueueAlgorithms {
// private:
//     stack<int> inStack;  // used for enqueue
//     stack<int> outStack; // used for dequeue/front

//     void printStack(stack<int> s, const string& label) {
//         vector<int> content;
//         while (!s.empty()) { content.push_back(s.top()); s.pop(); }
//         cout << label << " (bottom->top): ";
//         for (int i = (int)content.size() - 1; i >= 0; i--) cout << content[i] << " ";
//         cout << endl;
//     }

//     // move elements from inStack to outStack only when outStack is empty
//     void transferIfNeeded() {
//         if (outStack.empty()) {
//             cout << "  outStack empty -> transferring all elements from inStack" << endl;
//             while (!inStack.empty()) {
//                 outStack.push(inStack.top());
//                 inStack.pop();
//             }
//         }
//     }

// public:
//     // Enqueue: simply push onto inStack.
//     void enqueue() {
//         cout << endl << "========== ENQUEUE ==========" << endl;
//         int val;
//         cout << "Enter value to enqueue: ";
//         cin >> val;
//         inStack.push(val);
//         cout << "Pushed " << val << " onto Stack 1 (inStack)" << endl;
//         printStack(inStack, "Stack 1");
//         printStack(outStack, "Stack 2");
//         cout << endl << "Time Complexity: O(1) amortized" << endl;
//         cout << "Space Complexity: O(1) per call" << endl;
//     }

//     // Dequeue: if outStack empty, transfer all from inStack,
//     void dequeue() {
//         cout << endl << "========== DEQUEUE ==========" << endl;
//         transferIfNeeded();
//         if (outStack.empty()) {
//             cout << "Queue is empty. Cannot dequeue." << endl;
//             return;
//         }
//         int val = outStack.top();
//         outStack.pop();
//         cout << "Dequeued value: " << val << endl;
//         printStack(inStack, "Stack 1");
//         printStack(outStack, "Stack 2");
//         cout << endl << "Time Complexity: O(1) amortized, O(n) worst case" << endl;
//         cout << "Space Complexity: O(n)" << endl;
//     }

//     // Front: peek without removing.
//     void front() {
//         cout << endl << "========== FRONT ==========" << endl;
//         transferIfNeeded();
//         if (outStack.empty()) {
//             cout << "Queue is empty." << endl;
//             return;
//         }
//         cout << "Front value: " << outStack.top() << endl;
//         printStack(inStack, "Stack 1");
//         printStack(outStack, "Stack 2");
//         cout << endl << "Time Complexity: O(1) amortized" << endl;
//         cout << "Space Complexity: O(n)" << endl;
//     }

//     // Empty: check if queue has no elements.
//     void isEmpty() {
//         cout << endl << "========== EMPTY CHECK ==========" << endl;
//         bool empty = inStack.empty() && outStack.empty();
//         cout << "Queue State -> Stack 1 size=" << inStack.size()
//              << ", Stack 2 size=" << outStack.size() << endl;
//         cout << "Is Empty: " << (empty ? "true" : "false") << endl;
//         cout << endl << "Time Complexity: O(1)" << endl;
//         cout << "Space Complexity: O(1)" << endl;
//     }
// };

// // Menu
// class Menu {
// private:
//     LinkedListAlgorithms llAlgo;
//     StackAlgorithms stackAlgo;
//     QueueAlgorithms queueAlgo;

//     void displayMainMenu() {
//         cout << endl << "=============================================" << endl;
//         cout << " WEEK 4 DSA PRACTICE PROJECT" << endl;
//         cout << " Linked List - Stack - Queue" << endl;
//         cout << "=============================================" << endl << endl;
//         cout << "1.  Reverse Linked List" << endl;
//         cout << "2.  Merge Two Sorted Linked Lists" << endl;
//         cout << "3.  Valid Parentheses" << endl;
//         cout << "4.  Implement Queue Using Stacks" << endl;
//         cout << "5.  Add Two Numbers" << endl;
//         cout << "6.  Reorder List" << endl;
//         cout << "7.  Remove Nth Node From End" << endl;
//         cout << "8.  Daily Temperatures" << endl;
//         cout << "9.  Merge K Sorted Linked Lists" << endl;
//         cout << "10. Reverse Nodes in K-Group" << endl;
//         cout << "11. Display Current Linked List" << endl;
//         cout << "12. Clear Linked List" << endl;
//         cout << "0.  Exit" << endl << endl;
//         cout << "Enter Choice: ";
//     }

//     // For option 4, a small sub-menu lets the user demonstrate
//     // enqueue/dequeue/front/empty repeatedly on the same queue.
//     void queueSubMenu() {
//         bool back = false;
//         while (!back) {
//             cout << endl << "----- Queue Using Two Stacks -----" << endl;
//             cout << "1. Enqueue" << endl;
//             cout << "2. Dequeue" << endl;
//             cout << "3. Front" << endl;
//             cout << "4. Is Empty" << endl;
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
//                 case 1: queueAlgo.enqueue(); break;
//                 case 2: queueAlgo.dequeue(); break;
//                 case 3: queueAlgo.front(); break;
//                 case 4: queueAlgo.isEmpty(); break;
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
//                 cout << "Invalid input! Please enter a number between 0 and 12." << endl;
//                 continue;
//             }

//             switch (choice) {
//                 case 1: llAlgo.reverseList(); break;
//                 case 2: llAlgo.mergeTwoSortedLists(); break;
//                 case 3: stackAlgo.validParentheses(); break;
//                 case 4: queueSubMenu(); break;
//                 case 5: llAlgo.addTwoNumbers(); break;
//                 case 6: llAlgo.reorderList(); break;
//                 case 7: llAlgo.removeNthFromEnd(); break;
//                 case 8: stackAlgo.dailyTemperatures(); break;
//                 case 9: llAlgo.mergeKSortedLists(); break;
//                 case 10: llAlgo.reverseKGroup(); break;
//                 case 11: llAlgo.displayCurrentList(); break;
//                 case 12: llAlgo.clearList(); break;
//                 case 0:
//                     llAlgo.clearList(); // free memory before exit
//                     cout << endl << "Thank you for using the Week 4 DSA Practice Project." << endl;
//                     running = false;
//                     break;
//                 default:
//                     cout << "Invalid choice! Please enter a number between 0 and 12." << endl;
//             }
//         }
//     }
// };

// int main() {
//     Menu menu;
//     menu.start();
//     return 0;
// }