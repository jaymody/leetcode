# 554
# Brick Wall
# https://leetcode.com/problems/brick-wall/
# python
# medium
# O(n)
# O(n)
# hash_map

# hash map solution
# time: O(n)
# space: O(n)
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        counter = collections.defaultdict(int)
        for row in wall:
            total = 0
            for brick in row[:-1]:
                total += brick
                counter[total] += 1
        return len(wall) - (max(counter.values()) if counter else 0)
