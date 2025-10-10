// Binary Tree Maximum Depth Calculator


#include<iostream>

struct node
{
    int data;
    node* left;
    node* right;
    
    node(int val) {
        data = val;
        left = right = NULL;
    }
    
    // Recursively deletes all child nodes
    ~node() {
        delete left;
        delete right;
    }
};

// Time: O(n), Space: O(h) where h is height
class solution
{
public:
    // Returns the maximum depth of binary tree
    int maxdepth(node* root) {
        if(root == NULL) return 0;
        
        int lh = maxdepth(root->left);
        int rh = maxdepth(root->right);
        
        return 1 + std::max(lh, rh);
    }
};

int main() {
    // Create tree:    1
    //                / \
    //               2   3
    //              / \
    //             4   5
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    
    solution sol;
    std::cout << "Max Depth: " << sol.maxdepth(root) << std::endl;
    
    delete root;
    return 0;
}