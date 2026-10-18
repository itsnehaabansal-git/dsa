class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
int tm =0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);
            int delr[4] = {-1, 0, 1, 0};
            int delc[4] = {0, -1, 0, 1};
            for (int i = 0; i < 4; i++) {
                int nr = r + delr[i];
                int nc = c + delc[i];
                if (nr >= 0 and nc >= 0 and nr < n and nc < m and
                    grid[nr][nc] == 1 and vis[nr][nc] != 2) {
                   q.push({{nr, nc}, t + 1});
                    vis[nr][nc] = 2;
                }
            }
        }
      

      for(int i = 0; i< n ; i++){
        for(int j =0 ; j< m; j++){
            if(grid[i][j] == 1 and vis[i][j] !=2){
                return -1;
            }
        }
      }

return tm;
    }
};