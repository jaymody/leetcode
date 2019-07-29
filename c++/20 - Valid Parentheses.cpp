// 20
// Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
// c++
// easy
// O(n)
// O(n)
// string stack

// very fast solution using switch and stack
// O(n), O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        
        for (char& c : s) {
            switch (c) {
                case '[': stck.push(']'); break;
                case '{': stck.push('}'); break;
                case '(': stck.push(')'); break;
                default:
                    if (stck.empty() || c != stck.top()) return false;
                    stck.pop();
            }
        }
        
        return stck.empty();
    }
};
