#include <bits/stdc++.h>
using namespace std;


const int N = 200006;
vector<int> g[N];
vector<int> vis(N,0);
int v,e;
bool flag;

void dfs(int node){
    vis[node] = 1;
    if(g[node].size()!=2){
            flag=0;
            // return ;
    }
    for(auto child:g[node]){
        if(!vis[child]){
            dfs(child);
        }
        
    }
    return ;
}


int main() {

        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif
        cin>>v>>e;  
        for(int i=1;i<=e;i++){   //edges
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int ans=0;
        for(int i=1;i<=v;i++){
            flag=1;
            if(!vis[i]){
                dfs(i);
                if(flag) ans++;
            }
        }
        cout<<ans;
	return 0;
}
