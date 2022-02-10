#include<iostream>
#include<queue>
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
void leftview(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i=1;i<=n;i++)
        {
            Node* curr= q.front();
            q.pop();
            if(i==1)
            {
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }

       
    }
}
int main()
{
    struct Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(33);
    root->right->right = new Node(52);
    root->right->left = new Node(45);
    root->left->left = new Node (65);
    root->left->right = new Node (78);
    leftview(root);
    return 0;
}