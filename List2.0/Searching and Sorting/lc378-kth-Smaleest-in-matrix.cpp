// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/


class Solution {
public:
    typedef pair<int,pair<int,int>> pi;
    int kthSmallest(vector<vector<int>>& m, int k) {
        int n = m.size();
        vector<int> idx(n,0);
        priority_queue<pi,vector<pi>,greater<pi>> p;
        for(int i=0;i<n;i++){
            p.push({m[i][0],{i,0}});
        }
        int ans=INT_MAX;
        while(!p.empty()&&k>0){
            auto x = p.top();
            p.pop();
            int num = x.first;
            int row = x.second.first;
            int col = x.second.second;
            idx[row] = col+1;
            if(col+1<n)
                p.push({m[row][col+1],{row,col+1}});
            ans = num;
            k--;
        }
        return ans;
    }
};
