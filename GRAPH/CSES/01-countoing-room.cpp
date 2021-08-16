#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m;

void dfs(int i, int j, vector<vector<char>> &v){
    if(i>=n || i<0 || j>=m || j<0 || v[i][j]=='#')
        return;
    
    if(v[i][j]=='@'){
        return;
    }
     
    v[i][j]='@';
    dfs(i+1,j,v);
    dfs(i,j+1,v);
    dfs(i-1,j,v);
    dfs(i,j-1,v);
}

int main(){
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='.'){
                cnt++;
                dfs(i,j,v);
            }
        }
    }
    cout<<cnt;
}
