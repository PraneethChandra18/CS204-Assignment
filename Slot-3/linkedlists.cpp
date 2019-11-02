#include<bits/stdc++.h>
using namespace std;

/*
ADT-
-----
insertatstart
insertatend
insertatpos -- inserts after pos.
deletenode
search -- prints out if exist or not. If exists then the number of times too.
print
---------------------------------------------
*/
struct Node
{
  int data;
  struct Node *ptr;
};
struct Node *st = NULL;
void insertatstart(int val)
{
  struct Node *temp = new Node;
  temp->data = val;
  temp->ptr = st;
  st = temp;
}

void insertatend(int val)
{
  struct Node *temp;
  temp = st;
  if(temp==NULL)
  {
    insertatstart(val);
  }
  else
  {
    while(temp->ptr!=NULL)
    {
      temp = temp->ptr;
    }
    struct Node *temp1 = new Node;
    temp1->data = val;
    temp1->ptr = NULL;
    temp->ptr = temp1;
  }
}

void insertatpos(int val,int pos)
{
  struct Node *temp;
  temp = st;
  while(temp!=NULL)
  {
    if(temp->data == pos)
      break;
    temp = temp->ptr;
  }
  if(temp==NULL)
    cout << "Position not found !!!";
  else if(temp->ptr == NULL)
    insertatend(val);
  else
  {
  struct Node *temp1 = new Node;
  temp1->data = val;
  temp1->ptr = temp->ptr;
  temp->ptr = temp1;
  }

}

void search(int val)
{
  struct Node *temp;
  temp = st;
  int n=0;
  while(temp!=NULL)
  {
    if(temp->data == val)
    {
      n++;
    }
    temp = temp->ptr;
  }
  if(n>0)
  cout << "Exists " << n << " times" << endl;
  else
  cout << "Doesn't exist" << endl;
}

void deletenode(int val)
{
  struct Node *temp,*prev;
  temp = st;
  while(temp!=NULL)
  {
    if(temp->data == val)
      break;
    prev = temp;
    temp = temp->ptr;
  }
  if(temp == NULL)
  {
    cout << "Element not found";
  }
  else if(temp == st)
    st = temp->ptr;
  else
    prev->ptr = temp->ptr;
  free(temp);
}

void print()
{
  struct Node *temp;
  temp = st;
  while(temp!=NULL)
  {
    cout << temp->data << " ";
    temp = temp->ptr;
  }
  cout << '\n';
}


int main()
{
  // insertatstart(5);
  // insertatend(4);
  // insertatend(2);
  // insertatend(1);
  // insertatpos(3,4);
  // search(3);
  // deletenode(3);
  // deletenode(1);
  // deletenode(5);
  // search(1);
  // search(5);
  // insertatpos(5,4);
  // insertatpos(5,4);
  // search(5);
  // insertatstart(8);
  // print();
}
