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

void addTwoNumbers(Node *&l1, Node *&l2)
{
    Node *dummy = new Node(0);
    Node *t1 = l1;
    Node *t2 = l2;
    int c = 0;
    Node *curr = dummy;
    int sum = 0;
    while (t1 != nullptr || t2 != nullptr)
    {
        if (t1 != = nullptr && t2 != nullptr)
        {
            sum = t1->data + t2->data + c;
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1 != nullptr)
        {
            sum = t1->data + c;
            t1 = t1->next;
        }
        else if (t2 != nullptr)
        {
            sum = t2->data + c;
            t2 = t2->next;
        }
        c = sum / 10;
        Node *newNode = new Node(sum % 10);
        curr->next = newNode;
        curr = curr->next;
        sum = 0;
    }
    if (c > 0)
    {
        Node *newNode = new Node(c);
        curr->next = newNode;
        curr = curr->next;
    }
}

int main()
{
}