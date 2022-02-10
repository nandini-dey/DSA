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

void printsubtree(Node* root, int k){
    if(root == NULL || k<0){
        return;
    }
    if(k==0){
        cout<< root->data <<endl;
        return;
    }
    printsubtree(root->left, k-1);
    printsubtree(root->right, k-1);
}

int printnodesatk(Node* root, Node* target, int k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        printsubtree(root,k);
        return 0;
    }
    int dl= printnodesatk(root->left,target,k);
    while(dl != -1){
        if(dl+1 == k){
            cout<< root->data<< " ";
        }else{
            printsubtree(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr= printnodesatk(root->right,target,k);
    while(dr != -1){
        if(dr+1 == k){
            cout<< root->data<< " ";
        }else{
            printsubtree(root->left,k-dl-2);
        }
        return 1+dr;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    printnodesatk(root,root->left,1);
    return 0;
}