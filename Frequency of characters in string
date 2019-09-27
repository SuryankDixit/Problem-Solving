//Finding the frequency of each character in the string using STL:
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main()
{
    unordered_map<char,int> m;
    string s;
    cout<<"Enter String :";
    cin>>s;
    for(int i=0;i<s.size();i++)
    m[s[i]]++;
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<< i->first<<"  ::  "<<i->second<<endl;
    }
    return 0;
}
