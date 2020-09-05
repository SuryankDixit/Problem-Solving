class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        // if(n==1)
        //     return {"()"};
        vector<string> ans;
        string str="";
        dfs(ans,str,n,n);
        return ans;
    }

    void dfs(vector<string> &ans, string &s,int left,int right){
        
        if(left==0 && right ==0){
            ans.push_back(s);
            return ;
        }
        
        if(left>0){
            s += "(";
            dfs(ans,s,left-1,right);
            s.pop_back();
        }
        if(right>left){         // this condition checking is for valid bracket formation.
            s += ")";
            dfs(ans,s,left,right-1);
            s.pop_back();
        }
    }
};
