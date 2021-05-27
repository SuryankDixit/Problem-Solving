class Solution {
public:
    
    double findMaxAverage(vector<int>& nums, int k) {
        
        double ans =INT_MIN;
        double sum = 0;
        for(int i=0;i<nums.size();i++){
            
            if(i<k)
                sum+=nums[i];
            else{
                ans = max(ans,sum);
                sum += nums[i]-nums[i-k];
            }
        }
        ans = max(sum,ans);
        return ans/k;
    }
};