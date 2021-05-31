class Solution 
{
    public:
    
    vector<int> vis;
    void dfs(int s,int &cnt,vector<int> g[]){
        vis[s]=1;
        for(auto x:g[s]){
            if(vis[x]==1){
                return;
            }else if(vis[x]==0){
                dfs(x,cnt,g);
                cnt++;
            }
        }
        vis[s]=2;
    }
    
    
    
	int findMotherVertex(int V, vector<int>g[])
	{
	    int n = V;
	    int v;
	    vis.resize(n,0);
	    int cnt=0;
	    for(int i=0;i<n;i++){
	        if(vis[i]==0){
	            dfs(i,cnt,g);
	            v=i;
	        }
	    }
	    cnt=0;
	    fill(vis.begin(),vis.end(),0);
	   // cout<<v<<endl;
	    dfs(v,cnt,g);
	   // cout<<cnt<<" ";
	   // cout<<endl;
	   // for(auto x:vis)
	       // cout<<x<<" ";
	    if(cnt==V-1)
	        return v;
	    return -1;
	}
};