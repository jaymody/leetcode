// 16
// 3Sum Closest
// https://leetcode.com/problems/3sum-closest/
// c++
// medium
// TBI
// TBI
// array

// brute force solution
// time: O(n^3)
// space: O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = INT_MAX;
        int result = -1;
        
        for (int i = 0; i < nums.size()-2; i++) {
            for (int j = i+1; j < nums.size()-1; j++) {
                for (int k = j+1; k < nums.size(); k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(sum-target) < closest) {
                        closest = abs(sum - target);
                        result = sum;
                    }
                }
            }
        }
        return result;
    }
};














