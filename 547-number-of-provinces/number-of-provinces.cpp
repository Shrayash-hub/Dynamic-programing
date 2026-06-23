class Disjoint {
public:
    vector<int> parent;
    vector<int> rank;

public:
    Disjoint(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionNormal(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }

    void unionByRank(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            rank[rootY]++;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        Disjoint ds(isConnected.size());

        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                // union the nodes if they are connected 
                if (isConnected[i][j] == 1) {
                    ds.unionNormal(i, j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            // agr koi node khud ka parent h , toh vo ek alag province h
            if (ds.find(i) == i) {
                cnt++;
            }
        }
        return cnt;
    }
};