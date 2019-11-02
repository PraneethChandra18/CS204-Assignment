#include<bits/stdc++.h>
using namespace std;

int buckets;

struct Node
{
  int data;
  struct Node *ptr;
};

void insertatstart(struct Node **st,int val)
{
  struct Node *temp = new Node;
  temp->data = val;
  temp->ptr = *st;
  *st = temp;
}

void insertatend(struct Node **st,int val)
{
  struct Node *temp;
  temp = *st;
  if(temp==NULL)
  {
    insertatstart(st,val);
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

void search(struct Node *st,int val)
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

void deletenode(struct Node **st,int val)
{
  struct Node *temp,*prev;
  temp = *st;
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
  else if(temp == *st)
    *st = temp->ptr;
  else
    prev->ptr = temp->ptr;
  free(temp);
}

void print(struct Node *st)
{
  struct Node *temp;
  temp = st;
  while(temp!=NULL)
  {
    cout << temp->data << " --> ";
    temp = temp->ptr;
  }
  cout << '\n';
}

Node **arr;

void Hashmap()
{
  arr = new Node*[buckets];
  for(int i=0 ; i < buckets ; i++)
  {
            arr[i]=NULL;
  }
}

int Hashfunc(int k)
{
  return k%buckets;
}

void insert(int k)
{
    int index = Hashfunc(k);
    insertatend(&arr[index],k);
}

void searchkey(int k)
{
  int index = Hashfunc(k);
  search(arr[index],k);
}

void deletekey(int k)
{
  int index = Hashfunc(k);
  deletenode(&arr[index],k);
}

void printHash()
{
  for (int i = 0; i < buckets; i++)
  {
    cout << i;
    cout << " --> ";
    print(arr[i]);
    cout << endl;
  }
}

int main()
{
  cout << "Enter the max number of buckets : " << endl;
  cin >> buckets;
  Hashmap();
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a)/sizeof(a[0]);
  for (int i = 0; i < n; i++)
    insert(a[i]);
  deletekey(12);
  searchkey(27);
  searchkey(12);
  printHash();

}
