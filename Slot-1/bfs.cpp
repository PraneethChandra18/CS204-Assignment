#include<iostream>
#include <list>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
        list<int> queue;
        visited[s] = true;
        queue.push_back(s);
        list<int>::iterator i;

    while(!queue.empty())
    {

        s = queue.front();
        cout << s << " ";
        queue.pop_front();


        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{   int V;
    int E;
    int x,y;
    cin>>V;
    cin>>E;
    Graph g(V);
    for(int i=0;i<E;i++)
    {   cin>>x;
        cin>>y;
        g.addEdge(x,y);
    }
    int s;
    cin>>s;

    cout << "Following is Breadth First Traversal "
        << "(starting from vertex "<<s<<" )"<<endl;
    g.BFS(s);

    return 0;
}
/*
input:
5
4
0 2
2 1
0 1
3 4
0
output:
0 2 1
*/
