# 64
# Minimum Path Sum
# https://leetcode.com/problems/minimum-path-sum/
# python
# medium
# O(m*n)
# O(1)
# dp matrix


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i > 0 and j > 0:
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1])
                elif i > 0:
                    grid[i][j] += grid[i - 1][j]
                elif j > 0:
                    grid[i][j] += grid[i][j - 1]
        return grid[-1][-1]
