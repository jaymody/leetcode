// 21
// Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/
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

// two pointer solution
// time: O(n) where n is the length of the two lists
// space: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        
        ListNode* prev = new ListNode(-1);
        prev->next = l1;
        ListNode* head = prev;
        
        while (l1 && l2) {
            prev->next = l1;
            while (l1 && l1->val <= l2->val) {
                prev = l1;
                l1 = l1->next;
            }
            prev->next = l2;
            swap(l1, l2);
        }
        
        return head->next;
    }
};