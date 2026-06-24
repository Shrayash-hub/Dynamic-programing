class DisjointSet {

public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        // initially sab apne parent khud hote h
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // find with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;

        // path compression -> tree flat ban jata h
        return parent[node] = findUPar(parent[node]);
    }

    // union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // agar same component me h -> cycle banega
        if (ulp_u == ulp_v)
            return;

        // choti tree ko badi me attach karo
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        // lets connect all the components that are connected
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0)
                    continue;

                // lets go in all four direction in search of land
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && nj >= 0 && ni < grid.size() &&
                        nj < grid[0].size() && grid[ni][nj] == 1) {
                        // as we are treating each cell as a node , we have to
                        // convert the coordinates
                        int indexInitial = i * n + j;
                        int indexNext = ni * n + nj;

                        ds.unionBySize(indexInitial, indexNext);
                    }
                }
            }
        }

        // lets try flipping each of the 0s to the 1s (one by one)
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    continue;

                // for counting unique nbr components
                set<int> components;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && nj >= 0 && ni < n && nj < n &&
                        grid[ni][nj] == 1) {
                        components.insert(ds.findUPar(ni * n + nj));
                    }
                }
                int currSize = 0;
                for (auto par : components) {
                    currSize += ds.size[par];
                }
                maxi = max(maxi, currSize + 1);
            }
        }

        // edge case -> when whole cell is filled with 1s , so just find the
        // ultimate parent size of each cell -> answer is largest components
        for (int cell = 1; cell <= n * n; cell++) {
            maxi = max(maxi, ds.size[ds.findUPar(cell)]);
        }
        return maxi;
    }
};