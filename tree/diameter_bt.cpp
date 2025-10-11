/**
 * @file binary_tree_diameter.cpp
 * @brief Solution to find the diameter of a binary tree
 * @details The diameter of a binary tree is the length of the longest path between
 *          any two nodes in a tree. This path may or may not pass through the root.
 *          The length of a path is represented by the number of edges between nodes.
 * 
 * Time Complexity: O(n) where n is the number of nodes
 * Space Complexity: O(h) where h is the height of the tree (recursion stack)
 * 
 * @author Your Name
 * @date 2025
 */

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/**
 * @struct TreeNode
 * @brief Definition for a binary tree node
 */
struct TreeNode {
    int val;                // Value stored in the node
    TreeNode *left;         // Pointer to left child
    TreeNode *right;        // Pointer to right child
    
    // Constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @class Solution
 * @brief Class containing solution for binary tree diameter problem
 */
class Solution {
public:
    /**
     * @brief Calculates the diameter of a binary tree
     * @param root Pointer to the root of the binary tree
     * @return The diameter (maximum number of edges in the longest path)
     */
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }

private:
    /**
     * @brief Helper function to calculate depth and update diameter
     * @param root Current node being processed
     * @param diameter Reference to variable storing maximum diameter found so far
     * @return Depth of the subtree rooted at current node
     * 
     * @details This function uses post-order traversal to:
     *          1. Calculate the depth of left and right subtrees
     *          2. Update the diameter if path through current node is longer
     *          3. Return the depth to parent node
     */
    int depth(TreeNode* root, int& diameter) {
        // Base case: empty tree has depth 0
        if (root == NULL) 
            return 0;
        
        // Recursively calculate depth of left subtree
        int lh = depth(root->left, diameter);
        
        // Recursively calculate depth of right subtree
        int rh = depth(root->right, diameter);
        
        // Update diameter if path through current node is longer
        // Path length through current node = left height + right height
        diameter = max(diameter, lh + rh);
        
        // Return depth of current subtree (max of left/right + 1 for current node)
        return 1 + max(lh, rh);
    }
};

/**
 * @brief Helper function to create a sample binary tree for testing
 * @return Pointer to root of created tree
 */
TreeNode* createSampleTree1() {
    /*
     * Creates the following tree:
     *          1
     *         / \
     *        2   3
     *       / \
     *      4   5
     * Diameter = 3 (path: 4->2->1->3 or 5->2->1->3)
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

/**
 * @brief Helper function to create another sample binary tree
 * @return Pointer to root of created tree
 */
TreeNode* createSampleTree2() {
    /*
     * Creates the following tree:
     *          1
     *         /
     *        2
     * Diameter = 1 (path: 1->2)
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    return root;
}

/**
 * @brief Helper function to delete binary tree and free memory
 * @param root Pointer to root of tree to be deleted
 */
void deleteTree(TreeNode* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

/**
 * @brief Helper function to print tree structure (level-order traversal)
 * @param root Pointer to root of tree
 */
void printTree(TreeNode* root) {
    if (root == NULL) {
        cout << "Empty tree" << endl;
        return;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    cout << "Tree structure (level-order): ";
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

/**
 * @brief Main function demonstrating the solution
 */
int main() {
    Solution solution;
    
    // Test Case 1
    cout << "=== Test Case 1 ===" << endl;
    TreeNode* tree1 = createSampleTree1();
    printTree(tree1);
    int diameter1 = solution.diameterOfBinaryTree(tree1);
    cout << "Diameter: " << diameter1 << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Test Case 2
    cout << "=== Test Case 2 ===" << endl;
    TreeNode* tree2 = createSampleTree2();
    printTree(tree2);
    int diameter2 = solution.diameterOfBinaryTree(tree2);
    cout << "Diameter: " << diameter2 << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test Case 3: Single node
    cout << "=== Test Case 3 ===" << endl;
    TreeNode* tree3 = new TreeNode(1);
    printTree(tree3);
    int diameter3 = solution.diameterOfBinaryTree(tree3);
    cout << "Diameter: " << diameter3 << endl;
    cout << "Expected: 0" << endl << endl;
    
    // Test Case 4: Empty tree
    cout << "=== Test Case 4 ===" << endl;
    TreeNode* tree4 = NULL;
    printTree(tree4);
    int diameter4 = solution.diameterOfBinaryTree(tree4);
    cout << "Diameter: " << diameter4 << endl;
    cout << "Expected: 0" << endl << endl;
    
    // Clean up memory
    deleteTree(tree1);
    deleteTree(tree2);
    deleteTree(tree3);
    // tree4 is NULL, no need to delete
    
    cout << "All test cases completed successfully!" << endl;
    
    return 0;
}