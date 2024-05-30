#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr, *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

void preOrder(Node *&root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

void inOrder(Node *&root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *&root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    preOrder(root);
    return 0;
}
