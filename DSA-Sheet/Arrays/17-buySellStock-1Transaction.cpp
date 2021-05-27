class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int p=0;
        int b=prices[0];
        for(int i=1;i<prices.size();i++){
            int x = prices[i]-b;
            p=max(p,x);
            b=min(b,prices[i]);
        }
        return p;
    }
};
