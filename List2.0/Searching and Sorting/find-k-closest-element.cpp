class Solution {
public:
    
    int n ;
    
    int bs(vector<int> &v,int x){
        int l=0,r=n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(v[mid]==x)
                return mid;
            else if(v[mid]>x)
                r=mid-1;
            else
                l=mid+1;
        }
        
        return r;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        n= arr.size();
        int l = bs(arr,x);
        int r=l+1;
        
        list<int> res;
        vector<int> ans;
        while(k>0){
            if(r>=n || (l>=0 && abs(x-arr[l])<=abs(x-arr[r])))
                l--;
            else
                r++;
            
            k--;
        }
        cout<<l<<" "<<r;
        for(int i=l+1;i<r;i++)
            ans.push_back(arr[i]);
        return ans;   
    }
};