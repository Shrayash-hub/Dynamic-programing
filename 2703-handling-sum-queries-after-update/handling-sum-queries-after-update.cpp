class Node {
public:
    int left = 0, right = 0; // Range boundaries [left, right]
    int sum = 0;             // Sum of 1s in this range
    int lazyTag = 0;         // Lazy propagation flag for range flip operations
};

class SegmentTree {
public:
    SegmentTree(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        // Allocate 4n nodes for the segment tree
        tree.resize(n << 2);
        for (int i = 0; i < tree.size(); ++i) {
            tree[i] = new Node();
        }
        // Build the segment tree starting from root (index 1)
        build(1, 1, n);
    }

    // Range modification: flip all bits in range [l, r]
    void modify(int nodeIdx, int l, int r) {
        // If current node's range is completely within [l, r]
        if (tree[nodeIdx]->left >= l && tree[nodeIdx]->right <= r) {
            // Toggle lazy flag
            tree[nodeIdx]->lazyTag ^= 1;
            // Flip the sum: total_elements - current_sum
            tree[nodeIdx]->sum = tree[nodeIdx]->right - tree[nodeIdx]->left +
                                 1 - tree[nodeIdx]->sum;
            return;
        }

        // Push down lazy propagation to children
        pushDown(nodeIdx);

        int mid = (tree[nodeIdx]->left + tree[nodeIdx]->right) >> 1;
        // Recursively modify left child if needed
        if (l <= mid) {
            modify(nodeIdx << 1, l, r);
        }
        // Recursively modify right child if needed
        if (r > mid) {
            modify(nodeIdx << 1 | 1, l, r);
        }

        // Update current node's sum from children
        pushUp(nodeIdx);
    }

    // Query the sum of elements in range [l, r]
    int query(int nodeIdx, int l, int r) {
        // If current node's range is completely within [l, r]
        if (tree[nodeIdx]->left >= l && tree[nodeIdx]->right <= r) {
            return tree[nodeIdx]->sum;
        }

        // Push down lazy propagation to children
        pushDown(nodeIdx);

        int mid = (tree[nodeIdx]->left + tree[nodeIdx]->right) >> 1;
        int result = 0;

        // Query left child if needed
        if (l <= mid) {
            result += query(nodeIdx << 1, l, r);
        }
        // Query right child if needed
        if (r > mid) {
            result += query(nodeIdx << 1 | 1, l, r);
        }

        return result;
    }

private:
    vector<Node*> tree; // Segment tree nodes
    vector<int> nums;   // Original array

    // Build the segment tree recursively
    void build(int nodeIdx, int l, int r) {
        tree[nodeIdx]->left = l;
        tree[nodeIdx]->right = r;

        // Leaf node: directly assign value from nums
        if (l == r) {
            tree[nodeIdx]->sum = nums[l - 1]; // Convert to 0-indexed
            return;
        }

        int mid = (l + r) >> 1;
        // Build left subtree
        build(nodeIdx << 1, l, mid);
        // Build right subtree
        build(nodeIdx << 1 | 1, mid + 1, r);

        // Update current node's sum from children
        pushUp(nodeIdx);
    }

    // Update parent node's sum from its children
    void pushUp(int nodeIdx) {
        tree[nodeIdx]->sum =
            tree[nodeIdx << 1]->sum + tree[nodeIdx << 1 | 1]->sum;
    }

    // Push down lazy propagation to children
    void pushDown(int nodeIdx) {
        if (tree[nodeIdx]->lazyTag) {
            int mid = (tree[nodeIdx]->left + tree[nodeIdx]->right) >> 1;

            // Apply flip operation to left child
            tree[nodeIdx << 1]->sum =
                mid - tree[nodeIdx]->left + 1 - tree[nodeIdx << 1]->sum;
            tree[nodeIdx << 1]->lazyTag ^= 1;

            // Apply flip operation to right child
            tree[nodeIdx << 1 | 1]->sum =
                tree[nodeIdx]->right - mid - tree[nodeIdx << 1 | 1]->sum;
            tree[nodeIdx << 1 | 1]->lazyTag ^= 1;

            // Clear the lazy tag
            tree[nodeIdx]->lazyTag ^= 1;
        }
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2,
                                  vector<vector<int>>& queries) {
        // Initialize segment tree with nums1
        SegmentTree* segTree = new SegmentTree(nums1);

        // Calculate initial sum of nums2
        long long totalSum = 0;
        for (int& value : nums2) {
            totalSum += value;
        }

        vector<long long> answer;

        // Process each query
        for (auto& query : queries) {
            if (query[0] == 1) {
                // Type 1: Flip bits in nums1 from index query[1] to query[2]
                // Convert to 1-indexed for segment tree
                segTree->modify(1, query[1] + 1, query[2] + 1);
            } else if (query[0] == 2) {
                // Type 2: Add query[1] * sum(nums1) to all elements in nums2
                // This effectively adds query[1] * sum(nums1) to totalSum
                totalSum += 1LL * query[1] * segTree->query(1, 1, nums1.size());
            } else {
                // Type 3: Return current sum of nums2
                answer.push_back(totalSum);
            }
        }

        return answer;
    }
};