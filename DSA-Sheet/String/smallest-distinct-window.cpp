
string findSubString(string str)
{
    unordered_set<char> s;
    for(auto x:str)
        s.insert(x);
    
    unordered_map<char,int> m;
    int len = s.size();
    
    int start = 0;
    int end =0;
    int ans = INT_MAX;
    int l =0;
    int r =0;
    
    for(start =0 ; start < str.size() ;start++){
        m[str[start]]++;
        
        while(m.size() == len){
            // cout<<l<<" "<<r<<endl;
            if(start-end+1 < ans){
                l = end;
                r = start;
                ans = start-end+1;
            }
            m[str[end]]--;
            if(m[str[end]] == 0)
                m.erase(str[end]);
            end++;
        }
    }
    // cout<<l<<" "<<r<<endl;
    string res = str.substr(l,r-l+1);
    // cout<<res<<endl;
    return res;
}