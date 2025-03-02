/*
TECHNIQUE USED:
- Brute force

TIME COMPLEXITY:
- O(n^3)

SPACE COMPLEXITY:
- O(1)
------------------------------
QUESTIONS:

------------------------------
VISUALS:

"abracadabra", "abc"
^
------------------------------
STEPS TO TAKE:
- Loop over the first string
  - Loop over the second string
    - Check if the substring contains all the characters of the second string
    - If it does, update the max_substring
- Return the max_substring

*/

#include <iostream>
#include <string>
using namespace std;
int contains_all_chars(string str1, string str2, int start, int end);
int solveProblem(string str1, string str2);
void tests();

int main() {
  tests();
  return 0;
}

int contains_all_chars(string str1, string str2, int start, int end) {
  int res = 0;
  int i = 0;
  
  while () {
    if (str1[start] == str2[i]) {
      res++;
    }
  }
}

int solveProblem(string str1, string str2) {
  int str1_len = str1.length();
  int str2_len = str2.length();
  int max_substring = 0;
  
  if (str1_len == 0 || str2_len == 0) return 0;
  
  for (int i = 0; i < str1_len; i++) {
    for (int j = 0; j < str1_len; j++) {
      int substring_res = contains_all_chars(str1, str2, i, j);
      if (substring_res > max_substring) {
        max_substring = substring_res;
      }
    }
  }
}

void tests() {
  string first_str_1 = "abracadabra";
  string second_str_1 = "abc";
  int res1 = solveProblem(first_str_1, second_str_1);
  int expected_res1 = 4;
  
  string first_str_2 = "zxycbaabcdwxyzzxwdcbxyzabccbazyx";
  string second_str_2 = "zzyzx";
  int res2 = solveProblem(first_str_2, second_str_2);
  int expected_res2 = 10;
  
  string first_str_3 = "dog";
  string second_str_3 = "god";
  int res3 = solveProblem(first_str_3, second_str_3);
  int expected_res3 = 3;
  
  string first_str_4 = "";
  string second_str_4 = "abc";
  int res4 = solveProblem(first_str_4, second_str_4);
  int expected_res4 = 0;
  
  
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
}