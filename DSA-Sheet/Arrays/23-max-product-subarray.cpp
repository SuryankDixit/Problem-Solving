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


/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> v(nums.size(),1);
        v[0]=nums[0];
        int ans = v[0];
        if(v[0]==0)
            v[0]=1;
        for(int i=1;i<nums.size();i++){
            v[i]=v[i-1]*nums[i];
            ans = max(ans,v[i]);
            if(v[i]==0)
                v[i]=1;
        }
        ans = max(ans,nums[nums.size()-1]);
        if(nums[nums.size()-1]==0)
            nums[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;i--){
            nums[i]=nums[i+1]*nums[i];
            ans=max(ans,nums[i]);
            if(nums[i]==0)
                nums[i]=1;
        }
        return ans;
    }
};
*/