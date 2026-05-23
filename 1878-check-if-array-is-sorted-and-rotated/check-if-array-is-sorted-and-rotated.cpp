class Solution {
public:
    bool check(vector<int>& nums) {
        // if array is sorted and rotated properly then there must be only one voilation where arr[i]>arr[i+1]
        // for index not getting out of bound we use arr[i % sizeof arr] , it will always result in 0 , 1 , 2
        // upto sizeof arr
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%nums.size()]){
                count++;
            }
        }
        return count<=1;
    }
};