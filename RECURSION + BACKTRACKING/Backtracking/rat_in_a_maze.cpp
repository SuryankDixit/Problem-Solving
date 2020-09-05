#include<bits/stdc++.h>
using namespace std;

int a,b;
int flag =0;
int cnt = 0;


bool findPath(vector<vector<int>> &v,vector<vector<int>> &ans,int i,int j){

	if(i>=a || j>=b || i<0 || j<0 || v[i][j]==0)
		return false;

	if(i==a-1 && j==b-1 && v[i][j]==1){
		ans[i][j] = 1;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        flag = 1;
		return true;
	}

    ans[i][j]=1;
    bool x = findPath(v,ans,i+1,j);
    bool y = findPath(v,ans,i,j+1);
    ans[i][j]=0;

    if(x||y)
        return true;
    return false;
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    
    cin>>a>>b;

    vector<vector<int>> v(a,vector<int>(b,0));
    vector<vector<int>> temp(a,vector<int>(b,0));

    for(int i=0;i<a;i++){
    	for(int j=0;j<b;j++){
    		cin>>v[i][j];
    	}
    }

    findPath(v,temp,0,0);
    if(flag==0)
    	cout<<"Not Possible";
    else
    	cout<<"Possible";

    cout<<endl;
}
// 4 4
// 1 0 0 0
// 1 1 0 1
// 0 1 0 0
// 1 1 1 1


// 4 4
// 1 1 1 0
// 1 1 0 1
// 0 1 0 0
// 1 1 1 1  
