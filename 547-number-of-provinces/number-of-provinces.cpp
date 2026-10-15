class Solution {
private:
    void dfs(int node, vector<int> adjls[], vector<int>& vis) {
        vis[node] = 1;
        for (auto it: adjls[node]) {
            if (vis[it] == 0) {
                dfs(it, adjls, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjls[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 and i != j) {
                    adjls[i].push_back(j);
                  
                }
            }
        }

    vector<int> vis(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                count++;
                dfs(i, adjls, vis);
            }
        }

        return count;
    }
};