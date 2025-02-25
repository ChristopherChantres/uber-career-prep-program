/*
TECHNIQUE USED:
- Fixed-size sliding window

TIME COMPLEXITY:
- O(n*m)
  - n: length of the array
  - m: size of "k"

SPACE COMPLEXITY:
- O(1)


------------------------------------
QUESTIONS:

- Can I have a k = 0 or k = 1?
- Can I have an empty array?
- What is the smallest number and greatest number (do they fit in an integer)?

------------------------------------
VISUALS:

I will assume that the subarray must be contiguous --> a,b,c
We will have a fixed window size

k = 2
[4, 5, -3, 2, 6, 1]
    ^
        ^
- k > 0

------------------------------------
STEPS TO TAKE:

max_mean = -infinity
- Define the start and the end of our fixed window
- Loop over the array:
  - Get the sum of the elements inside of the interval interval_sum = [start, end]
  - Get the mean of the interval_mean = interval_sum
    - if (interval_mean > max_mean) ==> max_mean = interval_mean
    - else ==> continue
    
In order to get the sum of the elements from the interval, we need to iterate ==> (i = 0; i < k; i++)
  - This means that we will have a time complexity of O(n*m)
    - n: length of the array
    - m: size of "k"
*/

#include <iostream>
#include <vector>
using namespace std;
void tests();
double solveProblem(vector<int> arr, int k);


int main() {
  tests();
  return 0;
}

// Tests
void tests() {
  vector<int> vec1 = {4, 5, -3, 2, 6, 1};
  int k1 = 2;
  double expected_res1 = 4.5;
  
  vector<int> vec2 = {4, 5, -3, 2, 6, 1};
  int k2 = 3;
  double expected_res2 = 3;
  
  vector<int> vec3 = {1, 1, 1, 1, -1, -1, 2, -1, -1};
  int k3 = 3;
  double expected_res3 = 1;
  
  vector<int> vec4 = {};
  int k4 = 10;
  double expected_res4 = -1000; // Let's set 1,000 as a returning value whenever we have an empty array
  
  double res1 = solveProblem(vec1, k1);
  double res2 = solveProblem(vec2, k2);
  double res3 = solveProblem(vec3, k3);
  double res4 = solveProblem(vec4, k4);
  
  if (res1 == expected_res1) {
    cout << "TEST (1) PASSED!" << endl;
  } else {
    cout << "TEST (1) DID NOT PASSED!" << endl;
  }
  
  if (res2 == expected_res2) {
    cout << "TEST (2) PASSED!" << endl;
  } else {
    cout << "TEST (2) DID NOT PASSED!" << endl;
  }
  
  if (res3 == expected_res3) {
    cout << "TEST (3) PASSED!" << endl;
  } else {
    cout << "TEST (3) DID NOT PASSED!" << endl;
  }
  
  if (res4 == expected_res4) {
    cout << "TEST (4) PASSED!" << endl;
  } else {
    cout << "TEST (4) DID NOT PASSED!" << endl;
  }
}

// Main Algorithm
double solveProblem(vector<int> arr, int k) {
  int arr_size = arr.size();
  if (arr_size == 0) return -1000; // Depends on the interviewer
  
  int end = k - 1;
  double max_mean = -100; // -infinity
  
  // Loop n*m
  for (int start = 0; end < arr_size; start++) {
    double interval_sum = 0;
    double interval_mean = 0;
    
    for (int j = start; j <= end; j++) {
      interval_sum += arr[j];
    }
    
    interval_mean = interval_sum / k;
    if (interval_mean > max_mean) {
      max_mean = interval_mean;
    }
    end++;
  }
  return max_mean;
}

// I spent all 40 minutes on this problem (including comments and tests)