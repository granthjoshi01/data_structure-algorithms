// Balanced Binary Tree Checker
// A tree is balanced if height difference between left and right subtrees <= 1
// Time: O(n), Space: O(h)

#include<iostream>
#include<cstdlib>  // for abs()

struct node
{
    int data;
    node* left;
    node* right;
    
    node(int val) : data(val), left(nullptr), right(nullptr) {}
    
    // Recursively deletes all child nodes
    ~node() {
        delete left;
        delete right;
    }
};

class solution {
public:
    // Returns true if tree is balanced, false otherwise
    bool isbalanced(node* root) {
        return dfsheight(root) != -1;  // Fixed: was !=1, should be !=-1
    }
    
private:
    // Returns height if balanced, -1 if unbalanced
    int dfsheight(node* root) {  // Fixed: typo "hieght" -> "height"
        if(root == NULL) return 0;
        
        // Check left subtree
        int leftheight = dfsheight(root->left);
        if(leftheight == -1) return -1;  // Left subtree is unbalanced
        
        // Check right subtree
        int rightheight = dfsheight(root->right);
        if(rightheight == -1) return -1;  // Right subtree is unbalanced
        
        // Check if current node is balanced
        if(abs(leftheight - rightheight) > 1) return -1;
        
        // Return height of current subtree
        return std::max(leftheight, rightheight) + 1;
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
    std::cout << "Is Balanced: " << (sol.isbalanced(root) ? "Yes" : "No") << std::endl;
    
    delete root;
    return 0;
}