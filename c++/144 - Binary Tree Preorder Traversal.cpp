// 144
// Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/
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

// recursive pre-order traversal, pass by reference vector
// time: O(n)
// space: O(1)
class Solution {
public:
    void visit(TreeNode* root, vector<int>& values) {
        if (root) {
            values.push_back(root->val);
            visit(root->left, values);
            visit(root->right, values);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> values;
        visit(root, values);
        return values;
    }
};