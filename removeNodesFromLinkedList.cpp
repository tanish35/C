#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << ' ';
        cout << temp << endl;
        temp = temp->next;
    }
}

void insertAtTail(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void reverse(Node *&head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void removeNodes(Node *&head)
{
    reverse(head);
    int max = head->data;
    Node *curr = head;
    Node *next = head->next;
    while (next != nullptr)
    {
        if (next->data < max)
        {
            curr->next = next->next;
            next = curr->next;
        }
        else
        {
            max = next->data;
            curr = next;
            next = next->next;
        }
    }
    reverse(head);
}

int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 13);
    insertAtTail(tail, 3);
    insertAtTail(tail, 8);
    // print(head);
    removeNodes(head);
    print(head);
}