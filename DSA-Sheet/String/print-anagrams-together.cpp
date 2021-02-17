//User function Template for C++
vector<vector<string> > Anagrams(vector<string>& l) 
{
    unordered_map<string,vector<string>> m;
    
    for(string x:l){
        string s = x;
        sort(x.begin(),x.end());
        m[x].push_back(s);
    }
    
    vector<vector<string>> ans;
    for(string x: m){
        auto y = 
        ans.push_back(y);
    }
    return ans;
}