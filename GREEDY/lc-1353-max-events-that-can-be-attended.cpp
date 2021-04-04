class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n= events.size();
        if(n==0 || n==1)
            return n;
        
        unordered_map<int,vector<int>> m;
        for(auto x:events){
            m[x[0]].push_back(x[1]);
        }
        
        int ans=0;
        priority_queue<int,vector<int>,greater<int>> p;
        for(int d=1;d<100001;d++){
            for(auto x:m[d]){
                p.push(x);
            }
            while(p.size() && p.top()<d){
                p.pop();
            }
            if(p.size()){
                ans++;
                p.pop();
            }
        }
        return ans;
    }
};