# 125
# Valid Palindrome
# https://leetcode.com/problems/valid-palindrome/
# python
# easy
# O(n)
# O(1)
# string


# time O(n)
# space O(n)
# python makes this an easy, elegant solution
# however, for a better solution with even faster results
# and more importantly, a space complexity of O(1)
# a index/pointer algorithim should be used
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = re.sub(r'[^a-z0-9]', '', s.lower())
        if s == s[::-1]:
            return True
        return False
