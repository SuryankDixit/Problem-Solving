#include <bits/stdc++.h>
using namespace std;


vector<int> g[300001];
vector<vector<int>> cnt;
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

int get_max(int idx){
    int mx=0;
    for(int i=0;i<26;i++)
        mx = max(mx,cnt[idx][i]);
    return mx;
}

void fill_max(int s,int d){
    for(int i=0;i<26;i++){
        cnt[s][i]= max(cnt[s][i],cnt[d][i]);
    }
    return;
}


void dfs(int i, vector<int> &vis,string &s){
    vis[i]=1;

    int c=0;
    for(auto x:g[i]){
        c++;
        if(vis[x]==0)
            dfs(x,vis,s);
        fill_max(i,x);
    }
    cnt[i][s[i]-'a']++;
    // if(c==0)
    //     cnt[i][s[i]-'a']++;
}


int beauty(int n,int m, string s, int x[], int y[]){

    vector<int> vis(n,0);
    cnt.resize(n,vector<int>(26,0));

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
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(i,vis,s);
            ans = max(ans,get_max(i));
        }
    }
    return ans;
}


int main()
{
    // int n= 13;
    // int m= 14;
    // string s = "abcbcccbcadda";
    // int x[m] = {1,1,2,3,4,5,6,6,7,7,12,12,13,13};
    // int y[m] = {2,3,4,5,6,7,10,8,9,11,4,5,4,5};

    ios_base::sync_with_stdio(NULL),cin.tie(0);
    int n;
    int m;
    string s;
    cin>>n>>m>>s;

    int x[m];
    int y[m];
    for(int i=0;i<m;i++){
        cin>>x[i];
        cin>>y[i];
    }
    // int n= 5;
    // int m= 4;
    // string s = "abaca";
    // int x[m] = { 1,1,3,4};
    // int y[m] = { 2,3,4,5};
    cout<<beauty(n,m,s,x,y);
    return 0;
}
