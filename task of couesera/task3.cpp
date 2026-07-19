// #include <iostream>
// #include <cstring>
// using namespace std;

// class StringAlgorithms {
// private:
//     static const int MAX_LEN = 1000;
//     static const int MAX_STRINGS = 100;
    
//     char toLowerCase(char c) {
//         if (c >= 'A' && c <= 'Z') {
//             return c + 32;
//         }
//         return c;
//     }
    
//     bool isAlphanumeric(char c) {
//         return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
//     }
    
//     void getFrequency(const char* str, int freq[256]) {
//         for (int i = 0; i < 256; i++) freq[i] = 0;
//         for (int i = 0; str[i] != '\0'; i++) {
//             freq[(unsigned char)str[i]]++;
//         }
//     }
    
//     void displayFrequency(int freq[256], const char* str) {
//         cout << endl << "Character Frequencies:" << endl;
//         for (int i = 0; i < 256; i++) {
//             if (freq[i] > 0) {
//                 if (i >= 32 && i < 127) {
//                     cout << "  '" << (char)i << "': " << freq[i] << endl;
//                 }
//             }
//         }
//     }

// public:
//     void validAnagram() {
//         cout << endl << "========== VALID ANAGRAM ==========" << endl;
        
//         char str1[MAX_LEN], str2[MAX_LEN];
        
//         cout << "Enter first string: ";
//         cin.ignore();
//         cin.getline(str1, MAX_LEN);
        
//         cout << "Enter second string: ";
//         cin.getline(str2, MAX_LEN);
        
//         cout << endl << "String 1: " << str1 << endl;
//         cout << "String 2: " << str2 << endl;
        
//         if (strlen(str1) != strlen(str2)) {
//             cout << endl << "NOT an Anagram (Different lengths)" << endl;
//             cout << "Time Complexity: O(n)" << endl;
//             cout << "Space Complexity: O(1)" << endl;
//             return;
//         }
        
//         int freq1[256], freq2[256];
//         getFrequency(str1, freq1);
//         getFrequency(str2, freq2);
        
//         displayFrequency(freq1, str1);
//         cout << endl << "String 2 Frequencies:" << endl;
//         for (int i = 0; i < 256; i++) {
//             if (freq2[i] > 0) {
//                 if (i >= 32 && i < 127) {
//                     cout << "  '" << (char)i << "': " << freq2[i] << endl;
//                 }
//             }
//         }
        
//         cout << endl << "Comparison:" << endl;
//         bool isAnagram = true;
//         for (int i = 0; i < 256; i++) {
//             if (freq1[i] != freq2[i]) {
//                 isAnagram = false;
//                 break;
//             }
//         }
        
//         cout << endl << "--- Result ---" << endl;
//         if (isAnagram) {
//             cout << "Valid Anagram!" << endl;
//         } else {
//             cout << "NOT an Anagram" << endl;
//         }
        
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(1) - Fixed size array for ASCII" << endl;
//     }

//     void validPalindrome() {
//         cout << endl << "========== VALID PALINDROME ==========" << endl;
        
//         char str[MAX_LEN];
        
//         cout << "Enter string: ";
//         cin.ignore();
//         cin.getline(str, MAX_LEN);
        
//         cout << endl << "Original String: " << str << endl;
//         cout << "(Ignoring spaces, punctuation, and case)" << endl;
        
//         char cleaned[MAX_LEN];
//         int cleanIdx = 0;
        
//         cout << endl << "Cleaning Process:" << endl;
//         for (int i = 0; str[i] != '\0'; i++) {
//             if (isAlphanumeric(str[i])) {
//                 cleaned[cleanIdx++] = toLowerCase(str[i]);
//                 cout << "  Keep '" << str[i] << "' -> '" << cleaned[cleanIdx-1] << "'" << endl;
//             } else {
//                 cout << "  Skip '" << str[i] << "' (not alphanumeric)" << endl;
//             }
//         }
//         cleaned[cleanIdx] = '\0';
        
//         cout << endl << "Cleaned String: " << cleaned << endl;
        
//         cout << endl << "Two-Pointer Comparison:" << endl;
//         int left = 0, right = cleanIdx - 1;
//         bool isPalin = true;
//         int step = 1;
        
//         while (left < right) {
//             cout << "Step " << step << ": left=" << left << " ('" << cleaned[left] 
//                  << "'), right=" << right << " ('" << cleaned[right] << "')";
            
//             if (cleaned[left] != cleaned[right]) {
//                 cout << " NOT MATCHING" << endl;
//                 isPalin = false;
//                 break;
//             } else {
//                 cout << " MATCH" << endl;
//             }
//             left++;
//             right--;
//             step++;
//         }
        
//         cout << endl << "--- Result ---" << endl;
//         if (isPalin) {
//             cout << "Valid Palindrome!" << endl;
//         } else {
//             cout << "NOT a Palindrome" << endl;
//         }
        
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(n) - For cleaned string" << endl;
//     }

//     void reverseString() {
//         cout << endl << "========== REVERSE STRING ==========" << endl;
        
//         char str[MAX_LEN];
        
//         cout << "Enter string: ";
//         cin.ignore();
//         cin.getline(str, MAX_LEN);
        
//         int len = strlen(str);
//         cout << endl << "Original String: " << str << endl;
//         cout << "Length: " << len << endl;
        
//         cout << endl << "Reversal Process (Two Pointers):" << endl;
//         int left = 0, right = len - 1;
//         int step = 1;
        
//         while (left < right) {
//             cout << "Step " << step << ": Swap str[" << left << "]='" << str[left] 
//                  << "' with str[" << right << "]='" << str[right] << "'" << endl;
            
//             char temp = str[left];
//             str[left] = str[right];
//             str[right] = temp;
            
//             cout << "  Current: " << str << endl;
//             left++;
//             right--;
//             step++;
//         }
        
//         cout << endl << "--- Result ---" << endl;
//         cout << "Reversed String: " << str << endl;
        
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(1) - In-place reversal" << endl;
//     }

//     void firstUniqueCharacter() {
//         cout << endl << "========== FIRST UNIQUE CHARACTER ==========" << endl;
        
//         char str[MAX_LEN];
        
//         cout << "Enter string: ";
//         cin.ignore();
//         cin.getline(str, MAX_LEN);
        
//         int len = strlen(str);
//         cout << endl << "Original String: " << str << endl;
        
//         int freq[256];
//         getFrequency(str, freq);
        
//         cout << endl << "Character Frequencies:" << endl;
//         for (int i = 0; i < len; i++) {
//             if (freq[(unsigned char)str[i]] > 0) {
//                 cout << "  '" << str[i] << "': " << freq[(unsigned char)str[i]] << endl;
//                 freq[(unsigned char)str[i]] = -1;
//             }
//         }
        
//         cout << endl << "Searching for First Unique Character:" << endl;
//         int firstUniqueIdx = -1;
        
//         for (int i = 0; i < len; i++) {
//             int count = 0;
//             for (int j = 0; j < len; j++) {
//                 if (str[i] == str[j]) count++;
//             }
            
//             cout << "  Index " << i << " ('" << str[i] << "'): Count = " << count;
            
//             if (count == 1) {
//                 cout << " UNIQUE!" << endl;
//                 firstUniqueIdx = i;
//                 break;
//             } else {
//                 cout << endl;
//             }
//         }
        
//         cout << endl << "--- Result ---" << endl;
//         if (firstUniqueIdx != -1) {
//             cout << "First Unique Character: '" << str[firstUniqueIdx] << "'" << endl;
//             cout << "   Index: " << firstUniqueIdx << endl;
//         } else {
//             cout << "No Unique Character Found" << endl;
//         }
        
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(1) - Fixed size array for ASCII" << endl;
//     }

//     void longestSubstringWithoutRepeating() {
//         cout << endl << "========== LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS ==========" << endl;
        
//         char str[MAX_LEN];
        
//         cout << "Enter string: ";
//         cin.ignore();
//         cin.getline(str, MAX_LEN);
        
//         int len = strlen(str);
//         cout << endl << "Original String: " << str << endl;
        
//         cout << endl << "Sliding Window Process:" << endl;
        
//         int left = 0;
//         int maxLen = 0;
//         int maxStart = 0;
//         int lastIndex[256];
        
//         for (int i = 0; i < 256; i++) lastIndex[i] = -1;
        
//         for (int right = 0; right < len; right++) {
//             char c = str[right];
//             int cIdx = (unsigned char)c;
            
//             cout << endl << "right=" << right << " ('" << c << "')" << endl;
            
//             if (lastIndex[cIdx] >= left) {
//                 cout << "  Character '" << c << "' found at index " << lastIndex[cIdx] << endl;
//                 left = lastIndex[cIdx] + 1;
//                 cout << "  Move left to " << left << endl;
//             }
            
//             lastIndex[cIdx] = right;
//             int windowLen = right - left + 1;
            
//             cout << "  Window: [" << left << ", " << right << "] = '";
//             for (int i = left; i <= right; i++) cout << str[i];
//             cout << "' (len=" << windowLen << ")" << endl;
            
//             if (windowLen > maxLen) {
//                 maxLen = windowLen;
//                 maxStart = left;
//                 cout << "  NEW MAX LENGTH: " << maxLen << endl;
//             }
//         }
        
//         cout << endl << "--- Result ---" << endl;
//         cout << "Longest Substring Length: " << maxLen << endl;
//         cout << "   Substring: '";
//         for (int i = maxStart; i < maxStart + maxLen; i++) cout << str[i];
//         cout << "'" << endl;
        
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(min(n, charset size))" << endl;
//     }

//     void groupAnagrams() {
//         cout << endl << "========== GROUP ANAGRAMS ==========" << endl;
        
//         int numStrings;
//         cout << "Enter number of strings: ";
//         cin >> numStrings;
//         cin.ignore();
        
//         if (numStrings <= 0 || numStrings > MAX_STRINGS) {
//             cout << "Invalid number of strings" << endl;
//             return;
//         }
        
//         char strings[MAX_STRINGS][MAX_LEN];
//         char sorted[MAX_STRINGS][MAX_LEN];
        
//         cout << endl << "Enter " << numStrings << " strings:" << endl;
//         for (int i = 0; i < numStrings; i++) {
//             cout << "String " << i + 1 << ": ";
//             cin.getline(strings[i], MAX_LEN);
//             strcpy_s(sorted[i], MAX_LEN, strings[i]);
//         }
        
//         cout << endl << "Original Strings: ";
//         for (int i = 0; i < numStrings; i++) {
//             cout << strings[i];
//             if (i < numStrings - 1) cout << ", ";
//         }
//         cout << endl;
        
//         cout << endl << "Sorting Each String:" << endl;
//         for (int i = 0; i < numStrings; i++) {
//             int len = strlen(sorted[i]);
            
//             for (int j = 0; j < len - 1; j++) {
//                 for (int k = 0; k < len - j - 1; k++) {
//                     if (sorted[i][k] > sorted[i][k + 1]) {
//                         char temp = sorted[i][k];
//                         sorted[i][k] = sorted[i][k + 1];
//                         sorted[i][k + 1] = temp;
//                     }
//                 }
//             }
            
//             cout << "  '" << strings[i] << "' -> sorted key: '" << sorted[i] << "'" << endl;
//         }
        
//         cout << endl << "Grouping by Sorted Key:" << endl;
//         bool processed[MAX_STRINGS];
//         for (int i = 0; i < numStrings; i++) processed[i] = false;
        
//         int groupNum = 1;
//         for (int i = 0; i < numStrings; i++) {
//             if (processed[i]) continue;
            
//             cout << endl << "Group " << groupNum << " (key: '" << sorted[i] << "'): ";
//             cout << strings[i];
//             processed[i] = true;
            
//             for (int j = i + 1; j < numStrings; j++) {
//                 if (!processed[j] && strcmp(sorted[i], sorted[j]) == 0) {
//                     cout << ", " << strings[j];
//                     processed[j] = true;
//                 }
//             }
//             cout << endl;
//             groupNum++;
//         }
        
//         cout << endl << "Time Complexity: O(n * k log k) where k is average string length" << endl;
//         cout << "Space Complexity: O(n * k)" << endl;
//     }

//     void encodeDecodeStrings() {
//         cout << endl << "========== ENCODE AND DECODE STRINGS ==========" << endl;
        
//         int choice;
//         cout << "1. Encode Strings" << endl;
//         cout << "2. Decode String" << endl;
//         cout << "Enter choice (1-2): ";
//         cin >> choice;
//         cin.ignore();
        
//         if (choice == 1) {
//             int numStrings;
//             cout << endl << "Enter number of strings: ";
//             cin >> numStrings;
//             cin.ignore();
            
//             if (numStrings <= 0 || numStrings > MAX_STRINGS) {
//                 cout << "Invalid number" << endl;
//                 return;
//             }
            
//             char encoded[MAX_LEN * 5] = "";
            
//             cout << endl << "Enter " << numStrings << " strings:" << endl;
//             for (int i = 0; i < numStrings; i++) {
//                 char str[MAX_LEN];
//                 cout << "String " << i + 1 << ": ";
//                 cin.getline(str, MAX_LEN);
                
//                 int len = strlen(str);
//                 char lenStr[20];
//                 sprintf_s(lenStr, 20, "%d", len);
                
//                 strcat_s(encoded, MAX_LEN * 5, lenStr);
//                 strcat_s(encoded, MAX_LEN * 5, "#");
//                 strcat_s(encoded, MAX_LEN * 5, str);
                
//                 cout << "  Encoded: " << lenStr << "#" << str << endl;
//             }
            
//             cout << endl << "--- Encoding Result ---" << endl;
//             cout << "Full Encoded String: " << encoded << endl;
            
//         } else if (choice == 2) {
//             char encoded[MAX_LEN * 5];
//             cout << endl << "Enter encoded string: ";
//             cin.getline(encoded, MAX_LEN * 5);
            
//             cout << endl << "--- Decoding Process ---" << endl;
//             cout << "Encoded String: " << encoded << endl;
//             cout << endl << "Decoding:" << endl;
            
//             int pos = 0;
//             int stringNum = 1;
            
//             while (encoded[pos] != '\0') {
//                 int len = 0;
//                 while (encoded[pos] >= '0' && encoded[pos] <= '9') {
//                     len = len * 10 + (encoded[pos] - '0');
//                     pos++;
//                 }
                
//                 if (encoded[pos] == '#') pos++;
                
//                 char str[MAX_LEN];
//                 int strIdx = 0;
                
//                 for (int i = 0; i < len; i++) {
//                     str[strIdx++] = encoded[pos++];
//                 }
//                 str[strIdx] = '\0';
                
//                 cout << "String " << stringNum << ": '" << str << "'" << endl;
//                 stringNum++;
//             }
            
//         } else {
//             cout << "Invalid choice" << endl;
//         }
        
//         cout << endl << "Time Complexity: O(n)" << endl;
//         cout << "Space Complexity: O(n)" << endl;
//     }

//     void longestPalindromicSubstring() {
//         cout << endl << "========== LONGEST PALINDROMIC SUBSTRING ==========" << endl;
        
//         char str[MAX_LEN];
        
//         cout << "Enter string: ";
//         cin.ignore();
//         cin.getline(str, MAX_LEN);
        
//         int len = strlen(str);
//         cout << endl << "Original String: " << str << endl;
        
//         cout << endl << "Expand Around Center Approach:" << endl;
        
//         int maxLen = 0;
//         int maxStart = 0;
        
//         for (int center = 0; center < len; center++) {
//             int left = center, right = center;
            
//             while (left >= 0 && right < len && str[left] == str[right]) {
//                 int currLen = right - left + 1;
                
//                 if (currLen > maxLen) {
//                     maxLen = currLen;
//                     maxStart = left;
//                 }
                
//                 left--;
//                 right++;
//             }
            
//             left = center;
//             right = center + 1;
            
//             while (left >= 0 && right < len && str[left] == str[right]) {
//                 int currLen = right - left + 1;
                
//                 if (currLen > maxLen) {
//                     maxLen = currLen;
//                     maxStart = left;
//                 }
                
//                 left--;
//                 right++;
//             }
//         }
        
//         cout << endl << "Longest Palindrome Found:" << endl;
//         cout << "Start Index: " << maxStart << endl;
//         cout << "Length: " << maxLen << endl;
//         cout << "Substring: '";
//         for (int i = maxStart; i < maxStart + maxLen; i++) {
//             cout << str[i];
//         }
//         cout << "'" << endl;
        
//         cout << endl << "--- Result ---" << endl;
//         cout << "Longest Palindromic Substring: '";
//         for (int i = maxStart; i < maxStart + maxLen; i++) {
//             cout << str[i];
//         }
//         cout << "' (Length: " << maxLen << ")" << endl;
        
//         cout << endl << "Time Complexity: O(n^2)" << endl;
//         cout << "Space Complexity: O(1)" << endl;
//     }

//     void minimumWindowSubstring() {
//         cout << endl << "========== MINIMUM WINDOW SUBSTRING ==========" << endl;
        
//         char s[MAX_LEN], t[MAX_LEN];
        
//         cout << "Enter string s: ";
//         cin.ignore();
//         cin.getline(s, MAX_LEN);
        
//         cout << "Enter pattern t: ";
//         cin.getline(t, MAX_LEN);
        
//         int sLen = strlen(s);
//         int tLen = strlen(t);
        
//         cout << endl << "String s: " << s << endl;
//         cout << "Pattern t: " << t << endl;
        
//         int patternFreq[256];
//         getFrequency(t, patternFreq);
        
//         cout << endl << "Pattern Frequencies:" << endl;
//         for (int i = 0; i < 256; i++) {
//             if (patternFreq[i] > 0) {
//                 cout << "  '" << (char)i << "': " << patternFreq[i] << endl;
//             }
//         }
        
//         int windowFreq[256];
//         getFrequency("", windowFreq);
        
//         int left = 0, minLen = INT_MAX, minStart = 0;
//         int formed = 0;
//         int required = 0;
        
//         for (int i = 0; i < 256; i++) {
//             if (patternFreq[i] > 0) required++;
//         }
        
//         cout << endl << "Sliding Window Process:" << endl;
        
//         for (int right = 0; right < sLen; right++) {
//             char c = s[right];
//             int cIdx = (unsigned char)c;
//             windowFreq[cIdx]++;
            
//             if (patternFreq[cIdx] > 0 && windowFreq[cIdx] == patternFreq[cIdx]) {
//                 formed++;
//             }
            
//             cout << endl << "right=" << right << " ('" << c << "')" << endl;
            
//             while (formed == required && left <= right) {
//                 if (right - left + 1 < minLen) {
//                     minLen = right - left + 1;
//                     minStart = left;
//                     cout << "  NEW MIN: [" << left << ", " << right << "] = '";
//                     for (int i = left; i <= right; i++) cout << s[i];
//                     cout << "'" << endl;
//                 }
                
//                 char leftChar = s[left];
//                 int leftIdx = (unsigned char)leftChar;
//                 windowFreq[leftIdx]--;
                
//                 if (patternFreq[leftIdx] > 0 && windowFreq[leftIdx] < patternFreq[leftIdx]) {
//                     formed--;
//                 }
                
//                 left++;
//             }
//         }
        
//         cout << endl << "--- Result ---" << endl;
//         if (minLen != INT_MAX) {
//             cout << "Minimum Window: '";
//             for (int i = minStart; i < minStart + minLen; i++) {
//                 cout << s[i];
//             }
//             cout << "' (Length: " << minLen << ")" << endl;
//         } else {
//             cout << "No window found" << endl;
//         }
        
//         cout << endl << "Time Complexity: O(n + m)" << endl;
//         cout << "Space Complexity: O(charset size)" << endl;
//     }

//     void regularExpressionMatching() {
//         cout << endl << "========== REGULAR EXPRESSION MATCHING ==========" << endl;
//         cout << "Support: '.' (any character) and '*' (0 or more)" << endl << endl;
        
//         char s[MAX_LEN], p[MAX_LEN];
        
//         cout << "Enter string s: ";
//         cin.ignore();
//         cin.getline(s, MAX_LEN);
        
//         cout << "Enter pattern p: ";
//         cin.getline(p, MAX_LEN);
        
//         int sLen = strlen(s);
//         int pLen = strlen(p);
        
//         cout << endl << "String: " << s << endl;
//         cout << "Pattern: " << p << endl;
        
//         bool dp[MAX_LEN + 1][MAX_LEN + 1];
        
//         for (int i = 0; i <= sLen; i++) {
//             for (int j = 0; j <= pLen; j++) {
//                 dp[i][j] = false;
//             }
//         }
        
//         dp[0][0] = true;
        
//         for (int j = 2; j <= pLen; j++) {
//             if (p[j - 1] == '*') {
//                 dp[0][j] = dp[0][j - 2];
//             }
//         }
        
//         cout << endl << "--- DP Table Construction ---" << endl;
        
//         for (int i = 1; i <= sLen; i++) {
//             for (int j = 1; j <= pLen; j++) {
//                 if (p[j - 1] == '*') {
//                     dp[i][j] = dp[i][j - 2];
                    
//                     if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
//                         dp[i][j] = dp[i][j] || dp[i - 1][j];
//                     }
//                 } else if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
//                     dp[i][j] = dp[i - 1][j - 1];
//                 }
//             }
//         }
        
//         cout << "DP Table:" << endl;
//         cout << "  ";
//         for (int j = 0; j <= pLen; j++) {
//             if (j == 0) cout << "  ";
//             else cout << p[j - 1] << " ";
//         }
//         cout << endl;
        
//         for (int i = 0; i <= sLen; i++) {
//             if (i == 0) cout << "  ";
//             else cout << s[i - 1] << " ";
            
//             for (int j = 0; j <= pLen; j++) {
//                 cout << (dp[i][j] ? "T" : "F") << " ";
//             }
//             cout << endl;
//         }
        
//         cout << endl << "--- Result ---" << endl;
//         if (dp[sLen][pLen]) {
//             cout << "String MATCHES the pattern" << endl;
//         } else {
//             cout << "String DOES NOT match the pattern" << endl;
//         }
        
//         cout << endl << "Time Complexity: O(m * n)" << endl;
//         cout << "Space Complexity: O(m * n)" << endl;
//     }
// };

// class Menu {
// private:
//     StringAlgorithms algorithms;
    
//     void displayMainMenu() {
//         cout << endl << "==========================================" << endl;
//         cout << " WEEK 3 DSA PRACTICE PROJECT" << endl;
//         cout << " Strings - Hashing - Sliding Window" << endl;
//         cout << "==========================================" << endl << endl;
//         cout << "1.  Valid Anagram" << endl;
//         cout << "2.  Valid Palindrome" << endl;
//         cout << "3.  Reverse String" << endl;
//         cout << "4.  First Unique Character" << endl;
//         cout << "5.  Longest Substring Without Repeating Characters" << endl;
//         cout << "6.  Group Anagrams" << endl;
//         cout << "7.  Encode and Decode Strings" << endl;
//         cout << "8.  Longest Palindromic Substring" << endl;
//         cout << "9.  Minimum Window Substring" << endl;
//         cout << "10. Regular Expression Matching" << endl;
//         cout << "0.  Exit" << endl << endl;
//         cout << "Enter your choice (0-10): ";
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
//                 cout << "Invalid input! Please enter a number between 0 and 10." << endl;
//                 continue;
//             }
            
//             switch (choice) {
//                 case 1:
//                     algorithms.validAnagram();
//                     break;
//                 case 2:
//                     algorithms.validPalindrome();
//                     break;
//                 case 3:
//                     algorithms.reverseString();
//                     break;
//                 case 4:
//                     algorithms.firstUniqueCharacter();
//                     break;
//                 case 5:
//                     algorithms.longestSubstringWithoutRepeating();
//                     break;
//                 case 6:
//                     algorithms.groupAnagrams();
//                     break;
//                 case 7:
//                     algorithms.encodeDecodeStrings();
//                     break;
//                 case 8:
//                     algorithms.longestPalindromicSubstring();
//                     break;
//                 case 9:
//                     algorithms.minimumWindowSubstring();
//                     break;
//                 case 10:
//                     algorithms.regularExpressionMatching();
//                     break;
//                 case 0:
//                     cout << endl << "" << endl << "Thank you for using Week 3 DSA Practice!" << endl << "Keep learning and practicing!" << endl << "" << endl << endl;
//                     running = false;
//                     break;
//                 default:
//                     cout << "Invalid choice! Please enter a number between 0 and 10." << endl;
//             }
//         }
//     }
// };

// int main() {
//     Menu menu;
//     menu.start();
    
//     return 0;
// }