#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;
string res;

void wordBreak(string &str,int index){

    // cout<<res<<endl;
    if(index == str.size()){

        cout<<res<<endl;
        return;
    }
    string temp;
    int flag=0;
    for(int i=index;i<str.size();i++){

        temp += str[i];
        // cout<<temp<<" "<<i<<endl;
        if(s.find(temp)!=s.end()){

            res += temp;
            res+=" ";
            // cout<<res<<endl;
            wordBreak(str,index+temp.size());
            res.pop_back();
            flag=1;
        }
        if(flag==1){
            for(int j=0;j<temp.size();j++)
                res.pop_back();
            flag=0;
        }
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    

    string str = "ilikeicecreamandmango";
    // cout<<str<<" ";
    s.insert("i");
    s.insert("mobile");
    s.insert("samsung");
    s.insert("sung");
    s.insert("sam");
    s.insert("man");
    s.insert("mango");
    s.insert("ice");
    s.insert("cream");
    s.insert("like");
    // s.insert("i");
    s.insert("go");
    s.insert("and");
    s.insert("icecream");

    wordBreak(str,0);
    return 0;
}

// input

// string str = "ilikeicecreamandmango";
//     // cout<<str<<" ";
//     s.insert("i");
//     s.insert("mobile");
//     s.insert("samsung");
//     s.insert("sung");
//     s.insert("sam");
//     s.insert("man");
//     s.insert("mango");
//     s.insert("ice");
//     s.insert("cream");
//     s.insert("like");
//     // s.insert("i");
//     s.insert("go");
//     s.insert("and");
//     s.insert("icecream");


//output
// i like ice cream and man go 
// i like ice cream and mango 
// i like icecream and man go 
// i like icecream and mango 
