class Solution {
public:
    typedef pair<char,int> pi;
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<pi> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push({'(',i});
            else if(s[i]==')'){
                if(!st.empty()&& st.top().first=='(')
                    st.pop();
                else
                    st.push({')',i});
            }
        }
        unordered_set<int> m;
        while(!st.empty()){
            m.insert(st.top().second);
            st.pop();
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(m.find(i)==m.end()){
                ans+=s[i];
            }
        }
        return ans;
    }
};