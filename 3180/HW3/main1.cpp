#include <iostream>
#include <string>

bool isPalinHelper(const std::string& s, int begin, int end) {
    // Base case: if the string is empty or has only one character, it's a palindrome
    if (begin >= end) {//0 >= 6 no
        return true;
    }
    
    // Check if the characters at the current positions are equal
    if (s[begin] != s[end]) { 
        return false;
    }
    
    // Recursively check the substring without the first and last characters
    return isPalinHelper(s, begin + 1, end - 1);
}

bool isPalin(const std::string& s) {
    return isPalinHelper(s, 0, s.size() - 1);
}
//string is put here first, it acts to initialize values 
//.size() gives normal counting not starting at 0

//racecar = 7 begin is 0 end is 6 
//this dunction will call recursively until the middle of the word when the begin equals the end 


int main() {
    std::string s1{"racecar"}; // Palindrome
    if (isPalin(s1)) std::cout << s1 << " is a palindrome" << std::endl;
    else std::cout << s1 << " is not a palindrome" << std::endl;

    std::string s2{"racecars"}; // Not a palindrome
    if (isPalin(s2)) std::cout << s2 << " is a palindrome" << std::endl;
    else std::cout << s2 << " is not a palindrome" << std::endl;

    std::string s3{"gohangasalamiimalasagnahog"};
    if (isPalin(s3)) std::cout << s3 << " is a palindrome" << std::endl;
    else std::cout << s3 << " is not a palindrome" << std::endl;

    return 0;
}
