// 274
// H-Index
// https://leetcode.com/problems/h-index/
// c++
// medium
// O(n)
// O(n)
// hash_table

// time O(n log n) (for the sorting)
// space O(1)
// slightly slower solution using sorted vector, low memory usage
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int i = citations.size()-1;
        int total = 0;
        while(i >= 0 && citations[i--]>total) total++;

        return total;
    }
};

// time O(n)
// space O(set(n))
// fast solution using map, high memory
class Solution {
public:
    int hIndex(vector<int>& citations) {
        map<int, int> m;
        int N = citations.size();
        
        if (N == 0) 
            return 0;
        
        for (int i = 0; i < N; i++)
            m[citations[i]]+=1;
        
        int i = m.rbegin()->first;
        int n = m[i];
        while (i>n)
            n+=m[--i];
        
        return i;
    }
};
