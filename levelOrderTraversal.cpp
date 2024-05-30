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
    cout << root->data << ' ';
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *&root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}

void postOrder(Node *&root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ' ';
}

void levelOrder(Node *&root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    unordered_map<Node *, int> m;
    q.push(root);
    m[root] = 0;
    vector<vector<int>> res;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (res.size() == m[temp])
        {
            res.push_back(vector<int>());
        }
        res[m[temp]].push_back(temp->data);
        if (temp->left)
        {
            q.push(temp->left);
            m[temp->left] = m[temp] + 1;
        }
        if (temp->right)
        {
            q.push(temp->right);
            m[temp->right] = m[temp] + 1;
        }
    }
    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << ' ';
        }
        cout << endl;
    }
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    levelOrder(root);
    return 0;
}