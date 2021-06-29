#include "bits/stdc++.h"
using namespace std;
 
const int N = 1e5 + 5;
const int INF = 1e9;
 
 
/*
KEYNOTES:
------------------------------------------
merge(X,identity_element) = X
------------------------------------------
------------------------------------------
identity_transformation.combine(X) = X
------------------------------------------
------------------------------------------
ALWAYS: older_update.combine(newer_update)
------------------------------------------
*/
 
 
 
// example: addition: identity element is 0
 
// a + 0 = a or 0 + a = a
 
// min(x,INF) = x
 
struct my_node
{
	int mn = INF;
	int freq = 0;
	// use more variables if you want more information
	// these default values should be identity_element
	my_node(){}
	my_node(int val){
		mn = val;
		freq = 1;
	}
	void merge(const my_node &l,const my_node &r){ // store the thing you wanna query
 
		mn = min(l.mn,r.mn);
		freq = 0;
		if(l.mn == mn) freq += l.freq;
		if(r.mn == mn) freq += r.freq;
 
		// if we wanted the maximum, then we would do
		// like v = max(l.v,r.v)
	}
};
 
// example: add on a range: identity transformation = 0
// old += new
 
// if old is identity which is 0, then 0 + new which new
 
struct my_update
{
	int v = 0; // 4
	// use more variables if you want more information
	// these default values should be identity_transformation
	my_update(){}
	my_update(int val){
		v = val; // 5
	}
	// combine the current my_update with the other my_update (see keynotes)
	void combine(my_update &other,const int32_t &tl,const int32_t &tr){
		v += other.v; // 6
 
		// you can be sure that the "other" is newer than current
 
	}
	// store the correct information in the my_node x
	void apply(my_node &x,const int32_t &tl,const int32_t &tr){
 
		// no change in freq
		x.mn += v;
 
	}
};
 
template<typename node,typename update>
struct segtree
{
	int len;
	vector<node> t;
	vector<update> u;
	vector<bool> lazy;
	node identity_element;
	update identity_transformation;
	segtree(int l){
		len = l;
		t.resize(4 * len);
		u.resize(4 * len);
		lazy.resize(4 * len);
		identity_element = node();
		identity_transformation = update();
	}
 
	void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr){
		if(!lazy[v]) return;
		int32_t tm = (tl + tr) >> 1;
		apply(v<<1,tl,tm,u[v]);
		apply(v<<1|1,tm+1,tr,u[v]);
		u[v] = identity_transformation;
		lazy[v] = 0;
	}
 
	void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd){
		if(tl != tr){
			lazy[v] = 1;
			u[v].combine(upd,tl,tr);
		}
		upd.apply(t[v],tl,tr);
	}
 
	template<typename T>
	void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){
		if(tl == tr){
			t[v] = arr[tl];
			return;
		}
		int32_t tm = (tl + tr) >> 1;
		build(arr,v<<1,tl,tm);
		build(arr,v<<1|1,tm+1,tr);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}
 
	node query(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r){
		if(l > tr || r < tl){
			return identity_element;
		}
		if(tl >= l && tr <= r){
			return t[v];
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
		ans.merge(a,b);
		return ans;
	}
 
	// rupd = range update
	void rupd(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,const update &upd){
		if(l > tr || r < tl){
			return;
		}
		if(tl >= l && tr <= r){
			apply(v,tl,tr,upd);
			return;
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		rupd(v<<1,tl,tm,l,r,upd);
		rupd(v<<1|1,tm+1,tr,l,r,upd);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}
 
	public:
	template<typename T>
	void build(const T &arr){
		build(arr,1,0,len-1);
	}
	node query(const int32_t &l,const int32_t &r){
		return query(1,0,len-1,l,r);
	}
	void rupd(const int32_t &l,const int32_t &r,const update &upd){
		rupd(1,0,len-1,l,r,upd);
	}
};
 
int main(){
 
	segtree<my_node,my_update> s(1000); // create a segment tree of length 1000
	vector<int> v(1000);
 
 
	segtree<my_node2,my_update2> s2(34543);
 
	v[10] = 35;
	v[13] = 3;
 
	s.build(v);
 
	s.rupd(2,5,8);
 
	s.rupd(1,3,-4);
 
	for(int i = 0; i < 15; i++){
		cout << s.query(i,i).mn << " ";
	}
 
	cout <<"\n\n" << s.query(2,4).mn << " " << s.query(2,4).freq;
 
	return 0;
}
 
 
 
 
// how to define the behaviour or the nature of the 
// updates and queries
 
 
// this segtree was sum in range and add on range
 
 
// let's change it to -> (sum on range) and (set all values on range)
 
 
 
// let's make the one from the question earlier
 
// get min element and frequency of min element on a range AND add on a range
