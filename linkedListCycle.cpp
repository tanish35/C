#include <bits/stdc++.h>
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

void FindCycle(Node *&head)
{
    unordered_set<Node *> s;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (s.find(temp) != s.end())
        {
            cout << "Cycle exists";
            return;
        }
        s.insert(temp);
        temp = temp->next;
    }
}

int main()
{
    Node *node1 = new Node(0);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    Node *temp = tail;
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    print(head);
    // tail->next = temp;
    FindCycle(head);
    return 0;
}