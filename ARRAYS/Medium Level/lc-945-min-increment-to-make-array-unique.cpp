#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        
        sort(A.begin(), A.end());
        int ans = 0;                
        int need_in_next_idx = 0;   // need 0 at 0th index
        
        for (auto x: A) {
            ans += max(need_in_next_idx - x, 0);
            need_in_next_idx = max(need_in_next_idx , x)+1;
        }
        return ans;
    }
};



// class Solution {
// public:
//     int minIncrementForUnique(vector<int>& A) {
        
//         sort(A.begin(), A.end());
//         int ans = 0;                
//         for(int i=1;i<A.size();i++){
//             if(A[i]<=A[i-1]){
//                 ans+=A[i-1]+1-A[i];
//                 A[i] = A[i-1]+1;
//             }
//         }
//         return ans;
//     }
// };