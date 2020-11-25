# 347
# Top K Frequent Elements
# https://leetcode.com/problems/top-k-frequent-elements/
# python
# medium
# O(nlogk)
# O(n)
# heap

# implementation using a counter and heap
# time: O(nlogk)
# space: O(n)
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = collections.defaultdict(int)
        for num in nums:
            counter[num] += 1
        return [
            x[0] for x in heapq.nlargest(k, list(counter.items()), key=lambda x: x[1])
        ]
