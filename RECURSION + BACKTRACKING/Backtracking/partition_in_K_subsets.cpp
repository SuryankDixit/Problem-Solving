#include <bits/stdc++.h>
using namespace std;

int n;
void partition_in_K_subsets(int index,vector<string> ans, int k){

    if(index>n){

        int flag =0;
        for(auto x:ans){
            if(x.size()==0){
                flag=1;
                break;
            }
        }
        string res;
        if(flag==0){
            for(auto x:ans){
                res += x+" ";
            }
            cout<<res;
            cout<<endl;
        }
        return;
    }

    for(int i=0;i<k;i++){
        if(ans[i].size()==0){
            ans[i] = ans[i]+to_string(index);
            partition_in_K_subsets(index+1,ans,k);
            ans[i].pop_back();
            break;
        }else{
            ans[i] = ans[i]+to_string(index);
            partition_in_K_subsets(index+1,ans,k);
            ans[i].pop_back();
        }
    }

}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
  
    int k;
    cin>>n>>k;

    vector<string> ans(k);
    partition_in_K_subsets(1,ans,k);
    return 0;
}

//input
// 5 2
// //output
// 1234 5 
// 1235 4 
// 123 45 
// 1245 3 
// 124 35 
// 125 34 
// 12 345 
// 1345 2 
// 134 25 
// 135 24 
// 13 245 
// 145 23 
// 14 235 
// 15 234 
// 1 2345 
