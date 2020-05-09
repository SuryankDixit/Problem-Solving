/*
85. Maximal Rectangle
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6

*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.size()==0)
            return 0;
        
        int row=matrix.size();
        int col=matrix[0].size();
        
        int max_area=0;
        vector<int> h(col+1,0);
        
        for(int i=0;i<row;i++)
        {
            stack<int> s;
            for(int j=0;j<col+1;j++)
            {
                if(j<col)
                {
                    if(matrix[i][j]=='1')
                        h[j]+=1;
                    else
                        h[j]=0;
                }
                while(!s.empty() && h[j]<h[s.top()])
                {
                    int k=h[s.top()];
                    s.pop();
                    int left_smaller= s.empty() ? -1 : s.top();
                    max_area=max(max_area, (j-left_smaller-1)*k);
                }
                s.push(j);
            }
        }
        return max_area;
    }
};