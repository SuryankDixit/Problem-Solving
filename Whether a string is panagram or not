include <bits/stdc++.h>

using namespace std;

int main()
{
string s;
cout<< "Enter the string to check :";
cin>>s;
pangrams(s);
}


void pangrams(string s) {
vector<int> mark(26,1);
int index;
for(int i=0;i<s.size();i++)
{
    if(s[i]>='A'&&s[i]<='Z')
        index=s[i]-'A';             // or mark[s[i]%65]--;
    else if(s[i]>='a'&&s[i]<='z')
      index=s[i]-'a';              //  or mark[s[i]%97]--;
    mark[index]=0;
}
for(int i=0;i<26;i++)
{
    if(mark[i]!=0)                // or      (mark[i]!=1)?cout<<"Panagram":"Not Panagram";
      cout<<"not pangram";
}
cout<< "pangram";
}
