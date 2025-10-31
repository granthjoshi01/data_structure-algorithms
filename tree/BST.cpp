#include <stdio.h>
#include <stdlib.h>

/* Node structure for BST */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/* Create a new node and return its pointer (NULL on allocation failure) */
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

/* Iterative insert into BST (avoids deep recursion) */
/* If value already exists, function does not insert duplicates. */
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    struct Node* parent = NULL;
    struct Node* curr = root;

    while (curr != NULL) {
        parent = curr;
        if (value < curr->data)
            curr = curr->left;
        else if (value > curr->data)
            curr = curr->right;
        else {
            /* duplicate value — do not insert */
            printf("Value %d already exists in BST. Skipping duplicate.\n", value);
            return root;
        }
    }

    struct Node* newNode = createNode(value);
    if (newNode == NULL) return root; /* allocation failed, return unchanged tree */

    if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

/* Inorder traversal (prints sorted order) */
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* Free all nodes (postorder) */
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    struct Node* root = NULL;
    int n;

    printf("Enter number of nodes to insert in BST: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of nodes. Exiting.\n");
        return 1;
    }

    printf("Enter %d integer values (space/newline separated):\n", n);
    for (int i = 0; i < n; ) {
        int value;
        if (scanf("%d", &value) != 1) {
            /* clear invalid input */
            fprintf(stderr, "Invalid input detected. Please enter integers only.\n");
            int c;
            while ((c = getchar()) != EOF && c != '\n'); /* flush line */
            continue;
        }
        root = insert(root, value);
        i++;
    }

    printf("\nInorder Traversal of Constructed BST: ");
    inorder(root);
    printf("\n");

    freeTree(root); /* clean up allocated memory */
    return 0;
}
