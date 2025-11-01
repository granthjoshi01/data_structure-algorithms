#include <stdio.h>
#include <stdlib.h>

// Function to search index of a value in Inorder[]
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Function to print Postorder from Inorder and Preorder
void buildPostorder(int inorder[], int preorder[], int start, int end, int* preIndex) {
    if (start > end)
        return;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    int rootIndex = search(inorder, start, end, rootVal);

    // Left subtree
    buildPostorder(inorder, preorder, start, rootIndex - 1, preIndex);
    // Right subtree
    buildPostorder(inorder, preorder, rootIndex + 1, end, preIndex);
    // Print root (postorder)
    printf("%d ", rootVal);
}

int main() {
    int inorder[] = {4, 2, 5, 1, 3, 6};
    int preorder[] = {1, 2, 4, 5, 3, 6};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;

    printf("Postorder traversal: ");
    buildPostorder(inorder, preorder, 0, n - 1, &preIndex);
    printf("\n");

    return 0;
}
