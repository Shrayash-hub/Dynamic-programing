class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> indexMap;
        int minDistance = INT_MAX;
 
        for (int j = 0; j < (int)nums.size(); j++) {
            // Look up nums[j] — earlier entries stored reverse(nums[i]) as key
            if (indexMap.count(nums[j])) {
                minDistance = min(minDistance, j - indexMap[nums[j]]);
            }
 
            // Store reverse(nums[j]) → j, overwriting older index (only need the latest)
            int reversed = reverseDigits(nums[j]);
            indexMap[reversed] = j;
        }
 
        return minDistance == INT_MAX ? -1 : minDistance;
    }
 
private:
    int reverseDigits(int num) {
        int reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + (num % 10);
            num /= 10;
        }
        return reversed;
    }
};