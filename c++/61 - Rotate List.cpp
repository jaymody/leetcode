// 61
// Rotate List
// https://leetcode.com/problems/rotate-list/
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

// double iteration solution
// time: O(n)
// space: O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return NULL;
        
        ListNode* last;
        ListNode* node = head;
        int size = 0;
        while (node->next) {
            size++;
            node = node->next;
        }
        
        size++;
        last = node;
        node = head;
        for (int i = 0; i < size-(k%size)-1; i++)
            node = node->next;
        
        last->next = head;
        head = node->next;
        node->next = NULL;
        
        return head;
    }
};