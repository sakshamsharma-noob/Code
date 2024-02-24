#include <bits/stdc++.h>
using namespace std;

// Node Creation.
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int Calcht(Node *root)
{
    if (root == NULL)
        return 0;
    int Lheight = Calcht(root->left);
    int Rheight = Calcht(root->right);
    return max(Lheight, Rheight) + 1;
}
int main()
{

    //  Tree Creation.
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Calling function.
    cout << Calcht(root) <<" \n ";

    return 0;
}