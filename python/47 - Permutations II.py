# 47
# Permutations II
# https://leetcode.com/problems/permutations-ii/
# python
# medium
# O(n!)
# O(n^2)
# permute backtracking


# Not a very space efficient solution, but I like the concept (quite simple)
# O(n!)
# O(n^2)
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = []

        def visit(curr, pool):
            if not pool:
                ans.append(curr)
            prev = set()
            for i in range(len(pool)):
                if pool[i] in prev:
                    continue
                prev.add(pool[i])
                visit(curr + [pool[i]], pool[:i] + pool[i + 1 :])

        visit([], nums)
        return ans
