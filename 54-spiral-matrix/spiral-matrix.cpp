class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();    // rows;
        int n = matrix[0].size(); // cols;
        int sr = 0;
        int sc = 0;
        int er = m - 1;
        int ec = n - 1;
        vector<int> ans;

        while (sr <= er and sc <= ec) {

            // print sr
            for (int c = sc; c <= ec; c++) {
                ans.push_back(matrix[sr][c]);
            }
            sr++;
            // print ec
            for (int r = sr; r <= er; r++) {
                ans.push_back(matrix[r][ec]);
            }
            ec--;

            // print er
            if (sr <= er) {

                for (int c = ec; c >= sc; c--) {
                    ans.push_back(matrix[er][c]);
                }
            }
            er--;

            // print sc
            if (sc <= ec) {
                for (int r = er; r >= sr; r--) {
                    ans.push_back(matrix[r][sc]);
                }
            }
            sc++;
          
        }
        return ans;
    }
};