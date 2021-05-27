#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        // cout<<n<<endl;
        string temp = s;
        string z=s;
        reverse(z.begin(),z.end());
        temp+="#"+z;
        vector<int> v(2*n+1,0);
        int len=0;
        int i=1;
        while(i<2*n+1){
            if(temp[i]==temp[len]){
                v[i]=len+1;
                len++;i++;
            }else{
                if(len>0){
                    len=v[len-1];
                }else{
                    v[i]=0;
                    i++;
                }
            }
        }
     
        string ans="";
        int x = v[2*n];
        // cout<<x<<" "<<n<<endl;
        for(i=n-1;i>=x;i--){
            ans+=s[i];
        }
        ans = ans+s;
        return ans;
    }
};