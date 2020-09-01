#include<bits/stdc++.h>

using namespace std;

int string_to_int(string &s,int index){

	if(index==0)
		return s[index]-'0';

	int x = s[index]-'0';
	int y = string_to_int(s,index-1);

	int ans =0;
	ans += x + 10*y;
	return ans;

}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    
    string s = "0008";
    int n = s.size()-1;
    cout<<string_to_int(s,n);

	return 0;
}
