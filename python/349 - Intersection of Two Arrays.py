# 349
# Intersection of Two Arrays
# https://leetcode.com/problems/intersection-of-two-arrays/
# python
# easy
# O(n)
# O(n)
# array

# pythonic solution, not very effecient, but uses inbuilt python functions
# time: O(n)
# space: O(n)
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(nums1).intersection(set(nums2)))