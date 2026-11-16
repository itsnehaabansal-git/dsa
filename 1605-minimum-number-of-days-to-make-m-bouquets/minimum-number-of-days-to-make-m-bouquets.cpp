class Solution {
    bool ispos(vector<int>& bloomDay, int m, int k, int mid) {
        int cnt = 0;
        int bouq = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt == k) {
                bouq++;
                cnt = 0;
            }
        }
        return bouq >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        if (1LL * m * k > bloomDay.size())
            return -1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (ispos(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};