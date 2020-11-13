# 33
# Search in Rotated Sorted Array
# https://leetcode.com/problems/search-in-rotated-sorted-array/
# python
# medium
# O(log n)
# O(1)
# binary_search


# modified version of binary search that takes advantage of the knowledge that
# for any (l, m, r), at least one of (l, m) or (m, r) is sorted.
# time: O(log n)
# space: O(1)
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            m = (l + r) // 2
            if nums[m] == target:
                return m
            elif nums[l] < nums[m]:
                if nums[l] <= target < nums[m]:
                    r = m - 1
                else:
                    l = m + 1
            else:
                if m != r and nums[m + 1] <= target <= nums[r]:
                    l = m + 1
                else:
                    r = m - 1
        return -1
