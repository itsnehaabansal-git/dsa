class Solution {
private:
    void dfs(vector<vector<char>>& board,
             vector<vector<int>>& vis, int row, int col) {
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        int n = board.size();
        int m = board[0].size();
        vis[row][col]=1;
        for(int i = 0 ; i< 4; i++){
            int nr = row + delrow[i];
            int nc = col +delcol[i];
            if(nr>=0  and nc>=0 and  nr< n and nc<m and  vis[nr][nc]== 0 and board[nr][nc]=='O' ){
                dfs(board,vis,nr,nc);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (board[i][j] == 'O' and vis[i][j] == 0) {
                        dfs(board, vis, i, j);
                    }
                }
            }
        }

       for(int i =0; i< n; i++){
        for(int j =0; j< m ; j++){
            if (board[i][j]=='O' and vis[i][j]==0){
                board[i][j]='X';
            }
        }
       }

    }
};