class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n + 1, 0);

        for (int x : arr) {
            freq[min(x, n)]++;
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            ans = min(i, ans + freq[i]);
        }

        return ans;
    }
};