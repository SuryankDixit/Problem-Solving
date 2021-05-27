// https://leetcode.com/problems/range-sum-query-mutable/
// 307. Range Sum Query - Mutable

// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

// The update(i, val) function modifies nums by updating the element at index i to val.

// Example:

// Given nums = [1, 3, 5]

// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8

#include <bits/stdc++.h>
#define ll long long

using namespace std;


class NumArray {
public:
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        if(n==0)
            return;
        tree.resize(4*n+1,INT_MIN);
        buildTree(tree,nums,0,n-1,0);
    }
    
    void update(int i, int val) {
        // for(auto x:tree)
        //     cout<<x<<" ";
        // cout<<endl;
        point_update(tree,0,n-1,0,i,val);
        // for(auto x:tree)
        //     cout<<x<<" ";
        // cout<<endl;
    }
    
    int sumRange(int i, int j) {
        return query(tree,i,j,0,n-1,0);
    }
    
void point_update(vector<int> &tree, int l,int r,int idx,int i,int val){
    // no overlap
    if(i<l || i>r)
        return;
    
    // complete overlap
    if(l==r){
        tree[idx] = val;
        return ;
    }
    // partial
    int mid = (l+r)/2;
    point_update(tree,l,mid,2*idx+1,i,val);
    point_update(tree,mid+1,r,2*idx+2,i,val);
    tree[idx]=tree[2*idx+1]+tree[2*idx+2];
}

int query(vector<int> &tree,int start,int end,int l,int r,int idx){
    // no overlap
    if(start>r || end<l)
        return 0;
    
    // complete overlap
    if(start<=l && end>=r)
        return tree[idx];
    
    // partial overlap
    int mid=(l+r)/2;
    return query(tree,start,end,l,mid,2*idx+1)+
            query(tree,start,end,mid+1,r,2*idx+2);
}

void buildTree(vector<int> &tree,vector<int> &nums,int l,int r,int idx){
    if(l==r){
        tree[idx]=nums[l];
        return;
    }
    int mid=(l+r)/2;
    buildTree(tree,nums,l,mid,2*idx+1);
    buildTree(tree,nums,mid+1,r,2*idx+2);
    tree[idx] = tree[2*idx+1]+tree[2*idx+2];
    return;
}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
