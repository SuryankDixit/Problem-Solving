#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int cnt=0;
        int r=m.size();
        int c=m[0].size();
        for(int i=0;i<c;i++)
            if(m[0][i]==1)cnt++;
        for(int i=1;i<r;i++)
            if(m[i][0]==1)cnt++;
        
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(m[i][j]==1){
                    m[i][j]=min(m[i-1][j-1],min(m[i][j-1],m[i-1][j]))+1;
                    cnt += m[i][j];
                    // cout<<cnt<<" "<<i<<","<<j<<" "<<m[i][j]<<endl;
                }
            }
        }
        return cnt;
    }
};