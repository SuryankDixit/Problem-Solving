class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int n = s.size();
        if(n==0)
            return 0;
        int i=0;int j=0;
        int ans=1;
        for(j=0;j<n;j++){
            while(m.find(s[j]) !=m.end()){
                // cout<<i<<" "<<j<<" "<<s[i]<<endl;
                m[s[i]]--;
                if(m[s[i]]==0)
                    m.erase(s[i]);
                i++;
            }
            m[s[j]]++;
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};