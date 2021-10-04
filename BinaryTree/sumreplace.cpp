#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preorder(Node *root)
{
    if (root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void ReplaceNode(Node* root)
{
    if(root==NULL){
        return;
    }
    ReplaceNode(root->left);
    ReplaceNode(root->right);
    if(root->left!=NULL)
    {
        root->data += root->left->data;
    }
    if(root->right!= NULL)
    {
        root->data += root->right->data;
    }
}



int main()
{
    struct Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->right = new Node(50);
    root->right->left = new Node(40);
    root->left->left = new Node (15);
    root->left->right = new Node (17);
    preorder(root);
    cout<<endl;
    ReplaceNode(root);
    preorder(root);
    return 0;
}