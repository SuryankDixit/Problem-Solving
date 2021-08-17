#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m;
vector<int> g[N];
vector<int> col;

void dfs(int i, int c){

    if(col[i]!=-1){
        if(c!=col[i]){
            cout<<"IMPOSSIBLE";
            exit(0);
        }
        return ;
    }

    col[i]=c;
    for(auto child:g[i]){
        dfs(child,3-c);
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

    col.resize(N,-1);
    for(int i=0;i<n;i++){
        if(col[i]==-1){
            dfs(i,1);
        }
    }
    for(int i=0;i<n;i++){
        cout<<col[i]<<" ";
    }
}
