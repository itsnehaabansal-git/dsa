class Solution {
    vector<int> line(int n) {
        vector<int> seq;
        seq.push_back(1);
        long long ans1 = 1;
        for (int c = 1; c < n; c++) { // n here the n th row
            ans1 = ans1 * (n - c);
            ans1 = ans1 / c;
            seq.push_back(ans1);
        }
        return seq;
    }

public:
    vector<vector<int>> generate(int numRows) {
     vector<vector<int>>ans;
        for (int i = 1; i <= numRows; i++) {
            vector<int> temp = line(i);
            ans.push_back(temp);
        }
        return ans;
    }
};