// 145
// Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/
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

// recursive post-order traversal, pass by reference vector
// time: O(n)
// space: O(1)
class Solution {
public:
    void visit(TreeNode* root, vector<int>& values) {
        if (root) {
            visit(root->left, values);
            visit(root->right, values);
            values.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> values;
        visit(root, values);
        return values;
    }
};