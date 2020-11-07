
/*
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output: 6
Explanation: The consecutive numbers 
here are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
*/
int findLongestConseqSubseq(int arr[], int N)
{
    unordered_set<int> s;
    for(int i=0;i<N;i++){
        s.insert(arr[i]);
    }
    int ans=INT_MIN;
    for(int i=0;i<N;i++){
        
        int x = arr[i]-1;
        if(s.find(x)==s.end()){
            int y=arr[i];
            while(s.find(y)!=s.end())
                y++;
            
            ans=max(ans,y-arr[i]);
        }
    }
    return ans;
}
