class Solution {
   private:
    int solve(int i, int n, vector<int>& coins, vector<vector<int>>& dp) {
        if (i == 0) {
            if (n % coins[i] == 0)
                return n / coins[i];
            else
                return 1e9;
        }
        if (dp[i][n] != -1) return dp[i][n];

        int not_take = solve(i - 1, n, coins, dp);
        int take = 1e9;

        if (coins[i] <= n) {
            take = 1 + solve(i, n - coins[i], coins, dp);
        }
        return dp[i][n] = min(take, not_take);
    }

   public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = solve(n - 1, amount, coins, dp);
        return ans >= 1e9? -1: ans;
    }
};
