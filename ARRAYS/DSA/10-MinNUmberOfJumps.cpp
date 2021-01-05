
// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){
    // Your code here
    int idx_covered = 0;
    vector<int> dp(n,0);
    for(int i=0;i<n;i++){
        if(arr[i]==0 && idx_covered==i)
            return -1;
        if(idx_covered>=n-1){
            return dp[n-1];
        }
        int x = i+arr[i];
        for(int j=idx_covered+1;j<=x&&j<n;j++)
            dp[j]=dp[i]+1;
        idx_covered=max(idx_covered,x);
    }
    return dp[n-1];
}