# 90
# Subsets II
# https://leetcode.com/problems/subsets-ii/
# python
# medium
# O(2^n)
# O(n^2)
# array backtracking


# simple recursive algorithm that utilizes combinations algorithm
# with the use of a set to handle duplicates
# time: O(2^n)
# space: O(n^2)
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def visit(arr, start, k):
            if len(arr) == k:
                ans.append(arr)
            else:
                s = set()
                for i in range(start, len(nums)):
                    if nums[i] in s:
                        continue
                    s.add(nums[i])
                    visit(arr + [nums[i]], i + 1, k)

        nums.sort()
        ans = []
        for k in range(len(nums) + 1):
            visit([], 0, k)
        return ans
