class Solution {
private:
    bool solve(int ind, int total, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(ind == nums.size())
            return (total == target);
        
        if(dp[ind][total] != -1)
            return dp[ind][total];

        bool take = solve(ind+1, total+nums[ind], nums, target, dp);
        bool notake = solve(ind+1, total, nums, target, dp);

        return dp[ind][total] = take || notake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int total =0;
        for(int i:nums)
            total += i;
        if(total%2 != 0)    
            return false;
        vector<vector<int>> dp(nums.size()+1,vector<int>(total+1,-1));
        return solve(0, 0, nums, total/2, dp);
    }
};
