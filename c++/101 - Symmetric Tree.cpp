// 101
// Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/
// c++
// easy
// O(n)
// O(1)
// tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursive linear solution
// time: O(n)
// space: O(1)
class Solution {
public:
    bool visit(TreeNode* l, TreeNode* r) {
        if (l!=r && (!r || !l))
            return false;
        if (r)
            return l->val == r->val && visit(l->left, r->right) && visit(l->right, r->left);
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        
        return visit(l, r);
    }
};