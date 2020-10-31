# 867
# Transpose Matrix
# https://leetcode.com/problems/transpose-matrix/
# python
# easy
# O(n)
# O(n)
# array


class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        arr = [[0] * len(A) for _ in range(len(A[0]))]
        for i in range(len(A)):
            for j in range(len(A[0])):
                arr[j][i] = A[i][j]
        return arr
