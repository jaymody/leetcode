// 287
// Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/
// c++
// array
// 
// 
// two_pointers binary_search

// Problem states space complexity must be O(1)
// and time complexity must be < O(n^2)

// Initial solution using sort and linear search, O(n log n), O(1)
// The solution can actually be produced using the Floyd's Tortoise and Hare
// alogirithim (O(n) time, O(1) space)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                return nums[i];
            }
        }
        
        return -1;
    }
};
