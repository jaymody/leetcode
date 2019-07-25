# 454
# 4Sum II
# https://leetcode.com/problems/4sum-ii/
# python
# medium
# O(n^2)
# O(n^2)
# hash_table

class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        
        ans = 0
        count = collections.defaultdict(int)
        
        for a in A:
            for b in B:
                count[a+b]+=1
                
        for c in C:
            for d in D:
                try:
                    ans+=count[-c-d]
                except KeyError:
                    continue
        
        return ans
        
