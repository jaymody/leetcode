// 5
// Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/
// c++
// medium
// TBI
// TBI
// string

// slightly faster solution that returns on first found palindrome
// time: O(n^3)
// space: O(1)
class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        
        int pos = 0, length = 0;
        int len = s.size()+1;
        bool b;
        
        while (--len > 0) {
            for (int i = 0; i <= s.size()-len; i++)
                if (isPalindrome(s, i, i+len-1)) return s.substr(i, len);
        }
        
        return "";
    }
};

// initial brute force solution
// time: O(n^3)
// space: O(1)
class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        
        int pos = 0, length = 0;
        
        for (int i = 0; i < s.size() - 1; i++) {
            for (int j = i; j < s.size(); j++) {
                if (j - i > length && isPalindrome(s, i, j)) {
                    pos = i;
                    length = j - i;
                }
            }
        }
        
        return s.substr(pos, length+1);
    }
};