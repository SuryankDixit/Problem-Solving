#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int N = 10e5+5;
vector<int> parent;
vector<int> dist;
int n,m;

void dijkstra(int s,int d,vector<pair<int,int>> g[]){
    set<pair<int,int>> q;
    q.insert({0,s});
    parent[s]=-1;
    parent[d]=-2;
    dist[s]=0;
    while(!q.empty()){
        pair<int,int> t = *(q.begin());
        q.erase(q.begin());
        int dis = t.first;
        int s = t.second;
        for(auto child: g[s]){
            int old_d = child.second;
            int node = child.first;
            int new_d = old_d + dis;
            if(new_d < dist[node]){
                dist[node] = new_d;
                parent[node] = s;
                if(q.find({old_d,node})!=q.end()){
                    q.erase({old_d,node});
                    q.insert({new_d,node});
                }else{
                    q.insert({new_d,node});
                }
            }
        }
    }

    if(parent[d]==-2){
        cout<<-1<<endl;
    }else{
        vector<int> path;
        while(d!=s){
            path.push_back(d);
            d=parent[d];
        }
        path.push_back(s);
        reverse(path.begin(),path.end());
        for(auto x:path){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}


int32_t main(){
    cin>>n>>m;
    parent.resize(n+1,-1);
    dist.resize(n+1,LLONG_MAX);
    vector<pair<int,int>> g[n+1];

    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dijkstra(1,n,g);
    return 0;
}