#include<bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<ll,vector<ll>> adjList;
unordered_map<ll,ll> seen;
vector<ll> paths;
queue<ll> que;

void find_all_paths(ll source, ll destination);

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll total_members;
    cin>>total_members;
    for(ll i=0;i<total_members;i++){
        ll id;
        cin>>id;
        seen[id] = 0;
    }
    ll edges;
    cin>>edges;
    while(edges--){
        ll x,y;
        cin>>x>>y;
        adjList[x].push_back(y);
    }
    ll source;
    cin>>source;
    ll destination;
    cin>>destination;
    find_all_paths(source,destination);

}

void find_all_paths(ll source, ll destination){

    seen[source]=1;
    que.push(source);
    while(!que.empty())
    {
        ll node = que.front();
        que.pop();
        for(auto child : adjList[node])
        {
            if(!seen[child]){
                if(child == destination)
                paths.push_back(node);
                else{
                    seen[child] = 1;
                    que.push(child);
                }
            }
        }
    }
    sort(paths.begin(),paths.end());
    for(auto x : paths){
        cout<<x<<" ";
    }
}