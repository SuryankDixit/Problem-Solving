#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<bool> vis;
vector<int> g[N];
int n,m;

void dfs(int i){
    // cout<<i<<" ";
    vis[i]=true;
    for(auto child : g[i]){
        if(vis[child]==false)
            dfs(child);
        else
            continue;
    }
}

int main(){
    
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    cin>>n>>m;
    // vector<vector<int>> v(n,vector<int>(m,0));
    for(int j=0;j<m;j++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vis.resize(N,false);
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            ans.push_back(i);
            dfs(i);
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=1;i<ans.size();i++){
        cout<<ans[0]+1<<" "<<ans[i]+1<<endl;
    }
}
