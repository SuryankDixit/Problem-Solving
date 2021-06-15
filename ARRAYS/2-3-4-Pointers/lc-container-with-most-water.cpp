https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int ans=INT_MIN;
        int l=0,r=n-1;
        int Min=INT_MAX,Max=INT_MIN;
        while(l<r){
            ans = max(ans, (r-l)*min(h[l],h[r]));
            if(h[l]>h[r])
                r--;
            else
                l++;
        }
        return ans;
    }
};