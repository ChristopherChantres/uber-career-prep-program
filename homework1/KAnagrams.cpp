/*
TECHNIQUE USED:
- Hashing:
    - One-directional running computation/total

TIME COMPLEXITY:
- O(n)
  - n: length of the first string

SPACE COMPLEXITY:
- O(n)
  - n: length of the first string

------------------------------
QUESTIONS/COMMENTS:

- What if we have at least one empty string?

Let's assume that k >=0

------------------------------
VISUALS:

"apple" "peach"
output: 2 --> "ch"?


"cat" "dog"
output: 3 --> "cat"?

"debit curd" "bad credit"
output: 1 --> "r"?

"" "hola"
k = 3
otuput: false

"" ""
k = 0
output: true

------------------------------
STEPS TO TAKE:

k = whatever value given
counter = 0;

- We can create a frequency table with an unordered_map<char, int> --> frequency_table
- We loop over the first string, and we append each char into the frequency_table
- We loop over the second string, and we perform the following validations:
  - if we DO NOT find str2[i] in the frequency_table:
    - counter++

- Lastly, we compare:
  - if (counter <= k):
    - return true;
  else:
    - return false;
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
bool solveProblem(string str1, string str2, int k);
void tests();

int main() {
  tests();
  return 0;
}

// Main Algorithm
bool solveProblem(string str1, string str2, int k) {
  int str1_len = str1.length();
  int str2_len = str2.length();
  if (str1_len == 0 && str2_len == 0) return true;
  
  unordered_map<char, int> frequency_table;
  int counter = 0;
  
  // Append chars from str1 to the frequency_table
  for (char ch : str1) {
    frequency_table[ch]++;
  }
  
  for(char ch : str2) {
    // if we do not find ch in frequency_table
    if (frequency_table.find(ch) == frequency_table.end()) {
      counter++;
    }
  }
  
  if (counter <= k) {
    return true;
  } else {
    return false;
  }
}

// Tests
void tests() {
  // TEST PASSED
  string str01 = "apple";
  string str11 = "peach";
  int k1 = 1;
  bool res1 = solveProblem(str01, str11, k1);
  bool expected_res1 = false;
  
  // TEST PASSED
  string str02 = "apple";
  string str22 = "peach";
  int k2 = 2;
  bool res2 = solveProblem(str02, str22, k2);
  bool expected_res2 = true;
  
  // TEST PASSED
  string str03 = "cat";
  string str33 = "dog";
  int k3 = 3;
  bool res3 = solveProblem(str03, str33, k3);
  bool expected_res3 = true;

  // TEST PASSED
  string str04 = "debit curd";
  string str44 = "bad credit";
  int k4 = 1;
  bool res4 = solveProblem(str04, str44, k4);
  bool expected_res4 = true;
  
  // TEST PASSED
  string str05 = "";
  string str55 = "hola";
  int k5 = 3;
  bool res5 = solveProblem(str05, str55, k5);
  bool expected_res5 = false;
  
  // TEST PASSED
  string str06 = "";
  string str66 = "hola";
  int k6 = 4;
  bool res6 = solveProblem(str06, str66, k6);
  bool expected_res6 = true;
  
  // TEST PASSED
  string str07 = "";
  string str77 = "";
  int k7 = 0;
  bool res7 = solveProblem(str07, str77, k7);
  bool expected_res7 = true;
  
  
  if (res1 == expected_res1) {
    cout << "TEST (1) PASSED!!" << endl;
  } else {
    cout << "TEST (1) DID NOT PASSED!!" << endl;
  }
  
  if (res2 == expected_res2) {
    cout << "TEST (2) PASSED!!" << endl;
  } else {
    cout << "TEST (2) DID NOT PASSED!!" << endl;
  }
  
  if (res3 == expected_res3) {
    cout << "TEST (3) PASSED!!" << endl;
  } else {
    cout << "TEST (3) DID NOT PASSED!!" << endl;
  }
  
  if (res4 == expected_res4) {
    cout << "TEST (4) PASSED!!" << endl;
  } else {
    cout << "TEST (4) DID NOT PASSED!!" << endl;
  }
  
  if (res5 == expected_res5) {
    cout << "TEST (5) PASSED!!" << endl;
  } else {
    cout << "TEST (5) DID NOT PASSED!!" << endl;
  }
  
  if (res6 == expected_res6) {
    cout << "TEST (6) PASSED!!" << endl;
  } else {
    cout << "TEST (6) DID NOT PASSED!!" << endl;
  }
  
  if (res7 == expected_res7) {
    cout << "TEST (7) PASSED!!" << endl;
  } else {
    cout << "TEST (7) DID NOT PASSED!!" << endl;
  } 
}

// I spent 34:11 minutes on this problem (including tests and comments)