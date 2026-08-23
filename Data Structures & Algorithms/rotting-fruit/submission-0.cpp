class Solution {
public:
    const int dir[5] = {0, 1, 0, -1, 0}; 

    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> q; 
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                } else if (grid[i][j] == 1) { 
                    fresh++;
                }
            }
        }

        int minutes = 0;

        while (!q.empty()) {
            auto [r, c, time] = q.front(); 
            q.pop();
            minutes = time;

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; 
                    fresh--;
                    q.push({nr, nc, time + 1});
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};
