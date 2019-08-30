// 51
// N-Queens
// https://leetcode.com/problems/n-queens/
// c++
// hard
// O(n^n)
// O(n)
// basic

// time: O(n^n)
// space: O(n)
class Solution {
public:
    bool valid(int& r, int& c, vector<int>& vec) {  
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == c || abs(vec[i]-c) == abs(i-r))
                return false;
        }
        return true;
    }
    
    void visit(int& n, int r, vector<int> vec, vector<vector<string>>& results) {        
        for (int c = 0; c < n; c++) {
            if (!valid(r, c, vec))
                continue;
            if (r == n-1) {
                vector<string> result;
                for (auto p : vec) {
                    string s(n, '.');
                    s.replace(p, 1, "Q");
                    result.push_back(s);
                }
                string s(n, '.');
                s.replace(c, 1, "Q");
                result.push_back(s);
                results.push_back(result);
            }    
            else {
                vec.push_back(c);
                visit(n, r+1, vec, results);
                vec.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<int> vec;
        visit(n, 0, vec, results);
        return results;
    }
};