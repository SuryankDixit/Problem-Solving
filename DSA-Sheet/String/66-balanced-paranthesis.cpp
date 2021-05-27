#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return if the paranthesis are balanced or not
bool ispar(string a)
{
    // Your code here
    stack<char> s;
    for(auto x:a){
        if(x=='('||x=='{'||x=='[')
            s.push(x);
        else if(!s.empty() &&(x==')' && s.top()=='('))
            s.pop();
        else if(!s.empty() &&(x=='}' && s.top()=='{'))
            s.pop();
        else if(!s.empty() &&(x==']' && s.top()=='['))
            s.pop();
        else 
            return false;
    }
    if(s.empty())
        return true;
    return false;
}


// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends