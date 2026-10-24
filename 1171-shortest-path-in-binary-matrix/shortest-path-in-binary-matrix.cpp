class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dis(n, vector<int>(n,INT_MAX));

        if(grid[0][0]== 1 or grid[n-1][n-1]==1){ // already vis 1 hota h see ex2 ex3
            return -1;
        }
        
        dis[0][0]=1; // marked src ka dis 
        q.push({1,{0,0}});
        int dr[]={-1,0,1,0,1,-1,-1,1};
        int dc[]={0,1,0,-1,1,-1,1,-1};
        while(!q.empty()){
          auto it = q.front(); // dis,{row,col}
          q.pop();
            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;
         if(row == n-1 and col == n-1){
            return dist;
         }
            for(int i =0; i< 8 ; i++){
                int nr = row+ dr[i];
                int nc = col+ dc[i];
                if(nr == n-1 and nc == n-1){
                    return dist+1;
                }

                if(nr >=0 and nr< n and nc>=0 and nc< n and grid[nr][nc] == 0 and dist +1 < dis[nr][nc] ){
                    dis[nr][nc]=dist+1;
                    q.push({dist+1,{nr,nc}});
                }
            }



        }
        return -1;
    }
};