class Solution {
public:
    string addStrings(string nums1, string nums2) {
        int i=nums1.size()-1;
        int j = nums2.size()-1;
        int carry=0;
        string ans = "";
        while(i>=0 || j>=0 || carry){
            long sum=0;
            if(i>=0)
                sum += (nums1[i]-'0'); i--;
            if(j>=0)
                sum += (nums2[j]-'0'); j--;
            sum+=carry;
            carry= sum/10;
            sum = sum%10;
            ans+=to_string(sum);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};