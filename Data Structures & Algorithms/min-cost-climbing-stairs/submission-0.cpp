class Solution {
private:
    int solve(int n, vector<int>& cost, vector<int>& dp){
        if(n == 0 || n == 1)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        dp[n] = min(solve(n-1, cost, dp) + cost[n-1],solve(n-2, cost, dp) + cost[n-2]);
        return dp[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return solve(n, cost, dp);
    }
};
