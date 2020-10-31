# 74
# Search 2D Matrix
# https://leetcode.com/problems/search-a-2d-matrix/submissions/
# python
# medium
# O(log m + log n)
# O(1)
# array binary_search matrix

# double binary search
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False

        u = 0
        d = len(matrix) - 1
        while u <= d:
            i = (u + d) // 2
            if matrix[i][0] <= target <= matrix[i][-1]:
                l = 0
                r = len(matrix[0]) - 1
                while l <= r:
                    j = (l + r) // 2
                    if matrix[i][j] == target:
                        return True
                    elif matrix[i][j] > target:
                        r = j - 1
                    else:
                        l = j + 1
                return False
            elif matrix[i][0] > target:
                d = i - 1
            else:
                u = i + 1
        return False
