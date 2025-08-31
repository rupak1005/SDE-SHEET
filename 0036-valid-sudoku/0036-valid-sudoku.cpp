class Solution {
public:
    // Check if the digit at board[row][col] is valid
    bool isvalid(const vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c && i != row) return false;          // Check column, excluding current cell
            if (board[row][i] == c && i != col) return false;          // Check row, excluding current cell
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == c && (boxRow != row || boxCol != col)) return false; // Check 3x3 block
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                if (!isvalid(board, i, j, c)) {
                    return false;
                }
            }
        }
        return true;
    }
};
