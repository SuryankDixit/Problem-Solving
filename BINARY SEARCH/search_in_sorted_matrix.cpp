#include <bits/stdc++.h>
using namespace std;


int search_matrix(vector<vector<int>> &v, int n,int m,int &x){
    
    int i = 0;
    int j = m-1;
    
    while(i>=0 && i<n && j>=0 && j<m){
        
        if(v[i][j] == x)
            return 1;
        else if(v[i][j] > x)
            j--;
        else if(v[i][j] < x)
            i++;
    }
    return 0;
}


int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int>> v(n,vector<int>(m));
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>v[i][j];
	        }
	    }
	    
	    int x;
	    cin>>x;
	    
	    cout<<search_matrix(v,n,m,x)<<endl;
	} 
	return 0;
}
