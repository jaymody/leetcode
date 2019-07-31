// 35
// Search Insert Position
// https://leetcode.com/problems/search-insert-position/
// c++
// easy
// O(log n)
// O(1)
// array binary_search

// Simple O(log n), O(1) binary search solution
// (slightly faster implementation found below this one)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        int mid;
        
        // binary search
        while (left <= right) {
            mid = (left + right) / 2;
            
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] <  target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return nums[mid] > target ? mid : ++mid;
    }
};

// Slightly faster solution (with one more int variable being used)
// since the check if the closest number to target is greater than or less than
// it doesn't need to be checked again
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        int mid;
        int tmp;
        
        // binary search
        while (left <= right) {
            mid = (left + right) / 2;
            
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] <  target) {
                left = mid+1;
                tmp = 1;
            }
            else {
                right = mid-1;
                tmp = 0;
            }
        }
        
        return mid + tmp;
    }
};
