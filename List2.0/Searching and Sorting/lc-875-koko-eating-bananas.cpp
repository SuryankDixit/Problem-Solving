https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    
    bool isValid(vector<int> &v,int h,int k){
        int hrs=0;
        for(int i=0;i<v.size();i++){
            hrs += v[i]/k;
            if(v[i]%k != 0){
                hrs++;
            }
        }
        // cout<<hrs;
        return hrs<=h;
    }
    
    int minEatingSpeed(vector<int>& v, int h) {
        int n = v.size();
        int l=1;
        int r= INT_MIN;
        for(auto x:v)
            r=max(r,x);
        int ans=r+1;
        while(l<=r){
            int mid = (l+r)/2;
            if(isValid(v,h,mid)){
                ans = mid;
                r=mid-1;
                // cout<<l<<" "<<r;
            }else
                l=mid+1;
        }
        return ans;
    }
};