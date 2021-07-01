#include <bits/stdc++.h>
using namespace std;


const int N = 100005;
vector<int> g[N];
vector<int> cats(N,0);
vector<int> vis(N,0);
int v,c;    //nodes, cats
int ans=0;

void dfs(int node, int cat){
    vis[node] = 1;
    if(cats[node]==1 && cat+1>c){
        return;
    }else if(cats[node]){
        cat++;
    }else{
        cat =0;
    }
    int cnt=0;
    for(auto child:g[node]){
        if(!vis[child]){
            cnt++;
            dfs(child,cat);
        }
    }
    if(cnt==0){
        ans+=1;
    }
}


int main() {

        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif
        cin>>v>>c;  
        
        for(int i=1;i<=v;i++){
            cin>>cats[i];
        }

        for(int i=1;i<v;i++){   //edges
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        dfs(1,0);
        cout<<ans;
	return 0;
}
