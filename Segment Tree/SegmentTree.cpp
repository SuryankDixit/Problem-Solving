#include <bits/stdc++.h>
using namespace std;

vector<int> tree(1e5+5,0);

// nl,nr = node left,node right (Tree range)
// id = point to update value
//idx = iterator over tree
// O(logN)
void point_update(int idx ,int nl,int nr,int id,int updated_value){
    
    // complete overlap
    if(id==nl && id==nr){
        tree[idx] = updated_value;
        return;
    }
    
    // no overlap
    if(id<nl || id>nr){
        return;
    }
    
    // partial overlap (id lies in the range nl-------nr)
    int nm = (nl+nr)/2;
    point_update(2*idx,nl,nm,id,updated_value);
    point_update(2*idx+1,nm+1,nr,id,updated_value);
    tree[idx] = (tree[2*idx]+tree[2*idx+1]);
    return;
}


// ql,qr = query range
O(logN)
int query(int idx,int nl,int nr, int ql,int qr){
    
    // complete overlap
    // whery node range lies in query range
    if(ql>=nl && qr<=nr){
        return tree[idx];
    }
    
    // No overlap
    if(qr<nl || ql>nr){
        return 0;
    }
    
    // partial overlap
    int nm = (nl+nr)/2;
    int left = query(2*idx,nl,nm,ql,qr);
    int right = query(2*idx+1,nm+1,nr,ql,qr);
    return left+right;
}


int main() {
    // vector<int> v{};
    int n = tree.size();
    point_update(1,0,n-1,2,5);
    point_update(1,0,n-1,4,3);
    point_update(1,0,n-1,3,2);
    cout<<query(1,0,n-1,2,5);
	return 0;
}
