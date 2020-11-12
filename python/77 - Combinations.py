# 77
# Combinations
# https://leetcode.com/problems/combinations/
# python
# medium
# O(nCk)
# O(n)
# combinatronics backtracking


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []

        def visit(arr, start):
            if len(arr) == k:
                ans.append(arr)
                return
            for i in range(start, n + 1):
                visit(arr + [i], i + 1)

        visit([], 1)
        return ans
