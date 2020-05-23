
// Check for euler path, visit each edge exactly one time.

class Solution {
public:
    
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> graph;
    vector<string> result;
    
    void dfs(string vertex)
    {
        
        while(!graph[vertex].empty())
        {
            string temp=graph[vertex].top();
            graph[vertex].pop();
            dfs(temp);
        }
        
        result.push_back(vertex);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        // construct graph
        for(int i=0;i<tickets.size();i++)
            graph[tickets[i][0]].push(tickets[i][1]);
        
        // there exist at least one itinerary , so go for dfs directly;
        dfs("JFK");
        reverse(result.begin(),result.end());
        return result;
    }
};
