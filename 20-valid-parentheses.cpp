#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        /*
         * Add any opening brackets to a stack. When we encounter a closing
         * bracket, see if its matching opening bracket is on top. If so, pop it
         * off. If the top has a mismatch or if the stack isn't empty, the
         * string is invalid.
         */

        vector<char> stack;
        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') stack.push_back(c);
            else if (c == ')') {
                if (stack.empty() || stack.back() != '(') return false;
                stack.pop_back();
            } else if (c == '}') {
                if (stack.empty() || stack.back() != '{') return false;
                stack.pop_back();
            } else if (c == ']') {
                if (stack.empty() || stack.back() != '[') return false;
                stack.pop_back();
            } else {
                // We won't get here.
                return false;
            }
        }
        if (!stack.empty()) return false;
        return true;
    }
};