# 209
# Minimum Size Subarray Sum
# https://leetcode.com/problems/minimum-size-subarray-sum/
# python
# medium
# O(n)
# O(1)
# array two_pointers


# two pointers sliding window algorithm
# time: O(n)
# space: O(1)
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        lptr, rptr = 0, 0
        total = sum(nums[:1])
        output = len(nums) + 1

        while lptr < len(nums) and rptr < len(nums):
            if total >= s:
                output = min(rptr - lptr + 1, output)
                total -= nums[lptr]
                lptr += 1
            else:
                rptr += 1
                if rptr != len(nums):
                    total += nums[rptr]

        return output if output < len(nums) + 1 else 0
