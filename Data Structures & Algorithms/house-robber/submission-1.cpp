class Solution {
   private:
    int solve(int n, vector<int>& nums, vector<int>& dp) {
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];

        int rob = nums[n] + solve(n - 2, nums, dp);
        int skip = solve(n - 1, nums, dp);

        return dp[n] = max(rob, skip);
    }

   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(n - 1, nums, dp);
    }
};
