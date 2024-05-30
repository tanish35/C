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
    unordered_map<Node *, int> mp;
    Node *temp = head;
    int c = 1;
    while (temp != nullptr)
    {
        if (mp[temp])
        {
            cout << mp[temp] - 1 << endl;
            return;
        }
        mp[temp] = c;
        temp = temp->next;
        c++;
    }
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 2);
    Node *temp = tail;
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    tail->next = temp;
    FindCycle(head);
    return 0;
}