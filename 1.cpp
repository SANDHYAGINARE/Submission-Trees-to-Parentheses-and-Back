// binary tree to parenthesis string

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};

void treeToParens(Node *root, string &str)
{
    if (root == NULL)
        return;

    str.push_back(root->data + '0');

    if (!root->left && !root->right)
    {
        return;
    }

    str.push_back('(');
    treeToParens(root->left, str);
    str.push_back(')');

    if (root->right)
    {
        str.push_back('(');
        treeToParens(root->right, str);
        str.push_back(')');
    }
}

int main()
{
    /*
             1
            / \
            2 3
           / \ \
           4 5 6                           */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    string str = "";
    treeToParens(root, str);
    cout << str;
}