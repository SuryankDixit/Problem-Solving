#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>> *adjList;
public:
    Graph(int n){
        V=n;
        adjList = new list<pair<int,int>>[V];
    }
    void addEdge(int x,int y, int wt){
        adjList[x].push_back(make_pair(y,wt));
        adjList[y].push_back(make_pair(x,wt));
    }

    int primsMST(){

        // Min Heap of state (wt,directedTo) -> (wt,directedTo)
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> visited(V,0);

        // insert source vertex in the queue and make it visited;
        // source node is inserted which is connected to Node 0 carrying weight =0;

        q.push({0,0});
        int ans=0;

        while(!q.empty()){

            pair<int,int> node = q.top();
            q.pop();
            int wt = node.first;
            int toNode = node.second;           // going to Node node.second;

            // We will check if this  node is already in MSTSet or not;
            if(visited[toNode]){
            // discard this node and all the edges connected to it;
                continue;
            }

            // Otherwise take this edge in answer;
            ans += wt;
            visited[toNode]=1;

            // Add active edges of this node in queue
            for(auto edges: adjList[toNode]){
                int connectedNode = edges.first;
                int weight = edges.second;
                if(visited[connectedNode]==0){
                    q.push({weight,connectedNode});
                }
            }
        }
        return ans;
    }
};


int main() {
    int vertex,edges;
    cin>>vertex>>edges;

    Graph g(vertex);
    for(int i=0;i<edges;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        g.addEdge(x,y,wt);
    }
    int minCost = g.primsMST();
    cout<<"Minimum cost to cover the Network :"<<minCost<<endl;
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

//4 5
//0 1 10
//1 2 15
//0 2 5
//3 1 2
//2 2 40
