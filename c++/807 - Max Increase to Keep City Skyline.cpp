// 807
// Max Increase to Keep City Skyline
// https://leetcode.com/problems/max-increase-to-keep-city-skyline/
// c++
// medium
// O(m*n)
// O(m+n)
// matrix

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // Variables
        int sum = 0;
        
        int nRows = grid.size();
        int nCols = grid[0].size();
        
        vector<int> rowMax(nRows, -1);
        vector<int> colMax(nCols, -1);
        
        // Get max for each row
        for (int row = 0; row < nRows; row++) {
            for (int col = 0; col < nCols; col++) {
                if (grid[row][col] > rowMax[row])
                    rowMax[row] = grid[row][col];
            } 
        }
        // Get max for each col
        for (int col = 0; col < nCols; col++) {
            for (int row = 0; row < nRows; row++) {
                if (grid[row][col] > colMax[col])
                    colMax[col] = grid[row][col];
            } 
        }
        
        for (int row = 0; row < nRows; row++) {
            for (int col = 0; col < nCols; col++) {
                if (rowMax[row] < colMax[col]) {
                    sum += rowMax[row] - grid[row][col];
                    grid[row][col] = rowMax[row];
                }
                else {
                    sum += colMax[col] - grid[row][col];
                    grid[row][col] = colMax[col];
                }
            }
        }
        
        return sum;
    }
};
