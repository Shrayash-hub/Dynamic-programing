class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int n = nums.size();
        while(i < n && j < n){
            // if both are zero , then move j by 1 -> so that j reaches to a non zero nums
            if(nums[i] == 0 && nums[j] == 0){
                j++;
            }
            // if i at zero and j at non zero then swap -> so that zero come at the end
            else if(nums[i] == 0 && nums[j] != 0){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            // if j at zero and i at not zero , so its already at right position, and if both are non zero then already at right positions
            else{
                i++;
                j++;
            }
        }
    }
};