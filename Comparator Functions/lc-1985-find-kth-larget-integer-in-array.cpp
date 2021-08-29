class NumStrComparator {
public:
    bool operator() (string &a, string &b) {
        
        if(b.size() != a.size())
            return b.size() < a.size();
        return  b < a;
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, NumStrComparator> minHeap;
        for (string& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};