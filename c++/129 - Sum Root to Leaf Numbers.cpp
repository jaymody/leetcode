// 129
// Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/
// c++
// medium
// O(n)
// O(d)
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

// recursive ternary linear solution
// time: O(n) where n is the total number of nodes
// space: O(d) where d is the max depth of the tree
// the reason the space is O(d) is because d number of int num
// variables will be created at each recursion step
class Solution {
public:
    int visit(TreeNode* root, int num) {
        if (!root) return 0;
        num = num*10 + root->val;
        return !root->right && !root->left ? num : visit(root->left, num) + visit(root->right, num);
    }
    int sumNumbers(TreeNode* root) {
        return visit(root,0);
    }
};