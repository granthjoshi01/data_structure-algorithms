#include <iostream>
#include <queue>
#include <vector>

/**
 * @struct TreeNode
 * @brief Represents a node in a binary tree.
 */
struct TreeNode {
    int data;               ///< Value stored in the node
    TreeNode* left;         ///< Pointer to the left child
    TreeNode* right;        ///< Pointer to the right child

    /**
     * @brief Constructs a node with the given value.
     * @param val The value to store in the node.
     */
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}

    /**
     * @brief Destructor to free memory of child nodes.
     */
    ~TreeNode() {
        delete left;
        delete right;
    }
};

/**
 * @brief Performs a preorder traversal of a binary tree (root -> left -> right).
 * @param root Pointer to the root node of the tree or subtree.
 */
void pre_traversal(TreeNode* root) {
    if (root == nullptr) return;
    std::cout << root->data << " ";
    pre_traversal(root->left);
    pre_traversal(root->right);
}

/**
 * @brief Performs an inorder traversal of a binary tree (left -> root -> right).
 * @param root Pointer to the root node of the tree or subtree.
 */
void in_traversal(TreeNode* root) {
    if (root == nullptr) return;
    in_traversal(root->left);
    std::cout << root->data << " ";
    in_traversal(root->right);
}

/**
 * @brief Performs a postorder traversal of a binary tree (left -> right -> root).
 * @param root Pointer to the root node of the tree or subtree.
 */
void post_traversal(TreeNode* root) {
    if (root == nullptr) return;
    post_traversal(root->left);
    post_traversal(root->right);
    std::cout << root->data << " ";
}

/**
 * @brief Performs a level-order (breadth-first) traversal of a binary tree.
 * @param root Pointer to the root node of the tree.
 * @return A vector of vectors, where each inner vector contains the node values at a given level.
 */
std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> levels; // Stores nodes level by level
    if (root == nullptr) return levels;    // Return empty vector for empty tree
    std::queue<TreeNode*> q;              // Queue for BFS
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();         // Number of nodes at current level
        std::vector<int> currentLevel;    // Nodes at current level
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->data);
            if (node->left) q.push(node->left);   // Add left child to queue
            if (node->right) q.push(node->right); // Add right child to queue
        }
        levels.push_back(currentLevel);
    }
    return levels;
}

/**
 * @brief Main function to test binary tree traversal implementations.
 * @return 0 on successful execution.
 */
int main() {
    // Test Case 1: Standard tree with multiple levels
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Test Case 1: Standard Tree\n";
    std::cout << "Preorder: "; pre_traversal(root); std::cout << "\n";
    std::cout << "Inorder: "; in_traversal(root); std::cout << "\n";
    std::cout << "Postorder: "; post_traversal(root); std::cout << "\n";
    std::cout << "Level Order Traversal:\n";
    std::vector<std::vector<int>> result = levelOrder(root);
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << "Level " << i << ": [";
        for (size_t j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j];
            if (j < result[i].size() - 1) std::cout << ", ";
        }
        std::cout << "]\n";
    }

    // Clean up memory
    delete root;

    // Test Case 2: Empty tree
    std::cout << "\nTest Case 2: Empty Tree\n";
    std::cout << "Level Order Levels: " << levelOrder(nullptr).size() << "\n";

    // Test Case 3: Single node tree
    TreeNode* single = new TreeNode(1);
    std::cout << "\nTest Case 3: Single Node Tree\n";
    std::cout << "Preorder: "; pre_traversal(single); std::cout << "\n";
    std::cout << "Inorder: "; in_traversal(single); std::cout << "\n";
    std::cout << "Postorder: "; post_traversal(single); std::cout << "\n";
    std::vector<std::vector<int>> singleResult = levelOrder(single);
    for (size_t i = 0; i < singleResult.size(); i++) {
        std::cout << "Level " << i << ": [";
        for (size_t j = 0; j < singleResult[i].size(); j++) {
            std::cout << singleResult[i][j];
            if (j < singleResult[i].size() - 1) std::cout << ", ";
        }
        std::cout << "]\n";
    }

    // Clean up memory
    delete single;
    return 0;
}
