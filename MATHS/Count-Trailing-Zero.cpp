class Solution {
public:
    
//     The idea is to consider prime factors of a factorial n. A trailing zero is always produced by prime factors 2 and 5. If we can count the number of 5s and 2s, our task is done. Consider the following examples.
// n = 5: There is one 5 and 3 2s in prime factors of 5! (2 * 2 * 2 * 3 * 5). So a count of trailing 0s is 1.
// n = 11: There are two 5s and eight 2s in prime factors of 11! (2 8 * 34 * 52 * 7). So the count of trailing 0s is 2.
    
    int trailingZeroes(int n) 
    {
        int count=0;
        while(n>0)
        {
            count = count+n/5;
            n=n/5;
        }
        return count;
    }
};