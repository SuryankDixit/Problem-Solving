#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 100005;

vector<int> graph[N];

bool detectCycle(int node,vector<int> &visited){

    cout<<node<<" ";
    visited[node]=1;
    for(auto child:graph[node]){
        if(visited[child]==0){
            bool isCyclePresent = detectCycle(child,visited);
            if(isCyclePresent)
                return true;
        }
        else if(visited[child]==1)
            return true;
    }
    visited[node]=2;
    return false;
}


int main() {

    int vertex,edges;
    cin>>vertex>>edges;

    for(int i=0;i<edges;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }

    // 0 : not visited
    // 1 : processing in stack
    // 2 : Processed.

    vector<int> visited(N,0);

    bool isCyclePresent;
    for(int i=1; i<=vertex; i++){
        if(visited[i]==0) {
            isCyclePresent = detectCycle(i, visited);
            if(isCyclePresent)
                break;
        }
    }
    if(isCyclePresent)
        cout<<"Cycle is Present";
    else
        cout<<"Cycle is not Present";
}


// Input Graph
//7 7
//1 2
//2 3
//3 4
//4 5
//5 3
//5 6
//6 7
