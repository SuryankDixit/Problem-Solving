#include<bits/stdc++.h>
using namespace std;

// name,id,marks;
typedef pair<string,pair<int,int>> pii;


// less <
// greater >
class compare{
    public:
        bool operator()(const pii &a,const pii &b){
            string n1,n2;
            n1=a.first;n2=b.first;
            int id1,id2;
            int m1,m2;
            id1 = a.second.first;id2 = b.second.first;
            m1 = a.second.second;m2 = b.second.second;
            if(m1<m2){
                return true;
            }
            return false;
        }
};


int main(){

    // set<datatype,class/structure
    priority_queue<pii,vector<pii> ,compare>pq;
    pq.push({"sk",{1,2}});
    pq.push({"dk",{2,7}});
    pq.push({"pk",{3,88}});
    pq.push({"tk",{4,12}});
    // pq.push({"zk",{5,88}});
    // pq.push({"zk",{6,88}});
    while(!pq.empty()){
        auto x = pq.top();
        cout<<x.second.second<<" "<<x.first<<" "<<x.second.first<<" "<<endl;
        pq.pop();
    }
    return 0;
}

