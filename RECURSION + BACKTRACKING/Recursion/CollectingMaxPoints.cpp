#include <bits/stdc++.h>
using namespace std;


int dfs(int i,int j,vector<vector<int>> &v){

    int row = v.size();
    int c = v[0].size();
    
    if(i<0 || j<0 || i>=row || j>=c || v[i][j]==0)
        return 0;

    int ans = 0;
    ans += v[i][j];
    v[i][j] = 0;

    int l = dfs(i,j-1,v);
    int r = dfs(i,j+1,v);
    int u = dfs(i-1,j,v);
    int d = dfs(i+1,j,v);
    ans +=  l+ r+ u+ d; 
    // cout<<l<<" "<<r<<" "<<u<<" "<<d<<" "<<endl;
    return ans;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    int a,b;
    cin>>a>>b;

    vector<vector<int>> v(a,vector<int>(b));

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>v[i][j];
        }
    }
    
    int ans=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){

            if(v[i][j]!=0){
                int x = dfs(i,j,v);
                ans = max(x,ans);
                cout<<x<<" ";
            }
        }
    }
    cout<<endl<<ans;
    return 0;
}


//input
// 7 7
// 10 0 100 200 0 8 0
// 20 0 0 0 0 6 0
// 30 0 0 9 12 3 4
// 40 0 2 5 8 3 11
// 0 0 0 0 0 9 0
// 5 6 7 0 7 4 2
// 8 9 10 0 1 10 8

//output
// 300
