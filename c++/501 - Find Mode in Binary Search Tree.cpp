// 501
// Find Mode in Binary Search Tree
// https://leetcode.com/problems/find-mode-in-binary-search-tree/submissions/
// c++
// easy
// O(n^2)
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


// initial O(n^2) O(n) solution using a hash map
// time complexity is n^2 because worst case, every entry in the BST
// is unique and so the traversal through the hash map is O(n)
// NOTE: there is a better solution out there with O(n) time O(1) space
// that I haven't solved for yet (but know exists)
class Solution {
public:
    void visit(TreeNode* root, unordered_map<int,int>& map) {
        if (root) {
            visit(root->left, map);
            visit(root->right, map);
            map[root->val] += 1;
        }
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> map;
        visit(root, map);
        int max = 0;
        vector<int> results;
        for (auto& it : map) {
            // cout << it.first << ": " << it.second << endl;
            if (it.second > max) {
                max = it.second;
                results.clear();
                results.push_back(it.first);
            }
            else if (it.second == max) {
                results.push_back(it.first);
            }
        }
        return results;
    }
};
