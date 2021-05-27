
/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

*/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26,0);
        //int flag=0;
        for(int i=0;i<s.size();i++)
        {
            v[s[i]%97]++;
        }
        int j;
        for(j=0;j<s.size();j++)
        {
                if(v[s[j]%97]==1)
                 return j;
        }
        return -1;
        
    }
};