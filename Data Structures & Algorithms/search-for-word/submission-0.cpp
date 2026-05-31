class Solution {
private:
    bool search(vector<vector<char>>& board, string& word,
                vector<vector<int>>& vis, int i, int j, int index) {
        if (index == word.size())
            return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            vis[i][j] || board[i][j] != word[index])
            return false;
        int m = board.size(), n = board[0].size();
        vis[i][j] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int ind = 0; ind < 4; ind++) {
            int nrow = i + drow[ind];
            int ncol = j + dcol[ind];
            if (search(board, word, vis, nrow, ncol, index + 1)) 
                return true;
        }
        vis[i][j] = 0;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        char curr;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        string find;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (search(board, word, vis, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};