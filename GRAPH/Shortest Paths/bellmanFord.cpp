#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edge;

vector<int> bellmanFord(int n, int source){             // Total time complexity is O(N*E)

    vector<int> distance(n+1,INT_MAX);
    distance[source] = 0;
    for(int i=1;i<n;i++){                           // iterating N-1 times where N is the number of vertices in the graph
        for(auto x : edge){                        // iterating over all the edges i.e. E
            int from = x[0];
            int to = x[1];
            int wt = x[2];
            if( distance[from]!=INT_MAX && distance[to] > distance[from] + wt )
                distance[to]= distance[from] + wt;
        }
//        for(int i=1;i<=n;i++){
//            cout<<i<<"==>"<<distance[i];
//        }
//        cout<<endl;
    }
    for(auto x : edge){
        int from = x[0];
        int to = x[1];
        int wt = x[2];
        if( distance[from]!=INT_MAX && distance[to] > distance[from] + wt ){
            distance[to]= distance[from] + wt;
            exit(0);
            }
    }
    return distance;
}


int main() {
    int vertex,edges;
    cin>>vertex>>edges;

    for(int i=0;i<edges;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        edge.push_back({x,y,wt});
    }
    int source;
    cin>>source;
    vector<int> dis = bellmanFord(vertex, source);
    for(int i=1;i<=vertex;i++){
        cout<<"Distance of node "<<i<<" from "<<source<<" is "<<dis[i]<<endl;
    }
    return 0;
}

//Input test case for -ve weight cycle;
//3 3
//1 2 5
//2 3 4
//3 1 -11
//1


// +ve weight cycle
//3 3
//1 2 5
//1 3 7
//3 2 -3
//1
