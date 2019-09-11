// 2
// Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/
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

// iterative solution
// time: O(n) where n is the length of the longest linked list
// space: O(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* prev = new ListNode(-1);
        prev->next = l1;
            
        int sum = 0;
        int xtra = 0;
        
        while (l1 && l2) {
            sum = xtra + l1->val + l2->val;
            l1->val = sum % 10;
            xtra = sum < 10 ? 0 : 1;
            
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 && xtra==1) {
            sum = xtra + l1->val;
            l1->val = sum % 10;
            xtra = sum < 10 ? 0 : 1;
            
            prev = l1;
            l1 = l1->next;
        }
        
        if (l2)
            prev->next = l2;
        while (l2 && xtra==1) {
            sum = xtra + l2->val;
            l2->val = sum % 10;
            xtra = sum < 10 ? 0 : 1;
            
            prev = l2;
            l2 = l2->next;
        }
        
        if (xtra==1)
            prev->next = new ListNode(1);
        
        return head;
    }
};