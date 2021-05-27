class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return 1;
        
        int f,df;
        int cnt=1;
        (arr[0]>arr[1])?df=0:df=1;
        
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            (arr[i]>arr[i-1])?f=1:f=0;
            if(arr[i]==arr[i-1]){
                ans=max(ans,cnt);
                cnt=1;
                continue;
            }
            if(f!=df){
                cnt=2;
            }else{
                cnt++;
                ans=max(ans,cnt);
                df=1-df;
            }
        }
        return ans;
    }
};