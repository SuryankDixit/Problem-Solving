#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    
    void dfs(int i,int j,vector<vector<char>> &v){
        if(i<0||j<0||i>=v.size()||j>=v[0].size()){
            return;
        }
        
        if(v[i][j]!='1'){
            return;
        }
        
        v[i][j]='0';
        for(int x=0;x<8;x++){
            dfs(i+dx[x],j+dy[x],v);
        }
        return; 
    }

    int numIslands(vector<vector<char>>& v) {
        int n=v.size();
        int n1=v[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n1;j++){
                if(v[i][j]=='1'){
                    cnt++;
                    dfs(i,j,v);
                }
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends