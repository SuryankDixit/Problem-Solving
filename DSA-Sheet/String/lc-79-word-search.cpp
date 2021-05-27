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
    
    // cout<<i<<" "<<j<<"      "<<s[idx]<<endl;
    char ch=v[i][j];
    v[i][j]='@';
    for(int dir=0;dir<4;dir++){
        bool status = pattern(s,v,i+ax[dir],j+by[dir],idx+1);
        if(status)
            return status;
    }
    v[i][j]=ch;
    return false;
}
    
    bool exist(vector<vector<char>>& v, string s) {
        int n=v.size();
        int m=v[0].size();
        
        for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(pattern(s,v,i,j,0))
	                return true;
	        }
	    }
        return false;
    }
};