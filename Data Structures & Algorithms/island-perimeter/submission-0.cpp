class Solution {
public:
    int rows;
    int cols;
    unordered_set<int> visited; 

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return 1;
        }

        int key = r * cols + c;
        if (visited.count(key)) {
            return 0;
        }

        visited.insert(key);

        return dfs(grid, r - 1, c) + 
               dfs(grid, r + 1, c) + 
               dfs(grid, r, c - 1) + 
               dfs(grid, r, c + 1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    return dfs(grid, r, c);
                }
            }
        }
        return 0;
    }
};
