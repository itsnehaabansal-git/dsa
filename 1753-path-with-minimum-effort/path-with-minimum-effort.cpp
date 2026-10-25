class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        //   {diff,{row,col}}
        // priority queue
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>dis(n,vector<int>(m,INT_MAX)); //distance
        
        dis[0][0]=0;
        pq.push({0,{0,0}}); // diff 0 ,row 0 col 0
        int dr[]={-1,0,1,0};
        int dc []={0,1, 0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first; //old effort
            int row = it.second.first;
            int col = it.second.second;
            if(row == n-1 and col == m-1){
                return diff;
            }
           for(int i =0 ; i<4; i++){
            int nr = row+ dr[i];
            int nc = col + dc[i];
            if(nr>=0 and nc>=0 and nr<n and nc< m  ){
                int newEffort = max((abs(heights[nr][nc]- heights[row][col])),diff);
                    if(newEffort < dis[nr][nc]){
                   dis[nr][nc] = newEffort;
                   pq.push({newEffort, {nr, nc}});
                    
                }
            }
           }

        }


         return 0;
        
    }
};