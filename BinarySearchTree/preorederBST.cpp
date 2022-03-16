#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* constructBST(int preorder[] ,int* preorderindex, int key,int min,int max,int n){
    if(*preorderindex >= n ){
        return NULL;
    }
    Node* root = NULL;
    if(key>min && key<max){
        root = new Node(key);
        *preorderindex = *preorderindex+1;

        if(*preorderindex<n){
            root->left = constructBST(preorder,preorderindex,preorder[*preorderindex],min,key,n);
            if(*preorderindex<n){
                root->right = constructBST(preorder,preorderindex,preorder[*preorderindex],key,max,n);
            }
        }
    }
    return root;
}
void preorderprint(Node* root){
    if(root==NULL){
        return;
    }
cout<<root->data<<" ";
preorderprint(root->left);
preorderprint(root->right);
}
int main(){
    int preorder[]={10,2,1,13,11};
    int n=5;
    int preorederindex = 0;
    Node* root = constructBST(preorder, &preorederindex, preorder[0], INT8_MIN,INT8_MAX,n);
    preorderprint(root);
    return 0;
}