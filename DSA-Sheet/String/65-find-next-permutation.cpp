// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int idx=-1;
        int idx2=-1;
        for(int i=N-1;i>=1;i--){
            if(arr[i]>arr[i-1]){
                idx=i-1;
                break;
            }
        }
        if(idx==-1){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        for(int i=N-1;i>idx;i--){
            if(arr[i]>arr[idx]){
                idx2=i;
                break;
            }
        }
        swap(arr[idx],arr[idx2]);
        reverse(arr.begin()+idx+1,arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends