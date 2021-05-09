#include<bits/stdc++.h>
using namespace std;


int numberOfSubarray(int size,vector<int> v,int x){
    int idx=-1;
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        return 0;
    }

    unordered_map<int,int> m1,m2;
    m1[0]=m1[1]=m2[0]=m2[1]=0;
    int mx,mn;
    mx=mn=0;
    for(int i=idx-1;i>=0;i--){
        if(v[i]>x){
            mx++;
        }else{
            mn++;
        }
        m1[mx-mn]++;
    }
    mx=mn=0;
    for(int i=idx+1;i<v.size();i++){
        if(v[i]>x){
            mx++;
        }else{
            mn++;
        }
        m2[mx-mn]++;
    }

    int cnt=1;
    cnt = cnt + m1[0]+ m1[1]+ m2[0]+ m2[1];
    for(auto x1:m1){
        int n = x1.first;
        if(m2.find(-1*n)!=m2.end()){
            cnt+= x1.second*m2[-1*n];
        }
        if(m2.find(-1*(n-1))!=m2.end()){
            cnt+= x1.second*m2[-1*(n-1)];
        }
    }
    return cnt;
}


int main(){
    int x=3;
    vector<int> v{4,1,3,5,2};
    cout<<numberOfSubarray(5,v,x);
}