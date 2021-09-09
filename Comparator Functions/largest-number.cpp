
bool comp(string &a, string &b)
{
    string temp1 = a + b;
    string temp2 = b + a;
    if (temp1 > temp2)
        return true;
    return false;
}

string Solution::largestNumber(const vector<int> &a)
{
    vector<string> v;
    string s = "";
    int c = 0;
    for (auto x : a)
    {
        if (x == 0)
            c++;
        v.push_back(to_string(x));
    }
    if (c == v.size())
        return "0";
    sort(v.begin(), v.end(), comp);
    string ans = "";
    for (auto x : v)
    {
        ans += x;
    }
    return ans;
}
