# 58
# Length of Last Word
# https://leetcode.com/problems/length-of-last-word/
# python
# easy
# O(n)
# O(n)
# string

# very pythonic solution (obvs not the most efficient however)
# O(n)
# O(n)
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return 0 if not s.split() else len(s.split()[-1])