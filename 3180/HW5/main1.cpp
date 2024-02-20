#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool areParanthesisBalanced(string temp) {
    stack<char> st;
    
    for (char c : temp) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) {
                return false; // No matching opening parenthesis found
            }
            
            char top = st.top();
            st.pop();
            
            // Check if the current closing parenthesis matches the top of the stack
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    
    // If there are any remaining opening parentheses in the stack, the string is unbalanced
    return st.empty();
}

int main() {
    vector<string> parans = {"{()}[]", "[[", "))", "{[()]}", "({[])}"};
    for (auto temp : parans) {
        if (areParanthesisBalanced(temp))
            cout << "Balanced" << endl;
        else
            cout << "Not Balanced" << endl;
    }
    return 0;
}
