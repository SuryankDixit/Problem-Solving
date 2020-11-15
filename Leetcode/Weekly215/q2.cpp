class Solution {
public:
    bool closeStrings(string w1, string w2) {
        vector<int> f1(26,0);
        vector<int> f2(26,0);
        for(auto x:w1)
            f1[x-'a']++;
        for(auto x:w2)
            f2[x-'a']++;
        
        for(int i=0;i<26;i++){
            if(f1[i] && !f2[i] || f2[i] && !f1[i])
                return false;
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        return f1==f2;
    }
};
