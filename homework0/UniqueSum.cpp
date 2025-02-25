/*
---------- THOUGHT PROCESS ----------

- Check for empty arrays
- Let's assume we don't have any type of overflow with the numbers and the array

Iterate over the array and append it to a set
Iterate over the set sum each value
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int unique_sum(vector<int>& arr) {
    int total = 0;
    unordered_set<int> bucket;
    
    // Validating for unique arrays: --> saving space & time
    if (arr.size() == 1) {
        return arr[0];
    }
    
    // Insert all elements from array to bucket (set)
    for (int i = 0; i < arr.size(); i++) {
        bucket.insert(arr[i]);
    }
    
    // Iterate over bucket (set) and adding each element to "total"
    for (const int& element : bucket) {
        total += element;
    }
    
    return total;
}


int main() {
    vector<int> vec1 = {1, 10, 8, 3, 2, 5, 7, 2, -2, -1}; // PASSED
    vector<int> vec2 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 6}; // PASSED
    vector<int> vec3 = {}; // PASSED
    vector<int> vec4 = {8}; // PASSED
    vector<int> vec5 = {-19}; // PASSED
    
    // The variable vec1 should be updated with the actual vector name
    if (vec1.size() == 0) { // <-- Here
        cout << "Empty array []"; // Alert the user for empty array
    } else {
        int res = unique_sum(vec1); // <-- Also here
        cout << res;
    }
    
    return 0;
}

/*
I spent 23:40 minutes to solve this exercise.
I tried to solve the problem with a time complexity of O(n) and space complexity of O(n).
*/