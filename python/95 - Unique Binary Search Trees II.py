# 95
# Unique Binary Search Trees II
# https://leetcode.com/problems/unique-binary-search-trees-ii/
# python
# medium
# O(4^n)
# O(4^n)
# tree dp

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# Time and space complexity based on the associated catalan number for this
# problem
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        self.ans = []
        return self.visit(1, n + 1) if n > 0 else []

    def visit(self, l, r):
        if l == r:
            return [None]

        nodes = []
        for i in range(l, r):
            lefts = self.visit(l, i)
            rights = self.visit(i + 1, r)
            for left in lefts:
                for right in rights:
                    root = TreeNode(i)
                    root.left = left
                    root.right = right
                    nodes.append(root)
        return nodes
