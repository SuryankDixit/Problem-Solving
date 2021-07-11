#include<bits/stdc++.h> 
using namespace std; 
#define ll long long

unordered_map<ll,vector<ll>> adjList;
unordered_map<ll,ll> visited;


void check_reachability(int node);

int main(){ 
 
  ll total_members;
    cin>>total_members;
    for(ll i=0;i<total_members;i++){
        ll id;
        cin>>id;
        visited[id] = 0;
    }
    ll edges;
    cin>>edges;
    
    while(edges--){
        ll x,y;
        cin>>x>>y;
        adjList[x].push_back(y);
    }
    ll source,destination;
    cin>>source>>destination;

    check_reachability(source);
    cout<<visited[destination];
}


void check_reachability(int node) 
{ 
    visited[node]=1; 
    for(auto child: adjList[node]){
        if(!visited[child]) check_reachability(child);
    }
    return; 
 
} 

/*
4 
2
5
7
9
4
2 9
7 2
7 9
9 5
7
9
*/