/**
 * @file bst.c
 * @brief Binary Search Tree (BST) Implementation in C
 * 
 * This program implements a Binary Search Tree with iterative insertion,
 * inorder traversal, and proper memory management. It demonstrates fundamental
 * BST operations while handling edge cases like duplicate values and memory
 * allocation failures.
 * 
 * @author [Your Name]
 * @date 2025-10-31
 * @version 1.0
 * 
 * Features:
 * - Iterative insertion (avoids stack overflow from deep recursion)
 * - Duplicate value detection and rejection
 * - Robust input validation
 * - Memory leak prevention with proper cleanup
 * - Inorder traversal for sorted output
 * 
 * Compilation:
 *   gcc -Wall -Wextra -O2 bst.c -o bst
 * 
 * Usage:
 *   ./bst
 *   Enter the number of nodes, then input integer values
 * 
 * Example:
 *   Enter number of nodes to insert in BST: 5
 *   Enter 5 integer values (space/newline separated):
 *   50 30 70 20 40
 *   Inorder Traversal of Constructed BST: 20 30 40 50 70
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct Node
 * @brief Represents a single node in the Binary Search Tree
 * 
 * Each node contains:
 * - An integer data value
 * - A pointer to the left child (values less than current node)
 * - A pointer to the right child (values greater than current node)
 */
struct Node {
    int data;              /**< Integer value stored in the node */
    struct Node* left;     /**< Pointer to left subtree (smaller values) */
    struct Node* right;    /**< Pointer to right subtree (larger values) */
};

/**
 * @brief Creates a new BST node with the given value
 * 
 * Allocates memory for a new node and initializes its fields.
 * Both left and right child pointers are set to NULL.
 * 
 * @param value The integer value to store in the new node
 * @return Pointer to the newly created node, or NULL if allocation fails
 * 
 * @note Caller is responsible for eventually freeing the allocated memory
 * @warning Prints error message to stderr if malloc fails
 */
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
 * @brief Inserts a new value into the BST using iterative approach
 * 
 * Iteratively traverses the tree to find the correct position for insertion.
 * This approach avoids potential stack overflow issues with deeply unbalanced
 * trees that could occur with recursive insertion.
 * 
 * BST Property Maintained:
 * - All values in left subtree < node value
 * - All values in right subtree > node value
 * 
 * @param root Pointer to the root node of the BST
 * @param value The integer value to insert
 * @return Pointer to the root of the modified BST
 * 
 * @note Duplicate values are not inserted; a message is printed instead
 * @note If memory allocation fails, the tree remains unchanged
 * 
 * Time Complexity: O(h) where h is the height of the tree
 * Space Complexity: O(1) - iterative approach uses constant space
 */
struct Node* insert(struct Node* root, int value) {
    /* Handle empty tree case */
    if (root == NULL) {
        return createNode(value);
    }
    
    struct Node* parent = NULL;
    struct Node* curr = root;
    
    /* Traverse to find insertion point */
    while (curr != NULL) {
        parent = curr;
        if (value < curr->data)
            curr = curr->left;
        else if (value > curr->data)
            curr = curr->right;
        else {
            /* Duplicate value — do not insert */
            printf("Value %d already exists in BST. Skipping duplicate.\n", value);
            return root;
        }
    }
    
    /* Create new node and link to parent */
    struct Node* newNode = createNode(value);
    if (newNode == NULL) return root; /* Allocation failed, return unchanged tree */
    
    if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    
    return root;
}

/**
 * @brief Performs inorder traversal of the BST (Left-Root-Right)
 * 
 * Recursively traverses the tree in sorted order:
 * 1. Visit left subtree
 * 2. Process current node (print value)
 * 3. Visit right subtree
 * 
 * For a valid BST, this produces output in ascending sorted order.
 * 
 * @param root Pointer to the root node of the BST (or subtree)
 * 
 * Time Complexity: O(n) where n is the number of nodes
 * Space Complexity: O(h) due to recursion stack, where h is tree height
 * 
 * @note Prints values separated by spaces to stdout
 */
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/**
 * @brief Frees all memory allocated for the BST
 * 
 * Uses postorder traversal (Left-Right-Root) to safely deallocate all nodes.
 * Children must be freed before freeing the parent to avoid memory leaks
 * and dangling pointers.
 * 
 * @param root Pointer to the root node of the BST to be freed
 * 
 * Time Complexity: O(n) where n is the number of nodes
 * Space Complexity: O(h) due to recursion stack, where h is tree height
 * 
 * @warning After calling this function, the root pointer becomes invalid
 * @note Safe to call with NULL pointer (no operation performed)
 */
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/**
 * @brief Main function - Entry point of the program
 * 
 * Workflow:
 * 1. Prompts user for number of nodes to insert
 * 2. Validates input (must be positive integer)
 * 3. Reads n integer values from user
 * 4. Inserts each value into the BST
 * 5. Displays inorder traversal (sorted output)
 * 6. Cleans up all allocated memory
 * 
 * Input Validation:
 * - Checks for valid integer input
 * - Rejects non-positive node counts
 * - Handles invalid input gracefully with error messages
 * - Continues prompting until valid input received
 * 
 * @return 0 on successful execution, 1 on critical error
 * 
 * Example Run:
 * @code
 * Enter number of nodes to insert in BST: 7
 * Enter 7 integer values (space/newline separated):
 * 50 30 70 20 40 60 80
 * Inorder Traversal of Constructed BST: 20 30 40 50 60 70 80
 * @endcode
 */
int main(void) {
    struct Node* root = NULL;
    int n;
    
    /* Get number of nodes from user */
    printf("Enter number of nodes to insert in BST: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of nodes. Exiting.\n");
        return 1;
    }
    
    /* Read and insert n values */
    printf("Enter %d integer values (space/newline separated):\n", n);
    for (int i = 0; i < n; ) {
        int value;
        if (scanf("%d", &value) != 1) {
            /* Clear invalid input from buffer */
            fprintf(stderr, "Invalid input detected. Please enter integers only.\n");
            int c;
            while ((c = getchar()) != EOF && c != '\n'); /* Flush line */
            continue;
        }
        root = insert(root, value);
        i++;
    }
    
    /* Display the constructed BST in sorted order */
    printf("\nInorder Traversal of Constructed BST: ");
    inorder(root);
    printf("\n");
    
    /* Clean up allocated memory */
    freeTree(root);
    
    return 0;
}
