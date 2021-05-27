class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> v;
        if(matrix.size()==0)
            return v;
        int dir =0;
        // vector<int> v;
        int left,right,top,down;
        left=0;
        right=matrix[0].size()-1;
        top=0;
        down=matrix.size()-1;
        
        while(top<=down && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++)
                    v.push_back(matrix[top][i]);
                top++;
                dir=1;
            }
            else if(dir==1){
                for(int i=top;i<=down;i++)
                    v.push_back(matrix[i][right]);
                right--;
                dir=2;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--)
                    v.push_back(matrix[down][i]);
                down--;
                dir=3;
            }
            else if(dir==3){
                for(int i=down;i>=top;i--)
                    v.push_back(matrix[i][left]);
                left++;
                dir=0;
            }
        }
        return v;
    }
};
