#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    bool isValid(int x,int y,vector<vector<int>> &v){
        int N=v.size();
        if(x >= 1 && x < N && y >= 1 && y < N){
            return true;
        }
        return false;
            
        
    }
    
	int minStepToReachTarget(vector<int>&k, vector<int>&t, int n){
	    
	    int ax[]={-2, -1, 1, 2, -2, -1, 1, 2};
	    int by[]={-1, -2, -2, -1, 1, 2, 2, 1};
        if(k==t)
            return 0;
	    
	    vector<vector<int>> v(n+1,vector<int>(n+1,0));
	    queue<pair<int,int>> q;
	    q.push({k[0],k[1]});
        v[k[0]][k[1]]=-1;
	    int ans=0;
	    while(!q.empty()){
	        int k=q.size();
	        while(k--){
	            pair<int,int> temp = q.front();
	            q.pop();
	            int x=temp.first;
	            int y=temp.second;
	            if(x==t[0]&&y==t[1]){ 
	                return ans;
	            }
	            for(int i=0;i<8;i++){
	                int l = x+ax[i];
	                int r = y+by[i];
	                if(isValid(l,r,v) && v[l][r]!=-1){
                        v[l][r]=-1;
	                    q.push({l,r});   
	                }
	            }
	        }
	        ans++;
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
        // cout<<"Hello";
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends

// 1
// 7
// 6 1
// 2 4