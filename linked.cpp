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

void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
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

void deleteNode(Node *&head, Node *&tail, int position)
{
    Node *temp = head;
    if (position == 0)
    {
        head = temp->next;
        cout << "You have successfully deleted " << temp->data << endl;
        delete temp;
        return;
    }
    int i = 1;
    while (i < position)
    {
        temp = temp->next;
        i++;
        if (temp->next == NULL)
        {
            cout << "Position not found" << endl;
            return;
        }
    }

    if (temp->next == tail)
    {
        tail = temp;
    }

    // if (temp == NULL || temp->next == NULL)
    // {
    //     return;
    // }
    Node *del = temp->next;
    cout << "You have successfully deleted " << del->data << endl;
    temp->next = del->next;
    delete del;
}

void insertAtMiddle(Node *&head, Node *&tail, int data, int p)
{
    Node *newNode = new Node(data);
    Node *temp = head;
    if (p == 0)
    {
        insertAtHead(head, data);
        return;
    }
    int i = 1;
    while (i < p)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    if (temp->next == NULL)
    {
        tail = newNode;
    }
    temp->next = newNode;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    // print(head);
    insertAtMiddle(head, tail, 15, 1);
    print(head);
    cout << endl;
    deleteNode(head, tail, 3);
    print(head);
    cout << endl;
    cout << head->data << endl;
    cout << tail->data << endl;
}