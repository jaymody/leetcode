// 54
// Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/
// c++
// medium
// O(m*n)
// O(1)
// matrix

// simple iterative solution
// time: O(m*n)
// space: O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> results;
        
        if (!matrix.size() || !matrix[0].size())
            return results;
        
        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        
        int n = 0;
        
        while (bottom >= top and right >= left) {
            // go right
            if (n%4==0) {
               for (int i = left; i <= right; i++)
                    results.push_back(matrix[top][i]);
                top++; 
            }
            // go bottom
            else if (n%4==1) {
                for (int i = top; i <= bottom; i++)
                    results.push_back(matrix[i][right]);
                right--;
            }
            // go left
            else if (n%4==2) {
                for (int i = right; left <= i; i--)
                    results.push_back(matrix[bottom][i]);
                bottom--;
            }
            // go top
            else {
                for (int i = bottom; i >= top; i--)
                    results.push_back(matrix[i][left]);
                left++;
            }
            
            n++;
        }
        
        return results;
    }
};