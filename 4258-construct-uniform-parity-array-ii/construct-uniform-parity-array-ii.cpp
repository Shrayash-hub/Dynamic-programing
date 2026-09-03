class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        bool flag = true;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if ((nums[i] % 2) != (nums[0] % 2)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
        int mn = *min_element(nums.begin(), nums.end());
        return ((mn % 2) == 1);
    }
};