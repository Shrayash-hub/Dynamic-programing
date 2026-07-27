class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int Hashmap[256];
        for (int i = 0; i < 256; i++) {
            Hashmap[i] = -1;
        }
        int maxLen = 0;
        while (r < n) {
            // if the character is present in the Hashmap
            if (Hashmap[s[r]] != -1) {
                // now we have to check that if previously encountered char is
                // in the current window/ range or not if yes then move the left
                // pointer
                if (Hashmap[s[r]] >= l) {
                    l = Hashmap[s[r]] + 1;
                }
            }
            // find the maxLen
            maxLen = max(maxLen, r - l + 1);
            // update the newly index of this char
            Hashmap[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};