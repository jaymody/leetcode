# 7
# Reverse Integer
# https://leetcode.com/problems/reverse-integer/
# python
# easy
# O(log n)
# O(1)
# math string

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        s = str(x)
        
        if len(s)==1:
            return x
        
        s=s[::-1]
        
        i = 0
        while (s[i]=='0'):
            i+=1
        s = s[i:]
        if s[-1]=='-':
            s = ''.join(['-',s[:-1]])
            
        if abs(int(s)) > 2**31:
            return 0;
            
        return s
