// 24
// Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/
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

// Linear iterative solution
// time: O(n)
// space: O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        head = prev;
        
        ListNode* first = prev;
        ListNode* second;
        
        while (first->next && first->next->next) {
            prev = first;
            first = first->next;
            second = first->next;
            
            first->next = second->next;
            second->next = first;
            prev->next = second;
        }
        
        return head->next;
    }
};