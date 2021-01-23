

#include<bits/stdc++.h>
using namespace std;


int findPages(int arr[], int n, int m);

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        cout << findPages(A, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


// 78,5,90,100,50,40,98,59      
// 3

bool isValid(int arr[],int pages,int m,int n){
    int cnt=1;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+arr[i]>pages){
            cnt++;
            if(cnt>m)
                return false;
            sum = 0;
        }
        sum += arr[i];
        
    }
    return true;
}

int findPages(int arr[], int n, int m) {
    
    int start=0;
    int end=0;
    for(int i=0;i<n;i++){
        start = max(start,arr[i]);
        end += arr[i];
    }
    
    int ans=INT_MAX;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isValid(arr,mid,m,n)){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}

