class Solution {
public:
    int minSteps(int n) {
        int count=0;
        int current=1;
        int copied=0;
        while(current<n)
        {
            int rem=n-current;
            if(rem%current==0)
            {
                copied=current;
                current=current+copied;
                count+=2;
            }
            else
            {
                current=current+copied;
                ++count;
            }
        }
        return count;
    }
};