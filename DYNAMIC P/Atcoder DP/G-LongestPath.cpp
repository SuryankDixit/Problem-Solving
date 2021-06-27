#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> g[100005];
vector<int> vis;
int ans=INT_MIN;

int dfs(int i){
    if(vis[i]!=-1){
        return vis[i];
    }
    vis[i]=0;
    for(auto x:g[i]){
        vis[i] = max(vis[i],1+dfs(x));
    }
    return vis[i];
}

int main()
{
    int v,e;
    cin>>v>>e;
    for(int i=1;i<=e;i++){
        int x;int y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    vis.resize(v+1,-1);
    for(int i=1;i<=v;i++){
        if(vis[i]==-1){
            ans=max(ans,dfs(i));
        }
    }
    cout<<ans;
}
