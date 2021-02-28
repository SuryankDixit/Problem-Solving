#include <bits/stdc++.h>
using namespace std;
 
// s : given string
// return the expected answer
int fun(string &s) {
    int m=1e9+7;
    int a=0;int b=0;int c=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a')
            a=((2*a)%m+1)%m;
        else if(s[i]=='b')
            b=(a+(2*b)%m)%m;
        else if(s[i]=='c')
            c=(b+(2*c)%m)%m;
    }
    return c%m;
}
