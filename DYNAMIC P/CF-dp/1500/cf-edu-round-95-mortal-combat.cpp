#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int dp[200005][2];
int n;


int dfs(int i,int turn){
    if(i>=n){
        return 0;
    }

    if(dp[i][turn]!=-1)
        return dp[i][turn];

    // cout<<i<<" "<<turn<<" "<<dp[i][turn]<<endl;
    if(turn==0){
        // killing one boss
        int mn = INT_MAX;
        if(i<n && v[i]==0)
            mn = min(mn,dfs(i+1,1^turn));
        if(i<n && v[i]==1)
            mn = min(mn,1+dfs(i+1,1^turn));
        if(i+1<n && v[i]==0 && v[i+1]==1)
            mn = min(mn,1+dfs(i+2,1^turn));
        if(i+1<n && v[i]==1 && v[i+1]==0)
            mn = min(mn,1+dfs(i+2,1^turn));
        if(i+1<n && v[i]==0 && v[i+1]==0)
            mn = min(mn,dfs(i+2,1^turn));
        if(i+1<n && v[i]==1 && v[i+1]==1)
            mn = min(mn,2+dfs(i+2,1^turn));
        return dp[i][turn] = mn; 
    }else{
        return dp[i][turn] = min(dfs(i+1,1^turn),dfs(i+2,1^turn));
    }
}


void solve(){
    cin>>n;
    v.resize(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // dp.resize(n,vector<int>(2,-1));
    memset(dp,-1,sizeof(dp));
    dfs(0,0);
    cout<<dp[0][0]<<endl;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
    return 0;
}