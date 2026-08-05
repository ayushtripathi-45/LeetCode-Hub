class Solution {
public:
   
    void dfs(int curr, vector<vector<int>>& adj, vector<bool>& isSuspicious) {
        isSuspicious[curr] = true;
        
        for (int neighbor : adj[curr]) {
            if (!isSuspicious[neighbor]) {
                dfs(neighbor, adj, isSuspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            adj[u].push_back(v); 
        }

        vector<bool> isSuspicious(n, false);
        dfs(k, adj, isSuspicious);

        bool canRemove = true;
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            
            if (!isSuspicious[u] && isSuspicious[v]) {
                canRemove = false;
                break;
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (canRemove) {
               
                if (!isSuspicious[i]) {
                    result.push_back(i);
                }
            } else {
                
                result.push_back(i);
            }
        }

        return result;
    }
};