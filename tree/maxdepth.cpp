/**
 * Maximum Depth of Binary Tree
 * 
 * Problem: Given the root of a binary tree, return its maximum depth.
 * The maximum depth is the number of nodes along the longest path from 
 * the root node down to the farthest leaf node.
 * 
 * Time Complexity: O(n) where n is the number of nodes
 * Space Complexity: O(h) where h is the height (recursion stack)
 */

#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * Calculates the maximum depth of a binary tree using recursion
     * 
     * @param root Pointer to the root node of the binary tree
     * @return Maximum depth of the tree (0 if tree is empty)
     * 
     * Algorithm:
     * 1. Base case: if root is NULL, return 0
     * 2. Recursively calculate depth of left subtree
     * 3. Recursively calculate depth of right subtree
     * 4. Return max of both depths + 1 (for current node)
     */
    int maxDepth(TreeNode* root) {
        // Base case: empty tree has depth 0
        if (root == NULL) {
            return 0;
        }
        
        // Recursively find depth of left subtree
        int leftDepth = maxDepth(root->left);
        
        // Recursively find depth of right subtree
        int rightDepth = maxDepth(root->right);
        
        // Return the maximum of both depths plus 1 for current node
        return max(leftDepth, rightDepth) + 1;
    }
};

/**
 * Helper function to delete the tree and free memory
 */
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;
    
    // Example 1: Create tree [3,9,20,null,null,15,7]
    //        3
    //       / \
    //      9  20
    //        /  \
    //       15   7
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    
    cout << "Example 1:" << endl;
    cout << "Tree structure: [3,9,20,null,null,15,7]" << endl;
    cout << "Maximum Depth: " << solution.maxDepth(root1) << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Example 2: Create tree [1,null,2]
    //        1
    //         \
    //          2
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    
    cout << "Example 2:" << endl;
    cout << "Tree structure: [1,null,2]" << endl;
    cout << "Maximum Depth: " << solution.maxDepth(root2) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Example 3: Empty tree
    TreeNode* root3 = nullptr;
    
    cout << "Example 3:" << endl;
    cout << "Tree structure: []" << endl;
    cout << "Maximum Depth: " << solution.maxDepth(root3) << endl;
    cout << "Expected: 0" << endl << endl;
    
    // Example 4: Single node
    TreeNode* root4 = new TreeNode(1);
    
    cout << "Example 4:" << endl;
    cout << "Tree structure: [1]" << endl;
    cout << "Maximum Depth: " << solution.maxDepth(root4) << endl;
    cout << "Expected: 1" << endl;
    
    // Clean up memory
    deleteTree(root1);
    deleteTree(root2);
    deleteTree(root4);
    
    return 0;
}

/**
 * Compilation and Execution:
 * 
 * To compile: g++ -std=c++11 max_depth.cpp -o max_depth
 * To run: ./max_depth
 * 
 * Expected Output:
 * Example 1:
 * Tree structure: [3,9,20,null,null,15,7]
 * Maximum Depth: 3
 * Expected: 3
 * 
 * Example 2:
 * Tree structure: [1,null,2]
 * Maximum Depth: 2
 * Expected: 2
 * 
 * Example 3:
 * Tree structure: []
 * Maximum Depth: 0
 * Expected: 0
 * 
 * Example 4:
 * Tree structure: [1]
 * Maximum Depth: 1
 * Expected: 1
 */