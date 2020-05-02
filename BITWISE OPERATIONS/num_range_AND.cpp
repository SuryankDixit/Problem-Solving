// THERE IS A PATTERN TO LOOK, 

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        int count=0;
        while(m!=n)
        {
            m=m>>1;
            n=n>>1;
            count++;
        }
        return m<<=count;
}
};
