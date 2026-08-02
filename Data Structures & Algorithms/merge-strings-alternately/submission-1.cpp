class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        int i = 0, j = 0;
        bool flag = true;
        while (i < word1.length() && j < word2.length()) {
            if (flag) {
                ans += word1[i];
                flag = false;
                i++;
            } else {
                ans += word2[j];
                flag = true;
                j++;
            }
        }

        while (i < word1.length()) {
            ans += word1[i];
            i++;
        }

        while (j < word2.length()) {
            ans += word2[j];
            j++;
        }

        return ans;
    }
};