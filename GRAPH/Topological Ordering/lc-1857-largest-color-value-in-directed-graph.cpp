class Solution {
public:
    
    const int N = 1e5+5;
    vector<int> g[100005];
    vector<int> vis;
    int ans = INT_MIN;
    vector<vector<int>> cnt;
    int flag=0;
    
    void fill_max(int s,int d){
        for(int i=0;i<26;i++){
            cnt[s][i]= max(cnt[s][i],cnt[d][i]);
        }
        return;
    }
    
    int get_max(int idx){
        int mx=0;
        for(int i=0;i<26;i++)
            mx = max(mx,cnt[idx][i]);
        return mx;
    }

    
    void dfs(int i,string &s){
        vis[i]=1;

        for(auto x:g[i]){
            if(vis[x]==0){
                dfs(x,s);
                if(flag==1)
                    return ;
            }else if(vis[x]==1){
                flag=1;
                return;
            }
            fill_max(i,x);
        }
        cnt[i][s[i]-'a']++;
        vis[i]=2;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++)
            g[edges[i][0]].push_back(edges[i][1]);
        
        int n = colors.size();
        vis.resize(N,0);
        cnt.resize(n,vector<int>(26,0));
        
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,colors);
                if(flag==1)
                    return -1;
                // ans = max(ans,get_max(i));
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
                ans=max(ans,cnt[i][j]);
        }
        return ans;
    }
};