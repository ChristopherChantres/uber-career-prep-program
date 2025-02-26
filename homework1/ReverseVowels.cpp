/*
TECHNIQUE USED:
- Forward/backward two-pointer

TIME COMPLEXITY:
- O(n)
  - n: length of the string

SPACE COMPLEXITY:
- O(1)

------------------------
QUESTIONS:

- Can we have empty strings?
- What is the max size of the string?

------------------------
VISUALS:

flamingo
  ^
       ^

flominga
    ^
    ^
    
Uber Career Prep
^
               ^
              
------------------------
STEPS TO TAKE:

unorderd_map<chat, int> bucket = {
  {'a', 1},
  {'e', 1},
  {'i', 1},
  {'o', 1},
  {'u', 1}
}

left = 0, right = n - 1
- Loop(left != right):
  - if str[left] && str[right] in {a,e,i,o,u}
    - aux = str[right]
    - right = str[left]
    - left = aux

*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
void tests();
string solveProblem(string str);

int main() {
  tests();
  return 0;
}

// Main Algorithm
string solveProblem(string str) {
  int str_len = str.length();
  if (str_len== 0) return str;
  
  int left = 0;
  int right = str_len - 1;
  unordered_map<char, bool> vowels = {
    {'a', true},
    {'e', true},
    {'i', true},
    {'o', true},
    {'u', true},
  };
  
  while (left < right) {
    if ((vowels.find(str[left]) != vowels.end()) && (vowels.find(str[right]) != vowels.end())) {
      // swap str[left] & str[right]
      char aux = str[right];
      str[right] = str[left];
      str[left] = aux;
      right--;
      left++;
    } else {
      if (vowels.find(str[right]) != vowels.end()) {
        // str[right] is a vowel
        left++;
      } else {
        // str[right] is NOT a vowel
        right--;
      }
    }
  }
  
  return str;
}

// Tests
void tests() {
  // TEST DID NOT PASSED
  string str1 = "Uber Career Prep";
  string res1 = solveProblem(str1);
  string expected_res1 = "eber Ceraer PrUp";
  
  // TEST PASSED
  string str2 = "xyz";
  string res2 = solveProblem(str2);
  string expected_res2 = "xyz";
  
  // TEST PASSED
  string str3 = "flamingo";
  string res3 = solveProblem(str3);
  string expected_res3 = "flominga";
  
  // TEST PASSED
  string str4 = "";
  string res4 = solveProblem(str4);
  string expected_res4 = "";
  
  if (res1 == expected_res1) {
    cout << "TEST (1) PASSED!!" << endl;
  } else {
    cout << "TEST (1) DID NOT PASSED" << endl;
  }
  
  if (res2 == expected_res2) {
    cout << "TEST (2) PASSED!!" << endl;
  } else {
    cout << "TEST (2) DID NOT PASSED" << endl;
  }
  
  if (res3 == expected_res3) {
    cout << "TEST (3) PASSED!!" << endl;
  } else {
    cout << "TEST (3) DID NOT PASSED" << endl;
  }
  
  if (res4 == expected_res4) {
    cout << "TEST (4) PASSED!!" << endl;
  } else {
    cout << "TEST (4) DID NOT PASSED" << endl;
  }
}

// I spent all 40 minutes on this problem (including comments and tests)