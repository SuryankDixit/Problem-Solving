#include<bits/stdc++.h>
using namespace std;
int n,m;

void dfs(vector<vector<char>> &v,int i,int j){
    if(i<0 || j<0 || i>=n|| j>=m|| v[i][j]=='@'){
        return;
    }
    if(v[i][j]=='#'){
        return;
    }

    v[i][j]='@';
    dfs(v,i+1,j);
    dfs(v,i-1,j);
    dfs(v,i,j+1);
    dfs(v,i,j-1);
    return;
}


int main(){
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='.' && v[i][j]!='@'){
                dfs(v,i,j);
                cnt++;
            }
        }
    }
    cout<<cnt;
}