#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}
    
    bool isEmpty() {
        return top == nullptr;
    }
    
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }
    
    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack Underflow");
        }
        Node* temp = top;
        int popped = top->data;
        top = top->next;
        delete temp;
        return popped;
    }
    
    int peek() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return top->data;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }
    
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Usage
int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    cout << "Popped: " << stack.pop() << endl;
    cout << "Top: " << stack.peek() << endl;
    return 0;
}
