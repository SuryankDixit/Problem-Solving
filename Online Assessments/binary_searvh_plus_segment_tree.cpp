/*
You want to buy a laptop. Each laptop has two parameters: Rating & Price. Your task is to buy a laptop with the highest rating within a given price range. Given Q tasks, each query consisting of price range required, you have to print the highest rated laptop that can be bought within that price range.

Input format:

The first line contains N denoting the number of inputs.
The following N lines contain P & R denoting price and range of a laptop.
Next line contains Q denoting the number of queries.
The following Q lines contain two integers X & Y denoting the price range (inclusive).
Output format:
For each task Q, print the highest rating that can be bought within the range.
If you cannot get any laptop within the range, print -1.

Sample Input:
5
1000 300
1100 400
1300 200
1700 500
2000 600
3
1000 1400
1700 1900
0 2000

Sample Output:
400
500
600

*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree;
vector<bool> lazy(4*n,0);
vector<int> upd(4*n,0);

// nl,nr = node left,node right (Tree range)
// id = point to update value
//idx = iterator over tree
// O(logN)



// ql,qr = query range
// O(logN)
int query(int idx,int nl,int nr, int ql,int qr){
    
    // complete overlap
    // whery node range lies in query range
    if(ql<=nl && qr>=nr){
        return tree[idx];
    }
    
    // No overlap
    if(qr<nl || ql>nr){
        return INT_MIN;
    }
    
    // Remove lazy tag from node before going down so that children have correct information
    // pushdown(idx,nl,nr);
    
    // partial overlap
    int nm = (nl+nr)/2;
    int left = query(2*idx+1,nl,nm,ql,qr);
    int right = query(2*idx+2,nm+1,nr,ql,qr);
    // return left+right;
    return max(left,right);
}

void buildTree(vector<int> &v,int nl,int nr,int idx){

    // cout<<nl<<" "<<nr<<" "<<idx<<endl;
	if(nl==nr){
		tree[idx]=v[nl];
		return;
	}

	int mid=(nl+nr)/2;
	buildTree(v,nl,mid,2*idx+1);
	buildTree(v,mid+1,nr,2*idx+2);
	tree[idx]=max(tree[2*idx+1],tree[2*idx+2]);
	return;
}



int main() {
    
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int p,r;
        cin>>p>>r;
        v[i]={p,r};
    }

    sort(v.begin(),v.end());
    vector<int> rating(n),price(n);
    for(int i=0;i<n;i++){
        price[i] = v[i].first;
        rating[i] = v[i].second;
    }

    tree.resize(4*n,0);
    buildTree(rating,0,n-1,1);

    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        int ql = lower_bound(price.begin(),price.end(),x)-price.begin();
        int qr = upper_bound(price.begin(),price.end(),y)-price.begin()-1;
        cout<<query(1,0,n-1,ql,qr)<<endl;
    }
	return 0;
}
