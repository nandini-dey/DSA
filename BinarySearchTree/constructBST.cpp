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
Node* sortearray2BST(int arr[],int start, int end){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);
    root->left = sortearray2BST(arr,start,mid-1);
    root->right = sortearray2BST(arr,mid+1,end);
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
    int arr[]={10,20,30,40,50};
    Node* root = sortearray2BST(arr,0,4);
    preorderprint(root);
    return 0;
}