#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> f(n,0);     // forward maximum at index i;
        vector<int> b(n,0);     // backward maximum at index i;
        
        int l=0,g=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            l = arr[i];
            g += arr[i];
            if(l>g)
                g=l;
            f[i]=g;
            ans=max(ans,g);
        }
        l=0;g=0;
        for(int i=n-1;i>=0;i--){
            l = arr[i];
            g += arr[i];
            if(l>g)
                g=l;
            b[i]=g;
            ans=max(ans,g);
        }
        for(auto x:f)
            cout<<x<<" ";
        cout<<endl;
        for(auto x:b)
            cout<<x<<" ";
        for(int i=1;i<n-1;i++){
            ans=max(ans,f[i-1]+b[i+1]);
        }
        return ans;
    }
};