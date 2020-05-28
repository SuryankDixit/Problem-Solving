class Solution {
public:
    
    int mctFromLeafValues(vector<int>& arr) {
        
        int ans=0;
        stack<int> s;
        s.push(INT_MAX);
        for(int i=0;i<arr.size();i++)
        {
            while(s.top()<=arr[i])
            {
                int temp=s.top();
                s.pop();
                ans+=temp*min(s.top(),arr[i]);
            }
            s.push(arr[i]);
        }
        while(s.size()>=3)
        {
            int temp=s.top();
            s.pop();
            ans+=temp*s.top();
        }
        return ans;
    }
};