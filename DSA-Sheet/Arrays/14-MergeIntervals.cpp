class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> v(2);
        if(intervals.size()==0)
            return ans;
        v[0]=intervals[0][0];
        v[1]=intervals[0][1];
        int end_max=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if(v[1]>=intervals[i][0]){
                end_max = max(end_max,intervals[i][1]);
                v[1]= end_max;
            }else{
                ans.push_back(v);
                v[0]=intervals[i][0];
                v[1]=intervals[i][1];
                end_max=v[1];
            }
        }
        ans.push_back(v);
        return ans;
    }
};