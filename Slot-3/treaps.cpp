#include<bits/stdc++.h>
using namespace std;

/*
ADT-
------
Left rotate
Right rotate
insert
deletenode
search
inorder traversal
--------------------------------------------------------------------------------
*/

struct Node
{
  int key,priority;
  struct Node *left,*right;
};

Node *newNode(int key)
{
  struct Node *temp = new Node;
  temp->key = key;
  temp->priority=rand()%100;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

Node *leftrotate(Node *x)
{
  struct Node *y = x->right, *T2 = y->left;
  y->left = x;
  x->right = T2;
  return y;
}

Node *rightrotate(Node *y)
{
  struct Node *x = y->left, *T2 = x->right;
  x->right = y;
  y->left = T2;
  return x;
}
Node *insert(struct Node *root,int key)
{
  if(!root)
    root = newNode(key);

  else
  {
    if(key <= root->key)
    {
      root->left = insert(root->left,key);
      if(root->left->priority > root->priority)
          root = rightrotate(root);
    }
    else
    {
      root->right = insert(root->right,key);
      if(root->right->priority > root->priority)
          root = leftrotate(root);
    }
  }
  return root;
}

Node *deletenode(struct Node *root,int key)
{
  if(!root)
    return root;
  else
  {
    if(key < root->key)
      root->left = deletenode(root->left,key);
    else if(key > root->key)
      root->right = deletenode(root->right,key);
    else
    {
      if(root->left == NULL)
      {
        struct Node *temp;
        temp = root->right;
        delete(root);
        root = temp;
      }
      else if(root->right == NULL)
      {
        struct Node *temp;
        temp = root->left;
        delete(root);
        root = temp;
      }
      else if(root->left->priority < root->right->priority)
      {
        root = leftrotate(root);
        root->left = deletenode(root->left,key);
      }
      else
      {
        root = rightrotate(root);
        root->right = deletenode(root->right,key);
      }
    }
  }
  return root;
}

void search(struct Node *root,int key)
{
  if(!root)
  {
    cout << "Not found" << endl;
    return;
  }
  else if(root->key == key)
  {
    cout << "Found" << endl;
    return;
  }
  else
  {
    if(key < root->key)
      search(root->left,key);
    else
      search(root->right,key);
  }
  return;
}

void inorder(struct Node *root)
{
  if(root)
  {
    inorder(root->left);
    cout << root->key << " " ;
    inorder(root->right);
  }
}


int main()
{
  struct Node *root = NULL;
  root=insert(root,6);
  root=insert(root,5);
  root=insert(root,3);
  root=insert(root,8);
  inorder(root);
  cout<< endl;
  root=deletenode(root,5);
  root = insert(root,50);
  root = insert(root,30);
  root = insert(root,20);
  root = insert(root,40);
  root = insert(root,70);
  root = insert(root,60);
  root = insert(root,80);
  root = deletenode(root,20);
  root = deletenode(root,30);
  root = deletenode(root,50);
  search(root,3);
  search(root,5);
  inorder(root);
}
