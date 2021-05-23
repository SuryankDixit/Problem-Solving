class Solution {
public:
    bool isUgly(int n) {
        if(n<1)
            return false;
        if(n==1)
            return true;
        vector<int> v{2,3,5};
        for(int i=0;i<3;i++){
            while(n%v[i]==0){
                n=n/v[i];
                if(n==1)
                    return true;
            }
        }
        return false;
    }
};