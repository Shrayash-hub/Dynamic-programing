class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        unordered_map<int, int> mpp; // type -> freq
        while (r < n) {
            // increse the freq of that type in the map
            mpp[fruits[r]]++;
            // if map have more than 2 types of fruits
            if (mpp.size() > 2) {
                // reduce the window size by moving left pointer and also reduce the freq of types jispe se l shift hua h , coz ab vo window ki range me nhi h
                mpp[fruits[l]]--;
                // if freq of any type reduces to zero , remove that type , tbhi toh type <=2 a payenge
                if (mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                l++;
            }
            // age type max 2 h toh widow valid h , max length update krdo
            if (mpp.size() <= 2) {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};