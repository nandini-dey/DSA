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

int search(int inorder[],int start,int end,int curr)
{
    for(int j=start;j<=end;j++){
        if (inorder[j]==curr)
        {
            return j;
        }
        
    }
    return -1;
}
void Print_inorder(Node *root)
{
    if (root!=NULL)
    {
        Print_inorder(root->left);
        cout<<root->data<<" ";
        Print_inorder(root->right);
    }
}
Node* buildtree(int postorder[],int inorder[],int start,int end)
{
    static int i=6;//(array_size - 1)
    if(start>end){
        return NULL;
    }
    int posval = postorder[i];
    i--;
    Node* node = new Node(posval);
    if(start==end){
        return node;
    }
    int pos = search(inorder,start,end,posval);
    node->right = buildtree(postorder,inorder,pos+1,end);
    node->left = buildtree(postorder,inorder,start,pos-1);
    return node;
}
int main()
{
    int postorder[] = {15,17,20,40,50,30,10};
    int inorder[] = {15,20,17,10,40,30,50};
    Node* Root = buildtree(postorder,inorder,0,6);
    Print_inorder(Root);
    return 0;
}