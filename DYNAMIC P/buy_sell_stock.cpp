int max_diff=0;
        int min_num=INT_MAX;
    
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<min_num)
                min_num=prices[i];
            else if(prices[i]-min_num>max_diff)
                max_diff=prices[i]-min_num;
        }
        return max_diff;
