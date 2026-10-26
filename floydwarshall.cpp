// directed graph
// multisource to des
// works for -ve weight graph

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        for(int i =0 ; i< n; i++){
            for(int j =0; j< n ; j++){
                if(i == j ){
                    dist[i][j]=0; // node to node : distance is 0
                }
            }
        }
        
        // k is via ki kiske via jana h 
        // 0 ke 
        // 1 ke.... n-1 ke
        for(int k = 0 ; k< n ; k++){
            for(int i =0 ; i< n ; i++){
                for(int j =0 ; j< n ; j++){
                    if(dist[i][k] != 1e8  and dist[k][j] != 1e8 ){
                         dist[i][j] = min(dist[i][j],(dist[i][k] + dist[k][j]));
                             // update if shortest path
                    }
                
             
                }
            }
        }
        
       
        
    }
};