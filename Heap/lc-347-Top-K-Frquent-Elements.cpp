class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto x:nums)
            m[x]++;
        priority_queue<pi,vector<pi>,greater<pi>> p;
        for(auto t:m){
            if(p.size()>=k){
                auto x = p.top();
                if(x.first < t.second){
                    p.pop();
                    p.push({t.second,t.first});
                }
            }else{
                // cout<<nums[i]<<" "<<m[nums[i]]<<endl;
                p.push({t.second,t.first});
            }
        }
        vector<int> ans;
        while(!p.empty()){
            auto x = p.top();
            p.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};