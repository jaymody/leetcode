// 94
// Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/
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

// recursive in-order traversal, pass by reference vector
// time: O(n)
// space: O(1)
class Solution {
public:
    int visit(TreeNode* root, vector<int>& values) {
        if (root) {
            visit(root->left, values);
            values.push_back(root->val);
            visit(root->right, values);
        }
        
        return NULL;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;
        visit(root, values);
        return values;
    }
};
