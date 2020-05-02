#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    st.push(2);
    st.push(28);
    st.push(7);
    st.push(1);
    st.push(22);
    st.push(11);
    st.push(19);
    // Printing the top value of the stack;
    cout<<st.top();
    //Removing top most element;
    st.pop();
    cout<<st.top();
    
    return 0;
    
}
