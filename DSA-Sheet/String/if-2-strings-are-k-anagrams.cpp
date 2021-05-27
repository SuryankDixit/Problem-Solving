
#include<bits/stdc++.h>

/*Complete the function below*/
bool areKAnagrams(string str1, string str2, int k){
    
    unordered_map<char,int> m1,m2;
    
    for(auto x:str1){
        m1[x]++;
    }
    
    for(auto x: str2){
        if(m1.find(x)==m1.end()){
            m2[x]++;
        }else{
            m1[x]--;
            if(m1[x]==0)
                m1.erase(x);
        }
    }
    
    int cnt1=0;
    int cnt2=0;
    for(auto x: m1)
        cnt1+=x.second;

    for(auto x: m2)
        cnt2+=x.second;
    
    if( (cnt1 == cnt2) && cnt1<=k)
        return true;
    return false;
}



// Input:
// 1
// fodr gork
// 2
// Output:
// 1

// Explanation:
// Testcase1: change fd to gk

