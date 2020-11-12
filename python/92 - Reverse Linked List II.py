# 92
# Reverse Linked List II
# https://leetcode.com/problems/reverse-linked-list-ii/
# python
# medium
# O(n)
# O(1)
# linked_list


# this solution is so messy it hurts to look at
# O(n)
# O(1)
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        n1 = head if m > 1 else None
        for _ in range(m - 2):
            n1 = n1.next

        n2 = n1.next if n1 else head
        n4 = n1.next if n1 else head
        prev = None
        for _ in range(m, n + 1):
            temp = n4.next
            n4.next = prev
            prev = n4
            n4 = temp

        n3 = prev

        n2.next = n4
        if not n1:
            return n3
        n1.next = n3
        return head
