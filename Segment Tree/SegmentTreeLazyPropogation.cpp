#include <bits/stdc++.h>
using namespace std;

int n = 1e5+5;
vector<int> tree(4*n,0);
vector<bool> lazy(4*n,0);
vector<int> upd(4*n,0);

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


// This is the process of telling the node to remember the value 
void remember(int idx, int nl,int nr, int value){
    
    // Set correct information at the node
    tree[idx] += value * (nr-nl+1);
    
    // if the node is not the leaf node
    if(nl!=nr){
        lazy[idx]=1;
        upd[idx] += value;
    }
}

// send value to the children of nodes
void pushdown(int idx, int nl, int nr){
    
    // if it is lazy , propogate it
    if(lazy[idx]){
        lazy[idx] = 0;
        int nm = (nl+nr)/2;
        remember(2*idx,nl,nm,upd[idx]);
        remember(2*idx+1,nm+1,nr,upd[idx]);
        upd[idx]=0; 
        // Update done , Node idx doesn't rember anyting anymore
    }
}


void range_update(int idx ,int nl,int nr,int ql,int qr,int updated_value){
    
    // complete overlap
    if(ql<=nl && qr>=nr){
        // ask the node to remember it
        remember(idx,nl,nr,updated_value);
        return;
    }
    
    // no overlap
    if(nl>qr || nr<ql){
        return;
    }
    
    // Remove lazy tag from node before going down so that children have correct information
    pushdown(idx,nl,nr);
    
    // partial overlap (id lies in the range nl-------nr
    int nm = (nl+nr)/2;
    range_update(2*idx,nl,nm,ql,qr,updated_value);
    range_update(2*idx+1,nm+1,nr,ql,qr,updated_value);
    tree[idx] = (tree[2*idx]+tree[2*idx+1]);
    return;
}



// ql,qr = query range
// O(logN)
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
    
    // Remove lazy tag from node before going down so that children have correct information
    pushdown(idx,nl,nr);
    
    // partial overlap
    int nm = (nl+nr)/2;
    int left = query(2*idx,nl,nm,ql,qr);
    int right = query(2*idx+1,nm+1,nr,ql,qr);
    return left+right;
}


int main() {
    
    // point_update(1,0,n-1,2,5);
    // point_update(1,0,n-1,4,3);
    // point_update(1,0,n-1,3,2);
    range_update(1,0,n-1,2,5,6);
    cout<<query(1,0,n-1,2,5);
	return 0;
}
