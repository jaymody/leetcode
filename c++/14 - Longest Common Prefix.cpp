// 14
// Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
// c++
// easy
// O(s*n)
// O(1)
// string

// Time complexity O(n * s)
// where n is the number of elements in the input vector
// and where s is the length of the stortest string in the vector
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1)
            return strs[0];
        
        int i = 0;
        try {         
            while (true) {
                for (int s = 1; s < strs.size(); s++) {
                    if (strs[0].at(i) != strs[s].at(i)) 
                            return strs[0].substr(0,i);
                }
                i++;
            }
        }
        catch (out_of_range e) {
            return strs[0].substr(0,i);
        }
        
    }
};
