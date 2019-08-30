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
struct coord {
    int r;
    int c;
};

class Solution {
public:
    bool valid(int& r, int& c, vector<coord>& vec) {
        for (coord crd : vec) {
            if (crd.c == c)
                return false;
            else if (abs(crd.c-c) == abs(crd.r-r))
                return false;
        }
        return true;
    }
    
    void visit(int& n, int r, vector<coord>& vec, int& count) {        
        for (int c = 0; c < n; c++) {
            if (!valid(r, c, vec))
                continue;
            if (r == n-1)
                count += 1;
            else {
                coord crd{r, c};
                vec.push_back(crd);
                visit(n, r+1, vec, count);
                vec.pop_back();
            }
        }
    }
    
    int totalNQueens(int n) {
        if (!n)
            return 1;
        
        int count = 0;
        vector<coord> vec;
        visit(n, 0, vec, count);
        return count;
    }
};