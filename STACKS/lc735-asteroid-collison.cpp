class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &a)
    {
        int n = a.size();
        vector<int> ans;
        stack<int> s;
        for (auto x : a)
        {
            if (x > 0)
                s.push(x);
            else
            {
                if (s.empty())
                    ans.push_back(x);
                else
                {
                    while (!s.empty())
                    {
                        int t = s.top();
                        if (t > abs(x))
                            break;
                        else if (t == abs(x))
                        {
                            s.pop();
                            break;
                        }
                        else
                        {
                            s.pop();
                            if (s.empty())
                                ans.push_back(x);
                        }
                    }
                }
            }
        }
        vector<int> t;
        while (!s.empty())
        {
            int x = s.top();
            s.pop();
            t.push_back(x);
        }
        reverse(t.begin(), t.end());
        for (auto x : t)
            ans.push_back(x);
        return ans;
    }
};