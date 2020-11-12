# 78
# Subsets
# https://leetcode.com/problems/subsets/
# python
# medium
# O(2^n)
# O(n)
# combinatronics backtracking


# utilizes the simple recursive combinations algorithm, and simply runs it
# on all possible sizes for a subset
# time: O(2^n)
# space: O(n)
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # we can find the subset by finding all nCk combinations
        # for all values of 0 <= k <= len(nums)
        ans = []

        # simple recursive combinations algorithm
        def visit(arr, start):
            if len(arr) == self.k:
                ans.append(arr)
            for i in range(start, len(nums)):
                visit(arr + [nums[i]], i + 1)

        # run combinations for all values of k
        for k in range(len(nums) + 1):
            self.k = k
            visit([], 0)

        return ans
