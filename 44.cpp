 #include <iostream>
#include <stack>
#include <string>

bool isValidParentheses(const std::string& s) {
    std::stack<char> parentheses;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            parentheses.push(c);
        } else {
            if (parentheses.empty()) {
                return false; // No matching opening parenthesis
            }
            char top = parentheses.top();
            parentheses.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false; // Mismatched parentheses
            }
        }
    }
    
    return parentheses.empty(); // All opening parentheses should be matched
}

int main() {
    std::string test1 = "()[]{}";
    std::string test2 = "([)]";
    
    std::cout << test1 << " is " << (isValidParentheses(test1) ? "valid" : "invalid") << std::endl;
    std::cout << test2 << " is " << (isValidParentheses(test2) ? "valid" : "invalid") << std::endl;
    
    return 0;
}
