#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans=0;
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};

    bool isValid(int x,int y,int r ,int c){
        if(x<0||y<0||x>=r||y>=c)
            return false;
        return true;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int r=v.size();
        int c=v[0].size();
        
        if(r==1 &&c==1)
            return v[r-1][c-1];
        int ans=0;
        queue<pair<int,int>> q;
        
        int ones=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                
                if(v[i][j]==1){
                    q.push({i,j});
                    ones++;
                }
                int cnt=0;
                while(!q.empty()){
                    pair<int,int> t=q.front();
                    q.pop();
                    for(int j=0;j<4;j++){
                        int x = t.first+dx[j];
                        int y = t.second+dy[j];
                        if(isValid(x,y,r,c) && v[x][y]==1){
                            ones++;
                            cnt++;
                            ans=max(ans,cnt);
                            v[x][y]=0;
                            q.push({x,y});
                        }
                    }
                }
            }
        }
        if(ones!=0 && ans==0)
            return 1;
        return ans;
    }
};