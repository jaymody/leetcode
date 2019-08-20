// 45
// Jump Game II
// https://leetcode.com/problems/jump-game-ii/
// c++
// hard
// O(n)
// O(1)
// array

// linear solution
// time: O(n)
// space: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        
        int count = 1;
        
        int r = 1;
        int limit = nums[0];
        int max = -1;
        while (limit < nums.size()-1) {
            while (r <= limit) {
                int sum = nums[r]+r;
                if (sum >= max)
                    max = sum;
                r++;
            }
            
            r = limit+1;
            limit = max;
            count++;
        }
        
        return count;
    }
};

// initial solution (slow)
// time: O(n^2)
// space: O(n) (accounting for maximum possible function call stack)
class Solution {
public:
    void jmp(vector<int>& nums, int index, int& count) {
        for (int i = 0; i < index; i++) {
            if (nums[i] >= index-i) {
                count++;
                jmp(nums, i, count);
                return;
            }
        }
    }
    int jump(vector<int>& nums) {
        int count = 0;
        jmp(nums, nums.size()-1, count);
        return count;
    }
};