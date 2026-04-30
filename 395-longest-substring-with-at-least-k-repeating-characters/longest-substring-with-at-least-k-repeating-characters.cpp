class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int targetUnique = 1; targetUnique <= 26; targetUnique++) {
            vector<int> freq(26, 0);

            int left = 0, right = 0;
            int unique = 0;
            int atLeastK = 0;

            while (right < n) {
                // expand window
                if (freq[s[right] - 'a'] == 0) unique++;
                freq[s[right] - 'a']++;
                if (freq[s[right] - 'a'] == k) atLeastK++;
                right++;

                // shrink window if too many unique chars
                while (unique > targetUnique) {
                    if (freq[s[left] - 'a'] == k) atLeastK--;
                    freq[s[left] - 'a']--;
                    if (freq[s[left] - 'a'] == 0) unique--;
                    left++;
                }

                // valid window
                if (unique == targetUnique && unique == atLeastK) {
                    ans = max(ans, right - left);
                }
            }
        }

        return ans;
    }
};