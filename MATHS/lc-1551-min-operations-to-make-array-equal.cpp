#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // n = 6=> 1 3 5 7 9 11   (avg=6)
    // n = 5=> 1 3 5 7 9      (avg=5)
    // n = 4=> 1 3 5 7        (avg=4)
    
    int minOperations(int n) {
        int ans=0;
        for(int i=0;i<n/2;i++){
            ans+=n-2*i-1;
        }
        return ans;
    }
};

//return n*(n/4);