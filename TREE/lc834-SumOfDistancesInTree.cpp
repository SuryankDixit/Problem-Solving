/*
An undirected, connected tree with n nodes labelled 0...n-1 and n-1 edges are given.

The ith edge connects nodes edges[i][0] and edges[i][1] together.

Return a list ans, where ans[i] is the sum of the distances between node i and all other nodes.

Example 1:

Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: 
Here is a diagram of the given tree:
  0
 / \
1   2
   /|\
  3 4 5
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.  Hence, answer[0] = 8, and so on.

*/

class Solution {
public:
    vector<int> g[10005];
    vector<int> cntNodes;
    vector<int> ans;
    
    void dfs1(int root, int parent){
        for(auto child: g[root]){
            if(child==parent)
                continue;
            dfs1(child,root);
            cntNodes[root] += cntNodes[child];
            ans[root] += ans[child] + cntNodes[child];
        }
    }
    
    void dfs2(int root, int parent){
        for(auto child:g[root]){
            if(child==parent)
                continue;
            
            // When we move our root from parent to its child i, count[i] points get 1 closer to root, n - count[i] nodes get 1 futhur to root.
res[i] = res[root] - count[i] + N - count[i]
            ans[child] = ans[root]-cntNodes[child]+ cntNodes.size()-cntNodes[child];
            dfs2(child,root);
        }
    }
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& e) {
        for(auto x:e){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        cntNodes.resize(N,1);
        ans.resize(N,0);
        dfs1(0,-1);  // calculating 1). count in subtrees of node i. 2). total distance of all nodes from node i in its subtree.
        dfs2(0,-1);
        return ans;
    }
};
