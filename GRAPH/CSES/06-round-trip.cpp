#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m;
vector<int> g[N];
vector<int> p;
vector<bool> vis;

void dfs(int i, int par){
    p[i] = par;
    vis[i]=true;
    for(auto child:g[i]){
        if(child==par)
            continue;
        if(vis[child] && child!=par){
            vector<int> ans;
            int start = i;
            while(child!=i){ // 1, 3
                ans.push_back(i);
                i = p[i];
            }
            ans.push_back(child);
            ans.push_back(start);
            cout<<ans.size()<<endl;
            for(auto x:ans){
                cout<<x+1<<" ";
            }
            exit(0);
        }else{
            dfs(child,i);
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    p.resize(N,-1);
    vis.resize(N,false);
    for(int i=0;i<n;i++){
        if(p[i]==-1){
            dfs(i,-1);
        }
    }
    cout<<"IMPOSSIBLE";
}