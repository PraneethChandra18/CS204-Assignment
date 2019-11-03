#include<bits/stdc++.h>
using namespace std;

int num;
struct Node
{
  int data,rank=0,parent;
};

struct Node *arr;
void makearr()
{
  arr = new Node[num];
}

void makeset()
{
  for(int i=0;i<num;i++)
  {
    arr[i].parent = i;
    arr[i].data = i;
  }
}

int findset(int n)
{
  if(arr[n].parent==n)
    return n;
  else
    return findset(arr[n].parent);
}

void unionsets(int x,int y)
{
  int xset = findset(x);
  int yset = findset(y);
  if(xset == yset)
    return ;
  else
  {
    if(arr[x].rank > arr[y].rank)
    {
      arr[y].parent = xset;
    }
    else if (arr[x].rank < arr[y].rank)
    {
      arr[x].parent = yset;
    }
    else
    {
      // if(arr[x].parent > arr[y].parent)
      // {
        arr[y].parent = xset;
        arr[x].rank = arr[x].rank + 1;
      // }
      // else
      // {
      //   arr[x].parent = yset;
      //   arr[y].rank = arr[y].rank + 1;
      // }
    }
  }
}


int main()
{
  cout << "Enter the maximum number of sets : " << endl;
  cin >> num;
  makearr();
  makeset();
  unionsets(0,2);
  // unionsets(4,2);
  unionsets(3,1);
  unionsets(3,0);
  if(findset(2) == findset(0))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  if(findset(3) == findset(0))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;


  // cout << arr[4]->parent;
  // cout << arr[0]->parent;
}
