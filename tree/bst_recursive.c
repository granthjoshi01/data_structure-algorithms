#include <stdio.h>
#include <stdlib.h>

/**
 * Structure representing a node in the Binary Search Tree
 * 
 * @param data - Integer value stored in the node
 * @param left - Pointer to the left child node (contains smaller values)
 * @param right - Pointer to the right child node (contains larger values)
 */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/**
 * Creates and initializes a new BST node
 * 
 * Allocates memory for a new node and initializes its fields.
 * The left and right pointers are set to NULL, making it a leaf node.
 * 
 * @param data - The integer value to store in the new node
 * @return struct Node* - Pointer to the newly created node
 * 
 * Note: Caller is responsible for freeing the allocated memory
 */
struct Node* createNode(int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Initialize node data
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

/**
 * Inserts a new element into the Binary Search Tree
 * 
 * This function maintains the BST property:
 * - Left subtree contains nodes with values less than the parent
 * - Right subtree contains nodes with values greater than the parent
 * - Duplicate values are not inserted
 * 
 * @param root - Pointer to the root node of the BST (can be NULL for empty tree)
 * @param data - The integer value to insert into the BST
 * @return struct Node* - Pointer to the root of the modified BST
 * 
 * Time Complexity: O(h) where h is the height of the tree
 *                  Best case: O(log n) for balanced tree
 *                  Worst case: O(n) for skewed tree
 * Space Complexity: O(h) due to recursive call stack
 * 
 * Example:
 *     struct Node* root = NULL;
 *     root = insert(root, 50);  // Creates root node with value 50
 *     root = insert(root, 30);  // Inserts 30 to the left of 50
 *     root = insert(root, 70);  // Inserts 70 to the right of 50
 */
struct Node* insert(struct Node* root, int data) {
    // Base case: If tree is empty or reached a leaf position, create new node
    if (root == NULL) {
        return createNode(data);
    }
    
    // Recursive case: Traverse the tree to find the correct position
    
    // If data is smaller, insert into left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If data is larger, insert into right subtree
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // If data is equal to current node's data, don't insert (no duplicates allowed)
    // Simply return the unchanged root
    
    // Return the (potentially modified) root pointer