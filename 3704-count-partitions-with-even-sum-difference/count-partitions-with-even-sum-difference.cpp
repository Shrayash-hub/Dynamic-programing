class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;

        int n = nums.size();

        // if total is even -> all partitions valid
        if (total % 2 == 0) return n - 1;

        // if total is odd -> none valid
        return 0;
    }
};