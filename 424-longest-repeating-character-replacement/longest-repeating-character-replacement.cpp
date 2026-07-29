class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxFreq = 0; // to save the maximum freq encountered in a window
        int maxLen = 0;
        unordered_map<int, int> mpp; // char -> freq

        while (r < n) {
            mpp[s[r] - 'A']++;
            maxFreq = max(maxFreq, mpp[s[r] - 'A']); // update the maxFreq

            int len = r - l + 1;
            if (len - maxFreq > k) { // we can find number of operations by len - maxFreq as we need to change this number of letters to make substring repreating
            // if operations are greater than k , then reduce the window size by moving the left pointer and reducing the freq of the left out char
                mpp[s[l] - 'A']--;
                l++;
            }
            // if window is valid , update the max substring len
            len = r - l + 1;
            maxLen = max(maxLen, len);
            r++;
        }
        return maxLen;
    }
};