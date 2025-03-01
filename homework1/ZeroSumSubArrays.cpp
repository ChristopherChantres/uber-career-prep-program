/*
TECHNIQUE USED:
- Bruteforce

TIME COMPLEXITY:
  - O(n^2)
    - n: length of the array

SPACE COMPLEXITY:
  - O(1)


-----------------------
QUESTIONS:
  
  - Can we get an empty array?
  - Does each element fit into an "int"?
  - What is the max length that I can get from a given array?
  - What if we have an array filled with zeroes? (return the length of the array)
  - What if we have 2 or more contiguous zeroes? How do we determine if they are proper subarrays?
  
-----------------------
VISUALS:

total_count
arr_sum = 0
[4, 5, 2, -1, -3, -3, 4, 6, -7]
    ^
    ^
-----------------------
STEPS TO TAKE:

what do we need to do if we find a 0
  
  - Loop
    - if (number == 0):
      total_count++
    - add number to arr_sum
    - if (arr_sum == 0):
      - we have found a zero number
      total_count++
    - else:
      continue
*/

#include <iostream>
#include <vector>
using namespace std;
void tests();
int solveProblem(vector<int> arr);

// Main
int main() {
  tests();
  return 0;
}

// Main Algorith
int solveProblem(vector<int> arr) {
  int arr_size = arr.size();
  if (arr_size == 0) return arr_size;
  
  int total_count = 0;
  int arr_sum = 0;
  
  for (int i = 0; i < arr_size; i++) {
    arr_sum = 0;
    for (int j = i; j < arr_size; j++) {
      arr_sum += arr[j];
      
      if (arr_sum == 0) {
        if (arr[j] == 0) {
          total_count++; // check this part
          continue;
        }
        total_count++;
      }
    }
    
  }
  return total_count;
}

// Tests
void tests() {
  // TEST PASSED
  vector<int> vec1 = {4, 5, 2, -1, -3, -3, 4, 6, -7};
  int res1 = solveProblem(vec1);
  int expected_res1 = 2;
  
  // TEST PASSED
  vector<int> vec2 = {1, 8, 7, 3, 11, 9};
  int res2 = solveProblem(vec2);
  int expected_res2 = 0;
  
  // TEST PASSED
  vector<int> vec3 = {8, -5, 0, -2, 3, -4};
  int res3 = solveProblem(vec3);
  int expected_res3 = 2;
  
  // TEST PASSED
  vector<int> vec4 = {};
  int res4 = solveProblem(vec4);
  int expected_res4 = 0;
  
  // TEST PASSED
  vector<int> vec5 = {0, 0, 1};
  int res5 = solveProblem(vec5);
  int expected_res5 = 3;
  
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
}

// I spent all 40 minutes on this problem (including comments and tests)