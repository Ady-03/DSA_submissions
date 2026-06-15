class Solution {
   private:
    int solve(int ind, int total, int target, int stoneSum, vector<int>& stones,
              vector<vector<int>>& dp) {
        if (ind == stones.size() || total >= target) return abs(total - (stoneSum - total));

        if(dp[ind][total] != -1)
            return dp[ind][total];
        return dp[ind][total] = min(solve(ind + 1, total, target, stoneSum, stones, dp),
                   solve(ind + 1, total + stones[ind], target, stoneSum, stones, dp));
    }

   public:
    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = 0;

        for (int i = 0; i < stones.size(); i++) stoneSum += stones[i];
        vector<vector<int>> dp(stones.size() + 1, vector<int>((stoneSum + 3) / 2, -1));
        return solve(0, 0, (stoneSum + 1) / 2, stoneSum, stones, dp);
    }
};