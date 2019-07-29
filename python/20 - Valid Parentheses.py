# 20
# Valid Parentheses
# https://leetcode.com/problems/valid-parentheses/
# python
# easy
# O(n)
# O(n)
# string stack

# Initial solution in python using python [O(n), O(n)]
# Impoved version done in c++
class Solution:
    def isValid(self, s: str) -> bool:
        d = {
            "[": "]",
            "{": "}",
            "(": ")"
        }
        
        stack = []
        
        for c in s:
            if stack and stack[-1] == c:
                del stack[-1]
                continue
                
            if c in d.keys():
                stack.append(d[c])
            elif c in d.values():
                return False    

        return len(stack) == 0
