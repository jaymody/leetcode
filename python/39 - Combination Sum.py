# 39
# Combination Sum
# https://leetcode.com/problems/combination-sum/
# python
# medium
# O(n^t)
# O(n*t)
# array backtracking

# pretty fast algorithm overall, but is a memory hog
# time: O(n^t)
# space: O(n*t)
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # array need not be sorted, but when sorted in reverse,
        # the algorithm runs faster much faster (this is because it wastes less
        # time by stopping recursions early for impossible combinations,
        # especially in cases where multiple elements of candidates is greater
        # than target)
        candidates.sort(reverse=True)
        ans = []

        def visit(nums, total, start):
            if start >= len(candidates):
                return

            while total <= target:
                if total == target:
                    ans.append(nums[:])
                    break
                else:
                    visit(nums[:], total, start + 1)
                    nums.append(candidates[start])
                    total += candidates[start]

        visit([], 0, 0)
        return ans


# even faster than the above algorithm, but similarly, a memory hog
# time: O(n^t)
# space: O(n*t)
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(remain, arr, start):
            if remain == 0:
                ans.append(arr)
                return
            for i in range(start, len(candidates)):
                if candidates[i] > remain:
                    break
                dfs(remain - candidates[i], arr + [candidates[i]], i)

        candidates.sort()
        ans = []
        dfs(target, [], 0)
        return ans
