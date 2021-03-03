class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt=0;
        queue<int> rq,cq;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==0)
                    visited[i][j]=1;
                if(grid[i][j]==2)
                {
                    rq.push(i);
                    cq.push(j);
                    visited[i][j]=1;
                }
                if(grid[i][j]==1)
                    cnt++;
            }
        }
        if(cnt==0)
            return 0;
        
        int nodes_in_curr_layer=rq.size();
        int nodes_in_next_layer=0;
        int min=0;
        int row[4]={-1,+1,0,0};
        int col[4]={0,0,-1,+1};
        
        int r,c;
        int rr,cc;
         cout<<nodes_in_curr_layer<<endl;
        while(!rq.empty())
        {
            r=rq.front();
            rq.pop();
            c=cq.front();
            cq.pop();
            
            for(int i=0;i<4;i++)
            {
                rr=r+row[i];
                cc=c+col[i];
                
                if(rr<0 || cc<0 ) continue;
                if(rr>=grid.size() || cc>=grid[0].size()) continue;
                if(visited[rr][cc]==1) continue;
                if(grid[rr][cc]==1)
                {
                    rq.push(rr);
                    cq.push(cc);
                    visited[rr][cc]=1;
                    nodes_in_next_layer++;
                }
            }
           // cout<<nodes_in_curr_layer<<" "<<nodes_in_next_layer<<endl;
            nodes_in_curr_layer--;
            
            if(nodes_in_curr_layer==0)
            {
                nodes_in_curr_layer=nodes_in_next_layer;
                nodes_in_next_layer=0;
                min++;
            }
        }
        for(int i=0;i<visited.size();i++)
        {
            for(int j=0;j<visited[i].size();j++)
            {
                if(visited[i][j]==0)
                    return -1;
            }
        }
        return min-1;
    }
};
