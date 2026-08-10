class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= m ||
            c < 0 || c >= n ||
            board[r][c] != 'O') {
            return;
        }

        // Mark as safe
        board[r][c] = '#';

        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();

        if (m == 0)
            return;

        n = board[0].size();

        // First and last column
        for (int r = 0; r < m; r++) {
            if (board[r][0] == 'O')
                dfs(board, r, 0);

            if (board[r][n - 1] == 'O')
                dfs(board, r, n - 1);
        }

        // First and last row
        for (int c = 0; c < n; c++) {
            if (board[0][c] == 'O')
                dfs(board, 0, c);

            if (board[m - 1][c] == 'O')
                dfs(board, m - 1, c);
        }

        // Convert remaining O â X
        // Restore safe # â O
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (board[r][c] == 'O')
                    board[r][c] = 'X';

                else if (board[r][c] == '#')
                    board[r][c] = 'O';
            }
        }
    }
};
