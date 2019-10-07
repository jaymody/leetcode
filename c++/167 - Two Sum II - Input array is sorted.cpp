// 167
// Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// c++
// easy
// O(n)
// O(1)
// basic

// two pointer solution
// time: O(n)
// space: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        int sum;
        
        for (;;) {
            sum = numbers[l] + numbers[r];
            if (sum > target) r--;
            else if (sum < target) l++;
            else break;
        }
        
        return {l+1,r+1};
    }
};