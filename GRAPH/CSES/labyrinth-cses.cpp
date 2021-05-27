#include<bits/stdc++.h>
using namespace std;
int n,m;
int dy[] = {-1,0,0,1};
int dx[] = {0,-1,1,0};

bool isValid(int i ,int j){
    if(i<0 ||j<0 ||i>=n||j>=m){
        return false;
    }
    return true;
}

int main(){
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    queue<pair<int,int>> q;
    int sx,sy,ex,ey;
    vector<vector<pair<int,int>>> p(n,vector<pair<int,int>>(m));
    vector<vector<char>> vis(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='A'){
                q.push({i,j});
                sx=i;sy=j;
            }
            else if(v[i][j]=='B'){
                ex=i;ey=j;
            }
        }
    }

    int dis=0;
    int flag=0;
    while(!q.empty()){
        int k = q.size();
        dis++;
        while(k>0){
            pair<int,int> temp = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x = temp.first+dx[i];
                int y = temp.second+dy[i];
                if(isValid(x,y) && v[x][y]!='#' && vis[x][y]==false){
                    vis[x][y] = true;
                    p[x][y] = {temp.first,temp.second};
                    if(v[x][y]=='B'){
                        flag=1;
                        break;
                    }
                    q.push({x,y});
                }
            }
            k--;
            if(flag==1){
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    if(flag==0){
        cout<<"NO";
    }else{
        cout<<"YES"<<endl;
        cout<<dis<<endl;
        string ans="";
        while(ex!=sx || ey!=sy){
            int x=p[ex][ey].first;
            int y=p[ex][ey].second;
            if(x>ex && y==ey){
                ans.push_back('U');
            }else if(x<ex && y==ey){
                ans.push_back('D');
            }else if(x==ex && y>ey){
                ans.push_back('L');
            }else if(x==ex && y<ey){
                ans.push_back('R');
            }
            ex=x;ey=y;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }

    return 0;
}