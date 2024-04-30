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

int main()
{
    Node *node1 = new Node(1);
    Node *head1 = node1;
    Node *tail1 = node1;
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 4);
    Node *node2 = new Node(1);
    Node *head2 = node2;
    Node *tail2 = node2;
    insertAtTail(tail2, 3);
    insertAtTail(tail2, 4);
    Node *node3 = new Node(0);
    Node *head3 = node3;
    Node *tail3 = node3;
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data < head2->data)
        {
            insertAtTail(tail3, head1->data);
            head1 = head1->next;
        }
        else
        {
            insertAtTail(tail3, head2->data);
            head2 = head2->next;
        }
    }
    while (head1 != nullptr)
    {
        insertAtTail(tail3, head1->data);
        head1 = head1->next;
    }
    while (head2 != nullptr)
    {
        insertAtTail(tail3, head2->data);
        head2 = head2->next;
    }
    print(head3);
}