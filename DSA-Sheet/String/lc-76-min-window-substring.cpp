#include <bits/stdc++.h>
using namespace std;


class Solution {
public: 
    unordered_map<char,int> m;
    bool isEqual(vector<int> &v1, vector<int> &v2){
        for(auto x:m){
            char ch=x.first;
            int cnt = x.second;
            if(v1[int(ch)]<cnt)
                return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        
        if(n2>n1)
            return "";
        
        vector<int> v1(128,0);
        vector<int> v2(128,0);
        int i;
        for(i=0;i<n2;i++){
            v1[int(s[i])]++;
            m[t[i]]++;
        }
        
        int len=INT_MAX;
        int start =-1;
        int j=0;
        for(;i<n1;i++){
            while(isEqual(v1,v2)){
                if(i-j<len){
                    len=i-j;
                    start=j;
                }
                v1[int(s[j])]--;
                j++;
            }
            v1[int(s[i])]++;
        }
        while(isEqual(v1,v2)){
            if(i-j<len){
                len=i-j;
                start=j;
            }
            v1[int(s[j])]--;
            j++;
        }
        if(start==-1)
            return "";
        return s.substr(start,len);
    }
};