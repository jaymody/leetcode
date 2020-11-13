# 75
# Sort Colors
# https://leetcode.com/problems/sort-colors/
# python
# medium
# O(n)
# O(1)
# two_pointers


# simple two pointers solution that moves 0s to the left, and 2s to the right
# O(n)
# O(1)
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        r = len(nums) - 1
        l = 0

        i = 0
        while i <= r:
            if nums[i] == 0:
                nums[l], nums[i] = nums[i], nums[l]
                l += 1
                i += 1
            elif nums[i] == 2:
                nums[r], nums[i] = nums[i], nums[r]
                r -= 1
            else:
                i += 1
