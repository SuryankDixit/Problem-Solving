class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> a;
        int i=0;
        while(i<n){
            char ch = s[i];
            if(!a.empty() && a.top()==ch){
                a.pop();
            }
            else
                a.push(s[i]);
            
            i++;
        }
        s="";
        while(!a.empty()){
            char ch = a.top();
            a.pop();
            s+=ch;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};