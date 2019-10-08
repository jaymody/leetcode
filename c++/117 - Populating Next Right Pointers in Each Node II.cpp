// 117
// Populating Next Right Pointers in Each Node II
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// c++
// medium
// O(n)
// O(1)
// tree

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

// same idea as the solution right below this one, but more elegant looking
// time: O(n)
// space: O(1)
class Solution {
public:
    Node* findNext(Node* root) {
        if (!root) return NULL;
        if (root->left) return root->left;
        if (root->right) return root->right;
        return findNext(root->next);
    }
    
    void visit(Node* root) {
        if (!root) return;

        if (root->right) {
            root->right->next = findNext(root->next);
            if (root->left) root->left->next = root->right;
        }
        else if (root->left)
            root->left->next = findNext(root->next);
        
        visit(root->right);
        visit(root->left);
    }
    
    Node* connect(Node* root) {
        visit(root);
        return root;
    }
};

// a very ugly, but super fast and mem efficient solution
// time: O(n)
// space: O(1)
class Solution {
public:
    Node* findNext(Node* root) {
        if (!root) return NULL;
        if (root->left) return root->left;
        if (root->right) return root->right;
        return findNext(root->next);
    }
    void visit(Node* root) {
        if (!root) return;
        
        if (root->next) {
            if (root->right) {
                root->right->next = findNext(root->next);
                if (root->left) root->left->next = root->right;
            }
            else if (root->left)
                root->left->next = findNext(root->next);   
        }
        else {
            if (root->right) {
                root->right->next = NULL;
                if (root->left) root->left->next = root->right;
            }
            else if (root->left) root->left->next = NULL;
        }
        
        visit(root->right);
        visit(root->left);
    }
    Node* connect(Node* root) {
        visit(root);
        return root;
    }
};

// intial solution, recursive pre order reverse traversal with a vector
// time: O(n)
// space: O(d) where d is the depth of the tree
// explanation:
// The binary tree is traversed pre-order reversed (right to left)
// At each step, if the depth is greater than the length of the tracked vector.
// push back the vector with a NULL element.
// Then, the next pointer for the node is set to vector[depth],
// and vector[depth] is reassigned to the current node
class Solution {
public:
    void visit(Node* root, vector<Node*>& v, int d) {
        if (!root) return;
       
        if (d >= v.size())
            v.push_back(NULL);
        
        root->next = v[d];
        v[d] = root;
        
        visit(root->right, v, d+1);
        visit(root->left, v, d+1);
    }
    Node* connect(Node* root) {
        vector<Node*> v;
        visit(root, v, 0);
        return root;
    }
};