//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *nums, int n) {
	    // code here
	    long long Max = INT_MIN;
        long long product = 1;
        for(int i =0;i<n;i++){
            
            product *= nums[i];
            Max = max(Max,product);
            if(nums[i]==0){
                product=1;
            }
        }
        
        product =1;
        for(int i =n-1;i>=0;i--){
            
            product *= nums[i];
            // cout<<product<<" ";
            Max = max(Max,product);
            if(nums[i]==0){
                product=1;
            }
        }
        return Max;
	}
};
