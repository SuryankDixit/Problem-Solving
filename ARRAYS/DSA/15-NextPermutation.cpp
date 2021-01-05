class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int idx=-1,idx2,temp;
        
        if(n==1 || n==0)
            return;

        for(int i = n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                idx=i-1;
                temp= nums[i-1];
                break;
            }
        }
         if(idx==-1){
             reverse(nums.begin(),nums.end());
             return;
         }
        cout<<idx<<" "<<temp<<endl;
        int x=nums[n-1];
        for(int i=n-1;i>idx;i--){
            if((x>nums[i] && x>temp) || x<=temp){
                x=nums[i];
                idx2=i;
            }
        }
        cout<<x<<" "<<idx2<<endl;
        swap(nums[idx],nums[idx2]);
        int i = idx+1;
        int j = n-1;
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};