class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // bfs
        int n = grid.size();    // no.of rows
        int m = grid[0].size(); // no. of cols
       vector<vector<int>>vis(n,vector<int>(m,0));
        // i m traversing on the grid
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().first;  // old row
            int col = q.front().second; // old col
            // jiska pair q mei h and we have to traverse its 4 dir
            q.pop();

            int delrow[4] = {-1, 0, 1, 0};
            int delcol[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nr = row + delrow[i];
                int nc = col + delcol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 1 && vis[nr][nc] == 0) {
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }

int count =0;

        for(int i =0; i< n ; i++){
            for(int j =0 ; j< m ; j++){
                if(grid[i][j]== 1  and vis[i][j]== 0){
                    count++;
                }
            }
        }
        return count;
    }
};