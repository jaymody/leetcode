// 102
// Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/
// c++
// medium
// O(n)
// O(n)
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

// left to right recursive solution
// time: O(n)
// space: O(n)
class Solution {
public:    
    void visit(TreeNode* root, vector<vector<int>>& result, int depth) {
        if (root) {
            if (depth == result.size()) {
                vector<int> empty;
                result.push_back(empty);
            }

            result[depth].push_back(root->val);

            visit(root->left, result, depth+1);
            visit(root->right, result, depth+1);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; 
        visit(root, result, 0);
        return result;
    }
};