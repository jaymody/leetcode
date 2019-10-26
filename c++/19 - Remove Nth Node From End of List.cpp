// 19
// Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// c++
// medium
// O(n)
// O(1)
// linked_list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// initial linear solution
// time: O(n)
// space: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return NULL;
        
        ListNode* node = new ListNode(-1);
        node->next = head;
        ListNode* ahead = node; 
        head = node;
        
        for (int i = n; i > 0; i--)
            ahead = ahead->next;
        
        while (ahead->next) {
            node = node->next;
            ahead = ahead->next;
        }
        
        node->next = node->next->next;
        
        return head->next ? head->next : NULL;
    }
};