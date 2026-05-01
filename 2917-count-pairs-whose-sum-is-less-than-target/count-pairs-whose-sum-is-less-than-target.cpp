class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                cnt += right - left; // update the count
                left++;                // increment the left
            } else {                   // else
                right--;               // decrement the right
            }
        }
        return cnt;
    }
};