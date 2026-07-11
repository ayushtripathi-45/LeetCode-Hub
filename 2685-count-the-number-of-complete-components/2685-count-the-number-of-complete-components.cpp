class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &component)
    {
        vis[node] = 1;
        component.push_back(node);

        for(int neigh : adj[node])
        {
            if(!vis[neigh])
            {
                dfs(neigh, adj, vis, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(vis[i]) continue;

            vector<int> component;

            dfs(i, adj, vis, component);

            int nodes = component.size();

            int degreeSum = 0;

            for(int node : component)
            {
                degreeSum += adj[node].size();
            }

            int actualEdges = degreeSum / 2;

            int expectedEdges = (nodes * (nodes - 1)) / 2;

            if(actualEdges == expectedEdges)
            {
                ans++;
            }
        }

        return ans;
    }
};