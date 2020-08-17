#include<bits/stdc++.h>

using namespace std;

bool compare(string &a,string &b){
	int i=0,j=0;
	int m=a.size();
	int n=b.size();
	while(i<m && j<n){
		if(a[i]==b[j]){
			i++;j++;
		}
		else{
			cout<<"comparing "<<a<<" with "<<b<<endl;
			return a<b;
		}
	}
	return a.length()>b.length();		// return true if a.size()>b.size() ,meaning the order is correct in array
									              	// return false if condition false means a should comes after b;
}

int main()
{


	int n;
	cin>>n;
	vector<string> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	// 	cout<<s1<<" "<<s2<<endl;
	sort(v.begin(),v.end(),compare);
	for(auto i:v)
		cout<<i<<endl;
	return 0;

}
