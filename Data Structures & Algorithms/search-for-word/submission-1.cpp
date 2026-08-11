class Solution {
   private:
    bool solve(int i, int j, vector<vector<char>>& board, int idx, string& word) {
        if (idx == word.size()) return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;

        if (board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};

        for (int k = 0; k < 4; k++) {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            if (solve(nrow, ncol, board, idx + 1, word)) {
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }

   public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(i, j, board, 0, word)) return true;
            }
        }
        return false;
    }
};
