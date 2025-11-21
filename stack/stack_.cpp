#include <iostream>
using namespace std;

class Stack {
private:
    int st[10];          // Array to store stack elements
    int top;             // Points to the top element of stack
    int max_size;        // Maximum capacity of stack
    
public:
    // Constructor to initialize stack
    Stack() {
        top = -1;        // -1 indicates empty stack
        max_size = 10;
    }
    
    // Push: Add an element to the top of stack
    void push(int x) {
        // Check if stack is full
        if (top == max_size - 1) {
            cout << "Stack Overflow! Stack is full" << endl;
            return;
        }
        // Increment top and add element
        top++;
        st[top] = x;
        cout << x << " pushed to stack" << endl;
    }
    
    // Pop: Remove an element from the top of stack
    void pop() {
        // Check if stack is empty
        if (top == -1) {
            cout << "Stack Underflow! Stack is empty" << endl;
            return;
        }
        // Remove element and decrement top
        cout << st[top] << " popped from stack" << endl;
        top--;
    }
    
    // Top: Return the top element without removing it
    int peek() {
        // Check if stack is empty
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1; // Return dummy value
        }
        return st[top];
    }
    
    // Size: Return current number of elements in stack
    int size() {
        return top + 1;  // top is 0-indexed, so add 1
    }
    
    // Empty: Check if stack is empty
    bool empty() {
        return top == -1;
    }
    
    // Display: Print all elements in stack from bottom to top
    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (bottom to top): ";
        for (int i = 0; i <= top; i++) {
            cout << st[i] << " ";
        }
        cout << endl;
    }
    
    // Display stack from top to bottom
    void displayReverse() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << st[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    
    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    
    // Display stack
    s.display();
    s.displayReverse();
    
    // Get top element
    cout << "Top element: " << s.peek() << endl;
    cout << "Size: " << s.size() << endl;
    
    // Pop elements
    s.pop();
    s.pop();
    
    // Display after pop
    s.display();
    cout << "Top element: " << s.peek() << endl;
    cout << "Size: " << s.size() << endl;
    
    // Check if empty
    if (s.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }
    
    // Pop remaining elements
    s.pop();
    s.pop();
    
    // Try to pop from empty stack
    s.pop();
    
    // Check if empty now
    if (s.empty()) {
        cout << "Stack is empty" << endl;
    }
    
    return 0;
}