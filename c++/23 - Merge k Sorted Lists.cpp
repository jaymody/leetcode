// 23
// Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists
// c++
// hard
// O(k*N)
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

// no extra memory solution
// time: O(k*n) where n is the max length of a list
// space: O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Null case
        if (lists.empty()) return NULL;
        
        // Initial pointers
        ListNode* head = new ListNode(-1);
        ListNode* prev = head;
        int min = 0;
        
        // While
        for (;;) {
            // Find minimum
            for (int i = 0; i < lists.size(); i++) {
                if (lists[min] == NULL) 
                    min = i;
                else if (lists[i] && (lists[i]->val <= lists[min]->val))
                    min = i;
            }
            
            // Connect min to running list
            prev->next = lists[min];
            prev = prev->next;
            
            // Progress List[min] or break if all lists are exhausted
            if (lists[min]) 
                lists[min] = lists[min]->next;
            else
                break;
        }
        
        return head->next;
    }
};

