// 113
// Path Sum II
// https://leetcode.com/problems/path-sum-ii/
// c++
// medium
// O(n)
// O(d)
// tree stack

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// initial solution, recursive linear stack
// time: O(n) where n is the number of nodes
// space: O(d) where d is the max depth of the tree
class Solution {
public:
    void visit(TreeNode* root, vector<vector<int>>& results, vector<int>& stack, int sum) {
        if (!root) return;
        
        stack.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) 
            results.push_back(stack);
        else {
            visit(root->left, results, stack, sum - root->val);
            visit(root->right, results, stack, sum - root->val);
        }
        stack.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> results;
        vector<int> stack;
        visit(root, results, stack, sum);
        return results;
    }
};