class Solution {
   private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() &&
                grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                dfs(nrow, ncol, grid, vis);
            }
        }
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};
