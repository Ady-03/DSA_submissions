class Solution {
public:
    string minWindow(string s, string t) {

        int l = 0, r = 0, minlen = INT_MAX, cnt = 0;
        int SIndex = -1;
        int m = s.length(), n = t.length();
        vector<int> hash(256, 0);

        for (int i = 0; i < n; i++) {
            hash[t[i]]++;
        }

        while (r < m) {
            if (hash[s[r]] > 0)
                cnt++;

            hash[s[r]]--;
            while (cnt == n) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    SIndex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }

        return SIndex == -1 ? "" : s.substr(SIndex, minlen);
    }
};