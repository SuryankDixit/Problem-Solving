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