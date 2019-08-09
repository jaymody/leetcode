// 669
// Trim a Binary Search Tree
// https://leetcode.com/problems/trim-a-binary-search-tree/
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

// quick, simple O(n), O(1) solution (excluding stack size for space complexity)
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root)
            return NULL;
        
        root->right = trimBST(root->right, L, R);
        root->left = trimBST(root->left, L, R);
        
        if (root->val < L)
            return root->right;
        else if (root->val > R)
            return root->left;
        return root;
    }
};