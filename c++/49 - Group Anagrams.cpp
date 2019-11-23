// 49
// Group Anagrams
// https://leetcode.com/problems/group-anagrams/
// c++
// medium
// O(n*k*log k)
// O(k*n)
// string

// hashing solution
// time: O(n*k*log k) where n is the length of the vector and k is the max length of the strings
// space: O(k*n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        unordered_map<string, vector<string>> m;
        
        for (string& s : strs) {
            string hashable = s;
            sort(hashable.begin(), hashable.end());
            m[hashable].push_back(s);
        }
        for (auto& it : m) 
            results.push_back(it.second);
        
        return results;
    }
};