
class Solution{
    public:
    bool isSubSequence(string A, string B) 
    {
        int i=0;int j=0;
        while(i<A.size() && j<B.size()){
            if(A[i]==B[j]){
                i++;j++;
            }else{
                j++;
            }
        }
        if(i==A.size())
            return true;
        return false;
    }
};
