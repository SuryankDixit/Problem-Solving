#include <bits/stdc++.h>
#define ll long long

using namespace std;

void buildTree(vector<int> &tree,vector<int> &v,int nl,int nr,int idx){

	if(nl==nr){
		tree[idx]=v[nl];
		return;
	}

	int mid=(nl+nr)/2;
	buildTree(tree,v,nl,mid,2*idx+1);
	buildTree(tree,v,mid+1,nr,2*idx+2);
	tree[idx]=min(tree[2*idx+1],tree[2*idx+2]);
	return;
}

int query(vector<int> &tree,int l,int r,int start,int end,int idx){

	// No overlap
	if(end<l || start>r)
		return INT_MAX;

	// complete overlap
	if(l>=start && r<=end)
		return tree[idx];

	//partial overlap
	int mid=(l+r)/2;
	int x =query(tree,l,mid,start,end,2*idx+1);
	int y =query(tree,mid+1,r,start,end,2*idx+2);
	return min(x,y);
}

void pointUpdate(vector<int> &tree,int l,int r,int i,int idx,int inc){

	// no overlap
	if(idx<l || idx>r)
		return ;

	// complete overlap
	if(l==r){
		tree[i]+=inc;
		return;
	}

	// partial overlap
	int mid=(l+r)/2;
	pointUpdate(tree,l,mid,2*i+1,idx,inc);
	pointUpdate(tree,mid+1,r,2*i+2,idx,inc);
	tree[i]=min(tree[2*i+1],tree[2*i+2]);
	return;
}

void rangeUpdate(vector<int>& tree,int l,int r, int start,int end,int inc,int idx){

	// no overlap
	if(start>r || end<l)
		return;

	//complete overlap
	if(l==r){
		tree[idx]+=inc;
		return;
	}

	int mid=(l+r)/2;
	rangeUpdate(tree,l,mid,start,end,inc,2*idx+1);
	rangeUpdate(tree,mid+1,r,start,end,inc,2*idx+2);
	tree[idx]=min(tree[2*idx+1],tree[2*idx+2]);
	return;
}
 
int main() {
 
    #ifndef ONLINE_JUDGE    
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    	cin>>v[i];
    vector<int> tree(4*n+1);

    buildTree(tree,v,0,n-1,0);
    
    for(auto x:tree)
    	cout<<x<<" ";
    
    cout<<endl<<"Min Element";
    int x,y;
    cin>>x>>y;

    cout<<endl<<query(tree,0,n-1,x,y,0);
    
    cout<<endl<<"Tree after point update";
    int idx,inc;
    cin>>idx>>inc;

    pointUpdate(tree,0,n-1,0,idx,inc);
    cout<<endl;
    for(auto x:tree)
    	cout<<x<<" ";
// 
    cout<<endl<<"Tree After Range Update";
    int idx1,idx2,incr;
    cin>>idx1>>idx2>>incr;

    rangeUpdate(tree,0,n-1,idx1,idx2,incr,0);
    cout<<endl;
    for(auto x:tree)
    	cout<<x<<" ";
}


// input
// 6
// 1 3 2 -5 6 4
// 2 4
// 3 10
// 2 4 10
// output
// -5 1 -5 1 2 -5 4 1 3 0 0 -5 6 0 0 0 0 0 0 0 0 0 0 0 0 
// Min Element
// -5
// Tree after point update
// 1 1 4 1 2 5 4 1 3 0 0 5 6 0 0 0 0 0 0 0 0 0 0 0 0 
// Tree After Range Update
// 1 1 4 1 12 15 4 1 3 0 0 15 16 0 0 0 0 0 0 0 0 0 0 0 0 
