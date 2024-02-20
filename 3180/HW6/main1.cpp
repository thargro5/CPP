#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, int> charCount;

    // Count the frequency of characters in string s
    for (char c : s) {
        charCount[c]++;
    }

    // Decrement the frequency for characters in string t
    for (char c : t) {
        if (charCount.find(c) == charCount.end() || charCount[c] == 0) {
            return false; // Character not found or frequency is already 0
        }
        charCount[c]--;
    }

    // If all character frequencies are 0, then the strings are anagrams
    for (const auto& pair : charCount) {
        if (pair.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";
    if (isAnagram(s, t)) cout << "True" << endl;
    else cout << "False" << endl;

    s = "rat";
    t = "car";
    if (isAnagram(s, t)) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}
