class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& curr, vector<int>& vis) {
        vis[node] = 1;
        curr.push_back(node);

        for (auto nei : adj[node]) {
            if (vis[nei] != 1) {
                dfs(nei, adj, curr, vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];

        // making adj matrix using the given connected edges
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // making a visited array to avoid revisiting
        vector<int> vis(n, 0);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            // if node is not traversed that means we explored a new component
            if (vis[i] != 1) {
                vector<int> curr;
                dfs(i, adj, curr, vis);

                // letscount edges in this component
                int nodes = curr.size(); // number of nodes
                int edgeCount = 0;

                for (auto node : curr) {
                    edgeCount +=
                        adj[node].size(); // we can get number of edges from
                                          // this node through adj matrix
                }

                edgeCount /= 2; // because its a undirected graph

                // complete graph condition
                // k nodes -> k*(k-1)/2 edges
                if (edgeCount == (nodes * (nodes - 1)) / 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};