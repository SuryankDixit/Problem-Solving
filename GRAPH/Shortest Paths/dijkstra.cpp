#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    int V;
    unordered_map<T,list<pair<T,int>>> adjList;
public:
    explicit Graph(int n){
        V=n;
    }
    void addEdge(T x,T y, int wt,bool bidirectional){
        adjList[x].push_back(make_pair(y,wt));
        if(bidirectional) {
            adjList[y].push_back(make_pair(x,wt));
        }
    }
    void printList(){
        for(auto i:adjList){
            cout<<i<<"-->";
            for(auto j:adjList[i]){
                cout<<"("<<j.first<<","<<j.second<<")"<<",";
            }
            cout<<endl;
        }
    }

    int dijkstra(T source, T destination){

        // hashmap of visited nodes and min distance of that node from source
        unordered_map<T,int> visited;
        for(auto node: adjList){
            visited[node.first] = INT_MAX;
        }
        // Taking a set that will act as a priority queue:
        set<pair<int,T>> q;                 // distance , node
        q.insert({0,source});

        while(!q.empty()){
            auto p = *(q.begin());       // holds the node with the least distance of all the nodes and edges
            int parentDistance = p.first;
            int parentNode = p.second;

            q.erase(q.begin());
            visited[parentNode] = parentDistance;

            for(auto nodePair: adjList[parentNode]){
                T childNode = nodePair.first;
                int childDistance = nodePair.second;
                int newChildDistance = childDistance+parentDistance;
                if( newChildDistance < visited[childNode] ){
                    visited[childNode] = newChildDistance;
                    auto f =q.find(make_pair(childDistance,childNode));
                    if(f!=q.end()) {
                        q.erase(f);
                        q.insert(make_pair(newChildDistance,childNode));
                    }
                    else{
                        q.insert(make_pair(newChildDistance,childNode));
                    }
                }
            }
        }
        for(auto x:visited){
            cout<<x.first<<" "<<x.second<<endl;
        }
        return visited[destination];
    }
};


int main() {
    int vertex,edges;
    cin>>vertex>>edges;

    Graph<int> g(vertex);
    for(int i=0;i<edges;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        g.addEdge(x,y,wt,true);
    }
    int a,b;
    cin>>a>>b;
    int shortestPath = g.dijkstra(a,b);
    cout<<"Shortest path from node "<<a<<" to node "<<b<<": "<<shortestPath<<endl;
    return 0;
}

//input
//8 13
//0 1 1
//1 2 8
//0 3 4
//1 3 3
//1 4 7
//2 4 6
//3 4 5
//3 5 9
//3 6 10
//6 5 11
//6 7 13
//4 6 12
//4 7 2
//3 6


//4 5
//0 1 10
//1 2 15
//0 2 5
//3 1 2
//2 3 40
//0 2
