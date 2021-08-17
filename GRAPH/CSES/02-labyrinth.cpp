#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};


bool isValid(int i,int j){
    if(i<0||j<0||i>=n||j>=m)
        return false;
    
    return true;
}


int main(){
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m,0));
    int si,sj;
    int ei,ej;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(v[i][j]=='A'){
                si=i;sj=j;
            }else if(v[i][j]=='B'){
                ei=i;ej=j;
            }
        }
    }

    // cout<<si<<" "<<sj<<" "<<ei<<" "<<ej<<endl;
    vector<vector<pair<int,int>>> p(n,vector<pair<int,int>>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,false));

    queue<pair<int,int>> q;
    q.push({si,sj});
    int flag=0;
    int dis=0;
    while(!q.empty()){
        int k = q.size();
        dis++;
        while(k--){
            auto x = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int ax = x.first+dx[i];
                int ay = x.second+dy[i];
                if(isValid(ax,ay) && v[ax][ay]!='#' && vis[ax][ay]==false){
                    // cout<<ax<<" "<<ay<<endl;
                    vis[ax][ay]=true;
                    p[ax][ay]={x.first,x.second};
                    if(v[ax][ay]=='B'){
                        flag=1;
                        break;
                    }
                    q.push({ax,ay});
                }
            }
            if(flag==1)break;
        }
        if(flag==1)break;
    }

    if(flag==0){
        cout<<"NO";
    }else{
        cout<<"YES"<<endl;
        cout<<dis<<endl;
        string ans="";
        while(ei!=si || ej!=sj){
            int x = p[ei][ej].first;
            int y = p[ei][ej].second;
            if(x>ei && y==ej){
                ans+="U";
            }else if(x<ei && y==ej){
                ans+="D";
            }else if(x==ei && y>ej){
                ans+="L";
            }else if(x==ei && y <ej){
                ans+="R";
            } 
            ei=x;
            ej=y; 
        }
        reverse(ans.begin(),ans.end());
        cout<<ans;
    }
}