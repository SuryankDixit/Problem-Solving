#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 100005;

vector<int> graph[N];
int minCycleLen=INT_MAX;

void shortestCycle(int src,vector<int> visited, vector<int> distance, vector<int> parent){

    visited[src]=1;
    queue<int> q;
    q.push(src);
    visited[src]=1;
    distance[src]=0;
    parent[src]=-1;
    while(!q.empty()){
        int cnt=q.size();
        while(cnt>0){
            int node = q.front();
            q.pop();
            for(auto child:graph[node]){
                if(visited[child]==0){
                    visited[child]=1;
                    distance[child]=distance[node]+1;
                    parent[child]=node;
                    q.push(child);
                }
                else if(visited[child]==1 && parent[node]!=child){
                    minCycleLen = min(minCycleLen,distance[node]+distance[child]+1);
//                    cout<<node<<" "<<child<<"-->"<<minCycleLen<<endl;
                }
                cnt--;
            }
        }
    }
//    cout<<endl<<endl;
}


int main() {

    int vertex,edges;
    cin>>vertex>>edges;

    for(int i=0;i<edges;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> visited(N,0);
    vector<int> distance(N,0);
    vector<int> parent(N,0);

    // We can modify this code and instead of 3 arrays , we can do it in one array;
    // Just have distance array and initialize it with INT_MAX and if INT_MAX is updated that means the vertex is visited
    // Then to check back edge through BFS ====>>>> if( distance[child] >= distance[node] )
                                                //  then there is a back edge from node to child;


    for(int i=1;i<=vertex;i++){
        shortestCycle(i,visited,distance,parent);
    }
    cout<<"Min Cycle length = "<<minCycleLen<<endl;
}
