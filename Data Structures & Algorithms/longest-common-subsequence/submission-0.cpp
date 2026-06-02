class Solution {
   private:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]) return 1 + solve(i - 1, j - 1, s, t, dp);
        return dp[i][j] = max(solve(i - 1, j, s, t, dp), solve(i, j - 1, s, t, dp));
    }

   public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, text1, text2, dp);
    }
};
