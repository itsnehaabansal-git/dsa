
class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n ||
            grid[i][j] == '0' || vis[i][j] == 1) {
            return;
        }

        vis[i][j] = 1;

        dfs(i + 1, j, grid, vis);
        dfs(i, j + 1, grid, vis);
        dfs(i, j - 1, grid, vis);
        dfs(i - 1, j, grid, vis);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;

        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return count;
    }
};
