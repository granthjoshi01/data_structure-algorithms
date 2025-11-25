#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> stack1;  // For enqueue operations
    stack<int> stack2;  // For dequeue operations

public:
    // Insert an element at the rear of the queue (enqueue)
    void insert(int item) {
        stack1.push(item);
        cout << "Inserted " << item << " into queue" << endl;
    }
    
    // Remove and return element from the front of the queue (dequeue)
    int delete_element() {
        // If both stacks are empty, queue is empty
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty! Cannot delete." << endl;
            return -1;
        }
        
        // If stack2 is empty, transfer all elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        // Pop from stack2 (which has elements in correct order)
        int deleted_item = stack2.top();
        stack2.pop();
        cout << "Deleted " << deleted_item << " from queue" << endl;
        return deleted_item;
    }
    
    // Check if queue is empty
    bool is_empty() {
        return stack1.empty() && stack2.empty();
    }
    
    // Return front element without removing it
    int peek() {
        if (is_empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        return stack2.top();
    }
    
    // Display current queue elements
    void display() {
        if (is_empty()) {
            cout << "Queue: []" << endl;
            return;
        }
        
        cout << "Queue: [";
        
        // Create temporary stacks to avoid modifying original
        stack<int> temp1 = stack1;
        stack<int> temp2 = stack2;
        stack<int> temp_reverse;
        
        // Get elements from stack2 (already in correct order)
        while (!temp2.empty()) {
            temp_reverse.push(temp2.top());
            temp2.pop();
        }
        
        bool first = true;
        while (!temp_reverse.empty()) {
            if (!first) cout << ", ";
            cout << temp_reverse.top();
            temp_reverse.pop();
            first = false;
        }
        
        // Get elements from stack1 (need to reverse)
        while (!temp1.empty()) {
            if (!first) cout << ", ";
            cout << temp1.top();
            temp1.pop();
            first = false;
        }
        
        cout << "]" << endl;
    }
};

