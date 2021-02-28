
class Solution
{
    public:
        int patternCount(string s) 
        { 
            int cnt=0;
            int i=1;
            char ch=s[0];
            while(i<s.size()){
                if(s[i]=='0'&&ch=='1'){
                    while(s[i]=='0')
                        i++;
                    if(s[i]=='1')
                        cnt++;
                }
                ch=s[i];
                i++;
            }
            return cnt;
        } 

};
