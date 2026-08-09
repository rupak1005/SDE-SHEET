class Solution {
public:

    int rows;
    int cols;

    bool dfs(
        vector<vector<char>>& board,
        string& word,
        int row,
        int col,
        int index
    ) {

        // Found the entire word
        if (index == word.size()) {
            return true;
        }

        // Outside the board
        if (row < 0 ||
            row >= rows ||
            col < 0 ||
            col >= cols) {

            return false;
        }

        // Wrong character or already visited
        if (board[row][col] != word[index]) {
            return false;
        }

        // Save character
        char original = board[row][col];

        // Mark visited
        board[row][col] = '#';

        // Explore 4 directions
        bool found =
            dfs(board, word, row - 1, col, index + 1) ||
            dfs(board, word, row + 1, col, index + 1) ||
            dfs(board, word, row, col - 1, index + 1) ||
            dfs(board, word, row, col + 1, index + 1);

        // Undo
        board[row][col] = original;

        return found;
    }

    bool exist(
        vector<vector<char>>& board,
        string word
    ) {

        rows = board.size();
        cols = board[0].size();

        for (int row = 0; row < rows; row++) {

            for (int col = 0; col < cols; col++) {

                if (board[row][col] == word[0]) {

                    if (dfs(
                        board,
                        word,
                        row,
                        col,
                        0
                    )) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};