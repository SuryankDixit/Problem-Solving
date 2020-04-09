class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
        vector<int> v(256,0);
        int count=0;
        int start=0;
        int Max=INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            if(v[s[i]]==0)
            {
                count++;
                v[s[i]]++;
            }
            else
            {
                Max=max(Max,count) ;
                while(s[start]!=s[i])
                    v[s[start++]]=0;
                    
                count=i-start;
                start++;
                v[s[i]]=1;
            }
         //  cout<<count<<" "<<Max<<endl;
        }
        Max=max(Max,count);
        
        return Max;
    }
};
