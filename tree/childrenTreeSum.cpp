#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void changeTree(TreeNode<int>* root) {
        if (root == NULL) return;
        
        int child = 0;
        if (root->left) {
            child += root->left->data;
        }
        if (root->right) {
            child += root->right->data;
        }
        
        if (child >= root->data) {
            root->data = child;
        } else {
            // Distribute parent's value to children
            if (root->left) {
                root->left->data = root->data;
            } else if (root->right) {
                root->right->data = root->data;
            }
        }
        
        // Recursively process left and right subtrees
        changeTree(root->left);
        changeTree(root->right);
        
        // Update current node after children are processed
        int total = 0;
        if (root->left) {
            total += root->left->data;
        }
        if (root->right) {
            total += root->right->data;
        }
        // Only update if node has children
        if (root->left || root->right) {
            root->data = total;
        }
    }
};

// Utility function to print tree (level order)
void printLevelOrder(TreeNode<int>* root) {
    if (!root) return;
    
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode<int>* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }
}

// Utility to check if tree satisfies children sum property
bool isSumProperty(TreeNode<int>* root) {
    if (!root || (!root->left && !root->right))
        return true;
    
    int leftVal = (root->left) ? root->left->data : 0;
    int rightVal = (root->right) ? root->right->data : 0;
    
    return (root->data == leftVal + rightVal) &&
           isSumProperty(root->left) &&
           isSumProperty(root->right);
}

int main() {
    Solution sol;
    
    // Example 1
    cout << "=== Example 1 ===" << endl;
    TreeNode<int>* root1 = new TreeNode<int>(2);
    root1->left = new TreeNode<int>(35);
    root1->right = new TreeNode<int>(10);
    root1->left->left = new TreeNode<int>(2);
    root1->left->right = new TreeNode<int>(3);
    root1->right->left = new TreeNode<int>(5);
    root1->right->right = new TreeNode<int>(2);
    
    cout << "Before:" << endl;
    printLevelOrder(root1);
    cout << "Satisfies property: " << (isSumProperty(root1) ? "Yes" : "No") << endl;
    
    sol.changeTree(root1);
    
    cout << "\nAfter:" << endl;
    printLevelOrder(root1);
    cout << "Satisfies property: " << (isSumProperty(root1) ? "Yes" : "No") << endl;
    
    // Example 2
    cout << "\n=== Example 2 ===" << endl;
    TreeNode<int>* root2 = new TreeNode<int>(50);
    root2->left = new TreeNode<int>(7);
    root2->right = new TreeNode<int>(2);
    root2->left->left = new TreeNode<int>(3);
    root2->left->right = new TreeNode<int>(5);
    root2->right->left = new TreeNode<int>(1);
    root2->right->right = new TreeNode<int>(30);
    
    cout << "Before:" << endl;
    printLevelOrder(root2);
    
    sol.changeTree(root2);
    
    cout << "\nAfter:" << endl;
    printLevelOrder(root2);
    cout << "Satisfies property: " << (isSumProperty(root2) ? "Yes" : "No") << endl;
    
    // Example 3
    cout << "\n=== Example 3 ===" << endl;
    TreeNode<int>* root3 = new TreeNode<int>(10);
    root3->left = new TreeNode<int>(5);
    root3->right = new TreeNode<int>(3);
    
    cout << "Before:" << endl;
    printLevelOrder(root3);
    
    sol.changeTree(root3);
    
    cout << "\nAfter:" << endl;
    printLevelOrder(root3);
    cout << "Satisfies property: " << (isSumProperty(root3) ? "Yes" : "No") << endl;
    
    return 0;
}