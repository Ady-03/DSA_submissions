class Solution {
private:
    int solve(int n, vector<int>& coins, vector<int>& dp){
        if(n == 0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        
        int ans = INT_MAX;

        for(int i=0; i<coins.size(); i++){
            if(coins[i] <= n){
                int sub = solve(n-coins[i],coins,dp);
                
                if(sub != INT_MAX)
                    ans = min(ans,1+sub);
            }
        }
        return dp[n] = ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> dp(amount+1,-1);
        int ans = solve(amount, coins, dp);

        return ans == INT_MAX ? -1 : ans;
    }
};
