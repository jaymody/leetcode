// 26
// Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// c++
// easy
// O(n)
// O(1)
// array

// linear solution
// time: O(n)
// space: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 1;
        
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != nums[i-1]) nums[length++] = nums[i];
        
        return nums.size() ? length : 0;
    }
};