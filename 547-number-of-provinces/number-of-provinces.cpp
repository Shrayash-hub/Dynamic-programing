class Solution {
public:
    void dfs(vector<int> adj[], vector<bool>& visited, int node) {
        visited[node] = true;

        for (auto it : adj[node]) {
            if (visited[it] == false) {
                dfs(adj, visited, it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;
        for (int v = 0; v < n; v++) {
            if (visited[v] == false) {
                count++;
                dfs(adj, visited, v);
            }
        }
        return count;
    }
};