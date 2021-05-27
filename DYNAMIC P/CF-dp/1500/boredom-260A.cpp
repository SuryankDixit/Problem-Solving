#include<bits/stdc++.h>
using namespace std;

#define int long long

unordered_map<int,int> m;
vector<int> dp;

int dfs(vector<int> &v, int i, bool flag,int prev){
    if(i==v.size())
        return 0;

    if(prev+1!=v[i])
        flag=true;

    if(flag==false)
        return dfs(v,i+1,true,v[i]);

    if(dp[i]!=-1)
        return dp[i];
    
    return dp[i] = max( (v[i]*m[v[i]] + dfs(v,i+1,false,v[i]) ), dfs(v,i+1,true,v[i]) );
    
}


void solve(){
    int n;
    cin>>n;
    vector<int> v(n+1,0);
    v[0]=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        m[v[i]]++;
    }
    sort(v.begin(),v.end());
    auto ip = unique(v.begin(),v.end());
    v.resize(distance(v.begin(), ip));
    dp.resize(n+1,-1);

    // for(auto x:v)
    //     cout<<x<<" ";

    cout<<dfs(v,1,true,0);
}

signed main(){
    int t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}