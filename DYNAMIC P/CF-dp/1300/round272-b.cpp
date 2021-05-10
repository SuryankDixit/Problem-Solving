#include<bits/stdc++.h>
using namespace std;

#define int long long

int ans,t;
void dfs(string &s1,int s,int d,int i){
    if(i==s1.size()){
        if(s==d)
            ans++;
        return;
    }

    if(s1[i]=='+'){
        s++;
        dfs(s1,s,d,i+1);
    }else if(s1[i]=='-'){
        s--;
        dfs(s1,s,d,i+1);
    }else{
        // t++;
        // cout<<i<<" "<<t<<endl;
        dfs(s1,s+1,d,i+1);
        dfs(s1,s-1,d,i+1);
    }
}


void solve(){
    string s1,s2;
    cin>>s1>>s2;

    unordered_map<char,int> m;
    for(auto x:s1)
        m[x]++;
    for(auto x:s2){
        m[x]--;
        if(m[x]==0)
            m.erase(x);
    }
    double z = 1;
    if(m.size()==0)
        cout<<z;
    else{
        int d=0;
        for(auto c:s1){
            if(c=='+')  d++;
            else    d--;
        }

        t = abs(m['?']);
        t=pow(2,t);
        ans=0;
        dfs(s2,0,d,0);
        cout.precision(12);
        cout<<(double)ans/t;
    }
}


signed main(){
    int t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}