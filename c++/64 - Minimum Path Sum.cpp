// 64
// Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/
// c++
// medium
// O(m*n)
// O(n)
// dp

// dynamic programming iterative solution (NO MODIFICATION TO INPUT LIST)
// time: O(m*n)
// space: O(n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur;
        cur.push_back(grid[0][0]);
        
        for (int i = 1; i < n; i++) 
            cur.push_back(cur.back() + grid[0][i]);
        
        for (int i = 1; i < m; i++) {
            cur[0] += grid[i][0];
            for (int j = 1; j < n; j++)
                cur[j] = grid[i][j] + min(cur[j-1], cur[j]);
        }
        
        return cur[n-1];
    }
};

// dynamic programming iterative solution
// time: O(m*n)
// space: O(1) 
// NOTE: solution modifies the input space, otherwise would have a space complexity of O(m*n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int j = 1; j < n; j++)
            grid[0][j] += grid[0][j-1];
        for (int i = 1; i < m; i++) 
            grid[i][0] += grid[i-1][0];
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
        
        return grid[m-1][n-1];
    }
};

// slightly less elegant solution than above
// time: O(m*n)
// space: O(1) 
// NOTE: solution modifies the input space, otherwise would have a space complexity of O(m*n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i==0 && j!=0)
                    grid[i][j] += grid[i][j-1];
                else if (j==0 && i!=0)
                    grid[i][j] += grid[i-1][j];
                else if (j!=0 && i!=0)
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[m-1][n-1];
    }
};