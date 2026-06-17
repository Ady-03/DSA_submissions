class Solution {
   private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int& area) {
        vis[row][col] = 1;
        area = area + 1;
        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis, area);
            }
        }
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector(n, 0));
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int area = 0;
                    dfs(i, j, grid, vis, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
