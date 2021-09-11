vector<int> result;
if (k == 0)
    return result;
deque<int> w;
for (int i = 0, n = (int)nums.size(); i < n; i++)
{
    while (!w.empty() && w.front() <= i - k)
        w.pop_front();
    while (!w.empty() && nums[w.back()] >= nums[i])
        w.pop_back();
    w.push_back(i);
    if (i >= k - 1)
        result.push_back(nums[w.front()]);
}
return result;
// 23280703509553 23280704696892 23280727722831