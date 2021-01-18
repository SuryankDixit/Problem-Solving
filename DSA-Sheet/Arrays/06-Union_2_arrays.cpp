#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n,m;
    cin>>n>>m;
    // cout<<n<<m;
    vector<int>a(n),b(m);
    
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    for(int i=0;i<m;i++)
        cin>>b[i];
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    // for(int i=0;i<n;i++)
    //     cout<<a[i]<<" "<<b[i]<<endl;          
        
    vector<int> ans;
    int i,j,k;
    i=j=k=0;
    while(i<n&&j<m){
        if(a[i]==b[j]){
            if(k==0){
              ans.push_back(a[i]);
                k++;  
            }
            else if(k!=0&&ans[k-1]!=a[i]){
                ans.push_back(a[i]);
                k++;
            }
            i++;j++;
        }else if(a[i]>b[j]){
            if(k==0){
              ans.push_back(b[j]);
                k++;  
            }
            else if(k!=0&&ans[k-1]!=b[j]){
                ans.push_back(b[j]);
                k++;
             }
            j++;
        }else{
            if(k==0){
              ans.push_back(a[i]);
                k++;  
            }
            else if(k!=0&&ans[k-1]!=a[i]){
                ans.push_back(a[i]);
                k++;
             }
            i++;
        }
    }
    while(i<n){
        if(k==0){
              ans.push_back(a[i]);
                k++;  
            }
            else if(k!=0&&ans[k-1]!=a[i]){
                ans.push_back(a[i]);
                k++;
             }
            i++;
        }
    while(j<m){
        if(k==0){
              ans.push_back(b[j]);
                k++;  
            }
            else if(k!=0&&ans[k-1]!=b[j]){
                ans.push_back(b[j]);
                k++;
             }
            j++;
    }
        
    cout<<ans.size()<<endl;
}


int main() {
	//code
	int t;
	cin>>t;
    // t=1;
	while(t--){
	    solve();
	}
	return 0;
}
