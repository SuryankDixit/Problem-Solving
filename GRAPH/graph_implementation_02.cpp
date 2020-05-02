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
        adjList=new list<int>[V+1];
    }

    void add_edge(int u,int v,bool bidirectional=true)// bidirectional is to check for directed graphs
    {
        adjList[u].push_back(v);
        if(bidirectional==true)
            adjList[v].push_back(u);
    }
    void print_edge()
    {
        for(int i=1;i<=V;i++)
        {
            cout<<i<<"->     ";
            for(auto j=adjList[i].begin();j!=adjList[i].end();j++)
                cout<<*j<<", ";
            cout<<endl;
        }
    }
};

int main()
{
    graph g(5);
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(1,4);
    g.add_edge(5,2);
    g.add_edge(4,2);
    g.add_edge(3,2);
    g.print_edge();
    return 0;
}
