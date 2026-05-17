class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstMini = INT_MAX;
        int secondMini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= firstMini)
                firstMini = nums[i]; // i
            else if (nums[i] <= secondMini)
                secondMini = nums[i]; // j
            else
                return true; // we got third -> j
        }
        return false;
    }
};