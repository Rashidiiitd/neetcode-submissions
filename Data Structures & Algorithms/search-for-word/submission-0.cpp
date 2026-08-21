class Solution {
public:
    bool dfs(int r, int c, vector<vector<char>>& board, string &word, int idx)
    {
        if (idx == word.size()) {
            return true;
        }

        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[idx]) {
            return false;
        }

        char originalChar = board[r][c];
        board[r][c] = '#'; 

        bool left  = dfs(r, c - 1, board, word, idx + 1);
        bool right = dfs(r, c + 1, board, word, idx + 1);
        bool down  = dfs(r + 1, c, board, word, idx + 1);
        bool up    = dfs(r - 1, c, board, word, idx + 1);

        board[r][c] = originalChar;

        return left || right || down || up;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, board, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false; 
    }
};
