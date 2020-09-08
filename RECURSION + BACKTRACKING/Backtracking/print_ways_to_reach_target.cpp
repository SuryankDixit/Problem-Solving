#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
set<vector<int>> res;

void printWays(int x,vector<int> &v,int i){

    if(i==v.size() && x!=0)
        return;

    if(x==0){
        res.insert(ans);
        return;
    }
    
    // cout<<x<<" "<<i<<endl;
    for(int k = i;k<v.size();k++){
        if(v[k]>x)
            continue;
        else{
            ans.push_back(v[k]);
            printWays(x-v[k], v, k+1);
            ans.pop_back();
        }
    }
    return ;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int target,n;
    cin>>n>>target;
    vector<int> v(n);
    
    for(int i=0;i<n;i++)
        cin>>v[i];

    sort(v.begin(),v.end());
    printWays(target,v,0);

    for(auto i:res){
        for(auto x:i)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
} 
