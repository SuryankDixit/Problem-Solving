
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
typedef long long int ll;
typedef array<ll,2> arr;
ll n, m;
vector<arr> g[N];
vector<ll> dis;

int main(){
    cin>>n>>m;
    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        g[a].push_back({c,b});
    }
    dis.resize(n,LONG_MAX);

    priority_queue<arr,vector<arr>, greater<arr>> pq;
    pq.push({0,0});
    dis[0]=0;
    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        if (x[0] > dis[x[1]])
            continue;
        for(auto child:g[x[1]]){
            if(dis[child[1]]> dis[x[1]]+child[0]){
                dis[child[1]] = dis[x[1]]+child[0];
                pq.push({dis[child[1]],child[1]});
            }
        }
    }
    cout<<dis[n-1]/2;
}