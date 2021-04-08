class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        int ans=0;
        int prev=0;// number of valid subarrays ending with previous element.
        int idx=-1;//index of last element > R
        for(int i=0;i<n;i++){
            if(A[i]>R){
                prev=0;
                idx=i;
            }else if(A[i]<L){
                ans+=prev;
            }else{
                ans+=i-idx;
                prev=i-idx;
            }
        }
        return ans;
    }
};