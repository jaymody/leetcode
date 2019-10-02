// 199
// Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/
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

// recursive depth tracking solution
// time: O(n)
// space: O(1)
class Solution {
public:
    void visit(TreeNode* root, int& depth, int& max_depth, vector<int>& results) {
        if (!root) return;
        if (depth > max_depth) {
            results.push_back(root->val);
            max_depth++;
        }
        depth++;
        visit(root->right, depth, max_depth, results);
        visit(root->left, depth, max_depth, results);
        depth--;
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> results;
        int max_depth = 0;
        int depth = 1;
        visit(root, depth, max_depth, results);
        return results;
    }
};