//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int x = k-arr[i];
            if(m.find(x)!=m.end()){
                ans+=m[x];
            }
            m[arr[i]]++;
        }
        return ans;
    }
};
