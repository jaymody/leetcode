// 997
// Find the Town Judge
// https://leetcode.com/problems/find-the-town-judge/
// c++
// easy
// O(T)
// O(N)
// array

// linear space-time initial solution using hash map
// time: O(T) where is the number of entries in the trust array
// space: O(N) where N is the number of people
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if (!trust.size() && N==1) return 1;
        
        int val = -1;
        unordered_map<int,int> m;
        
        for (auto t : trust) {
            m[t[0]] = -1;
            
            if (m.find(t[1]) == m.end()) m[t[1]] = 1;
            else m[t[1]]++;
            
            if (m[t[1]] == N-1) {
                if (val != -1) return -1;
                val =  t[1];
            }
        }
        
        return m[val] == N-1 ? val : -1;
    }
};