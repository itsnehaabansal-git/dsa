class Solution {
    // merge sort is about --- divide nd then merge the sorted arrays
    int cnt = 0;
    void countpairs(vector<int>& nums, int low, int high, int mid) {
        int right = mid + 1;

        for (int i = low; i <= mid; i++) {

            while (right <= high and (nums[i]) > (2LL * nums[right])) {
                right++;
            }
            cnt += (right - (mid + 1));
        }
    }
    void merge(vector<int>& nums, int low, int high, int mid) {
        int i = low;     // sorted arr A start
        int j = mid + 1; // sorted arr B start
        vector<int> temp;
        while (i <= mid and j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= high) {
            temp.push_back(nums[j]);
            j++;
        }

       for (int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }
    }

    void divide(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = (low + high) / 2;
        divide(nums, low, mid);
        divide(nums, mid + 1, high);
        countpairs(nums, low, high, mid);
        merge(nums, low, high, mid);
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
         divide(nums, 0 , n-1);
        return cnt;
    }
};