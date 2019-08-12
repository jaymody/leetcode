// 66
// Plus One
// https://leetcode.com/problems/plus-one/
// c++
// easy
// O(n)
// O(1)
// basic

// O(n), O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        
        while(digits[i] >= 9) {   
            digits[i] = 0;
            if (!i) {
                digits.insert(digits.begin(), 0);
                break;
            }
            i--;
        }
        
        digits[i] += 1%10;
        
        return digits;
    }
};