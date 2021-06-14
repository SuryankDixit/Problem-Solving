https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    
    bool isValid(vector<int> &v,int mid,int m){
        int sum=0;
        int i=0;
        int cnt=1;
        while(i<v.size()){
            sum+=v[i];
            if(sum>mid){
                cnt++;
                if(cnt>m)
                    return false;
                sum=v[i];
            }
            i++;
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int r=0;
        int l=INT_MIN;
        for(int i=0;i<nums.size();i++){
            l=max(l,nums[i]);
            r+=nums[i];
        }
        // cout<<l<<" "<<r;
        int ans=0;
        while(l<=r){
            int mid = (l+r)/2;
            // cout<<l<<" "<<r<<" "<<mid<<endl;
            if(isValid(nums,mid,m)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};