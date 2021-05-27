
/*
503. Next Greater Element II

Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        if(nums.size()==0)
            return nums;
        stack<int> s;
        s.push(0);
        //unordered_map<int,int> m;
        int N=nums.size();
        vector<int> res(N,-1);
        int n=2*nums.size(); 
        for(int i=1;i<n;i++)    // Traverse array 2 times which completes a cycle;
        {
            while(!s.empty() && nums[(s.top())%N]<nums[i%N])
            {
                res[(s.top())%N] = nums[i%N];
                s.pop();
            }
            //if(!s.empty() && nums[(s.top())%N]==nums[i%N])
              //  continue;
            //else
            if(res[i%N] == -1)
                s.push(i%N);
        }
       /* while(!s.empty())
        {
            int k=s.top();
            if(m.find(k)==m.end())
                m[k]=-1;
            s.pop();
        }
        for(int i=0;i<nums.size();i++)
        {
            int k=m[i];
            nums[i]=k;
        }
        return nums;
        */
        return res;
    }
};