#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void dfs(int i,int j,vector<vector<char>>&v){
        if(i<0||j<0||i>=v.size()||j>=v[0].size())
            return;
        
        if(v[i][j]!='#')
            return;
        
        v[i][j]='O';
        dfs(i-1,j,v);
        dfs(i,j-1,v);
        dfs(i,j+1,v);
        dfs(i+1,j,v);
        return;
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                    board[i][j]='#';
            }
        }
        
        for(int i=0;i<m;i++){
            dfs(i,0,board);
            dfs(i,n-1,board);
        }
        
        for(int i=0;i<n;i++){
            dfs(0,i,board);
            dfs(m-1,i,board);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#')
                    board[i][j]='X';
            }
        }
        
        return;
    }
};