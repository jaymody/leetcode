// 404
// Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/
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

// cleaner solution
// O(n) time
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        
        if (root == NULL)
            return sum;
        
        if (root->left != NULL) 
            if (root->left->left == NULL && root->left->right == NULL)
                sum += root->left->val;
            else
                sum += sumOfLeftLeaves(root->left);
        if (root->right != NULL)
            sum += sumOfLeftLeaves(root->right);
        
        return sum;
    }
}

// my first solution
// O(n) time
class Solution {
public:
    int right(TreeNode* root) {
        int num = 0;
        if (root->right != NULL)
            num += right(root->right);
        if (root->left != NULL)
            num += left(root->left);
        return num;
    }
    
    int left(TreeNode* root) {
        int num = 0;
        bool islast=true;
        if (root->right != NULL) {
            islast = false;
            num += right(root->right);
        }
        if (root->left!= NULL) {
            islast = false;
            num += left(root->left);
        }
        if (islast)
            num += root->val;
        return num;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        
        if (root == NULL)
            return sum;
        
        if (root->right != NULL)
            sum += right(root->right);
        if (root->left != NULL)
            sum += left(root->left);
        
        return sum;
    }
};
