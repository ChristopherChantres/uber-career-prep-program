/*
---------- THOUGHT PROCESS ----------

I can sum an element with itself to get 0

- Can we have empty arrays?
- What is the max length of the array?

result = 0
[1, 10, 8, 3, 2, 5, 7, 2, -2, -1]
     ^
     *

if arr[i] == arr[j]:
    result++
    
We can use a Set to store the numbers that are already taken
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int zero_sum(vector<int>& arr) {
    int result = 0; // Assume the integer is lesser than 2^31
    unordered_set<int> taken_numbers; // O(1) insertion/retrieval
    
    if (arr.size() == 0) {
        return -1; // We can validate the "-1" when we call the funtion in the main()
    }
    
    if (arr.size() == 1) {
        return 0; // Since we cannot take the same number twice
    }
    
    for (int i = 0; i < arr.size(); i++) {
        // Validate if arr[i] is in taken_numbers
        // if (taken_numbers.find(arr[i]) != taken_numbers.end()) {
        //     continue;
        // }
        
        for (int j = i; j < arr.size(); j++) {
            // Validate if arr[j] is in taken_numbers
            if (taken_numbers.find(arr[j]) != taken_numbers.end()) {
                continue;
            }
            if (arr[i] + arr[j] == 0) {
                taken_numbers.insert(arr[i]);
                taken_numbers.insert(arr[j]);
                result++;
            }
        }
    }
    
    return result;
}

int main() {
    int res;
    vector<int> v1 = {1, 10, 8, 3, 2, 5, 7, 2, -2, -1}; // PASSED
    vector<int> v2 = {1, 10, 8, -2, 2, 5, 7, 2, -2, -1}; // FAILED
    vector<int> v3 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 6}; // FAILED
    vector<int> v4 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 0}; // PASSED
    vector<int> v5 = {}; // PASSED
    vector<int> v6 = {0}; // PASSED
    vector<int> v7 = {5}; // PASSED
    
    res = zero_sum(v7);
    
    if (res == -1) {
        cout << "Empty array was given";
    } else {
        cout << res << endl;
    }

    return 0;
}

/*
I spent all 40 minues to solve the problem, although I did not finished it.
I tried to solve the problem with a time complexity of O(n^2) and space complexity of O(n).
*/