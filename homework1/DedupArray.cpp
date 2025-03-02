/*
TECHNIQUE USED:
- Looping over the array once
  - Arithmetic operations

TIME COMPLEXITY:
- O(n)

SPACE COMPLEXITY:
- O(1)

-------------------------
QUESTIONS:

- Can I get an empty array?
- Does each number from the array fit into an integer?

-------------------------
VISUALS:

number_before = 12
i = 5
[1, 3, 4, 10, 12]
               ^

-------------------------
STEPS TO TAKE:

Time: O(n)
Space: O(1)

- Loop over the array:
  - if number_before == arr[i]:
    arr.erase(arr.begin() + i)
    i--;
    -
  else:
    - number_before = arr[i]
  

*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> solveProblem(vector<int> arr);
void tests();

// Main
int main() {
  tests();
  return 0;
}

// Main Algorithm
vector<int> solveProblem(vector<int> arr) {
  int arr_size = arr.size();
  if (arr_size == 0 || arr_size == 1) return arr;
  
  int number_before = -1;
  for (int i = 0; i < arr.size(); i++) {
    if (number_before == arr[i]) {
      arr.erase(arr.begin() + i);
      i--;
    } else {
      number_before = arr[i];
    }
  }
  
  return arr;
}

// Tests
void tests() {
  // TEST PASSED
  vector<int> vec1 = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  vector<int> res1 = solveProblem(vec1);
  vector<int> expected_res1 = {1, 2, 3, 4};
  
  // TEST PASSED
  vector<int> vec2 = {0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15};
  vector<int> res2 = solveProblem(vec2);
  vector<int> expected_res2 = {0, 1, 4, 5, 8, 9, 10, 11, 15};
  
  // TEST PASSED
  vector<int> vec3 = {1, 3, 4, 8, 10, 12};
  vector<int> res3 = solveProblem(vec3);
  vector<int> expected_res3 = {1, 3, 4, 8, 10, 12};
  
  // TEST PASSED
  vector<int> vec4 = {1};
  vector<int> res4 = solveProblem(vec4);
  vector<int> expected_res4 = {1};
  
  // TEST PASSED
  vector<int> vec5 = {};
  vector<int> res5 = solveProblem(vec5);
  vector<int> expected_res5 = {};
  
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

// I spent 37:47 minutes on this problem.