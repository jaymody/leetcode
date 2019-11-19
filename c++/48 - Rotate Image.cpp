// 48
// Rotate Image
// https://leetcode.com/problems/rotate-image/
// c++
// medium
// O(n^2)
// O(1)
// matrix

// in-place iterative solution (using 4 derived formulas)
// time: O(n^2)
// space: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        if (n < 1) return;
        
        for (int i = 0; i < (n+1)/2; i++) {
            for (int j = i; j < n-i; j++) {
                int temp = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = matrix[j][n-i]; 
                matrix[j][n-i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};
