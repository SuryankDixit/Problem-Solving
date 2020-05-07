
//20. Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                stk.push(s[i]);
            else
            {
                switch(s[i])
                {
                    case ')':
                        if( !stk.empty() && stk.top()=='(' )
                            stk.pop();
                        else
                            return false;
                        break;
                    case ']':
                        if(!stk.empty() && stk.top()=='[')
                            stk.pop();
                        else
                            return false;
                        break;
                    case '}':
                        if(!stk.empty() && stk.top()=='{')
                            stk.pop();
                        else
                            return false;
                        break;
                }
            }
        }
        if(!stk.empty())
            return false;
        return true;
    }
};