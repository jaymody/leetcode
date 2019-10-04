// 109
// Convert Sorted List to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// c++
// medium
// O(n)
// O(n)
// tree linked_list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursive vector solution (memory ineffecient)
// time: O(n)
// space: O(n)
class Solution {
public:
    TreeNode* visit(vector<int>& list, int l, int r) {
        if (l > r) return NULL;
        if (l == r) return new TreeNode(list[l]);
        
        int m = (l+r)/2;
        
        TreeNode* root = new TreeNode(list[m]);
        root->left = visit(list, l, m-1);
        root->right = visit(list, m+1, r);

        return root; 
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        
        vector<int> list;
        while (head) {
            list.push_back(head->val);
            head = head->next;
        }
        
        return visit(list, 0, list.size()-1);
    }
};