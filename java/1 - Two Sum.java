// 1
// Two Sum
// https://leetcode.com/problems/two-sum/
// java
// easy
// O(n^2)
// O(1)
// basic

// O(n^2) time BRUTE FORCE METHOD VERY SLOW (see c++ or python implementation for O(n))
class Solution {
    public int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length-1; i++) {
            for (int j = i+1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[] {i, j};
                }
            }
        }
        
        return null;
    }
}
