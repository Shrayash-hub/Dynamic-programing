class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int arr[101] = {0};
        vector<int> ans;
        for (int a = 0; a < nums.size(); a++)
            arr[nums[a]]++;
        for (int a = 1; a < 101; a++)
            arr[a] += arr[a - 1];
        for (int a = 0; a < nums.size(); a++) {
            if (nums[a] == 0)
                ans.push_back(0);
            else
                ans.push_back(arr[nums[a] - 1]);
        }
        return ans;
    }
};