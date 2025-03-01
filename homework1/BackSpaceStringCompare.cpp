/*
TECHNIQUE USED:
- Backward iteration

TIME COMPLEXITY:
- O(n)
  - n: length of the string

SPACE COMPLEXITY:
- O(1)

/*
----------------------------
QUESTIONS:

- Can I have empty strings?
- Can we have something like: "abc##c##"? (I assume we don't)

----------------------------
VISUALS:

hash_counter = 3
"abcdef###xyz"
      ^

"abcw#xyz"
^

- Whenever we see "#", we need to erase the thing behind
- Note that we write from left to right

----------------------------
STEPS TO TAKE:

str_len = str.length()
hash_counter = 0;
right = str_len - 1

- Loop:
  - if (str[i] == "#")
    - if (str[i] == "#"):
      - hash_counter++
    - else:
      - right--;
  

*/


#include <iostream>
#include <string>
using namespace std;
bool solveProblem(string str1, string str2);
void tests();

int main() {
  tests();
  return 0;
}

bool solveProblem(string str1, string str2) {
  int str1_len = str1.length();
  int str2_len = str2.length();
  
  if (str1_len == 0 && str2_len == 0) {
    return true;
  }
  
  int right1 = str1_len - 1;
  int right2 = str2_len - 1;
  
  // Loop for the str1
  int str1_hash_counter = 0;
  while (right1 >= 0) {
    if (str1[right1] == '#') {
      str1_hash_counter++;
    } else {
      if (str1_hash_counter > 0) {
        // delete from str1[right1] backward str1_hash_counter elements
        int start = right1 + 1 - str1_hash_counter;
        str1.erase(start, str1_hash_counter);
        right1 -= str1_hash_counter;
        continue;
      }
    }
    right1--;
  }
  
  for (int i = 0; i < str2_len; i++) {
    if (str2[i] == '#') str2.erase(i, 1);
  }
  
  // Loop for the str2
  int str2_hash_counter = 0;
  while (right2 >= 0) {
    if (str2[right2] == '#') {
      str1_hash_counter++;
    } else {
      if (str1_hash_counter > 0) {
        // delete from str1[right2] backward str1_hash_counter elements
        int start = right2 + 1 - str1_hash_counter;
        str1.erase(start, str1_hash_counter);
        right2 -= str1_hash_counter;
        continue;
      }
    }
    right2--;
  }
  
  for (int i = 0; i < str1_len; i++) {
    if (str1[i] == '#') str1.erase(i, 1);
  }
  
  if (str1 == str2) {
    return true;
  } else {
    return false;
  }
}


void tests() { 
  string str01 = "abcde";
  string str011 = "abcde";
  bool res1 = solveProblem(str01, str011);
  bool expected_res1 = true;
  
  string str02 = "Uber Career Prep";
  string str022 = "u#Uber Careee#r Prep";
  bool res2 = solveProblem(str02, str022);
  bool expected_res2 = true;
  
  string str03 = "abcdef###xyz";
  string str033 = "abcw#xyz";
  bool res3 = solveProblem(str03, str033);
  bool expected_res3 = true;
  
  string str04 = "abcdef###xyz";
  string str044 = "abcdefxyz###";
  bool res4 = solveProblem(str04, str044);
  bool expected_res4 = false;
  
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

// I did not get to solve the problem in 40 minutes
// I got this error message: "terminate called after throwing an instance of 'std::out_of_range' what():  basic_string::erase: __pos (which is 0) > this->size() (which is 0)"
// I will try to solve this problem againt later