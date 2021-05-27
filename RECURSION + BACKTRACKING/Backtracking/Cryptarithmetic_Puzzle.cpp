#include <bits/stdc++.h>
using namespace std;

unordered_map<char,int> m;
string s1,s2,s3,uniqueS;
vector<int> visited(10,0);
string total;

int getNum(string s){

    string num = "";
    for(int i =0; i<s.size(); i++){
        
        string x = to_string(m[s[i]]);
        num += x;
    }
    // cout<<num<<" ";
    int k = stoi(num) ;
    return k;
}


void printValues(int i){
    
    if(i == uniqueS.size()){

        int n1 = getNum(s1);
        int n2 = getNum(s2);
        int n3 = getNum(s3);

        // cout<<n1<<" "<<n2<<" "<<n3<<endl;
        if( n1+n2 == n3){
            for(int k=0;k<26;k++){
                char ch = char('a'+k);

                if(m.find(ch) != m.end()){

                    cout<<ch<<"-"<<m[ch]<<" ";
                }
            }
            cout<<endl;
            // for(int i=0;i<uniqueS.size();i++){
            //     char ch = uniqueS[i];
            //     cout<<ch<<"-"<<m[uniqueS[ch]]<<" ";
            // }
            // cout<<endl;
        }
        return;
    }
    // cout<<total<<endl;

    for(int j = 0; j<=9; j++){
        if(visited[j] == 0){

            visited[j] =1;
            m[uniqueS[i]] = j;

            printValues(i+1);

            visited[j] =0;
            m[uniqueS[i]] = -1;
        }
    }

}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    getline(cin,s1);   
    getline(cin,s2);
    getline(cin,s3);

    for(auto x:s1){
        if(m.find(x)==m.end()){
            m[x]=-1;
            uniqueS += x;
        }
    }
    for(auto x:s2){
        if(m.find(x)==m.end()){
            m[x]=-1;
            uniqueS += x;
        }
    }
    for(auto x:s3){
        if(m.find(x)==m.end()){
            m[x]=-1;
            uniqueS += x;
        }
    }


    printValues(0);
    
  
}


//input
// send
// more
// money

// output
// d-7 e-8 m-0 n-1 o-3 r-6 s-2 y-5 
// d-9 e-8 m-0 n-1 o-3 r-6 s-2 y-7 
// d-2 e-7 m-0 n-1 o-4 r-6 s-3 y-9 
// d-9 e-7 m-0 n-1 o-4 r-5 s-3 y-6 
// d-1 e-8 m-0 n-2 o-4 r-6 s-3 y-9 
// d-9 e-8 m-0 n-2 o-4 r-5 s-3 y-7 
// d-1 e-7 m-0 n-3 o-6 r-4 s-5 y-8 
// d-2 e-7 m-0 n-3 o-6 r-4 s-5 y-9 
// d-9 e-8 m-0 n-4 o-6 r-3 s-5 y-7 
// d-5 e-4 m-0 n-1 o-7 r-3 s-6 y-9 
// d-9 e-4 m-0 n-1 o-7 r-2 s-6 y-3 
// d-4 e-5 m-0 n-2 o-7 r-3 s-6 y-9 
// d-1 e-8 m-0 n-5 o-7 r-3 s-6 y-9 
// d-3 e-8 m-0 n-5 o-7 r-2 s-6 y-1 
// d-6 e-3 m-0 n-1 o-8 r-2 s-7 y-9 
// d-9 e-4 m-0 n-2 o-8 r-1 s-7 y-3 
// d-1 e-5 m-0 n-3 o-8 r-2 s-7 y-6 
// d-4 e-5 m-0 n-3 o-8 r-2 s-7 y-9 
// d-9 e-5 m-0 n-3 o-8 r-1 s-7 y-4 
// d-3 e-6 m-0 n-4 o-8 r-2 s-7 y-9 
// d-9 e-6 m-0 n-4 o-8 r-1 s-7 y-5 
// d-4 e-3 m-0 n-2 o-9 r-1 s-8 y-7 
// d-2 e-4 m-0 n-3 o-9 r-1 s-8 y-6 
// d-2 e-5 m-0 n-4 o-9 r-1 s-8 y-7 
// d-7 e-5 m-1 n-6 o-0 r-8 s-9 y-2 
