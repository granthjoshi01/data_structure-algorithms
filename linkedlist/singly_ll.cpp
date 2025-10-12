#include <iostream>

using namespace std;

// Node class to represent each element
class Node {
public:
    int data;      // Data part
    Node* next;    // Pointer to next node

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// SinglyLinkedList class to manage the list
class SinglyLinkedList {
private:
    Node* head;    // Pointer to the first node

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }

    // Destructor to free memory
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Insert at the beginning
    void push_front(int value) {
        Node* node = new Node(value);  // Create new node
        node->next = head;
        head = node;
    }

    // Insert at the end
    void push_back(int value) {
        Node* node = new Node(value);  // Create new node
        if (head == nullptr) {
            head = node;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = node;
    }

    // Insert at specific position (0-based index)
    void insert(int value, int position) {
        if (position < 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (position == 0) {
            push_front(value);
            return;
        }
        Node* node = new Node(value);  // Create new node
        Node* current = head;
        Node* prev = nullptr;
        int currentPos = 0;
        while (current != nullptr && currentPos < position) {
            prev = current;
            current = current->next;
            currentPos++;
        }
        if (currentPos != position) {
            cout << "Position out of range!" << endl;
            delete node;  // Free memory if position is invalid
            return;
        }
        prev->next = node;
        node->next = current;
    }

    // Delete the first occurrence of a value
    void remove(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Value not found!" << endl;
            return;
        }
        prev->next = current->next;
        delete current;
    }

    // Display the list
    void display() {
        Node* current = head;
        if (current == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Example usage in main
int main() {
    SinglyLinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);

    cout << "Original list: ";
    list.display();  // Output: 5 10 20 30

    list.insert(15, 2);
    cout << "After inserting 15 at position 2: ";
    list.display();  // Output: 5 10 15 20 30

    list.remove(10);
    cout << "After removing 10: ";
    list.display();  // Output: 5 15 20 30

    list.insert(25, 5);  // Try invalid position
    // Output: Position out of range!
    list.remove(100);    // Try removing non-existent value
    // Output: Value not found!

    return 0;
}