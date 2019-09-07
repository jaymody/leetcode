// 63
// Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/
// java
// medium
// O(m*n)
// O(1) 
// array

// simple iterative solutuion
// time: O(m*n)
// space: O(1)
public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {    
        int rows = obstacleGrid.length;
        int cols = obstacleGrid[0].length;
        
        for(int r = rows-1; r >= 0; r--) {
            for(int c = cols-1; c >= 0; c--) {
                if (obstacleGrid[r][c] == 1)
                    obstacleGrid[r][c] = 0;
                else {
                    if (r != rows-1) {
                        obstacleGrid[r][c] += obstacleGrid[r+1][c];
                        if (c != cols-1)
                            obstacleGrid[r][c] += obstacleGrid[r][c+1];
                    }
                    else if (c != cols-1)
                        obstacleGrid[r][c] += obstacleGrid[r][c+1];
                    else
                        obstacleGrid[r][c] += 1;
                }
            }
        }
        
        return obstacleGrid[0][0];
    }
}