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

void deleteNode(Node *&node)
{
    Node *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    delete temp;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    insertAtHead(head, 1);
    tail = head;
    insertAtTail(tail, 2);
    tail = tail->next;
    insertAtTail(tail, 3);
    tail = tail->next;
    insertAtTail(tail, 4);
    tail = tail->next;
    insertAtTail(tail, 5);
    tail = tail->next;
    print(head);
    cout << endl;
    deleteNode(head->next->next);
    print(head);
    return 0;
}