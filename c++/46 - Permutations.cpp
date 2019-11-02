// 46
// Permutations
// https://leetcode.com/problems/permutations/
// c++
// medium
// O(n*n!)
// O(1)
// permute

// memory effecient swapping algorthim
// time: O(n*n!) (multiplied by n due to copying of vector into result which takes linear time)
// space: O(1)  excluding output space ofc
class Solution {
public:
    void visit(int begin, vector<int>& nums, vector<vector<int>>& results) {
        if (begin == nums.size())
            results.push_back(nums);
        for (int i = begin; i < nums.size(); i++) {
            swap(nums[i], nums[begin]);
            visit(begin+1, nums, results);
            swap(nums[i], nums[begin]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        visit(0, nums, results);
        return results;
    }
};