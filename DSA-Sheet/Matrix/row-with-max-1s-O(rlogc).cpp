//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > matrix, int r, int c) {
	    // code here
	    int Min=INT_MAX;
	    int ans=-1;
	    for(int i=0;i<r;i++){
            auto idx = lower_bound(matrix[i].begin(), matrix[i].end() ,1)-matrix[i].begin();
            // cout<<idx<<" ";
            if(idx<Min && matrix[i][idx]==1){
                Min=idx;
                ans=i;
            }
        }
        // cout<<endl;
        return ans;
	}

};
