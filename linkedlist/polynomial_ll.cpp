#include <iostream>
using namespace std;

// Node structure to store one term of polynomial
// Example: for term 5x^2, coeff=5 and exp=2
struct Node {
    int coeff;  // coefficient (number before x)
    int exp;    // exponent (power of x)
    Node* next; // pointer to next term in the list
};

// Function to create a new node
// Parameters: c = coefficient, e = exponent
// Returns: pointer to the newly created node
Node* createNode(int c, int e) {
    Node* newNode = new Node;  // Allocate memory for new node
    newNode->coeff = c;        // Set coefficient
    newNode->exp = e;          // Set exponent
    newNode->next = NULL;      // Initially points to nothing
    return newNode;            // Return the new node
}

// Function to insert a term at the end of the polynomial
// Parameters: head = pointer to pointer of first node
//             c = coefficient, e = exponent
void insertTerm(Node** head, int c, int e) {
    Node* newNode = createNode(c, e);  // Create new node with given values
    
    // Case 1: If list is empty, make new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Case 2: List is not empty, traverse to the last node
    Node* temp = *head;              // Start from head
    while (temp->next != NULL) {     // Keep moving until last node
        temp = temp->next;
    }
    
    // Add new node at the end
    temp->next = newNode;
}

// Function to display the polynomial
// Parameter: head = pointer to first node
void display(Node* head) {
    // If polynomial is empty
    if (head == NULL) {
        cout << "0";
        return;
    }
    
    Node* temp = head;  // Start from first term
    
    // Traverse through all terms
    while (temp != NULL) {
        // Print current term in format: coeffx^exp
        cout << temp->coeff << "x^" << temp->exp;
        
        // Add " + " between terms (but not after last term)
        if (temp->next != NULL) {
            cout << " + ";
        }
        
        temp = temp->next;  // Move to next term
    }
    cout << endl;
}

int main() {
    Node* poly = NULL;  // Initialize empty polynomial
    
    // Create polynomial: 5x^2 + 4x^1 + 2x^0
    cout << "Polynomial: ";
    
    insertTerm(&poly, 5, 2);  // Insert term 5x^2
    insertTerm(&poly, 4, 1);  // Insert term 4x^1
    insertTerm(&poly, 2, 0);  // Insert term 2x^0 (constant term)
    
    display(poly);  // Display the complete
}