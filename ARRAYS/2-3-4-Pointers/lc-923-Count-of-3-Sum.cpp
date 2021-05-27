class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<3)
            return 0;
    
        int mod=1e9+7;
        long long int ans = 0;
        unordered_map<int,long long int> m;
        for(auto x:nums)
            m[x]++;
        for(int i=0;i<101;i++){
            for(int j=i;j<101;j++){
                int sum = i+j;
                int k = target-sum;
                if(k>100||k<0) continue;
                
                if(i==j && j==k)
                    ans += ((m[i]*(m[i]-1)*(m[i]-2))/6)%mod;
                else if(i==j && j!=k)
                    ans += ((m[i]*(m[i]-1)*m[k])/2)%mod;
                else if(i<j && j<k)
                    ans += (m[i]*m[j]*m[k])%mod;
            }
        }
        return ans%mod;
    }
};