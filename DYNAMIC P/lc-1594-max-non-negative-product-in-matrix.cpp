#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // v1=min matrix;
    // v2=max matrix;
    int mod = 1e9+7;
    // typedef long long int;
    int maxProductPath(vector<vector<int>>& g) {
        
        int m = g.size();
        int n = g[0].size();
        vector<vector<long long>> v1(m,vector<long long>(n)),v2(m,vector<long long>(n));
        v1[0][0] = v2[0][0] = g[0][0];
        for(int i=1;i<n;i++)
            v1[0][i] = v2[0][i] = g[0][i]*v1[0][i-1];
        for(int i=1;i<m;i++)
            v1[i][0] = v2[i][0] = g[i][0]*v2[i-1][0];
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(g[i][j]<0){
                    v1[i][j] = (max(v2[i-1][j],v2[i][j-1])*g[i][j]);      //min matrix
                    v2[i][j] = (min(v1[i-1][j],v1[i][j-1])*g[i][j]);      //max matrix
                }else{
                    v1[i][j] = (min(v1[i-1][j],v1[i][j-1])*g[i][j]);
                    v2[i][j] = (max(v2[i-1][j],v2[i][j-1])*g[i][j]);
                }
            }
        }
        int ans = v2[m-1][n-1]%mod;
        if(ans<0)
            return -1;
        return ans;
    }
};