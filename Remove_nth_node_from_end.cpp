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
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int data)
{
    Node *n = new Node(data);
    n->next = head;
    head = n;
}

void insertAtTail(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void removeFromEnd(Node *&head, int n)
{
    Node *left = head;
    Node *right = head;
    Node *toDelete;
    for (int i = 0; i < n; i++)
    {
        right = right->next;
    }
    if (right == NULL)
    {
        toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    while (right->next != NULL)
    {
        left = left->next;
        right = right->next;
    }
    toDelete = left->next;
    left->next = toDelete->next;
    delete toDelete;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    removeFromEnd(head, 4);
    print(head);
}