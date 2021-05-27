#include <bits/stdc++.h>

using namespace std;


int dfs_profit(vector<int> &v, int level,int i, int j,vector<vector<int>>& dp){

    if(i==j){
        return v[i]*level;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int profit1 = dfs_profit(v,level+1,i+1,j,dp) + v[i]*level;
    int profit2 = dfs_profit(v,level+1,i,j-1,dp) + v[j]*level;

    cout<<"("<<i<<","<<j<<") "<<profit1<<" "<<profit2<<endl;
    return dp[i][j] = max(profit1,profit2);
}


int main() {
    

     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<vector<int>> dp(n,vector<int>(n,-1));

    cout<<dfs_profit(v,1,0,n-1,dp);
}

