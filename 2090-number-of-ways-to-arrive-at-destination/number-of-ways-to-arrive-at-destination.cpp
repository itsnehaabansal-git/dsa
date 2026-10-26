class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long >dis(n,LLONG_MAX); // int was causing err therefore long long
        vector<int>ways(n,0);
        priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;

      dis[0]=0;
      ways[0]=1;
      pq.push({0,0}); // dis,node

      while(!pq.empty()){
        auto it = pq.top();
        long long dist = it.first; // already carrying time to reach dist
         int node = it.second;
         pq.pop();
         for(auto it : adj[node]){
           long long v = it.first ;
            int time = it.second;
            if(dist + time < dis[v]){
                dis[v]=dist + time;
                pq.push({ dis[v],v});
                ways[v]=ways[node];
            }
            else  if( dist + time == dis[v]){
              ways[v]=(ways[node]+ ways[v]) % mod;
            } // already vis path in min time i need to add prev ways into my curr ones,.

         }
      }
      return ways[n-1] % mod;
    }
};