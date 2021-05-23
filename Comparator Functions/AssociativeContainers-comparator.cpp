#include<bits/stdc++.h>
using namespace std;

// name,id,marks;
typedef pair<string,pair<int,int>> pii;

class compare{
    public:
        bool operator()(const pii &a,const pii &b){
            string n1,n2;
            n1=a.first;n2=b.first;
            int id1,id2;
            int m1,m2;
            id1 = a.second.first;id2 = b.second.first;
            m1 = a.second.second;m2 = b.second.second;
            if(m1>m2 || (m1==m2 && n1<n2) || (m1==m2 && n1==n2 && id1>id2)){
                return true;
            }
            return false;
        }
};


int main(){

    // set<datatype,class/structure>

    set<pii, compare> v{{"sk",{1,2}},{"dk",{2,7}},{"pk",{3,88}},{"tk",{4,12}},{"zk",{5,88}},{"zk",{6,88}}};
    for(auto x:v){
        cout<<x.second.second<<" "<<x.first<<" "<<x.second.first<<" "<<endl;
    }
    return 0;
}


// output
// 88 pk 3 
// 88 zk 6 
// 88 zk 5 
// 12 tk 4 
// 7 dk 2 
// 2 sk 1 