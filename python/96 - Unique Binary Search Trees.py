# 96
# Unique Binary Search Trees
# https://leetcode.com/problems/unique-binary-search-trees/
# python
# medium
# O(n)
# O(n)
# tree dp

# Recursive memorization solution
#
# We know the base cases for n = 0 and n = 1 (ie there is only one unique
# structure in those cases), so we can iterate through n, at each iteration
# choosing i to be the root, and recusively compute for the left side
# and right side and multiply them to get the number of posssible combinations
# with i in the middle. We sum up the combinations from each iteration to get
# the total for n. If we use a dictionary to memorize the values we find, we
# remove repeat recursions and get an O(n) solution.
class Solution:
    dp = {}

    def numTrees(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1

        total = 0
        for i in range(n):
            if i not in self.dp:
                self.dp[i] = self.numTrees(i)
            if n - 1 - i not in self.dp:
                self.dp[n - 1 - i] = self.numTrees(n - 1 - i)
            total += self.dp[i] * self.dp[n - 1 - i]
        return total
