#include <iostream>
#include <vector>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
    Node(int data1)
    {
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};
Node *convertarrtoll(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < 5; i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
}
Node *deleteNode(Node *&head, int k)
{
    if (!head)
        return nullptr; // Empty list

    Node *temp = head;
    int pos = 1;

    // Move to the k-th node
    while (temp && pos < k)
    {
        temp = temp->next;
        pos++;
    }

    // If k is out of bounds or value not found
    if (!temp)
        return head;

    // Update pointers
    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next; // Deleting head

    if (temp->next)
        temp->next->prev = temp->prev;

    delete temp; // Free memory
    return head;
}
Node *insertNode(Node *&head, int k, int data)
{
    Node *newNode = new Node(data);
    // Empty list or insert at head
    if (!head && k <= 1)
    {
        return newNode;
    }
    if (!head)
        return head; // k > 1 and empty list, invalid

    Node *temp = head;
    int pos = 1;
    // Move to the node before the insertion point
    while (temp && pos < k)
    {
        temp = temp->next;
        pos++;
    }
    // If k is out of bounds, append at the end
    if (!temp && k > pos)
    {
        temp = head;
        while (temp->next)
            temp = temp->next;
    }
    // Insert at head (k = 1 or beyond current length with early stop)
    if (pos == 1 && (k <= 1 || !temp))
    {
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        return newNode;
    }

    if (temp)
    {
        newNode->prev = temp->prev;
        newNode->next = temp;
        if (temp->prev)
            temp->prev->next = newNode;
        temp->prev = newNode;
    }
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertarrtoll(arr);
    print(head);
    deleteNode(head, 2);
    cout << "\n";
    print(head);
    insertNode(head, 2, 10);
    cout << "\n";
    print(head);
    return 0;
}
