// 142
// Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/
// c++
// medium
// TBI
// TBI
// linked_list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// iterative solution using a set (memory ineffecient)
// time: O(n)
// space: O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> adr;
        while (true) {
            adr.insert(head);
            if (!head)
                return NULL;
            if (adr.find(head->next) != adr.end())
                return head->next;
            head = head->next;
        }
    }
};