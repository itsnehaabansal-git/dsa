class Solution {
    int first(vector<int>& nums, int target) {
        int low = 0;
        int first = -1;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] >= target) {
                first = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return first;
    }

    int last(vector<int>& nums, int target) {
        int low = 0;
        int last = -1;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] <= target) {
                last = mid;
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return last;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = first(nums, target);

        if (f == -1 || nums[f] != target) {
            return {-1, -1};
        }

        int l = last(nums, target);

        return {f, l};
    }
};