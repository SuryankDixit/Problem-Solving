#include <bits/stdc++.h>
using namespace std;

void permute(string s,vector<int> cnt,vector<char> result,int level)
{
    // level tells the depth of recursion and is used as result array index;
    if(level==s.size())
    {
        for(char x:result)
            cout<<x;
        cout<<endl;
        return;
    }
    else
    {
        for(int i=0;i<s.size();i++)
        {
            if(cnt[i]==0)
                continue;
            else
            {
                result[level]=s[i];
                // As we go to the next level we decrement the count to the character which has 
                //been used in th result;
                cnt[i]--;
                permute(s,cnt,result,level+1);
                //When we go back or backtrack the previous level we store the count of the that character.
                cnt[i]++;
            }
        }
    }
}



int main()
{
    string s="abcd";

    // cnt array tells at each step whether character needs to be included(if 1) or not(if 0)
    vector<int> cnt(s.size(),1); 
    // result stores the characters of string while going in depth of recursion.
    vector<char> result(s.size());
    permute(s,cnt,result,0);
    return 0;
}
