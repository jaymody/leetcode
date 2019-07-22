// 125
// Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/
// c++
// easy
// O(n)
// O(1)
// string

// time O(n)
// space O(1)
// first solution, not elegant but its fast and decent on memory
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        
        while (left < right) {
            char lc = s.at(left);
            if (!isalnum(lc)) {
                left++;
                continue;
            }
            char rc = s.at(right);
            if (!isalnum(rc)) {
                right--;
                continue;
            }
            
            if (tolower(rc) != tolower(lc))
                return false;
            
            left++;
            right--;
        }
        
        return true;
    }
};
