class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;  // {row, col, distance}
        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            grid[row][col] = min(dis, grid[row][col]);

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == INT_MAX &&
                    !vis[nrow][ncol]) {
                    q.push({{nrow, ncol}, dis + 1});
                }
            }
        }
    }
};
