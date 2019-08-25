// 62
// Unique Paths
// https://leetcode.com/problems/unique-paths/
// java
// medium
// O(m*n)
// O(m)
// array

// dynamic programming
// time: O(m*n)
// space: O(m)
class Solution {
    public int uniquePaths(int m, int n) {
        int[] row = new int[m];
        java.util.Arrays.fill(row, 1);

        for (int r = 1; r < n; r++) {
            for (int c = 1; c < m; c++)
                row[c] += row[c-1];  
        }
        
        return row[m-1];
    }
}