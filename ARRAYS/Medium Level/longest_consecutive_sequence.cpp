/*

sorting based solution O(nlogn) time O(n) space

Hashtable based O(n) time and space


*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int count=0;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        
        
        for(int itr=0;itr<nums.size();itr++){
            
            if(s.find(nums[itr])==s.end())
                continue;
            int n= nums[itr];
            s.erase(n);
            int prev = n-1;
            int next = n+1;
            
            // Expand search in both sides.
            while(s.find(prev)!=s.end()){
                s.erase(prev);
                --prev;
            }
            while(s.find(next)!=s.end()){
                s.erase(next);
                ++next;
            }
            count= max(count, next-prev-1);
        }
        return count;
    }
};
