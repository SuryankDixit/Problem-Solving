vector<int> Solution::findPerm(const string A, int B)
{
    int n = A.size();
    if (n == 1 && A[0] == 'D')
    {
        return {2, 1};
    }
    else if (n == 1)
    {
        return {1, 2};
    }

    vector<int> ans;
    stack<int> s;
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 'D')
        {
            s.push(c++);
        }
        else
        {
            s.push(c++);
            while (!s.empty())
            {
                int x = s.top();
                s.pop();
                ans.push_back(x);
            }
        }
    }
    s.push(c++);
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        ans.push_back(x);
    }
    return ans;
}
