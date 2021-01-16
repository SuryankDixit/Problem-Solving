
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > matrix, int r, int c) {
	    int ans_row=-1;
	    int j=c-1;
	    for(int i=0;i<r;i++){
	        while(j>=0 && matrix[i][j]==1){
	            j--;
	            ans_row=i;
	        }
	        if(j<0)
	            return ans_row;
	    }
	    return ans_row;
	}
};
