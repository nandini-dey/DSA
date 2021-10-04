#include<iostream>
using namespace std;
struct Node
{
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
int heightNode(Node* root)
{
    if(root==NULL){return 0;}
    else return max(heightNode(root->left),heightNode(root->right))+1;
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(5);
    root->right->left = new Node(4);
    root->left->left = new Node (6);
    root->left->right = new Node (7);
    root->left->right->left = new Node (7);
    cout<<heightNode(root);
    return 0;
}