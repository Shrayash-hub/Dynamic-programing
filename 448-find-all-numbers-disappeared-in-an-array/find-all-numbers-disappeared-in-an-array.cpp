class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // nums[i]-1 btayega ki is index ka element nums[i] me available h
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                // visited krney k liye -nums[i] kr diya h us index pr jakey
                nums[idx] = -nums[idx];
            }
        }
        
        // collecting the  missing numbers -> as jis index pr nonn negative value hogi , uska mtlb us inde pr jo number hona chahiye vo present hi nhi h
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};