#include <bits/stdc++.h>
using namespace std;

vector<int> visited;
string s;

void friendsPairing(int i,string s){

    int n = visited.size()-1;
    if(i>n){
        cout<<s<<endl;
        return;
    }

    if(visited[i]==1){

        friendsPairing(i+1,s);
    }else{
        visited[i] =1;
        friendsPairing(i+1,s+"("+to_string(i)+")");
        for(int j =1; j<=n; j++){
            if(visited[j]==0){
                visited[j] =1;
                friendsPairing(i+1,s+"("+to_string(i)+to_string(j)+")");
                visited[j] =0;
            }
        }
        visited[i]=0;
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
  
    int n;
    cin>>n;

    visited.resize(n+1,0);
    friendsPairing(1,s);
    
  
}

//input
// 4
// output
// (1)(2)(3)(4)
// (1)(2)(34)
// (1)(23)(4)
// (1)(24)(3)
// (12)(3)(4)
// (12)(34)
// (13)(2)(4)
// (13)(24)
// (14)(2)(3)
// (14)(23)
