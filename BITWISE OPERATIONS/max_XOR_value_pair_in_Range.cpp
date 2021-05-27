#include<bits/stdc++.h>
using namespace std;

int main () {
	int l,r;
	cin>>l>>r;
	int x = l^r;

	// fing MSB position in XOR;
	int pos = 0;
	while(x){
		pos++;
		x>>=1;
	}
	int ans = 0;
	int twos_power =1;
	while(pos--){
		ans+=twos_power;
		twos_power<<=1;
	}
	cout<<ans;
}
