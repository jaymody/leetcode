# 79
# Word Search
# https://leetcode.com/problems/word-search/
# python
# medium
# O(m*n*4^l)
# O(l)
# search


# simple depth-first search solution
# O(m*n*4^l)
# O(l)
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(i, j):
            nonlocal n, visited
            if n == len(word):
                return True
            elif not 0 <= i < len(board) or not 0 <= j < len(board[0]):
                return False
            elif not visited[i][j] and board[i][j] == word[n]:
                n += 1
                visited[i][j] = True
                if dfs(i + 1, j) or dfs(i - 1, j) or dfs(i, j + 1) or dfs(i, j - 1):
                    return True
                visited[i][j] = False
                n -= 1
            return False

        n = 0
        visited = [[False] * len(board[0]) for _ in range(len(board))]
        for y in range(len(board)):
            for x in range(len(board[0])):
                if dfs(y, x):
                    return True
        return False

