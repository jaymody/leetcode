// 104
// Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
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

// one line ternary operator recursive solution
// time: O(n)
// time: O(1)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return !root ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};