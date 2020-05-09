
/*
84. Largest Rectangle in Histogram

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Input: [2,1,5,6,2,3]
Output: 10

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        
        stack<int>s;
        h.push_back(0);
        int max_area=0;
        s.push(0);
        for(int i=1;i<h.size();i++)
        {
            while(!s.empty() && h[i]<h[s.top()])
            {
                int height=h[s.top()];
                s.pop();
                int left_smaller= s.empty() ? -1 : s.top();
                max_area=max(max_area,(i-left_smaller-1)*height);
            }
            s.push(i);
        }
        return max_area;


        /*
        class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        
        if(h.size()==0)
            return 0;
        stack<int>s;
        vector<int> right_smaller(h.size());
        vector<int> left_smaller(h.size());
        s.push(0);
        for(int i=1;i<h.size();i++)
        {
            while(!s.empty() && h[i]<h[s.top()])
            {
                right_smaller[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            right_smaller[s.top()]=h.size();
            s.pop();
        }
        
        s.push(h.size()-1);
        for(int i=h.size()-2;i>=0;i--)
        {
            while(!s.empty() && h[i]<h[s.top()])
            {
                left_smaller[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            left_smaller[s.top()]=-1;
            s.pop();
        }
        
        int Max=INT_MIN;
        for(int i=0;i<h.size();i++)
        {
            h[i]=(right_smaller[i]-left_smaller[i]-1)*h[i];
            Max=max(Max,h[i]);
        }
        return Max;
    }  
};
        */
    }  
};