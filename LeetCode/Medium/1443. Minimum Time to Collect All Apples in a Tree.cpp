class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return max(0, DFS(0, -1, adj, hasApple) - 2);
    }
    int DFS(int node, int parent, vector<vector<int>> &adj, vector<bool>& hasApple)
    {
        int time = 0;
        for(auto child : adj[node])
        {
            if(child != parent)
                time += DFS(child, node, adj, hasApple);
        }
        return (time > 0 || hasApple[node] ? time += 2 : 0);
    }
};
