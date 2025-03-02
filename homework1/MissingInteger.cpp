/*
TECHNIQUE USED:
- Brute force

TIME COMPLEXITY:
- O(n)
  - n: length of the array

SPACE COMPLEXITY:
- O(1)


----------------------------
QUESTIONS/COMMENTS:

 - Can we have negative integers?
 - Can we get an empty array? --> Already implemented
 Let's assume that we get numbers [1, ...] where "..."" fits an integer
 

----------------------------
VISUALS:

n = 7
counter = 5
[1, 2, 3, 4, 6, 7]
             ^ 
output = 5


----------------------------
STEPS TO SOLVE:

For an O(n) algorithm
- We can start a counter and validate as we iterate over the array.
- Loop:
  - if (counter == arr[i]):
    - We have that number
  - else:
    - The number does not exists
*/

#include <iostream>
#include <vector>
using namespace std;
int solveProblem(vector<int> arr);
void tests();

int main() {
  tests();
  return 0;
}

int solveProblem(vector<int> arr) {
  int arr_size = arr.size();
  if (arr_size == 0) return arr_size + 1;
  
  int counter = 1;
  for (int i = 0; i < arr_size; i++) {
    if (counter != arr[i]) {
      break;
    }
    counter++;
  }
  
  return counter;
}

void tests() {
  vector<int> vec1 = {1, 2, 3, 4, 6, 7};
  int res1 = solveProblem(vec1);
  int expected_res1 = 5;
  
  vector<int> vec2 = {1};
  int res2 = solveProblem(vec2);
  int expected_res2 = 2;
  
  vector<int> vec3 = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};
  int res3 = solveProblem(vec3);
  int expected_res3 = 9;
  
  vector<int> vec4 = {};
  int res4 = solveProblem(vec4);
  int expected_res4 = 1;
  
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

// I spent 30 minutes on this problem (including comments and tests)