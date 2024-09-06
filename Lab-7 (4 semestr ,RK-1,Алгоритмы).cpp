#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath> 
using namespace std;


// 3042. Count Prefix and Suffix Pairs I

class Solution_1 {
public:
    // Function to check if one string is both prefix and suffix of another
    bool check(string& a, string& b) {
        int n = a.length(), m = b.length();
        if (m < n)   return false;
        string x = b.substr(0, n);
        string y = b.substr(m - n, n);
        return a == x && a == y;
    }

    // Function to count pairs of words where one is a prefix and suffix of another
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0, n = words.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (check(words[i], words[j]))   count++;
        return count;
    }
};


// 1461. Check If a String Contains All Binary Codes of Size K

class Solution {
public:
    // Function to check if all possible binary codes of length k are present in the string s
    bool hasAllCodes(string s, int k) {
        set<string> st;
        string str = "";
        for (int i = 0; i < s.size(); i++) {
            str += s[i];
            if (i >= k) str.erase(0, 1);
            if (str.size() == k) st.insert(str);
        }
        return st.size() == pow(2, k); // Return true if all codes are present, false otherwise
    }
};


// 705. Design HashSet

class MyHashSet {
public:
    vector<int> hash_table;

    // Constructor to initialize hash table
    MyHashSet() {
        hash_table.resize(1e6 + 5, 0);
    }

    // Function to add a key to the hash set
    void add(int key) {
        hash_table[key] = 1;
    }

    // Function to remove a key from the hash set
    void remove(int key) {
        hash_table[key] = 0;
    }

    // Function to check if the hash set contains a key
    bool contains(int key) {
        return hash_table[key] == 1;
    }
};


// 187. Repeated DNA Sequences

class Solution_2 {
public:
    // Function to find repeated DNA sequences in the given string s
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> arr;
        if (s.size() < 10) return {}; // If string size is less than 10, return empty vector

        // Count occurrences of 10-character substrings
        for (int i = 0; i < s.size() - 9; ++i) {
            string str = s.substr(i, 10);
            arr[str]++;
        }

        // Store repeated sequences in a vector
        vector<string> ans;
        for (auto x : arr) {
            if (x.second > 1)
                ans.push_back(x.first);
        }

        return ans;
    }
};

int main() {
    return 0;
}
