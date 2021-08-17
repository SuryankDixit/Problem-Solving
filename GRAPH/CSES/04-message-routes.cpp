#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m;
vector<int> g[N];
vector<bool> vis;
vector<int> p;

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

    vis.resize(N,false);
    p.resize(N,-1);
    queue<int> q;
    q.push(0);
    p[0]=-2;

    while(!q.empty()){
        int k = q.size();
        while(k--){
            auto x = q.front();
            q.pop();
            for(auto child:g[x]){
                if(p[child]==-1){
                    p[child] = x;
                    q.push(child);
                }
            }
        }
    }
    vector<int> ans;
    if(p[n-1]<0){
        cout<<"IMPOSSIBLE";
    }else{
        int d = n-1;
        while(d!=-2){
            ans.push_back(d);
            d=p[d];
        }
        // ans.push_back(0);
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto x: ans){
            cout<<x+1<<" ";
        }
    }
}