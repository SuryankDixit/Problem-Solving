#include<bits/stdc++.h>
using namespace std;

vector<string> v{"", "a", "b", "c", "d", "e", 
        "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", 
        "s", "t", "u", "v", "w", "x", "v", "z"};

vector<string> ans;

void decodeStrings(string &x,int index, string &s){
// 	cout<<index<<" ";
	if(index >= x.size()){
	   // cout<<s<<" ";-
		ans.push_back(s);
		return ;
	}	
    char temp = x[index];
	string t(1,x[index]);
// 	cout<<t<<" ";
	int i = stoi(t);
// 	cout<<i<<" "<<endl;
	s += v[i];
	decodeStrings(x,index+1,s);
// 	cout<<s<<" ";
	s.pop_back();
	
	if(index<=x.size()-2){
	    t += x[index+1];
	    i = stoi(t);
	   // cout<<i<<" "<<v[i];
	    s += v[i];
// 		cout<<s<<" ";
		if(i<27){
		    decodeStrings(x,index+2,s);
		    s.pop_back();
		}
	} 
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    
    string s ="1001";
    string t;
    decodeStrings(s,0,t);
    for(auto x:ans)
    	cout<<x<<" ";
}






// #include<bits/stdc++.h>

// using namespace std;

// vector<string> v{"", "a", "b", "c", "d", "e", 
//         "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", 
//         "s", "t", "u", "v", "w", "x", "v", "z"};

// vector<string> ans;

// void decodeStrings(string &x,int index, string &s){
// // 	cout<<index<<" ";
// 	if(index >= x.size()){
// 	   // cout<<s<<" ";-
// 		ans.push_back(s);
// 		return ;
// 	}	
    
//     int digit = x[index]-'0';
//     char ch = digit+ 'a'-1;
//     s += ch;
//     decodeStrings(x,index+1,s);
// 	s.pop_back();
	
// 	if(index<=x.size()-2){
// 	    int secondDigit = x[index]-'0';
// 	    int no = digit*10+secondDigit;
// 		if(no<27){
// 		    ch = no +'a'-1;
// 		    s+=ch;
// 		    decodeStrings(x,index+2,s);
// 		    s.pop_back();
// 		}
// 	} 
// 	return;
// }

// int main()
// {
    
//     string s ="101";
//     string t;
//     decodeStrings(s,0,t);
//     for(auto x:ans)
//     	cout<<x<<" ";
// }
