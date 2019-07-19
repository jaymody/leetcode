// 15
// 3Sum
// https://leetcode.com/problems/3sum/
// c++
// medium
// O(n^2)
// O(1)
// array two_pointers

class Solution {
public:  
        vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the input vector
        sort(nums.begin(), nums.end());
        
        int size = nums.size();
        
        // init output vector
        vector<vector<int>> ans;
        vector<int> temp;
        
        for (int i = 0; i < size-1 && nums[i] <= 0; i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i];
            
            int j = i + 1;
            int k = size - 1;
            while (j<k) {
                int sum = nums[j]+nums[k];
                if (sum < target)
                    j++;
                else if (sum > target)
                    k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int cur_j = nums[j];
                    int cur_k = nums[k];
                    j++;
                    k--;
                    while (j<k && cur_j == nums[j])
                        j++;
                    while (j<k && cur_k == nums[k])
                        k--;
                }
            }
        }
        
        return ans;
    }
};
