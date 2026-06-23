class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        // initially har node khud ka parent
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // find with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;

        // path compression → tree flatten ho jata h
        return parent[node] = findUPar(parent[node]);
    }

    // union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // already same component → no need
        if (ulp_u == ulp_v)
            return;

        // smaller tree → larger tree me attach
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mpp; // email -> account

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                    // if email is already present in the mpp
                if (mpp.find(email) == mpp.end()) {
                    mpp[email] = i;
                }
                // if this email is already in the mpp, make the ultimate parent
                // same
                else {
                    ds.unionBySize(mpp[email], i);
                }
            }
        }

        // grouping emails by parent
        vector<string> adj[accounts.size()];

        for (auto& it : mpp) {
            string email = it.first;
            int node = ds.findUPar(it.second);

            // jinke ultimate parents same h , put them together as -> they belong to same account 
            adj[node].push_back(email);
        }

        // building answer
        vector<vector<string>> ans;

        for (int node = 0; node < accounts.size(); node++) {
            if (adj[node].empty())
                continue;

            auto emails = adj[node];

            // sorting emails
            sort(emails.begin(), emails.end());

            // insert the account name at start
            emails.insert(emails.begin(), accounts[node][0]);
            ans.push_back(emails);
        }

        return ans;
    }
};