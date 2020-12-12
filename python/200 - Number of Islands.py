# 200
# Number of Islands
# https://leetcode.com/problems/number-of-islands/
# python
# medium
# O(mn)
# O(1)
# dfs bfs graph


# in-place dfs
# time: O(mn)
# space: O(1)
# in the event that we are not allowed to modify the input array, we can
# assign visited squares with -1 and at the end revert any -1 entries back to 1
class Solution:
    def numIslands(self, grid):
        def dfs(row, col):
            grid[row][col] = "0"
            if col + 1 < len(grid[0]) and grid[row][col + 1] == "1":  # right
                dfs(row, col + 1)
            if col - 1 >= 0 and grid[row][col - 1] == "1":  # left
                dfs(row, col - 1)
            if row + 1 < len(grid) and grid[row + 1][col] == "1":  # down
                dfs(row + 1, col)
            if row - 1 >= 0 and grid[row - 1][col] == "1":  # up
                dfs(row - 1, col)

        num_islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    num_islands += 1
                    dfs(i, j)

        return num_islands
