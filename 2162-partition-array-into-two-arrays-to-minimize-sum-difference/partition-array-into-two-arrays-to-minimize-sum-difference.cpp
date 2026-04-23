class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        int total = 0;
        for (int num : nums) total += num;

        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());

        // Store subset sums grouped by count
        vector<vector<int>> leftSum(half + 1), rightSum(half + 1);

        // Generate subset sums
        generate(left, leftSum);
        generate(right, rightSum);

        // Sort right side for binary search
        for (int i = 0; i <= half; i++) {
            sort(rightSum[i].begin(), rightSum[i].end());
        }

        int ans = INT_MAX;

        for (int k = 0; k <= half; k++) {
            auto& lList = leftSum[k];
            auto& rList = rightSum[half - k];

            for (int lSum : lList) {
                int target = total / 2 - lSum;

                auto it = lower_bound(rList.begin(), rList.end(), target);

                // check it
                if (it != rList.end()) {
                    int sum = lSum + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }

                // check previous
                if (it != rList.begin()) {
                    --it;
                    int sum = lSum + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }
            }
        }

        return ans;
    }

private:
    void generate(vector<int>& arr, vector<vector<int>>& res) {
        int n = arr.size();
        int total = 1 << n;

        for (int mask = 0; mask < total; mask++) {
            int sum = 0;
            int count = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += arr[i];
                    count++;
                }
            }

            res[count].push_back(sum);
        }
    }
};