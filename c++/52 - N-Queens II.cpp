// 52
// N-Queens II
// https://leetcode.com/problems/n-queens-ii/
// c++
// hard
// O(n^n)
// O(n)
// basic

// Quick, memory safe solution
// time: O(n^n)
// space: O(n)
class Solution {
public:
    bool valid(int& r, int& c, vector<pair<int,int>>& vec) {
        for (auto p : vec) {
            if (p.second == c || abs(p.second-c) == abs(p.first-r))
                return false;
        }
        return true;
    }
    
    void visit(int& n, int r, vector<pair<int,int>> vec, int& count) {        
        for (int c = 0; c < n; c++) {
            if (!valid(r, c, vec))
                continue;
            if (r == n-1)
                count += 1;
            else {
                pair p{r, c};
                vec.push_back(p);
                visit(n, r+1, vec, count);
                vec.pop_back();
            }
        }
    }
    
    int totalNQueens(int n) {
        if (!n)
            return 1;
        
        int count = 0;
        vector<pair<int,int>> vec;
        visit(n, 0, vec, count);
        return count;
    }
};