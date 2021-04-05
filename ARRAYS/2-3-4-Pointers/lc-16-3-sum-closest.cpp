class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        // if(n==3){
        //     int x=nums[0]+nums[1]+nums[2];
        //     return x;
        // }
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int res=0;
        for(int i=0;i<n;i++){
            int x=target-nums[i];
            int j=i+1;
            int k=n-1;
            while(j<k){
                int y=nums[j]+nums[k];
                int sum = nums[i]+nums[j]+nums[k];
                int diff = abs(target-sum);
                if(diff<ans){
                    res=sum;
                    ans=diff;
                }
                if(y<x){
                    j++;
                }else if(y>x){
                    k--;
                }else if(y==x){
                    int z=y+nums[i];
                    return z;
                }
                // cout<<x<<" "<<y<<" "<<ans<<" "<<j<<" "<<k<<endl;
            }
        }
        return res;
    }
};