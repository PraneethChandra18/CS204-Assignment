#include<bits/stdc++.h>
using namespace std;
/*
ADT-
---
insert
delete
search
sizeHashtable
print
--------------------------------------------------------------------------------
*/

struct HashNode
{
  int key,data;
};

int capacity,size=0;
HashNode **arr;

void Hashmap()
{
  arr = new HashNode*[capacity];
  for(int i=0 ; i < capacity ; i++)
            arr[i] = NULL;
}
struct HashNode *createNode(int k,int d)
{
  struct HashNode *temp = new HashNode;
  temp->key = k;
  temp->data = d;
  return temp;
}
struct HashNode *dummy = createNode(-1,-1);

int Hashcode(int k)
{
  return k%capacity;
}
/* -----------------------------------------------------------------------------*/

void insert(int k,int d)
{
  struct HashNode *temp = createNode(k,d);
  int hashindex = Hashcode(k);
  int count=0;
  while(arr[hashindex]!=NULL && arr[hashindex]->key!=k && arr[hashindex]->key!=-1)
  {
    if(count>capacity)
    {
      cout << "Hashtable is full" << endl;
      return;
    }
    count++;
    hashindex++;
    hashindex%=capacity;
  }
  if(arr[hashindex]==NULL || arr[hashindex]->key==-1)
    size++;
  arr[hashindex]=temp;
}

void deletenode(int k)
{
  int hashindex=Hashcode(k);
  int count=0;
  while(arr[hashindex])
  {
    if(count>capacity)
    {
      cout << "Key doesnt exist" << endl;
      return;
    }
    count++;
    if(arr[hashindex]->key==k)
    {
      arr[hashindex] = dummy;
      size--;
      return;
    }
    hashindex++;
    hashindex%=capacity;
  }
}

int search(int k)
{
  int hashindex=Hashcode(k);
  int count=0;
  while(arr[hashindex])
  {
    if(count>capacity)
      break;
    count++;
    if(arr[hashindex]->key==k)
    {
      return arr[hashindex]->data;
    }
    hashindex++;
    hashindex%=capacity;
  }
  cout << "Doesn't exist" << endl;
}

void sizeHashtable()
{
  cout << size << endl;
}

void print()
{
  for(int i=0;i<capacity;i++)
  {
    if(arr[i]!=NULL && arr[i]->key!=-1)
      cout << "Key = " << arr[i]->key << " " << "Data = " << arr[i]->data << endl;
  }
}


int main()
{
  cout << "Enter the max capacity of Hashtable : " << endl;
  cin >> capacity;
  Hashmap();
  insert(1,5);
  insert(2,6);
  insert(3,7);
  insert(4,8);
  deletenode(3);
  search(3);
  sizeHashtable();
  print();
}
