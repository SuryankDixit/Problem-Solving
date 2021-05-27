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
