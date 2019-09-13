// 100
// Same Tree
// https://leetcode.com/problems/same-tree/
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

// one liner solution using short circuit boolean expressions
// time: O(n)
// space: O(1)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
            return p == q || p && q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};