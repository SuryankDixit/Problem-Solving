class Solution {
public:
    typedef pair<int,int> pi;
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)
            return -1;
        if(n==1 &&grid[0][0]==0)
            return 1;
        int dy[]={-1,-1,-1,0,0,1,1,1};
        int dx[]={-1,0,1,-1,1,-1,0,1};
        queue<pi> q;
        int level=0;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()){
            int k = q.size();
            level++;
            while(k--){
                auto t = q.front();
                q.pop();
                for(int i=0;i<8;i++){
                    int x=dx[i]+t.first;
                    int y=dy[i]+t.second;
                    if(x>=0&&y>=0&&x<n&&y<n && grid[x][y]==0){
                        q.push({x,y});
                        grid[x][y]=1;
                        if(x==n-1&&y==n-1)
                            return level+1;
                    }
                }
            }
        }
        return -1;
    }
};