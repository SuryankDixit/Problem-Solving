class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> p;
        for(int i=0;i<nums.size();i++){
            if(p.size()>=k){
                if(p.top()<nums[i]){
                    p.pop();
                    p.push(nums[i]);   
                }
            }else{
                p.push(nums[i]);
            }
        }
        return p.top();
    }
};