#include <iostream>
#include <cmath>
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

void findMiddle(Node *&head)
{
    int m = 0;
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        m++;
    }
    cout << m << endl;
    if (m == 0)
    {
        cout << head->data;
        return;
    }
    m = ceil((float)m / 2);
    temp = head;
    while (m--)
    {
        temp = temp->next;
    }
    cout << temp->data;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    print(head);
    findMiddle(head);
    return 0;
}