#include <bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    list<int> *adjList;
public:

    graph(int v)
    {
        V=v;
        adjList=new list<int>[V];
    }

    void add_edge(int u,int v,bool bidirectional=true)// bidirectional is to check for directed graphs
    {
        adjList[u].push_back(v);
        if(bidirectional==true)
            adjList[v].push_back(u);
    }
    void print_edge()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->     ";
            for(auto j=adjList[i].begin();j!=adjList[i].end();j++)
                cout<<*j<<", ";
            cout<<endl;
        }
    }

    void bfs(int source)
    {
        queue<int> q;
        bool visited[6]={false};
        q.push(source);
        visited[source]=true;

        while(!q.empty())
        {
            source=q.front();
            cout<<source<<" ";
            q.pop();

            for(auto i=adjList[source].begin();i!=adjList[source].end();i++)
            {
                if(visited[*i]!=true){
                q.push(*i);
                visited[*i]=true;
                }
            }
        }
        cout<<endl;
    }

    void shortestpath(int source, int dest)
    {
        queue<int> q;
        bool visited[6]={false};
        q.push(source);
        visited[source]=true;
        int distance[V]={0};
        int parent[V];
        for(int i=0;i<V;i++)
            parent[i]=-1;

        while(!q.empty())
        {
            source=q.front();
            q.pop();

            for(auto i=adjList[source].begin();i!=adjList[source].end();i++)
            {
                if(visited[*i]!=true){
                q.push(*i);
                visited[*i]=true;
                distance[*i]=distance[source]+1;
                parent[*i]=source;
                }
            }
        }
        for(int i=0;i<V;i++)
            cout<<parent[i]<<" ";
            cout<<endl;
        int temp=dest;
        cout<<endl;
        while(temp!=-1)
        {
            cout<<temp<<"<--";
            temp=parent[temp];
        }
    }
};

int main()
{
    graph g(6);
    g.add_edge(0,5);
    g.add_edge(4,3);
    g.add_edge(1,2);
    g.add_edge(5,4);
    g.add_edge(3,2);
    g.add_edge(2,4);
    g.print_edge();
    cout<<endl;
    cout<<"Traversal of Graph using BFS: ";
    cout<<endl<<endl<<"source 1   :";
    g.bfs(0);
    cout<<endl<<endl<<"source 5   :";
    g.bfs(5);
    cout<<endl<<endl;
    cout<<"Shortest path from node 0 to node 1 is :";
    g.shortestpath(0,1);
    cout<<endl<<endl;
    cout<<"Shortest path from node 5 to node 2 is :";
    g.shortestpath(5,2);
    cout<<endl;
    return 0;
}
