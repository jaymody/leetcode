// 136
// Single Number
// https://leetcode.com/problems/single-number/
// c++
// easy
// O(n)
// O(1)
// map

// simple bitwise XOR solution
// time: O(n)
// space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int& n : nums)
            ans ^= n;
        return ans;
    }
};

// hash map solution
// time: O(n)
// space: O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, bool> map;
        
        for (int& n : nums) {
            if (map.find(n) != map.end())
                map[n] = false;
            else
                map[n] = true;
        }
        
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second)
                return it->first;
        }
        
        return 0;
    }
};