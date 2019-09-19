// 141
// Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/
// c++
// easy
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

// initial hash_table solution
// time: O(n)
// space: O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        
        set<ListNode*> s;
        
        while (s.find(head) == s.end()) {
            s.insert(head);
            head = head->next;
            if (!head)
                return false;
        }
        return true;
    }
};