#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node *newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtMiddle(Node *&head, Node *&tail, int position, int data)
{
    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }
    int i = 1;
    Node *newNode = new Node(data);
    Node *temp = head;
    while (i < position)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }
    temp->next->prev = newNode;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node *&head, Node *&tail, int position)
{

    Node *temp = head;
    if (position == 0)
    {
        head = temp->next;
        delete temp;
        return;
    }
    int i = 1;
    while (i < position)
    {
        temp = temp->next;
        i++;
    }
    Node *del = temp->next;
    if (temp->next == tail)
    {
        tail = temp;
        temp->next = del->next;
        delete del;
        return;
    }
    temp->next = del->next;
    del->next->prev = temp;
    delete del;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    // print(head);
    // cout << endl;
    insertAtMiddle(head, tail, 1, 15);
    print(head);
    cout << endl;
    deleteNode(head, tail, 3);
    print(head);
    // cout << tail->data << endl;
    // cout << head->data << endl;
}