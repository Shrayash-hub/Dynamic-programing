class Solution {
public:
    string minWindow(string s, string t) {
        int startInd = -1;
        int minLen = INT_MAX;
        int cnt =
            0; // for storing the number of char of t found in substring of s
        int mpp[255] = {0}; // char -> freq
        int r = 0,
            l = 0;
        // increasing the freq of all the char of t in map
        for (auto it : t) {
            mpp[it]++;
        }
        while (r < s.size()) {
            // if char is present in map and have freq greater than 1 then its a char from 't'
            if (mpp[s[r]] > 0)
                cnt++;
            // reduce the freq of curr char 
            mpp[s[r]]--;

            // if cnt == t.size  then we got a valid window and we need to try to shrink it as possible as we can
            while (cnt == t.size()) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startInd = l;
                }
                // move the left pointer and increase the frequency in map
                mpp[s[l]]++;
                // if any chars freq become greater than 1 then its re inserted , cnt should be reduced and it is going out of window
                if (mpp[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        if (startInd != -1) {
            return s.substr(startInd, minLen);
        }
        return "";
    }
};