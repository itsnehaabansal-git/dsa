class Solution {
    bool ispossible(int mid, vector<int>& weights, int days) {
        int days_ = 1; // curr day count is 1
        int load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > mid) {
                days_++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days_ <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); // low
        int high = 0;                                           // high
        for (int i = 0; i < weights.size(); i++) {
            high += weights[i];
        }
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (ispossible(mid, weights, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};