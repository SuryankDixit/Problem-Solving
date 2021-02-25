class Solution {
public:
    // string _sort(string x){
    //     vector<int> v(26,0);
    //     for(auto c:x){
    //         v[c-'a']++;
    //     }
    //     string ans="";
    //     for(int i=0;i<26;i++){
    //         while(v[i]){
    //             ans+= 'a'+i;
    //             v[i]--;
    //         }
    //     }
    //     return ans;
    // }
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        if(p.length()>s.length())
            return {};
        vector<int>mp(256),m(256);
        int i;
        for(i=0;i<p.length();i++){
            mp[p[i]]++;
            m[s[i]]++;
    }
        for(;i<s.length();i++)
        {
            
            if(mp==m)
                res.push_back(i-p.length());
            m[s[i]]++;
            m[s[i-p.length()]]--;
        }
        if(mp==m)
            res.push_back(i-p.length());
        return res;
    }
};