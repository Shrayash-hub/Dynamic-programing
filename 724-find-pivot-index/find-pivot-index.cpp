class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (auto it : nums) {
            sum += it;
        }
        int lSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            lSum += nums[i];
            int rSum = sum - lSum;
            if (lSum == (rSum + nums[i]))
                return i;
        }
        return -1;
    }
};