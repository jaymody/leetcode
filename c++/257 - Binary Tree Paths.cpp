// 257
// Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/
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

// recursive linear solution
// time: O(n)
// space: O(1)
class Solution {
public:
    void visit(TreeNode* root, string s, vector<string>& results) {
        if (!root) return;
        if (!root->right && !root->left) results.push_back(s + to_string(root->val));
        else {
            s += to_string(root->val) + "->";
            visit(root->left, s, results);
            visit(root->right, s, results);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        visit(root, "", results);
        return results;
    }
};