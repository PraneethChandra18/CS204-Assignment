#include<bits/stdc++.h>
using namespace std;
#define INF 10000000

int main()
{    int V;
    cin>>V;
    int E;
    cin>>E;
     int x;
        int y;
      int w;
    int graph[V][V];
    for(int i=0;i<V; i++)
	    {
			for(int j=0;j<V;j++)
			{
				graph[i][j]=INF;
			}
		}


    for(int i=0;i<V;i++)
    {
        graph[i][i]=0;
    }
    for(int i=0;i<E;i++)
    {
        cin>>x;
        cin>>y;
        cin>>w;
        graph[x][y]=w;

    }
    int dist[V][V];
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			dist[i][j]=graph[i][j];
		}
	}
	for(int k=0;k<V;k++)
	{
		for(int i=0;i<V; i++)
	    {
			for(int j=0;j<V;j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

			}
		}
	}

	int sum=0;
	int i,j;
	    for(i=0;i<V;i++)
	{
		for( j=0;j<V;j++)
		{
			if(dist[i][j]== INF)
			{
			    break;
			}
			else
			{
			    sum=sum+dist[i][j];
			}
		}
		if(j==V)
		{
		    cout<<"YES"<<" value of sum is "<<sum<<" city is "<<i<<endl;
		    break;
		}

	}
    if(i==V)
    {
        cout<<"NO";
    }
    return 0;
}

/*
input :
4
4
0 3 10
0  1 5
1 2 3
2 3 1
output:
YES value of sum is 22 city is 0
input:
4
4
0 3 10
0  1 5
2  1 3
2 3 1
output:
NO
*/
