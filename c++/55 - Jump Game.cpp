// 55
// Jump Game
// https://leetcode.com/problems/jump-game/
// c++
// medium
// O(n)
// O(1)
// 

// converted recursive solution (found below) to iterative solution
// to reduce space complexity caused by the function call stack
// time: O(n)
// space: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int anchor = nums.size()-1;
        int i = anchor;
        
        while (i >= 1) {
            i--;
            if (nums[i] >= anchor-i) {
                anchor = i;
                continue;
            } 
        }

        return nums[0] >= anchor-i;
    }
};

// initial solution using recursion
// time: O(n)
// space: O(n) (n space is used up by the recursive stack)
class Solution {
public:
    bool jump(vector<int>& nums, int index) {
        // if at the beginning of the vector, their is a valid path
        if (not index)
            return true;
        
        // recurse through all paths that are able to reach the current one
        int i = index;
        while (i-- >= 1) {
            if (nums[i] >= index-i)
                return jump(nums, i);
        }

        // if true and recursion is not triggered, there is no path
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        return jump(nums, nums.size()-1);
    }
}; 