#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> v;
    
    void prefix_sum(vector<vector<int>> &m){
        int r=m.size();
        int c=m[0].size();
        v.resize(r+1,vector<int>(c+1,0));
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                v[i][j] = m[i-1][j-1]+v[i-1][j]+v[i][j-1]-v[i-1][j-1];
            }
        }
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        prefix_sum(mat);
        int r=mat.size();   
        int c=mat[0].size();
        vector<vector<int>> ans(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int x=i+1;int y=j+1;
                int r1,c1,r2,c2; r1=r2=c1=c2=0;
                r1=max(1,x-k);
                r2=min(r,x+k);
                c1=max(1,y-k);
                c2=min(c,y+k);
                // cout<<i<<" "<<j<<"      "<<r1<<" "<<c1<<"        "<<c1<<" "<<c2<<"        "<<c+1<<" "<<y+k<<endl;
                ans[i][j] = v[r2][c2]-v[r1-1][c2]-v[r2][c1-1]+v[r1-1][c1-1];
            }
        }
        return ans;
    }
};