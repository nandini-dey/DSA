#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right= NULL;
    }
};
Node* lca(Node *root,int n1,int n2){
    if(root==NULL){
    return NULL;
    }
    if ((root->data==n1)||(root->data==n2)){
    return root;
    }
    Node* left = lca(root->left,n1,n2);
    Node* right= lca(root->right,n1,n2);
    if(left !=NULL && right != NULL){
        return root;
    }
    if(left == NULL && right == NULL){
        return NULL;
    }
    if(left!=NULL){
        return(lca(root->left,n1,n2));
    }
    return(lca(root->right,n1,n2));
}
int finddist(Node *root,int k,int D){
    if(root==NULL){
        return -1;
    }
    if(root->data==k){
        return D;
    }

    int left = finddist(root->left,k,D+1);
    if(left!=-1){
        return left;
    }
    return (finddist(root->right,k,D+1));
}
int dist(Node* root, int n1, int n2){
    Node* LCA=lca(root,n1,n2);
    int d1 = finddist(LCA,n1,0);
    int d2 = finddist(LCA,n2,0);
    return d1+d2;
}
int main()
{
    Node *root = new Node(1);
     root->left = new Node(2);
     root->right = new Node(3);
     root->left->left = new Node(4);
     root->right->right = new Node(5);
     cout << dist(root,4,5) << endl;
     return 0;
}