#include<bits/stdc++.h>
using namespace std;


struct student{
    public:
    int rn;int marks;
    student(int a,int b){
        rn=a;
        marks=b;
    }
};


// decreasing 
bool compare1(const int &a,const int &b){

    // 2>1; return true;
    // if order is already maintained then return true;
    // return (a>b);

    if(a>b)
        return true;
    return false;
}



// increasing marks
bool compare2(const student &s1,const student &s2){
    if(s1.marks < s2.marks || (s1.marks==s2.marks && s1.rn < s2.rn))
        return true;
    return false;
}

int main(){
    vector<int> v{1,4,2,3,6,7,4,5,88,9,10};
    sort(v.begin(),v.end(),compare1);
    for(auto x:v)
        cout<<x<<" ";


    student s1(1,90);
    student s2(2,100);
    student s3(3,85);
    student s4(4,85);
    student s5(0,90);
    vector<student> st{s1,s2,s3,s4,s5};
    sort(st.begin(),st.end(),compare2);
    cout<<endl;
    for(auto x:st){
        cout<<x.rn<<" "<<x.marks<<endl;
    }
    return 0;
}