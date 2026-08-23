class Solution {
public:
    unordered_set<int> st;
    int row;
    int col;

    vector<int> dir = {0, 1, 0, -1, 0};
    int tmp;

    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (r >= row || c >= col || r < 0 || c < 0 || grid[r][c] == 0) {
            return;
        }

        int key = r * col + c;

        if (st.count(key)) {
            return;
        }

        st.insert(key);
        tmp++;
        for (int i = 0; i < 4; i++) {
            int nrow = r + dir[i];
            int ncol = c + dir[i+1];
            dfs(grid, nrow, ncol);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        row = grid.size();
        col = grid[0].size(); 
        int nums = 0;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                int key = r * col + c;
                if (grid[r][c] == 1 && !st.count(key)) {
                    tmp  = 0;
                    dfs(grid, r, c);

                    nums = max(nums,tmp); 
                }
            }
        }

        return nums;
    }
};
