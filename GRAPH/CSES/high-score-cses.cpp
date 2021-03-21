#include<bits/stdc++.h>
using namespace std;

#define int long long int
vector<int> dist;
int n,m;

void bellman(int s,int d, vector<pair<pair<int,int>,int>> &e){

    dist[s]=0;
    for(int i=1;i<n;i++){
        for(auto x: e){
            int from = x.first.first;
            int to = x.first.second;
            int w = x.second;
            if(dist[from]!=LLONG_MAX && dist[to]>dist[from]+w){
                dist[to] = dist[from]+w;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        for(auto x: e){
            int from = x.first.first;
            int to = x.first.second;
            int w = x.second;
            if(dist[to]>dist[from]+w){
                dist[to] = LLONG_MIN;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

    if(dist[n]==LLONG_MIN){
        cout<<-1;
    }else{
        cout<<-1*dist[n];
    }
}


int32_t main(){
    cin>>n>>m;
    dist.resize(n+1,LLONG_MAX);
    vector<pair<pair<int,int>,int>> e(m);

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        c=-c;
        e[i] = {{a,b},c};
    }
    bellman(1,n,e);
    return 0;
}