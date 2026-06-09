class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int l = 0, r = 0;
        int hash1[26] = {0};
        int n = s1.length();
        
        for (int i = 0; i < n; i++) {
            hash1[s1[i] - 'a']++;
        }

        int hash2[26] = {0};
        bool ans = false;
        
        while (r < s2.length()) {
            hash2[s2[r] - 'a']++;
            if (r - l + 1 > n) {
                hash2[s2[l] - 'a']--;
                l++;
            }
            if (r - l + 1 == n) {
                ans = true;
                for (int i = 0; i < 26; i++) {
                    if (hash1[i] != hash2[i]) {
                        ans = false;
                        break;
                    }
                }
            }

            if (ans) return true;
            r++;
        }
        return false;
    }
};
