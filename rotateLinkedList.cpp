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

void rotateLinkedList(Node *&head, int k)
{
    Node *temp = head;
    int c = 0;
    while (temp != nullptr)
    {
        c++;
        temp = temp->next;
    }
    k = k % c;
    Node *p1 = head;
    Node *p2 = head;
    for (int i = 0; i < k; i++)
    {
        p2 = p2->next;
    }
    cout << p1->data << ' ' << p2->data << endl;
    while (p2->next != nullptr)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    p2->next = head;
    head = p1->next;
    p1->next = nullptr;
}

int main()
{
    Node *node1 = new Node(0);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    // insertAtTail(tail, 4);
    // insertAtTail(tail, 5);
    rotateLinkedList(head, 4);
    print(head);
}