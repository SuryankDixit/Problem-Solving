// https://leetcode.com/problems/k-th-smallest-prime-fraction/

class Solution {
public:
    typedef pair<double,pair<int,int>> pi;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n= arr.size();
        
        // auto comp = [](pi a, pi b){
        //     double x = arr[a.first]/(double)arr[a.second];
        //     double y = arr[b.first]/(double)arr[b.second];
        //     if(x>y)
        //         return true;
        //     return false;
        // };
        
        // priority_queue<pi,vector<pi>,decltype(comp)> p(comp);
        
        priority_queue<pi,vector<pi>,greater<pi>> p;
        
        for(int i=0;i<n-1;i++){
            p.push({arr[i]/(double)arr[n-1],{i,n-1}});
        }
   
        for(int i=1;i<k;i++){
            auto x = p.top();
            p.pop();
            int nr = x.second.first;
            int dr = x.second.second;
            if(nr<dr)
                dr--;
            p.push({arr[nr]/(double)arr[dr],{nr,dr}});
        }
        return {arr[p.top().second.first],arr[p.top().second.second]};
    }
};
