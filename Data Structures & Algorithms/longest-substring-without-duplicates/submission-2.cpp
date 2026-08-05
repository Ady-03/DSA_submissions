class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int hash[256] = {0};
        int maxlen = 0;
        int l = 0, r = 0;

        while (r < s.length()) {
            hash[s[r]]++;

            while (hash[s[r]] > 1) {
                hash[s[l]]--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
