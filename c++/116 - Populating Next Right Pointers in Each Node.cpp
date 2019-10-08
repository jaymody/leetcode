// 116
// Populating Next Right Pointers in Each Node
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
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

// linear recursive solution
// time: O(n)
// space: O(1)
class Solution {
public:
    void visit(Node* root) {
        if(!root) return;

        if(root->left) root->left->next = root->right;
        if(root->right && root->next) root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);
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
// A vector of size d is initialized with NULL elements.
// The binary tree is traversed pre-order reversed (right to left)
// At each step, the next pointer is set to vector[depth],
// and vector[depth] is reassigned to the current node
class Solution {
public:
    void visit(Node* root, vector<Node*>& v, int d) {
        if (!root) return;
        
        root->next = v[d];
        v[d] = root;
        
        visit(root->right, v, d+1);
        visit(root->left, v, d+1);
    }
    Node* connect(Node* root) {
        vector<Node*> v;

        Node* node = root;
        while (node) {
            v.push_back(NULL);
            node = node->left;
        }
        
        visit(root, v, 0);
        return root;
    }
};