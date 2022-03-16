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
Node* inordersuccessor(Node* root){
    Node* curr= root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}
Node* DeleteBST(Node* root,int key){
    if(root->data > key){
        root->left = DeleteBST(root->left,key);
    }
    else if(root->data < key){
        root->right = DeleteBST(root->right,key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = inordersuccessor(root->right);
        root->data = temp->data;
        root->right = DeleteBST(root->right,temp->data);
    }
    return root;
}
void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    inorder(root);
    root=DeleteBST(root,5);
    cout<<"\n";
    inorder(root);
    return 0;
}