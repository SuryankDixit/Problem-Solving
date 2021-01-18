
class Solution {
  public:
    int countSquares(int N) {
        int x= sqrt(N);
        if((x*x)==N)
            return x-1;
        return x;
    }
};
