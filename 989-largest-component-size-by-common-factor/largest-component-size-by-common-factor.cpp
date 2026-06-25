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
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();

        // finding the maximum value in the array
        int mx = *max_element(nums.begin(), nums.end());
        DisjointSet ds(mx);

        // connecting every number with its factors
        for (int i = 0; i < nums.size(); i++) {

            // checking all factors up to sqrt(number)
            for (int j = 2; j <= sqrt(nums[i]); j++) {

                // If j is a factor
                if (nums[i] % j == 0) {

                    // connect number with factor j
                    ds.unionBySize(nums[i], j);

                    // connect the paired factor with j
                    ds.unionBySize(nums[i] / j, j);
                }
            }
        }

        // storing the frequency of each connected component
        unordered_map<int, int> map;

        // lets find the parent of every number
        for (int i = 0; i < nums.size(); ++i) {

            //  getting the representative of the component
            int _x = ds.findUPar(nums[i]);

            // increase the size of this component
            map[_x]++;
        }

        // finding the component with maximum size
        int maxCount = 0;

        // largest component
        for (auto& m : map)
            maxCount = max(maxCount, m.second);

        return maxCount;
    }
};