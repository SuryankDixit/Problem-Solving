

class Solution{
    public:
    
    static int bits_count(int n){
        int count = 0;
        for (; n; count++)
            n = n & (n - 1);
        
        return count;
    }
    
    
    static int cmp(int x,int y){
        int cnt1= bits_count(x);
        int cnt2= bits_count(y);
        if(cnt1<=cnt2)
            return false;
        return true;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr,arr+n,cmp);
    }
};