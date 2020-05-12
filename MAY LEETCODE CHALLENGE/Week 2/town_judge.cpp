class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        /*vector<pair<int,int>> visited(N+1,make_pair(0,0));
        for(int i=0;i<trust.size();i++){
            visited[trust[i][0]].first=1;
            visited[trust[i][1]].second+=1;
        }
        
        for(int i=1;i<visited.size();i++)
        {
            if(visited[i].second==N-1 && visited[i].first==0)
                return i;
        }
        return -1;*/
        
        vector<int> in(N+1);
        vector<int> out(N+1);
        
        for(int i=0;i<trust.size();i++)
        {
            in[trust[i][1]]++;
            out[trust[i][0]]++;
        }
        for(int i=1;i<=N;i++)
        {
            if(in[i]==N-1 && out[i]==0)
                return i;
        }
    
        return -1;
    }
};