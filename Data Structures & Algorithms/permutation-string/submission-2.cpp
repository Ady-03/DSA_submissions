class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int hash1[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            hash1[s1[i] - 'a']++;
        }

        int l = 0, r = 0;
        bool ans = false;
        int hash2[26] = {0};

        while (r < s2.length()) {
            hash2[s2[r] - 'a']++;

            while (r - l + 1 > s1.length()) {
                hash2[s2[l] - 'a']--;
                l++;
            }

            if (r - l + 1 == s1.length()) {
                ans = true;
                for (int i = 0; i < 26; i++) {
                    if (hash1[i] != hash2[i]){
                        ans = false;
                        break;
                    }
                }
            }
            if(ans)
                return true;
            r++;
        }
        return false;
    }
};
