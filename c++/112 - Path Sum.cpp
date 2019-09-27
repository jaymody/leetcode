// 112
// Path Sum
// https://leetcode.com/problems/path-sum/
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

// intial solution, recursive linear
// time: O(n)
// space: O(1)
class Solution {
public:
    bool visit(TreeNode* root, int sum, int& target) {
        sum += root->val;
        
        if (root->left && visit(root->left, sum, target))
            return true;
        if (root->right && visit(root->right, sum, target))
            return true;
        if (!root->right && !root->left)
            return sum == target;
        return NULL;
        
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return root && visit(root, 0, sum);
    }
};

// more concise single function recursive solution
// time: O(n)
// space: O(1)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (sum == root->val && !root->right && !root->left) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};