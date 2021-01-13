class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        if(n<3)
            return 0;
        vector<int> v(n,INT_MIN),v1(n,INT_MIN);
        v[0]=arr[0];
        for(int i=1;i<n;i++){
            v[i]=max(v[i-1],arr[i]);
        }
        v1[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            v1[i]=max(v1[i+1],arr[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(min(v[i],v1[i])-arr[i]);
        }
        return ans;
    }
};
