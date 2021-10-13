#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> graph[1001];
vector<pair<ll,vector<ll>>> paths;


void helper(ll nodes,vector<ll> routes[]){
    vector<int> ans(nodes+1,0);
    ans[1] = 1;
    ans[nodes] = 1;
    for(int i=2;i<=nodes-1;i++){
        if(routes[i].size() > 0){
            ll tm = routes[i][0];
            ll up = upper_bound(routes[i].begin(),routes[i].end(),tm) - routes[i].begin();
            ans[i] = up;
        }
    }
    for(int i=1;i<=nodes;i++)
    cout<<ans[i]<<" ";
}


void store_paths(ll start,ll end,ll city,vector<ll> temp,vector<ll> &seen){
   temp.push_back(start);
   if(start == end){
       paths.push_back({city*(temp.size()-1),temp});
       return;
   }
   for(auto child : graph[start]){
       if(seen[child] == 0){
          seen[start] = 1;
          store_paths(child,end,city,temp,seen);
          seen[start] = 0;
       }
   }
}

int main()
{
    ll nodes,edges,time,city;
    cin>>nodes>>edges>>time>>city;
    while(edges--){
        ll u; ll v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<ll> seen(nodes+1,0);
    vector<ll> temp;
    store_paths(1,nodes,city,temp,seen);

    // helper()
    sort(paths.begin(),paths.end());
    vector<ll> routes[nodes+1];
    for(int i=0;i<paths.size();i++){
        ll next = paths[i].second.size();
        for(auto child : paths[i].second){
            routes[child].push_back(next);
        }
    }
    helper(nodes,routes);
    return 0;
}