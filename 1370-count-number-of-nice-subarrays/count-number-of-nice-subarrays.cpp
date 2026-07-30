class Solution {
public:
    int cntSubarraySmallerThanEqualToGoal(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int n = nums.size();
        int cnt = 0;
        int sum = 0;
        int right = 0;
        int left = 0;

        while (right < n) {
            sum += (nums[right] % 2); // cosidering odd -> 1 and even -> 0
            // the sum exceeds the goal , we need to move the left pointer until
            // sum comes in range
            while (sum > goal) {
                sum = sum - (nums[left] % 2);
                left++;
            }
            // we need to count all the subarrays , from left to current right
            // as we need sum<= goal
            cnt += (right - left + 1);
            right++;
        }
        return cnt;
    }
    // this question becomes exactly similar to "binary subarray with sum k lc
    // 930", if we consider odd elements in the array as 1 and even elements as
    // zero
    int numberOfSubarrays(vector<int>& nums, int k) {
        // instead of counting the subarray with sum  goal , cnt the subarrays
        // with sum <= goal and sum <= goal-1 , then subtract them , remains
        // will be the cnt of subarray with sum = goal
        return cntSubarraySmallerThanEqualToGoal(nums, k) -
               cntSubarraySmallerThanEqualToGoal(nums, k - 1);
    }
};