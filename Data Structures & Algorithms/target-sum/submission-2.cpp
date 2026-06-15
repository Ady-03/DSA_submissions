class Solution {
   private:
    int solve(int ind, int total, vector<int>& nums, int target, vector<vector<int>>& dp, int offset) {
        if (ind == nums.size()) {
            return (total == target);
        }

        if (dp[ind][total + offset] != -1) return dp[ind][total+offset];

        int take1 = solve(ind + 1, total + nums[ind], nums, target, dp, offset);
        int take2 = solve(ind + 1, total - nums[ind], nums, target, dp, offset);

        return dp[ind][total+offset] = take1 + take2;
    }

   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int i=0; i<nums.size(); i++)
            total += nums[i];
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2*total + 1, -1));
        return solve(0, 0, nums, target, dp, total);
    }
};
