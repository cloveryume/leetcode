class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i) {
            bool *bs = new bool[10]();
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                if (bs[board[i][j] - '0']) return false;
                bs[board[i][j] - '0'] = true;
            }
            delete []bs;
        }

        for (int i = 0; i < 9; ++i) {
            bool *bs = new bool[10]();
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') continue;
                if (bs[board[j][i] - '0']) return false;
                bs[board[j][i] - '0'] = true;
            }
            delete []bs;
        }

        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9; j += 3) {
            bool *bs = new bool[10]();
            for (int m = i; m < i + 3; ++m) 
                for (int n = j; n < j + 3; ++n) {
                    if (board[m][n] == '.') continue;
                    if (bs[board[m][n] - '0']) return false;
                    bs[board[m][n] - '0'] = true;
            }
            delete []bs;
        }
        return true;
    }
};
