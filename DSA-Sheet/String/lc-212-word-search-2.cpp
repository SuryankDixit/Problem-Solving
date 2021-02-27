#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ax[4]={-1,0,1,0};
    int by[4]={0,-1,0,1};

bool pattern(string &s,vector<vector<char>> &v,int i,int j,int idx){
    
    if(idx==s.size())
        return true;
    
    if(i<0||j<0||i>=v.size()||j>=v[0].size())
        return false;
    
    if(s[idx]!=v[i][j])
        return false;
    
    char ch=v[i][j];
    v[i][j]='@';
    bool status=false;
    for(int dir=0;dir<4;dir++){
        status = status || pattern(s,v,i+ax[dir],j+by[dir],idx+1);
    }
    v[i][j]=ch;
    return status;
}
    
    vector<string> findWords(vector<vector<char>>& v, vector<string>& s) {
        int n=v.size();
        int m=v[0].size();
        
        vector<string> ans;
        
         for(auto x:s){
             int flag=0;
             for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(flag==0 && pattern(x,v,i,j,0)){
                    ans.push_back(x);
                    flag=1;
                }
            }
         }
         }
        return ans;
    }
};