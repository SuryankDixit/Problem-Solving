#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int> pi;
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> m[26];
        for(int i=0;i<s.size();i++)
            m[s[i]-'a'].push_back(i);
        
        int ans=0;
        for(auto x:words){
            int k=-1;
            bool f= true;
            for(int i=0;i<x.size();i++){
                int ch = x[i]-'a';
                int idx = upper_bound(m[ch].begin(),m[ch].end(),k) - m[ch].begin();
                // cout<<idx<<" ";
                if(idx==m[ch].size()){
                    f=false;
                    break;
                }
                else
                    k=m[ch][idx];
            }
            if(f)
                ans++;
        }
        return ans;
    }
};