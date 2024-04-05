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

void insertAtHead(Node *&tail, Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

void insertAtTail(Node *&tail, Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, head, 20);
    insertAtTail(tail, head, 30);
    insertAtTail(tail, head, 40);
    print(head);
}