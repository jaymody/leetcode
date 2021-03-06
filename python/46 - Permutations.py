# 46
# Permutations
# https://leetcode.com/problems/permutations/
# python
# medium
# O(n*n!)
# O(1)
# permute

# solution using running list of options and path
# time: O(n*n!)
# space: O(n^2)
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        results = []

        def recurse(path, options):
            if len(options) == 1:
                results.append(path[:] + options[:])
            else:
                for i in range(len(options)):
                    recurse(path + [options[i]], options[:i] + options[i + 1 :])

        recurse([], nums)
        return results


# initial swapping solution
# time: O(n*n!)
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
                recurse(start + 1)
                nums[start], nums[i] = nums[i], nums[start]

        recurse(0)
        return results


# another recursive algorithm
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []

        def visit(curr, pool):
            if not pool:
                ans.append(curr)
            for i in range(len(pool)):
                visit(curr + [pool[i]], pool[:i] + pool[i + 1 :])

        visit([], nums)
        return ans
