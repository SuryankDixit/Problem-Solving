#include<bits/stdc++.h>
using namespace std;

vector<int> tree[200005];
int cnt=0;

void dfs(int s,int p,int flag){

    // cout<<s<<" "<<p<<" "<<flag<<endl;
    int t=true;
    for(int i=0;i<tree[s].size();i++){
        int child = tree[s][i];
        if(child!=p){
            // cout<< child<<" "<<p<<" ";
            if(t && flag==0){
                cnt++;
                t=false;
                // cout<<cnt;
                dfs(child,s,1-flag);
            }else{
                if(flag==1)
                    dfs(child,s,1-flag);
                else
                    dfs(child,s,flag);
            }
            // cout<<endl;
            
        }
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1,-1,0);
    cout<<cnt;
}