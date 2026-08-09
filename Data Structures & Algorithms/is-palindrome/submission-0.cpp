#include <string>
using namespace std;

enum CharType {
    LOWERCASE,
    UPPERCASE,
    DIGIT,
    OTHER
};

CharType checkType(char c) {
    if (c >= 'a' && c <= 'z') return LOWERCASE;
    if (c >= 'A' && c <= 'Z') return UPPERCASE;
    if (c >= '0' && c <= '9') return DIGIT;
    return OTHER;
}

bool isAlphaNumeric(char c) {
    CharType t = checkType(c);
    return (t == LOWERCASE || t == UPPERCASE || t == DIGIT);
}

char toLowerCustom(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');  // 32
    return c;
}

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

           
            while (left < right && !isAlphaNumeric(s[left]))
                left++;

            
            while (left < right && !isAlphaNumeric(s[right]))
                right--;

            
            if (toLowerCustom(s[left]) != toLowerCustom(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }
};