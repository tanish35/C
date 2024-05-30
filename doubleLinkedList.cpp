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

void doubleLinkedList(Node *&head)
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *next = head->next;
    while (curr != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next != nullptr)
        {
            next = next->next;
        }
    }
    head = prev;
    int c = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data * 2 > 9)
        {
            temp->data = (temp->data * 2 + c) % 10;
            c = 1;
        }
        else
        {
            temp->data = temp->data * 2 + c;
            c = 0;
        }
        if (temp->next == nullptr && c == 1)
        {
            Node *newNode = new Node(1);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    curr = head;
    prev = nullptr;
    next = head->next;
    while (curr != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next != nullptr)
        {
            next = next->next;
        }
    }
    head = prev;
    print(head);
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 8);
    insertAtTail(tail, 9);
    doubleLinkedList(head);
    return 0;
}