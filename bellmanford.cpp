//gfg problem 
// bellman ford algorithm 
// negative edgeweights of graph
class Solution {
	public:
	vector<int> bellmanFord(int V, vector<vector<int>> & edges, int src) {
		// Code here
		
		// bellman ford algo
		// if negative weights dijkstra algo fails
		
		// relaxation  of edges for V-1 iterations
		// and for the V TH ITERATION if it is still getting relaxed
		// means dis array still changing, it is  negative cycle
		vector<int>dis(V,1e8);
		dis[src]=0;
		for (int i = 0 ; i<V - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if(dis[u] != 1e8 and  dis[u]+ wt < dis[v]){
				    dis[v] = dis[u]+wt;
				}
			}
			
		}
		// vth iteration agr ismei relax ho rhe edge mtlb neg cycle h
		for(auto it : edges){
		    	int u = it[0];
				int v = it[1];
				int wt = it[2];
				if(dis[u] != 1e8 and  dis[u]+ wt < dis[v]){
				 return {-1}; //as said in ques neg cycle h bcz
				}
		}
	return dis;	
	}
};
