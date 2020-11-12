# 206
# Reverse Linked List
# https://leetcode.com/problems/reverse-linked-list/
# python
# easy
# O(n)
# O(1)
# linked_list


# simple iterative solution
# time: O(n)
# space: O(1)
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        while head != None:
            temp = head.next
            head.next = prev
            prev = head
            head = temp
        return prev


# simple recursive solution
# time: O(n)
# space: O(n)
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        def visit(curr, prev):
            if not curr:
                return prev
            temp = curr.next
            curr.next = prev
            return visit(temp, curr)

        return visit(head, None)
