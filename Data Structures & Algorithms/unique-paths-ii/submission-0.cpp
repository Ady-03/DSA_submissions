class Solution {
   private:
    int solve(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (row < 0 || col < 0) return 0;
        if (grid[row][col] == 1) return 0;
        if (row == 0 && col == 0) return 1;

        if (dp[row][col] != -1) return dp[row][col];

        return dp[row][col] = solve(row - 1, col, dp, grid) + solve(row, col - 1, dp, grid);
    }

   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(m - 1, n - 1, dp, obstacleGrid);
    }
};