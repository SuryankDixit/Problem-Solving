class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        map<int,int> r,c;
        vector<int> row,col;
        int ans=0;
        for(int i=0;i<grid.size();i++){
            int sum = accumulate(grid[i].begin(),grid[i].end(),0);
            // r[i] =sum;
            if(sum>1){
                row.push_back(i);
                // cout<<i<<" ";
                ans+=sum;
            }
        }
        
        // cout<<endl;
        for(int i=0;i<grid[0].size();i++){
            int sum=0;
            for(int j=0;j<grid.size();j++){
                sum+=grid[j][i];
            }
            // c[i] =sum;
            if(sum>1){
                col.push_back(i);
                // cout<<i<<" ";
                ans+=sum;
            }
        }
        
        // cout<<ans;

        for(int i=0;i<row.size();i++){
            for(int j=0;j<col.size();j++){
                // cout<<i<<" "<<j<<" "<<grid[i][j]<<endl;
                ans-= grid[row[i]][col[j]];
            }
        }
        
        return ans;
    }
};