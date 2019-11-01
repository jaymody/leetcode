# 46
# Permutations
# https://leetcode.com/problems/permutations/
# python
# medium
# O(n!)
# O(1)
# permute

# initial swapping solution
# time: O(n!)
# space: O(1) excluding output space
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        results = []
        end = len(nums)
        
        def recurse(start):
            if start == end:
                results.append(nums[:])
            for i in range(start, end):
                nums[start], nums[i] = nums[i], nums[start]
                recurse(start+1)
                nums[start], nums[i] = nums[i], nums[start]
        
        recurse(0)
        return results