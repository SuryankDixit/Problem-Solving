class Solution {
public:
    unordered_map<char,string> m;
    
    vector<string> letterCombinations(string digits) {
        m['2'] = "abc"; m['3'] = "def"; m['4'] = "ghi"; m['5'] = "jkl";
        m['6'] = "mno"; m['7'] = "pqrs"; m['8'] = "tuv"; m['9'] = "wxyz";
        
        if(digits.size()==0)
            return {};
        vector<string> ans;
        string s;
        dfs(ans,digits,s,0);
        return ans;
    }
    
    void dfs(vector<string> &ans, string &x, string &s,int index){
        if(index == x.size()){
            ans.push_back(s);
            return ;
        }
        string temp = m[x[index]];
        // cout<<x[index]<<" "<<temp<<endl;
        for(auto k: temp){
            s+=k;
            dfs(ans,x,s,index+1);
            s.pop_back();
        }
        return;
    }
};
