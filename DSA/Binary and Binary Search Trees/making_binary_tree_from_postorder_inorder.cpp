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

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end;i++){
        if(inorder[i]==curr){
            return i;
            // i is the position.
        }
    }
    return -1; // This case will not come because curr will always be there in array.
}

Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
        return NULL;
    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);
    if (start == end)
        return node;
    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder, inorder, start, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);
    return node;
}

void inorderprint(Node* root){
    if(root==NULL)
        return;
    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    // Build the tree.
    Node* root = buildTree(preorder, inorder, 0, 4);

    // Inorder print
    inorderprint(root);
    return 0;
}