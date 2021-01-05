
// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    
    
    int local=0;
    int global = 0;
    int sum = INT_MIN;
    for(int i=0;i<n;i++){
        
        local = arr[i];
        global = global + arr[i];
        if(local > global)
            global = local;
            
        sum = max(sum,global);
   }
   return sum;
    
    // Your code here
    
}