class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = nums.size()-1;

        // if nums is already sorted
        if(nums[low] <= nums[high]) return nums[low];
        while(low<high){
            int mid = low + (high-low)/2;
            // if right part is not sorted
            if(nums[mid]>nums[n-1]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];
    }
};