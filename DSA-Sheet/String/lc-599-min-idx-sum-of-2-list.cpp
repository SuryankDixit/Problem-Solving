class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        vector<string> ans;
        unordered_map<string,int> m;
        unordered_map<int,vector<string>> m1;
        
        for(int i=0;i<list1.size();i++)
            m[list1[i]]=i ;
        
        int Min=INT_MAX;
        for(int i=0 ; i<list2.size();i++){
            if(m.find(list2[i])!=m.end()){
                int key = i+m[list2[i]];
                m1[key].push_back(list2[i]);
                Min=min(key,Min);
            }
        }
        ans = m1[Min];
        return ans;
    }
};