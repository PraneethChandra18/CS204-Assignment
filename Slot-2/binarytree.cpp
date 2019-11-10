#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int x)
{
    Node* temp= new Node;
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;
}
void inorder(Node* x)
{
    if(x)
    {
      inorder(x->left);
      cout<<x->data<<" ";
      inorder(x->right);
    }
}
void insert(Node* t,int key)
{
    queue<Node*> q;
    q.push(t);

    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp->left==NULL)
            {
                temp->left=newNode(key);
                break;
            }
        else
        {
            q.push(temp->left);
        }

        if(temp->right==NULL)
            {
                temp->right=newNode(key);
                break;
            }
        else
        {
            q.push(temp->right);
        }
    }
}

void deleteDeepest(struct Node* root,struct Node* d_node)
{
    queue<struct Node*> q;
    q.push(root);

    struct Node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }

        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}
Node* deletion(Node* t,int key)
{
    if(t==NULL)return NULL;
    if(t->left==NULL&&t->right==NULL)
    {
        if(t->data==key)return NULL;
        else return t;
    }

    queue<Node*> q;
    q.push(t);
    Node* key_node=NULL;
    Node* temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->data==key)
        {
            key_node=temp;
        }
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
    if (key_node != NULL) {
        int x = temp->data;
        deleteDeepest(t, temp);
        key_node->data = x;
    }
    return t;
}

int main ()
{
    struct Node* root = newNode(10);
    insert(root,11);
    insert(root,7);
    insert(root,9);
    insert(root,15);
    insert(root,8);
    cout << "Inorder traversal before insertion:";
    inorder(root);

    int key = 12;
    insert(root, key);

    cout << endl;
    root = deletion(root,11);
    cout << "Inorder traversal after insertion and deletion:";
    inorder(root);
    cout << endl;
    return 0;

}
