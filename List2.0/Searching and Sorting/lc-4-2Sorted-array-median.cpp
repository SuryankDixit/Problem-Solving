class Solution {
public:
    int n1,n2;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1.size();
        n2=nums2.size();
        if(n1>n2)
            return findMedianSortedArrays(nums2,nums1);
        
        int l=0,r=n1;
        while(l<=r){
            int cut1 = (l+r)/2;
            int cut2 = (n1+n2+1)/2-cut1;
            
            // cout<<cut1<<" "<<cut2<<endl;
            
            int l1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            // cout<<l1<<" "<<cut2-1<<" "<<nums2[0];
            int l2 = cut2==0 ? INT_MIN : nums2[cut2-1];
            // cout<<l2;
            
            // cout<<l1<<" "<<l2<<endl;
            
            int r1 = cut1==n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2==n2 ? INT_MAX : nums2[cut2];
            
            // cout<<r1<<" "<<r2<<endl;
            
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }else
                    return max(l1,l2);
            }
            else if(l1>r2)
                r=cut1-1;
            else
                l=cut1+1;
        }
        return 0.0;
    }
};