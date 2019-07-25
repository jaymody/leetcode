// 86
// Partition List
// https://leetcode.com/problems/partition-list/
// c++
// medium
// O(n)
// O(1)
// linked_list two_pointers

// Good solution O(n), O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Pointers/Bools
        ListNode leftbase(0);
        ListNode* left = &leftbase;
    
        ListNode rightbase(0);
        ListNode* right = &rightbase;
        
        // Iterate
        while (head) {
            if (head->val < x) {
                left->next = head;
                left = head;
            } 
            else {
                right->next = head;
                right = head;
            }
            head = head->next;
        }
        
        right->next = NULL;
        left->next = rightbase.next;
        
        return leftbase.next;
    }
};
