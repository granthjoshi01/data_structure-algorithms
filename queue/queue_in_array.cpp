#include <iostream>
using namespace std;

class Queue {
private:
    int q[10];           // Array to store queue elements
    int start;           // Points to the front element
    int end;             // Points to the next position to insert
    int curr_size;       // Current number of elements in queue
    int max_size;        // Maximum capacity of queue
    
public:
    // Constructor to initialize queue
    Queue() {
        start = -1;
        end = -1;
        curr_size = 0;
        max_size = 10;
    }
    
    // Enqueue: Add an element to the rear of queue
    void enqueue(int x) {
        // Check if queue is full
        if (curr_size == max_size) {
            cout << "Queue is full!" << endl;
            return;
        }
        // If queue is empty, initialize start and end
        else if (curr_size == 0) {
            start = 0;
            end = 0;
            q[end] = x;
        }
        // Add element and move end pointer (circular)
        else {
            end = (end + 1) % max_size;
            q[end] = x;
        }
        curr_size++;
        cout << x << " enqueued to queue" << endl;
    }
    
    // Dequeue: Remove an element from the front of queue
    void dequeue() {
        // Check if queue is empty
        if (curr_size == 0) {
            cout << "Queue Underflow! Queue is empty" << endl;
            return;
        }
        // If only one element, reset queue
        else if (curr_size == 1) {
            cout << q[start] << " dequeued from queue" << endl;
            start = -1;
            end = -1;
            curr_size = 0;
        }
        // Remove element and move start pointer (circular)
        else {
            cout << q[start] << " dequeued from queue" << endl;
            start = (start + 1) % max_size;
            curr_size--;
        }
    }
    
    // Front: Return the front element without removing it
    int front() {
        // Check if queue is empty
        if (curr_size == 0) {
            cout << "Queue is empty!" << endl;
            return -1; // Return dummy value
        }
        return q[start];
    }
    
    // Rear: Return the rear element
    int rear() {
        // Check if queue is empty
        if (curr_size == 0) {
            cout << "Queue is empty!" << endl;
            return -1; // Return dummy value
        }
        return q[end];
    }
    
    // Size: Return current number of elements in queue
    int size() {
        return curr_size;
    }
    
    // Empty: Check if queue is empty
    bool empty() {
        return curr_size == 0;
    }
    
    // Display: Print all elements in queue
    void display() {
        if (curr_size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = start;
        for (int count = 0; count < curr_size; count++) {
            cout << q[i] << " ";
            i = (i + 1) % max_size;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    
    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    
    // Display queue
    q.display();
    
    // Get front and rear elements
    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.rear() << endl;
    cout << "Size: " << q.size() << endl;
    
    // Dequeue elements
    q.dequeue();
    q.dequeue();
    
    // Display after dequeue
    q.display();
    cout << "Front element: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;
    
    // Check if empty
    if (q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }
    
    return 0;
}