# 49
# Group Anagrams
# https://leetcode.com/problems/group-anagrams/
# python
# medium
# O(k*n^2)
# O(k*n)
# string

# Initial slow solution
# time: O(k*n^2) where n is the length of the list and k is the max length of the strings
# space: O(k*n)
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dicts = {}
        results = []
        i = 0;
        
        for s in strs: # O(n)
            count = dict(collections.Counter(list(s))) # O(k)
            try:
                index = list(dicts.values()).index(count) # O(nk)
            except:
                index = -1
            if index == -1:
                dicts[i] = count
                results.append([s])
                i+=1
            else:
                results[index].append(s)
        
        return results
                
        
        