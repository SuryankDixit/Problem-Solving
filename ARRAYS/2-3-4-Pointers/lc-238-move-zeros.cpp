class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j=0;
        for(int i=0;i<n;i++){
            // cout<<nums[i]<<" ";
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
        }
        for(j=j;j<n;j++)
            nums[j]=0;
    }
};