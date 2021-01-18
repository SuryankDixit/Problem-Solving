class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx1=-1;
        int idx2;
        
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                idx1=i-1;
                break;
            }
        }
        
        if(idx1==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int temp = nums[idx1];
        for(int i=n-1;i>idx1;i--){
            if(nums[i]>temp){
                idx2=i;
                break;
            }
        }
        
        swap(nums[idx1],nums[idx2]);
        int i=idx1+1;
        reverse(nums.begin()+i,nums.end());
        
        return;
    }
};
