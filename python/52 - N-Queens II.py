# 52
# N-Queens II
# https://leetcode.com/problems/n-queens-ii/
# python
# hard
# O(n!)
# O(n)
# matrix


class Solution:
    def valid(self, r, c, queens):
        for x, y in queens:
            if c == y or abs(r - x) == abs(c - y):
                return False
        return True

    def visit(self, r, queens):
        for c in range(self.n):
            if not self.valid(r, c, queens):
                continue
            elif r == self.n - 1:
                self.count += 1
            else:
                self.visit(r + 1, queens[:] + [(r, c)])

    def totalNQueens(self, n: int) -> int:
        self.n = n
        self.count = 0
        self.visit(0, [])
        return self.count if n > 0 else 1
