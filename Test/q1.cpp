#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll nodes,edges,time,city;
    cin>>nodes>>edges;
    cin>>time>>city;

    vector<ll> graph[nodes+1];

    while(edges--){
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<ll> vis(nodes+1,INT_MAX);
    set<pair<ll,ll>> s;
    s.insert({0,1});
    while(s.size()){
        auto _pair= *s.begin();
        ll node=_pair.second;
        ll distance=_pair.first;
        s.erase(s.begin());

        if(distance<=vis[node]){
            vis[node]=distance;
            for(auto i:graph[node]){
                ll node_d = distance;
                if(vis[node]%(2*time)>=time){
                    node_d += (2*time-vis[node]%(2*time));
                }
                if(vis[i] > node_d + city){
                    vis[i]= node_d+city;
                    s.insert({node_d+city,i});
                }
            }
        }
    }
    cout<<vis[nodes]<<endl;
}
/*
5 5 3 5
1 2
1 3
2 4
1 4
2 5


output 11

*/
// 1st