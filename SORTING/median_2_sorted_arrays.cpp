// TIME: O(m+n)
// SPACE: O(m+n)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
        
        int i=0,j=0;
        vector<int> v;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }else if(nums1[i]>nums2[j]){
                v.push_back(nums2[j]);
                j++;
            }else if(nums1[i]==nums2[j]){
                v.push_back(nums1[i]);
                v.push_back(nums2[j]);
                i++;j++;
            }
        }
        while(i<n){
            v.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            v.push_back(nums2[j]);
            j++;
        }
        int mid1=v.size()/2;
        if(v.size()%2!=0)
            return (double)(v[mid1]);
        int mid2=(v.size()-1)/2;
        // cout<<v[mid1]<<" "<<v[mid2];
        double x = (double)(v[mid1]+v[mid2])/2;
        return x;
    }
};
