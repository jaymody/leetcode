# 40
# Combination Sum II
# https://leetcode.com/problems/combination-sum-ii/
# python
# medium
# O(2^n)
# O(n^2)
# array backtracking


# similar to solution for combination sum problem, but we don't duplicate
# current index (so we recurse with i+1 instead of i for start), and we also
# use a set to keep track of what's numbers have been recursed on (we only
# want to recurse on the very first element of a sequence of duplicate)
# Time: O(2^n)
# Space: O(n^2)
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(remain, arr, start):
            if remain == 0:
                ans.append(arr)
                return

            prev = set()
            for i in range(start, len(candidates)):
                if candidates[i] > remain:
                    break
                elif candidates[i] in prev:
                    continue
                else:
                    prev.add(candidates[i])
                    dfs(remain - candidates[i], arr + [candidates[i]], i + 1)

        candidates.sort()
        ans = []
        dfs(target, [], 0)
        return ans
