# 509
# Fibonacci Number
# https://leetcode.com/problems/fibonacci-number/
# python
# easy
# basic

class Solution:
    def fib(self, N: int) -> int:
        a=0
        b=1
        for _ in range(N):
            b=a+b
            a=b-a
        return a