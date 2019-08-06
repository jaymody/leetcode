// 814
// Binary Tree Pruning
// https://leetcode.com/problems/binary-tree-pruning/submissions/
// c++
// medium
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

// more concise second solution that removes unecessary bools
// O(n) O(1)
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 1 || root->left || root->right) return root;
        else return NULL;
    }
};

// Simple quick initial O(n) O(1) solution
class Solution {
public:
    bool visit(TreeNode* root) {
        if (root != NULL) { 
            bool b1 = visit(root->left);
            bool b2 = visit(root->right);
            
            if (!b1) root->left = NULL;
            if (!b2) root->right = NULL;
            
            return root->val == 1 || b1 || b2;
        }
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool b = visit(root);
        if (!b)
            return NULL;
        return root;
    }
};
