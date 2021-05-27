#include <bits/stdc++.h>
using namespace std;

string ans;
int n;

bool isPalindrome(string &temp1){

    if(temp1.size()==1)
        return true;

    string temp2 = temp1;
    reverse(temp2.begin(),temp2.end());
    if(temp1==temp2)
        return true;
    return false;

}


void palindromePartitioning(int index,string &s){

    if(index>=n){

        cout<<ans<<endl;
        return;
    }

    string temp;
    for(int i =index;i<n;i++){

        temp += s[i];
        if(isPalindrome(temp)){
            ans  += "("+temp+")";
            palindromePartitioning(index+temp.size(),s);
            ans.pop_back();
            for(int j=0;j<temp.size();j++)
                ans.pop_back();
            ans.pop_back();
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
  
    
    string s;
    cin>>s;

    n=s.size();
    palindromePartitioning(0,s);

    return 0;
}

//input
// abaaba

//output
// (a)(b)(a)(a)(b)(a)
// (a)(b)(a)(aba)
// (a)(b)(aa)(b)(a)
// (a)(baab)(a)
// (aba)(a)(b)(a)
// (aba)(aba)
// (abaaba)
