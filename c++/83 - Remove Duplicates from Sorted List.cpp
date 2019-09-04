// 83
// Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// c++
// easy
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

// simple linear solution (no deallocation of memory)
// time: O(n)
// space: O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return NULL;
        
        ListNode* node = head;
        
        while (node->next) {
            if (node->val == node->next->val)
                node->next = node->next->next;
            else
                node = node->next;
        }
        
        return head;
    }
};