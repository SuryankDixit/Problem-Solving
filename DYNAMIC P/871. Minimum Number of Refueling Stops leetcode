int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int ans=0;
        priority_queue<int> pq;
        int tank=startFuel;
        int prev_dis=0;
        for(int i=0;i<stations.size();++i)
        {
            tank= tank-stations[i][0]+prev_dis;
            while(tank<0 && !pq.empty())
            {
                int x=pq.top();
                pq.pop();
                tank=tank+x;
                ++ans;
            }
            
            if(tank<0)
                return -1;
            
            pq.push(stations[i][1]);
            prev_dis=stations[i][0];
        }
        
        tank=tank-target+prev_dis;
        while(tank<0 && !pq.empty())
            {
                int x=pq.top();
                pq.pop();
                tank=tank+x;
                ++ans;
            }
             if(tank<0)
                return -1;
        
        return ans;
    }
