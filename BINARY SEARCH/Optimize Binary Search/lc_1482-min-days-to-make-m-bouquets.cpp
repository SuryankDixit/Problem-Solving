/*
Given an integer array bloomDay, an integer m and an integer k.

We need to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let's see what happened in the first three days. x means flower bloomed and _ means flower didn't bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
*/

class Solution {
public:
    
    bool isValid(vector<int>& bloomDay, int m, int k,int mid){
        
        int a=k;
        int bCnt=0;
        int fCnt=0;
        for(auto x: bloomDay){
            if(x<=mid){
                fCnt++;
                if(fCnt == k){
                    fCnt=0;
                    bCnt++;
                }
            }else{
                fCnt=0;
            }
        }
        if(bCnt>=m)
            return true;
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        if(m*k>n)
            return -1;
        
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = INT_MAX;
        
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isValid(bloomDay,m,k,mid)){
                ans = min(mid,ans);
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};
