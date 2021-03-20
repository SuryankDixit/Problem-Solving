#include<bits/stdc++.h>
using namespace std;

vector<int> tree[200005];
vector<int> ans;

void dfs(int s,int p){
    int subs = 0;
    for(auto x:tree[s]){
        if(x!=p){
            dfs(x,s);
            subs += 1 + ans[x];
        }
    }
    ans[s] = subs;
}

int main(){
    int n;
    cin>>n;
    ans.resize(n+1,0);
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        cout<< ans[i]<<" ";
    }
}