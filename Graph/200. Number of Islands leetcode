 if(grid.empty()||grid.size()==0) return 0;
				
        int rows=grid.size(),cols=grid[0].size();
        int count=0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    myDFS(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void myDFS(vector<vector<char>>& grid,int x, int y){
        int rows=grid.size();
        int cols=grid[0].size();
        
        if(x<0||y<0||x>=rows||y>=cols||grid[x][y]=='2'||grid[x][y]=='0')
             return;
        if(grid[x][y]=='1') grid[x][y]='2';
        
        myDFS(grid,x+1,y);
        myDFS(grid,x,y+1);
        myDFS(grid,x-1,y);
        myDFS(grid,x,y-1);
    }
