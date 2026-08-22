class Solution {
private:
    unordered_set<int> columns;
    unordered_set<int> positiveDiag;
    unordered_set<int> negativeDiag; 
    vector<vector<string>> solutions;

    void backtrack(vector<string>& board, int row, int n) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int posDiagKey = row + col;
            int negDiagKey = row - col;

            if (columns.count(col) || positiveDiag.count(posDiagKey) || negativeDiag.count(negDiagKey)) {
                continue;
            }

            columns.insert(col);
            positiveDiag.insert(posDiagKey);
            negativeDiag.insert(negDiagKey);
            board[row][col] = 'Q';

            backtrack(board, row + 1, n);

            columns.erase(col);
            positiveDiag.erase(posDiagKey);
            negativeDiag.erase(negDiagKey);
            board[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        solutions.clear();
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, n);
        return solutions;
    }
};
