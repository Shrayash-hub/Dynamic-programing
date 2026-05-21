class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = 0;
        for (auto it : nums) {
            sum += it;
        }
        vector<int> ans;
        int lSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            lSum += nums[i];
            int rSum = sum - lSum;
            int value1 = (nums[i] * (i + 1)) - lSum;
            int value2 = (nums[i] * (nums.size() - i - 1)) - rSum;
            ans.push_back(abs(value1) + abs(value2));
        }
        return ans;
    }
};