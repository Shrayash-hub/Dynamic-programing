class Solution {
public:
    int cntSubarraySmallerThanEqualToGoal(vector<int>& s, int k) {
        if (k < 0)
            return 0;
        int n = s.size();
        int left = 0;
        int right = 0;
        int cnt = 0;
        unordered_map<int, int> mpp;
        while (right < n) {
            mpp[s[right]]++;
            while(mpp.size() > k) {
                mpp[s[left]]--;
                if (mpp[s[left]] == 0) {
                    mpp.erase(s[left]);
                }
                left++;
            }
            cnt = cnt + (right - left + 1);
            right++;
        }

        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return cntSubarraySmallerThanEqualToGoal(nums, k) -
               cntSubarraySmallerThanEqualToGoal(nums, k - 1);
    }
};