class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return 0;
        vector<bool> v(n,true);
        v[0]=v[1]=false;
        for(int i=2;i<sqrt(n) ;i++){
            if(v[i]){
                for(int j=i*i;j<n;j+=i){
                    v[j]=false;
                }
            }
        }
        return count(v.begin(),v.end(),true);
    }
};