class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        
        
        int n = A.size();
        vector<int> ps(n+1,0);
        for(int i=1;i<=n;i++){
            ps[i] = ps[i-1]+A[i-1];
        }
        vector<int> cnt(K,0);
        for(int i=0;i<=n;i++){
            
            // Making -ve index to +ve.
            int index = (ps[i]%K+K)%K;
            cnt[index]++;
        }
        
        int ans= 0;
        for(int i=0;i<K;i++){
            if(cnt[i]>=2){
                int x = cnt[i];
                ans += (x*(x-1))/2;
            }
        }
        return ans;
    }
};