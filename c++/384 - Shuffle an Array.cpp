// 384
// Shuffle an Array
// https://leetcode.com/problems/shuffle-an-array/submissions/
// c++
// medium
// O(n)
// O(n)
// array random

// Fisher Yates solution (my first initial solution can be found below)
// Time O(n)
// Space O(n) 
// (typically space complexity does not include the output space but for this problem it seems fair)
class Solution {
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled(nums);
         for (int i = shuffled.size()-1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(shuffled[i], shuffled[j]);
         }
        return shuffled;
    }
};

// First initial solution O(n), O(1)
class Solution {
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> pool(nums);
        vector<int> shuffled;
        
        for (int i = 0; i < nums.size(); i++) {
            int r = rand() % pool.size();
            shuffled.push_back(pool[r]);
            pool.erase(pool.begin()+r);
        }
        
        return shuffled;
    }
};

// Cheating solution using c++ random_shuffle function
class Solution {
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled(nums);
        random_shuffle(shuffled.begin(), shuffled.end());
        return shuffled;
    }
};
