// 53
// Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/
// c++
// easy
// O(n)
// O(1)
// array

// dynamic program solution using a single tracking variable
// O(n)
// O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = nums[0];
        int max = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            prev = nums[i] + (prev > 0 ? prev : 0);
            if (prev > max) max = prev;
        }
        
        return max;
    }
};

// initial trivial brute force solution
// time: O(n^2)
// space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum > max) max = sum;
            }
        }
        
        return max;
    }
};