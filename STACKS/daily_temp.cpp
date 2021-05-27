
//739. Daily Temperatures
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        // variation of next greater element in right .
        stack<int> s;
        //vector<int> res(T.size());
        s.push(0);
        for(int i=1;i<T.size();i++)
        {
            while(!s.empty() && T[s.top()]<T[i])
            {
                T[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            T[s.top()]=0;
            s.pop();
        }
        return T;
    }
};