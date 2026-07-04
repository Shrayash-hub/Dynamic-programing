class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<vector<int>>> adj;

        for (auto& it : roads) {
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }

        queue<int> q;
        q.push(1);
        vector<bool> visited(n + 1, false);
        visited[1] = true;
        int ans = INT_MAX;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto nei : adj[node]) {
                int v = nei[0];
                int cost = nei[1];
                ans = min(cost, ans);
                if (visited[v] == true)
                    continue;

                q.push(v);
                visited[v] = true;
            }
        }
        return ans;
    }
};