#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,string> pi;
    
    // 2 1
    // dk sk
    class comp{
        public:
        bool operator()(const pi &a, const pi &b){
            if(a.first>b.first || (a.first == b.first && a.second<b.second))
                return true;
            return false;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto x:words)
            m[x]++;
        priority_queue<pi,vector<pi>, comp> p;
        for(auto x:m){
            p.push({x.second,x.first});
            if(p.size()>k){
                
                p.pop();
            }
        }
        
        vector<string> ans;
        while(!p.empty()){
            auto x=p.top();
            // cout<<x.second<<" ";
            p.pop();
            ans.push_back(x.second);
            k--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};