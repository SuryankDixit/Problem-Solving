// https://practice.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1

class Solution{
  public:
  
  int upperBound(int arr[],int n,int x){
      int i=0;
      int j=n;
      while(i<j){
          int mid = (i+j)/2;
          if(arr[mid]<=x){
              i=mid+1;
          }else{
              j=mid;
          }
      }
      return i;
  }
  
  
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
        sort(arr2,arr2+n);
        int idx=0;
        vector<int> ans;
        for(int i=0;i<m;i++){
            int x = arr1[i];
            idx = upperBound(arr2,n,x);
            ans.push_back(idx);
        }
        return ans;
    }
};