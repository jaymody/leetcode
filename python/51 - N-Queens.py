# 51
# N-Queens
# https://leetcode.com/problems/n-queens/
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
                self.ans.append(
                    [
                        "." * y + "Q" + "." * (self.n - y - 1)
                        for _, y in queens[:] + [(r, c)]
                    ]
                )
            else:
                self.visit(r + 1, queens[:] + [(r, c)])

    def solveNQueens(self, n: int) -> List[List[str]]:
        self.n = n
        self.ans = []
        self.visit(0, [])
        return self.ans if n > 0 else [[]]
