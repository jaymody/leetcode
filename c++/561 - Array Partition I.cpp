// 561
// Array Partition I
// https://leetcode.com/problems/array-partition-i/
// c++
// easy
// O(n log n)
// O(1)
// array

// simple solution using sorted array O(n log n)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i+=2)
            sum += nums[i];
        return sum;
    }
};