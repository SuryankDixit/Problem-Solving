#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> m;
int totalSum=0;
vector<int> res;
int Min= INT_MAX;
unordered_multiset<int> s1,s2;

void tugOfWar(vector<int> &v,int x,int index){

    if(res.size()==x){

        int sumSet1 = accumulate(res.begin(),res.end(),0);
        int sumSet2 = totalSum-sumSet1;
        int diff = abs(sumSet2 - sumSet1);
        if(diff<Min){
            Min= diff;
            if(s1.size()>0)
                s1.clear();
            for(int i=0;i<res.size();i++){
                s1.insert(res[i]);
            }
        }
        return;
    }

    if(index==v.size() && res.size()!=x)
        return;

    tugOfWar(v,x,index+1);
    res.push_back(v[index]);
    tugOfWar(v,x,index+1);
    res.pop_back();
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    totalSum = accumulate(v.begin(),v.end(),0);
    int mid = v.size()/2;

    tugOfWar(v,mid,0);

    for(auto x:v){
        if(s1.find(x)==s1.end()){
            s2.insert(x);
        }
    }
    

    for(auto x:s1)
        cout<<x<<" ";
    cout<<endl;

    for(auto x:s2)
        cout<<x<<" ";
}

//input
// 11
// 23 45 -34 12 0 98 -99 4 189 -1 4

//output

// -1 98 12 -34 45 
// 189 4 4 -99 0 23 
