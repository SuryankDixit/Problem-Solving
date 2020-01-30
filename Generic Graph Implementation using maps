#include <bits/stdc++.h>
using namespace std;

template<typename T>
class graph
{
    map<T,list<T> > adjList;
public:

    void add_edge(T u,T v,bool bidirectional=true)// bidirectional is to check for directed graphs
    {
        adjList[u].push_back(v);
        if(bidirectional==true)
            adjList[v].push_back(u);
    }
    void print_edge()
    {
        for(auto i=adjList.begin();i!=adjList.end();i++)
        {
            cout<<i->first<<"->     ";
            for(auto j=i->second.begin();j!=i->second.end();j++)
                cout<<*j<<", ";
            cout<<endl;
        }
    }
};

int main()
{
    graph<string> g;
    g.add_edge("Delhi","Agra");
    g.add_edge("Delhi","Kanpur");
    g.add_edge("Delhi","Amritsar");
    g.add_edge("Patiala","Agra");
    g.add_edge("Amritsar","Agra");
    g.add_edge("Kanpur","Agra");
    g.print_edge();
    return 0;
}
