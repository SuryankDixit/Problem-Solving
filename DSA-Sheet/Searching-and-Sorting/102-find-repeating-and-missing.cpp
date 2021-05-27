#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


class Solution{
public:
    vector<int> findTwoElement(int *arr, int n) {
        vector<int> a(2,0);
        int temp=0;
        for(int i=0;i<n;i++){
            int x=abs(arr[i]);
            arr[x-1]= -arr[x-1];
            if(arr[x-1]>0){
                a[0]=x;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0 && a[0]!=i+1){
                a[1]=i+1;
                break;
            }
        }
        // cout<<a[0]<<" "<<a[1]<<endl;
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
