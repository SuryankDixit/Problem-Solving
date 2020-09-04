#include<bits/stdc++.h>

using namespace std;

vector<string> ans;

void permuteString(string &s, int i ,int j , char* output){

	if(i == s.size()){
		output[j]='\0';
		ans.push_back(output);
		return;
	}
	output[j] = s[i];
	permuteString(s,i+1,j+1,output);
	permuteString(s,i+1,j,output);
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    
    string input ="abc";
    char output[5];
    permuteString(input,0,0,output);
    for(auto x:ans){
    	cout<<x<<" ";
    }
}
