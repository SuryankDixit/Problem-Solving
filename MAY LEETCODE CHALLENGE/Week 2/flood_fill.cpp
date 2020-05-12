/*
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int new_color) {
        int old_color=image[sr][sc];
        if(old_color==new_color)
            return image;
        dfs(image,sr,sc,new_color,old_color);
        return image;
    }
    void dfs(vector<vector<int>>& image,int x,int y,int new_color,int old_color)
    {
        int rows=image.size();
        int cols=image[0].size();
        
        if(x<0 || y<0 || x>=rows || x>=cols || image[x][y]!=old_color)
            return;
        if(image[x][y]==old_color)
            image[x][y]=new_color;
        
        dfs(image,x+1,y,new_color,old_color);
        dfs(image,x,y+1,new_color,old_color);
        dfs(image,x-1,y,new_color,old_color);
        dfs(image,x,y-1,new_color,old_color);
    }
};