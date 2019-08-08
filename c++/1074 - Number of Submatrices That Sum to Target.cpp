// 1074
// Number of Submatrices That Sum to Target
// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
// c++
// hard
// TBI
// TBI
// matrix

// for time and space complexities, 
// n is the number of rows in the matrix and m is number of columns

// my SECOND solution
// slow but very memory efficient algorithim, was accepted at 100% mem eff, 5% speed
// time O(n^2*m^2) (excluding coefficients of course), space O
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        
        int xmax = matrix.size();
        int ymax = matrix[0].size();
        
        // double for loop for start bounds
        for (int x = 0; x < xmax; x++) {
            for (int y = 0; y < ymax; y++) {
                vector<int> cache(ymax-y,0);
                
                // all submatrices for bounds double for loop
                for (int i = x; i < xmax; i++) {
                    int sum = 0;
                    for (int j = y; j < ymax; j++) { 
                        sum += matrix[i][j] + cache[j-y];
                        cache[j-y] += matrix[i][j];
                        if (sum == target)
                            ans++;
                    }
                }
            }
        } 
        
        return ans;
    }
};


// my FIRST solution
// im suprised leetcode servers didn't crash after this monstrosity of for loops
// the algorithim works, slowly, very very slowly, but hey, it works
// time O(infinity???), space O(1)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        
        int xmax = matrix.size();
        int ymax = matrix[0].size();
        
        // double for loop for start bounds
        for (int x = 0; x < xmax; x++) {
            for (int y = 0; y < ymax; y++) {
                // all submatrices for bounds double for loop
                for (int x2 = x; x2 < xmax; x2++) {
                    for (int y2 = y; y2 < ymax; y2++) { 
                        // sum of submatrix
                        int sum = 0;
                        for (int i = x; i <= x2; i++) {
                            for (int j = y; j <= y2; j++)
                                sum += matrix[i][j];
                        }
                        if (sum == target) 
                            ans += 1;
                    }
                }  
            }
        }       
        return ans;
    }
};
