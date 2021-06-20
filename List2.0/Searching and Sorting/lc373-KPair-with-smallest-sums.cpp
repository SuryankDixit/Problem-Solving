// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
class Solution {
public:
    typedef pair<int,pair<int,int>> pi;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size();
        int n2=nums2.size();
        priority_queue<pi,vector<pi>,greater<pi>> p;
        for(int i=0;i<min(k,n1);i++){
            p.push({nums1[i]+nums2[0],{i,0}});
        }
        vector<vector<int>> ans;
        int nr,dr=0;
        for(int i=0;i<k&&!p.empty();i++){
            // cout<<p.size()<<" ";
            auto x = p.top();
            p.pop();
            nr = x.second.first;
            dr = x.second.second;
            ans.push_back({nums1[nr],nums2[dr]});
            dr++;
            if(dr<n2){
                p.push({nums1[nr]+nums2[dr],{nr,dr}});
            }
        }
        return ans;
    }
};
