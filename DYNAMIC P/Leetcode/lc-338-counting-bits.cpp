#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:

    vector<int> countBits(int num) {
        vector<int> v(num+1, 0);
        for(int i=1;i<= num; i++) v[i]=v[i/2]+i%2;
        return v;
    }
};


class Solution {
public:
    
    int cnt_bits(int n){
        int cnt=0;
        while(n){
            n= n&(n-1);
            cnt++;
        }
        return cnt;
    }
    
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        for(int i=1;i<=num;i++){
            ans[i] = cnt_bits(i);
        }
        return ans;
    }
};