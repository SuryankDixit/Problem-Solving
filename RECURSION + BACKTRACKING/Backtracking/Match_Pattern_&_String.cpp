#include <bits/stdc++.h>
using namespace std;

unordered_map<char,string> m;

void patternMatcher(int idx1,string &s,int idx2,string &pattern){

    if(idx1 == s.size() && idx2 == pattern.size()){
        for(auto x:m){
            cout<<x.first<<" "<<x.second<<endl;
        }
        cout<<endl;
        return;
    }

    

    char ch = pattern[idx2];
    if(m.find(ch)!=m.end()){
        
        string temp = m[ch]; 
        int len = temp.size(); 
  
        string subStr = s.substr(idx1, len);  
        if(temp == subStr)
            return patternMatcher(idx1+len,s,idx2+1,pattern);


    }else{
        string temp;
        for (int len = 1; len <= s.size() - idx1; len++) 
        {   
            temp = s.substr(idx1,len);
            m[ch] = temp;
            patternMatcher(idx1+len,s,idx2+1,pattern);
            // temp.pop_back();
            m.erase(ch);
        }
    }
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
  
    string s,pattern;
    getline(cin,s);
    getline(cin,pattern);

    patternMatcher(0,s,0,pattern);
    return 0;
}

//input
// mzaddytzaddy
// abcb

// output

// c t
// b zaddy
// a m

// c tz
// b addy
// a mz

// c tza
// b ddy
// a mza

// c tzad
// b dy
// a mzad

// c tzadd
// b y
// a mzadd

