#include <bits/stdc++.h>
using namespace std;


vector<int> g[300001];
vector<int> cnt;
int ans=INT_MIN;

bool check(vector<int> &vis, int s){
    vis[s]=1;
    for(auto x:g[s]){
        if(vis[x] == 1){
            return true;
        }
        else{
            if(check(vis,x))
                return true;;
        }
    }
    vis[s]=2;
    return false;
}

int get_max(){
    int mx=-1;
    for(int i=0;i<26;i++){
        mx = max(mx,cnt[i]);
        cout<<cnt[i]<<" ";
    }
    cout<<endl<<mx<<endl<<endl;        
    return mx;
}


void dfs(int i, vector<int> &vis,string &s){
    vis[i]=1;
    cnt[s[i]-'a']++;
    int c=0;
    for(auto x:g[i]){
        if(vis[x]==0){
            c++;
            dfs(x,vis,s);
        }
    }
    // cout<<i<<" "<<s[i]-'a'<<" "<<c<<endl;
    if(c==0){
        cout<<i+1<<endl;
        ans = max(ans,get_max());
    }
    cnt[s[i]-'a']--;
    return ;
}


int beauty(int n,int m, string s, int x[], int y[]){
    
    vector<int> vis(n,0);
    for(int i=0;i<m;i++){
        g[x[i]-1].push_back(y[i]-1);
    }
    
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            if(check(vis,i))
                return -1;
        }
    }
    
    fill(vis.begin(),vis.end(),0);
    cnt.resize(26,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(i,vis,s);
        }
    }
    return ans;
}


int main()
{
    int n= 3;
    int m= 3;
    string s = "accaca";
    int x[m] = { 1,2,3};
    int y[m] = { 2,3,2};
    cout<<beauty(n,m,s,x,y);
    return 0;
}
