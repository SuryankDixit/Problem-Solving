#include <bits/stdc++.h>
using namespace std;


int firstOccurence(vector<int> &v,int x,int index){
    
    if(index==v.size())
        return -1;
    
    if(v[index]==x)
       return index;
    
    return firstOccurence(v,x,index+1);
}

int lastOccurence(vector<int> &v,int x,int index){
    if(index==-1)
        return -1;
    
    if(v[index]==x)
        return index;
    
    return lastOccurence(v,x,index-1);
}

void allOcuurences(vector<int> &v, int x ,int index){
    
    if(index==v.size())
        return ;
    
    if(v[index]==x)
        cout<<index<<" ";
    
    return allOcuurences(v,x,index+1);
}

int main() {
    
   vector<int> v{1,2,3,4,11,2,3,4,5,6,7,8,9,7,9,9,10};
   int x = 7;
   cout<<firstOccurence(v,x,0)<<endl;
   int n =v.size();
   cout<<lastOccurence(v,x,n-1)<<endl;
   allOcuurences(v,x,0);
}
