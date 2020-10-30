# 11
# Container With Most Water
# https://leetcode.com/problems/container-with-most-water/
# python
# medium
# O(n)
# O(1)
# array


class Solution:
    def maxArea(self, height: List[int]) -> int:
        ans = -1
        l = 0
        r = len(height) - 1
        while l < r:
            ans = max(ans, min(height[l], height[r]) * (r - l))
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
        return ans
