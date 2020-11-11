# 56
# Merge Intervals
# https://leetcode.com/problems/merge-intervals/
# python
# medium
# O(n log n)
# O(1)
# array


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        intervals.sort()

        ans = []
        l, r = intervals[0]
        for i, j in intervals:
            if i > r:
                ans.append([l, r])
                l = i
                r = j
            elif j > r:
                r = j
        return ans + [[l, r]]
