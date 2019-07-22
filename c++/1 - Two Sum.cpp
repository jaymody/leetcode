// 1
// Two Sum
// https://leetcode.com/problems/two-sum/
// c++
// easy
// O(n)
// O(n)
// basic

// quick, lightweight solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        
        int i=0;
        while(i<nums.size()) {
            int v = nums[i];
            int m = target-v;
            if (map.find(m)!=map.end())
                return {map[m],i};
            map[v]=i;
            i++;
        }
        
        return {NULL,NULL};
    }
};
