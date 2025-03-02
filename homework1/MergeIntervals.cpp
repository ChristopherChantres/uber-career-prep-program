/*
TECHNIQUE USED:
- Sorting & Searching Technique
  - Sort the array, then solve

TIME COMPLEXITY:
- O(n*log(n))
  - n: length of the array

SPACE COMPLEXITY:
- O(n)
  - n: length of the res array

------------------------------
QUESTIONS/COMMENTS:

- Can we have an empty array of intervals?
Let's assume we don't care about the output array order
  - In fact, the algorithm will output the result ordered
Let's assume that we have at least one element in the array of intervals


------------------------------
VISUALS:

[(5, 8), (6, 10), (2, 4), (3, 6)]

- Reorder the array based on the first interval number O(n*log(n))

min = 20
max = 21
  [(2, 4), (3, 6), (5, 8), (6, 10), (12, 15), (13, 14), (20, 21)]
                                                            ^


------------------------------
STEPS TO TAKE:

min = 20
max = 21
res = [[2, 10], [12, 15], [20, 21]]
append_last_interval = false;

- Sort arr based on the first element of every interval (increasing order)
- Loop over arr
  - append_last_interval = false
  - if min <= arr[i].first <= max:
    - max = MAX(max, arr[i].second)
  - else:
    - res.append([min, max])
    - min = arr[i].first
    - max = arr[i].second
    - append_last_interval = true
    
- if append_last_interval == true:
  - res.append([min, max]) 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> solveProblem (vector<pair<int, int>> arr);
void tests();

// Main
int main() {
  tests();
  return 0;
}

// Main Algorithm
vector<pair<int, int>> solveProblem (vector<pair<int, int>> arr) {
  int arr_len = arr.size();
  if (arr_len == 1) return arr;
  
  // Sort the array based on the first element of every interval (increasing order)
  sort(arr.begin(), arr.end(), [](const pair<int,int>& a, const pair<int,int>& b){
    return a.first < b.first;
  });
  
  int curr_min = arr[0].first;
  int curr_max = arr[0].second;
  bool append_last_interval = false;
  vector<pair<int, int>> res;
  
  for (int i = 0; i < arr_len; i++) {
    append_last_interval = false;
    if (curr_min <= arr[i].first && arr[i].first <= curr_max) {
      curr_max = max(curr_max, arr[i].second);
      if (i == arr_len - 1) {
        append_last_interval = true;
      }
    } else {
      res.emplace_back(curr_min, curr_max);
      curr_min = arr[i].first;
      curr_max = arr[i].second;
      append_last_interval = true;
    }
  }
  
  if (append_last_interval) {
    res.emplace_back(curr_min, curr_max);
  }
  
  return res;
}

// Tests
void tests() {
  // TEST PASSED
  vector<pair<int, int>> vec1 = {{2, 3}, {4, 8}, {1, 2}, {5, 7}, {9, 12}};
  vector<pair<int, int>> expected_res1 = {{1, 3}, {4, 8}, {9, 12}};
  vector<pair<int, int>> res1 = solveProblem(vec1);

  // TEST PASSED
  vector<pair<int, int>> vec2 = {{5, 8}, {6, 10}, {2, 4}, {3, 6}};
  vector<pair<int, int>> expected_res2 = {{2, 10}};
  vector<pair<int, int>> res2 = solveProblem(vec2);
  
  // TEST PASSED
  vector<pair<int, int>> vec3 = {{10, 12}, {5, 6}, {7, 9}, {1, 3}};
  vector<pair<int, int>> expected_res3 = {{1, 3}, {5, 6}, {7, 9}, {10, 12}};
  vector<pair<int, int>> res3 = solveProblem(vec3);
  
  // TEST PASSED
  vector<pair<int, int>> vec4 = {{1, 1000}};
  vector<pair<int, int>> expected_res4 = {{1, 1000}};
  vector<pair<int, int>> res4 = solveProblem(vec4);
  
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

// I spent all 40 minutes on this problem