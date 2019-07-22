# 1
# Two Sum
# https://leetcode.com/problems/two-sum/
# python
# easy
# O(n)
# O(n)
# basic

# solution can be imporved for time and space
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i,n in enumerate(nums):
            if target-n in d:
                return [d[target-n], i]
            d[n]=i
        return False
