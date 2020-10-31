# 73
# Set Matrix Zeroes
# https://leetcode.com/problems/set-matrix-zeroes/
# python
# medium
# O(m*n)
# O(1)
# array


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rb = 0 in matrix[0]
        cb = 0 in set(matrix[i][0] for i in range(len(matrix)))

        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0

        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[0][j] == 0 or matrix[i][0] == 0:
                    matrix[i][j] = 0

        if rb:
            matrix[0] = [0] * len(matrix[0])
        if cb:
            for i in range(len(matrix)):
                matrix[i][0] = 0
