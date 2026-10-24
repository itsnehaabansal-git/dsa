class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // Code here
    
     vector<vector<pair<int,int>>> adj(V+1);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        };
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(V+1,1e9);
        vector<int>parent(V+1);
        for(int i =1 ; i <= V ; i++){
            parent[i]=i;
        };
        dis[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int node =pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            if (distance > dis[node]) {
                          continue;
                      }
            for(auto it: adj[node]){
              int v=   it.first ;// v
              int wt =  it.second ;// wt
              if(distance + wt < dis[v]){
                  dis[v]= distance + wt;
                    pq.push({dis[v], v});
                  parent[v] = node;
                
                  
                  
              }
            }
        }
        if(dis[dest]== 1e9){
            return {-1};
        }
        vector<int>path;
        int n = dest;// current node
        while(parent[n]!= n){
            path.push_back(n);
            n = parent[n];
        }
        path.push_back(src);
        reverse(path.begin(),path.end());
        return path;
    }
};