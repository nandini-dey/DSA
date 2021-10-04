#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* leftchild;
    struct Node* rightchild;

    Node(int val)
    {
        data = val;
        leftchild = NULL;
        rightchild = NULL;
    }
};
void preorder(Node *root)
{
    if (root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}
void inorder(Node *root)
{
    if (root!=NULL)
    {
        inorder(root->leftchild);
        cout<<root->data<<" ";
        inorder(root->rightchild);
    }
}
void postorder(Node* root)
{   
    if(root!=NULL)
    {
        postorder(root->leftchild);
        postorder(root->rightchild);
        cout<<root->data<<" ";
    }
}

int main()
{
    struct Node* root = new Node(10);
    root->leftchild = new Node(20);
    root->rightchild = new Node(30);
    root->rightchild->rightchild = new Node(50);
    root->rightchild->leftchild = new Node(40);
    root->leftchild->leftchild = new Node (15);
    root->leftchild->rightchild = new Node (17);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}