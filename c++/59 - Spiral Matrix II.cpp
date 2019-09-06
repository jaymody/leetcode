// 59
// Spiral Matrix II
// https://leetcode.com/problems/spiral-matrix-ii/
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
    vector<vector<int>> generateMatrix(int n) {
        if (!n)
            return {};
        
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        
        int a = 0;
        int j = 1;
        
        while (bottom >= top and right >= left) {
            // go right
            if (a%4==0) {
                for (int i = left; i <= right; i++) {
                    matrix[top][i] = j;
                    j++;
                }
                top++;
            }
            // go bottom
            else if (a%4==1) {
                for (int i = top; i <= bottom; i++) {
                    matrix[i][right] = j;
                    j++;
                }
                right--;
            }
            // go left
            else if (a%4==2) {
                for (int i = right; left <= i; i--) {
                    matrix[bottom][i] = j;
                    j++;
                }
                bottom--;
            }
            // go top
            else {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = j;
                    j++;
                }
                left++;
            }
            
            a++;
        }
        
        return matrix;
    }
};