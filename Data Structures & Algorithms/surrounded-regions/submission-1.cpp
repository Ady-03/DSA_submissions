class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O') {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> node = q.front();
            int row = node.first;
            int col = node.second;
            q.pop();
            int drow[] = {0, -1, 0, 1};
            int dcol[] = {-1, 0, 1, 0};

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < board.size() && ncol >= 0 && ncol < board[0].size() &&
                    board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        for (int i = m - 2; i > 0; i--) {
            for (int j = n - 2; j > 0; j--) {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
