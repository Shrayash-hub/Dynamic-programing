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
    int findGCD(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        DisjointSet ds(mx);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 2; j <= sqrt(nums[i]); j++) {
                if (nums[i] % j == 0) {
                    ds.unionBySize(nums[i], j);
                    ds.unionBySize(nums[i] / j, j);
                }
            }
        }

        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int _x = ds.findUPar(nums[i]);
            map[_x]++;
        }

        int maxCount = 0;
        for (auto& m : map)
            maxCount = max(maxCount, m.second);

        return maxCount;
    }
};