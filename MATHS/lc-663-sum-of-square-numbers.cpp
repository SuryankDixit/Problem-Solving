class Solution {
public:
    typedef unsigned long long ll;
    bool judgeSquareSum(int num) {
        ll i=0;ll j=sqrt(num);
        while(i<=j){
            // ll ans = 
            if(i*i+j*j==num)
                return true;
            if(i*i+j*j<num)
                i++;
            else
                j--;
        }
        return false;
    }
};