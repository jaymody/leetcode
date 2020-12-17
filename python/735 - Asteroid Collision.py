# 735
# Asteroid Collision
# https://leetcode.com/problems/asteroid-collision/
# python
# medium
# O(n)
# O(n)
# stack linked_list

# stack solution
# time: O(n)
# space: O(n)
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []

        for current in asteroids:
            add_to_end = True

            while len(stack) != 0 and stack[-1] > 0 and current < 0:
                add_to_end = False
                if abs(stack[-1]) == abs(current):
                    stack.pop()
                    break
                elif abs(stack[-1]) > abs(current):
                    break
                else:  # top < current
                    stack.pop()
                    add_to_end = True

            if add_to_end:
                stack.append(current)

        return stack


# cursed solution using a double linked list, please forgive me for this code
# time: O(n)
# space: O(n)
class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None


class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        root = Node(0)
        prev = root
        for v in asteroids:
            node = Node(v)
            node.prev = prev
            prev.next = node
            prev = node

        node = root.next
        while node and node.next:
            lval = node.val
            rval = node.next.val
            if lval > 0 and rval < 0:
                print(lval, rval)
                if abs(lval) == abs(rval):
                    node.prev.next = node.next.next
                    node = node.prev
                elif abs(lval) > abs(rval):
                    node.next = node.next.next
                else:
                    node.prev.next = node.next
                    node = node.prev
            else:
                node = node.next

            if node:
                if node.next:
                    node.next.prev = node
                if node.val == 0:
                    node = node.next

        ans = []
        root = root.next
        while root != None:
            ans.append(root.val)
            root = root.next
        return ans
