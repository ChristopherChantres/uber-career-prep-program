/*
---------- THOUGHT PROCESS ----------

Return a string as the result

Use a map to store each character:
 --> char: int
 
Validate if we have a char inside of the map:
    if we do:
        move on to the next char
    else:
        insert element to the map
        append to the return string
    
"abracadabra"
        ^
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string first_occurence(string& sentence) {
    string result_string = "";
    unordered_map<char, int> bucket;
    
    // Base cases
    if (sentence.length() == 0) {
        return "";
    }
    
    if (sentence.length() == 1) {
        return sentence;
    }
    
    // Main Algorithm
    for (const char& element : sentence) {
        // Lookup into the bucket
        auto it = bucket.find(element); // C++ iterator
        
        if (it != bucket.end()) { // if TRUE: it means we have that key in the bucket
            continue;
        } else {
            bucket.insert({element, 1});
            result_string += element;
        }
    }
    
    return result_string;
}

int main() {
    string test1 = "abracadabra"; // PASSED
    string test2 = "Uber Career Prep"; // PASSED
    string test3 = "zzyzx"; // PASSED
    string test4 = ""; // PASSED
    string test5 = "4"; // PASSED
    string test6 = "r"; // PASSED
    
    string res = first_occurence(test6);
    cout << res << endl;
    
    return 0;
}

/*
I spent 30:20 minutes to solve this excerise.
I tried to solve the problem with a time complexity of O(n) and space complexity of O(n).
*/