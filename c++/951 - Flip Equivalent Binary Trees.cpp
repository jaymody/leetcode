// 951
// Flip Equivalent Binary Trees
// https://leetcode.com/problems/flip-equivalent-binary-trees/
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

// initial solution (NOTE: slightly cleaner and more optimized code below)
// O(n) time (with O(n^2) worst case), O(1) space (exclusing stack)
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        bool b1 = root1 == NULL;
        bool b2 = root2 == NULL;

        if (b1 != b2) return false;
        else if (b1 && b2) return true;
        else {
            if (root1->val != root2->val) return false;
            bool c1 = flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right);
            return c1 || (flipEquiv(root1->right, root2->right) && flipEquiv(root1->left, root2->left));
        }
    }
};

// slightly more optimized, cleaner solution
// still O(n) time (worst case O(n^2)), O(1) space
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL || root2 == NULL) return root1 == root2;
        else if (root1->val != root2->val) return false;
        else return (flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right)) || \
             (flipEquiv(root1->right, root2->right) && flipEquiv(root1->left, root2->left));
    }
};
