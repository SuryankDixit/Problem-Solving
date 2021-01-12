class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        if(n==1)
            return nums;
        int num1 ,num2,cnt1,cnt2;
        num1=num2=-1;
        cnt1=cnt2=0;
        for(int i=0;i<n;i++){
  
            if(num1==nums[i])
                cnt1++;
            else if(num2==nums[i])
                cnt2++;
            else if(cnt1==0){
                num1=nums[i];
                cnt1++;
            }
            else if(cnt2==0){
                num2=nums[i];
                cnt2++;
            }
            else{
                cnt1--;cnt2--;
            }
        }
        cout<<num1<<" "<<num2<<cnt1<<" "<<cnt2;
        cnt1=cnt2=0;
        for(auto x:nums){
            if(x==num1)
                cnt1++;
            else if(x==num2)
                cnt2++;
        }
        cout<<cnt1<<" "<<cnt2;
        if(cnt1>n/3)
            ans.push_back(num1);
        if(cnt2>n/3)
            ans.push_back(num2);
        
        return ans;
    }
};
