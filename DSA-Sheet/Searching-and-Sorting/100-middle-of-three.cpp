
//User function template for C++

class Solution{
  public:
    int middle(int a, int b, int c){
        int x1=a-b;
        int x2=b-c;
        int x3=c-a;
        if(x1*x2>0)
            return b;
        else if(x1*x3>0)
            return a;
        return c;
    }
};
