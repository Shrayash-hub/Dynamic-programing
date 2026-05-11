class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (auto it : nums) {
            if (it > 9) {
                vector<int> temp;
                while (it > 0) {
                    int digit = it % 10;
                    temp.push_back(digit);
                    it = it / 10;
                }
                for (int i = temp.size() - 1; i >= 0; i--) {
                    ans.push_back(temp[i]);
                }
            } else {
                ans.push_back(it);
            }
        }
        return ans;
    }
};