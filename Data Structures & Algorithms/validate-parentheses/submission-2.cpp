#include <stack>
#include <string>

class Solution {
public:
    int value(char c) {
        switch(c) {
            case '(': return 1;
            case ')': return -1;
            case '{': return 2;
            case '}': return -2;
            case '[': return 3;
            case ']': return -3;
            default:  return 0;
        }
    }

    bool isValid(string s) {
        std::stack<int> st;

        for (char c : s) {
            int val = value(c);

            if (val > 0) {
                st.push(val);
            } 
            else {
                if (st.empty() || st.top() + val != 0) {
                    return false;
                }
                st.pop(); 
            }
        }

        return st.empty();
    }
};
