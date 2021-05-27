#include <bits/stdc++.h>
using namespace std;

string ans;

void palindromicPermutation(int index, unordered_map<char,int> &m,int &len, char oddChar){


    // cout<<ans<<endl;
    if(index>len){
        // print ans;
        string temp1 = ans;
        string temp2 = ans;

        if(oddChar != '\0'){
            temp1 += oddChar;
        }

        reverse(temp2.begin(),temp2.end());
        temp1 += temp2;

        cout<<temp1<<endl;
        // for(int i =0;i<temp.size();i++)
        //     ans.pop_back();
        return;
    }

    for(auto x=m.begin();x!=m.end();x++){
        if(x->second>0){

            // cout<<x->first<<" "<<x->second<<endl;
            ans += x->first;
            x->second = x->second-1;
                
            palindromicPermutation(index+1,m,len,oddChar);

            ans.pop_back();
            x->second = x->second+1;
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

    unordered_map<char,int> m;
    for(auto x: s){
        m[x]++;
    }

    char oddChar;
    int oddFreq =0;
    int newLen =0;
    for(auto x=m.begin();x!=m.end();x++){

        if(x->second%2!=0){
            oddChar = x->first;
            oddFreq++;
        }
        x->second = x->second/2;
        newLen += x->second;
    }

    if(oddFreq==0){
        oddChar = '\0';
    }

    // for(auto x: m){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    if(oddFreq>1){
        cout<<"Palindrome not possible";
    }else{
        palindromicPermutation(1,m,newLen,oddChar);
    }

    return 0;
}

//input     aaaabbbbccc

// //output


// cbbaacaabbc
// cbabacababc
// cbaabcbaabc
// cabbacabbac
// cababcbabac
// caabbcbbaac
// bcbaacaabcb
// bcabacabacb
// bcaabcbaacb
// bbcaacaacbb
// bbacacacabb
// bbaacccaabb
// bacbacabcab
// bacabcbacab
// babcacacbab
// babacccabab
// baacbcbcaab
// baabcccbaab
// acbbacabbca
// acbabcbabca
// acabbcbbaca
// abcbacabcba
// abcabcbacba
// abbcacacbba
// abbacccabba
// abacbcbcaba
// ababcccbaba
// aacbbcbbcaa
// aabcbcbcbaa
// aabbcccbbaa
