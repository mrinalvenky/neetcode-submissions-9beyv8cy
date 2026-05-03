class Solution {
public:
    void capture(int row, int col, vector<vector<char>>& board) {
        if ( (row < 0 || row >= board.size()) ||
             (row < 0 || row >= board.size()) ||
             (board[row][col] != 'O')
        ) return;
        board[row][col] = 'T';
        capture(row + 1, col, board);
        capture(row - 1, col, board);
        capture(row, col + 1, board);
        capture(row, col - 1, board);
    }
    void solve(vector<vector<char>>& board) {
        if (!board.size() || !board[0].size()) return;
        int ROWS = board.size(), COLS = board[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j< COLS; j++) {
                if (((i == 0 || i == ROWS - 1) ||
                     (j == 0 || j == COLS - 1)) &&
                     (board[i][j] == 'O')) {
                        capture(i, j, board);
                     }
            }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j< COLS; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
