class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int n=arr.size();
        int local,gmin,gmax,global;
        global = local = gmin = gmax = 0;
        int Min=arr[0];int Max=arr[0];
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            local = arr[i];
            // global += arr[i];
            gmax = max(gmax+local,local);
            gmin = min(gmin+local,local);
            Max = max(Max,gmax);
            Min = min(Min,gmin);
            // cout<<gmax<<" "<<Max<<" "<<gmin<<" "<<Min<<endl;
        }
        int res = max(Max,sum-Min);
        
        // If all numbers are negative, maxSum = max(A) and minSum = sum(A).
        // In this case, max(maxSum, total - minSum) = 0, which means the sum of an empty subarray.
        // According to the deacription, We need to return the max(A), instead of sum of am empty subarray.
        // So we return the maxSum to handle this corner case.
        if(Max>0)       
            return res;
        return Max;
    }
};