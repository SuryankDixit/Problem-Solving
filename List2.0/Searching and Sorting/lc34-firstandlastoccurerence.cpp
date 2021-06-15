class Solution {
public:
    int n;
    
    int bs_first(vector<int> &nums,int x){
        int l=0,r=n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]>=x)
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
    
    int bs_last(vector<int> &nums,int x){
        int l=0,r=n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]>x)
                r=mid-1;
            else
                l=mid+1;
        }
        return r;
    }
    
    vector<int> searchRange(vector<int>& nums, int x) {
        n=nums.size();
        vector<int> v(2,-1);
        if(n==0)
            return v;
        int i1 = bs_first(nums,x);
        int i2 = bs_last(nums,x);
        cout<<i1;
        if(i1>=0 && i1<n && nums[i1]==x)
            v[0]=i1;
        if(i2>=0 && i2<n && nums[i2]==x)
            v[1]=i2;
        return v;
    }
};