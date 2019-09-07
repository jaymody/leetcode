// 63
// Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/
// c++
// medium
// O(m*n)
// O(1)
// array


// iterative solution that works but
// causes integer overflow on certain test sets
// in leetcode in c++ for some reason
// (but not for the equivalent java solution?!)
// time: O(m*n)
// space: O(1)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int nRows = obstacleGrid.size();
        int nCols = obstacleGrid[0].size();
        
        for (int r = nRows-1; r >= 0; r--) {
            for (int c = nCols-1; c >= 0; c--) {
                if (obstacleGrid[r][c] == 1) {
                    obstacleGrid[r][c] = 0;
                }
                else {
                    bool triggered = false;
                    
                    if (r != nRows-1) {
                        obstacleGrid[r][c] += obstacleGrid[r+1][c];
                        triggered = true;
                    }
                    if (c != nCols-1) {
                        obstacleGrid[r][c] += obstacleGrid[r][c+1];
                        triggered = true;
                    }
                    if (!triggered)
                        obstacleGrid[r][c] = 1;
                }
            }
        }
        
        return obstacleGrid[0][0];
    }
};

