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
void levelorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if (node!=NULL)
        {
            cout<<node->data<<" ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
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
    levelorder(root);
    return 0;
}