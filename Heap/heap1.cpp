/*
There are N ticket sellers each of whom has a certain amount of tickets. The price of a ticket is the number of tickets remaining with the ticket seller. They can sell a total of K tickets. Find the maximum amount they can earn by selling K tickets. The amount of tickets of each seller is provided in array A. Give the answer modulo 109 + 7.

Example 1:

Input: N = 5, K = 3
A = {4, 3, 6, 2, 4}
Output: 15
Explaination: Consider 0 based indexing. 
For first two turns the 2nd seller sells. 
For the third turn either 0th or 2nd 
seller can sell. So the total becomes 
6 + 5 + 4 = 15.

*/


class Solution{
public:
    int maxAmount(int N, int K, int A[])
    {
        int m = 1e9+7;
        priority_queue<int> p;
        for(int i=0;i<N;i++){
            p.push(A[i]);
        }
        int ans=0;
        for(int i=0;i<K;i++){
            int price = p.top();
            p.pop();
            ans= (ans+price)%m;
            price--;
            p.push(price);
        }
        return ans%m;
    }
};
